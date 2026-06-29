#include "render.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raylib.h"
#include "raymath.h"

#define NODE_W        180.0f
#define NODE_H        110.0f
#define COL_SPACING   260.0f
#define ROW_SPACING   150.0f
#define MARGIN_X      80.0f
#define MARGIN_Y      80.0f

#define WINDOW_W      1200
#define WINDOW_H      750

#define FONT_PATH     "assets/Amazon-Ember-Medium.ttf"
#define FONT_BASE_PX  48
#define FONT_SPACING  0.5f

static Font g_font;
static bool g_font_loaded = false;

static void font_load(void) {
    if (FileExists(FONT_PATH)) {
        g_font = LoadFontEx(FONT_PATH, FONT_BASE_PX, NULL, 0);
        if (g_font.texture.id != 0 && g_font.glyphCount > 0) {
            SetTextureFilter(g_font.texture, TEXTURE_FILTER_BILINEAR);
            g_font_loaded = true;
            return;
        }
    }
    fprintf(stderr, "render: could not load '%s', falling back to default font\n", FONT_PATH);
    g_font = GetFontDefault();
}

static void font_unload(void) {
    if (g_font_loaded) UnloadFont(g_font);
    g_font_loaded = false;
}

static void text_draw(const char *text, int x, int y, int size, Color color) {
    DrawTextEx(g_font, text, (Vector2){ (float)x, (float)y }, (float)size, FONT_SPACING, color);
}

static int text_width(const char *text, int size) {
    return (int)MeasureTextEx(g_font, text, (float)size, FONT_SPACING).x;
}

typedef struct { float x, y; } Pos;

static Pos *compute_layout(const Graph *graph, int *out_max_rank) {
    Pos *positions = calloc((size_t)graph->count, sizeof(Pos));
    if (!positions) return NULL;

    int max_rank = 0;
    for (int i = 0; i < graph->count; ++i) {
        if (graph->items[i].topo_rank > max_rank) max_rank = graph->items[i].topo_rank;
    }
    if (out_max_rank) *out_max_rank = max_rank;

    int *count_per_rank  = calloc((size_t)(max_rank + 1), sizeof(int));
    int *placed_per_rank = calloc((size_t)(max_rank + 1), sizeof(int));
    if (!count_per_rank || !placed_per_rank) {
        free(count_per_rank); free(placed_per_rank); free(positions);
        return NULL;
    }
    for (int i = 0; i < graph->count; ++i) count_per_rank[graph->items[i].topo_rank] += 1;

    /* Walk in topo order so predecessors place before successors,
     * which tends to reduce edge crossings. */
    for (int i = 0; i < graph->count; ++i) {
        int index = graph->topo_order ? graph->topo_order[i] : i;
        int rank = graph->items[index].topo_rank;
        int slot = placed_per_rank[rank]++;
        float col_height = (count_per_rank[rank] - 1) * ROW_SPACING;
        positions[index].x = MARGIN_X + rank * COL_SPACING + NODE_W * 0.5f;
        positions[index].y = MARGIN_Y + NODE_H * 0.5f + slot * ROW_SPACING - col_height * 0.5f
                             + max_rank * ROW_SPACING * 0.5f;
    }

    free(count_per_rank);
    free(placed_per_rank);
    return positions;
}

static void draw_arrow_head(Vector2 tip, Vector2 dir, float size, Color color) {
    Vector2 back = { tip.x - dir.x * size, tip.y - dir.y * size };
    Vector2 perp = { -dir.y, dir.x };
    Vector2 left  = { back.x + perp.x * size * 0.5f, back.y + perp.y * size * 0.5f };
    Vector2 right = { back.x - perp.x * size * 0.5f, back.y - perp.y * size * 0.5f };
    DrawTriangle(tip, right, left, color);
}

static void draw_edge(Vector2 from, Vector2 to, bool critical) {
    Color color = critical ? (Color){ 200, 40, 40, 255 } : (Color){ 90, 90, 90, 255 };
    float thickness = critical ? 3.0f : 2.0f;

    Vector2 start = { from.x + NODE_W * 0.5f, from.y };
    Vector2 end   = { to.x   - NODE_W * 0.5f, to.y   };
    DrawLineEx(start, end, thickness, color);

    Vector2 dir = Vector2Subtract(end, start);
    float length = Vector2Length(dir);
    if (length > 0.001f) {
        dir.x /= length; dir.y /= length;
        draw_arrow_head(end, dir, 12.0f, color);
    }
}

static void draw_node(const Activity *activity, Vector2 center) {
    Rectangle rect = { center.x - NODE_W * 0.5f, center.y - NODE_H * 0.5f, NODE_W, NODE_H };

    Color fill   = activity->is_critical ? (Color){ 255, 224, 224, 255 } : (Color){ 245, 247, 250, 255 };
    Color border = activity->is_critical ? (Color){ 200,  40,  40, 255 } : (Color){  60,  72,  88, 255 };
    Color text   = (Color){ 20, 24, 32, 255 };

    DrawRectangleRounded(rect, 0.12f, 6, fill);
    DrawRectangleRoundedLinesEx(rect, 0.12f, 6, activity->is_critical ? 2.5f : 1.5f, border);

    char header[64], early_line[64], late_line[64], slack_line[64];
    snprintf(header,     sizeof(header),     "%s  (%dd)", activity->id, activity->duration);
    snprintf(early_line, sizeof(early_line), "ES %-3d  EF %-3d", activity->es, activity->ef);
    snprintf(late_line,  sizeof(late_line),  "LS %-3d  LF %-3d", activity->ls, activity->lf);
    snprintf(slack_line, sizeof(slack_line), "Slack %d%s", activity->slack, activity->is_critical ? "  *" : "");

    int x = (int)(rect.x + 10);
    text_draw(header,         x, (int)(rect.y +  8), 18, text);
    text_draw(activity->name, x, (int)(rect.y + 32), 14, text);
    text_draw(early_line,     x, (int)(rect.y + 54), 13, text);
    text_draw(late_line,      x, (int)(rect.y + 70), 13, text);
    text_draw(slack_line,     x, (int)(rect.y + 88), 13,
              activity->is_critical ? (Color){ 180, 30, 30, 255 } : text);
}

static void draw_hud(const Graph *graph) {
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "Project duration: %d", graph->project_duration);
    DrawRectangle(0, 0, GetScreenWidth(), 34, (Color){ 30, 36, 48, 230 });
    text_draw(buffer, 12, 8, 20, RAYWHITE);

    const char *hint = "drag: pan   wheel: zoom   R: reset view   ESC: quit";
    text_draw(hint, GetScreenWidth() - text_width(hint, 14) - 12, 12, 14,
              (Color){ 200, 210, 220, 255 });
}

static void draw_legend(void) {
    int x = 12, y = GetScreenHeight() - 64;
    DrawRectangle(x - 4, y - 4, 200, 56, (Color){ 30, 36, 48, 220 });

    DrawRectangle(x, y + 4, 16, 12, (Color){ 245, 247, 250, 255 });
    DrawRectangleLines(x, y + 4, 16, 12, (Color){ 60, 72, 88, 255 });
    text_draw("Normal activity", x + 24, y + 4, 13, RAYWHITE);

    DrawRectangle(x, y + 28, 16, 12, (Color){ 255, 224, 224, 255 });
    DrawRectangleLines(x, y + 28, 16, 12, (Color){ 200, 40, 40, 255 });
    text_draw("Critical activity", x + 24, y + 28, 13, RAYWHITE);
}

void render_run(const Graph *graph) {
    if (!graph || graph->count <= 0) {
        fprintf(stderr, "render: nothing to draw (empty graph)\n");
        return;
    }

    int max_rank = 0;
    Pos *positions = compute_layout(graph, &max_rank);
    if (!positions) {
        fprintf(stderr, "render: out of memory laying out graph\n");
        return;
    }

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(WINDOW_W, WINDOW_H, "CPM - Critical Path Method");
    SetTargetFPS(60);
    font_load();

    float graph_w = (max_rank + 1) * COL_SPACING + MARGIN_X;
    float graph_h = (float)WINDOW_H;

    Camera2D camera = {
        .zoom = 1.0f,
        .offset = { WINDOW_W * 0.5f, WINDOW_H * 0.5f },
        .target = { graph_w * 0.5f, graph_h * 0.5f },
    };

    while (!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            Vector2 mouse_delta = GetMouseDelta();
            camera.target.x -= mouse_delta.x / camera.zoom;
            camera.target.y -= mouse_delta.y / camera.zoom;
        }

        float wheel = GetMouseWheelMove();
        if (wheel != 0.0f) {
            /* Zoom toward the cursor: keep the world point under the mouse fixed. */
            Vector2 before = GetScreenToWorld2D(GetMousePosition(), camera);
            camera.zoom *= 1.0f + wheel * 0.1f;
            if (camera.zoom < 0.2f) camera.zoom = 0.2f;
            if (camera.zoom > 4.0f) camera.zoom = 4.0f;
            Vector2 after = GetScreenToWorld2D(GetMousePosition(), camera);
            camera.target.x += before.x - after.x;
            camera.target.y += before.y - after.y;
        }

        if (IsKeyPressed(KEY_R)) {
            camera.zoom = 1.0f;
            camera.target = (Vector2){ graph_w * 0.5f, graph_h * 0.5f };
        }
        camera.offset = (Vector2){ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f };

        BeginDrawing();
        ClearBackground((Color){ 18, 22, 30, 255 });

        BeginMode2D(camera);
        for (int i = 0; i < graph->count; ++i) {
            const Activity *successor = &graph->items[i];
            for (int k = 0; k < successor->num_deps; ++k) {
                int pred_index = successor->deps[k];
                const Activity *predecessor = &graph->items[pred_index];
                bool critical = predecessor->is_critical && successor->is_critical
                                && predecessor->ef == successor->es;
                draw_edge((Vector2){ positions[pred_index].x, positions[pred_index].y },
                          (Vector2){ positions[i].x, positions[i].y }, critical);
            }
        }
        for (int i = 0; i < graph->count; ++i) {
            draw_node(&graph->items[i], (Vector2){ positions[i].x, positions[i].y });
        }
        EndMode2D();

        draw_hud(graph);
        draw_legend();
        EndDrawing();
    }

    font_unload();
    CloseWindow();
    free(positions);
}
