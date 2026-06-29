#include "render.h"

#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#define NODE_W       180.0f
#define NODE_H       110.0f
#define COL_SPACING  260.0f
#define ROW_SPACING  150.0f
#define MARGIN       80.0f
#define WINDOW_W     1200
#define WINDOW_H     750

typedef struct { float x, y; } Pos;

static Pos *compute_layout(const Activity *items, const int *topo_order,
                           int count, int *out_max_rank) {
    Pos *positions = calloc((size_t)count, sizeof(Pos));
    int *rank      = calloc((size_t)count, sizeof(int));
    if (!positions || !rank) { free(positions); free(rank); return NULL; }

    int max_rank = 0;
    for (int i = 0; i < count; ++i) {
        int idx = topo_order[i];
        int r = 0;
        for (int k = 0; k < items[idx].dep_count; ++k) {
            int p = find_activity(items, count, items[idx].deps_on_ids[k]);
            int pr = rank[p] + 1;
            if (pr > r) r = pr;
        }
        rank[idx] = r;
        if (r > max_rank) max_rank = r;
    }
    *out_max_rank = max_rank;

    int *slot = calloc((size_t)(max_rank + 1), sizeof(int));
    if (!slot) { free(positions); free(rank); return NULL; }

    for (int i = 0; i < count; ++i) {
        int idx = topo_order[i];
        int r = rank[idx];
        positions[idx].x = MARGIN + r * COL_SPACING + NODE_W * 0.5f;
        positions[idx].y = MARGIN + NODE_H * 0.5f + slot[r] * ROW_SPACING;
        slot[r]++;
    }

    free(slot);
    free(rank);
    return positions;
}

static void draw_edge(Vector2 from, Vector2 to, bool critical) {
    Color color = critical ? (Color){ 200, 40, 40, 255 } : (Color){ 90, 90, 90, 255 };
    float thickness = critical ? 3.0f : 2.0f;
    Vector2 start = { from.x + NODE_W * 0.5f, from.y };
    Vector2 end   = { to.x   - NODE_W * 0.5f, to.y   };
    DrawLineEx(start, end, thickness, color);
}

static void draw_node(const Activity *a, const CPMResult *r, Vector2 center) {
    bool is_critical = (r->total_float == 0);
    Rectangle rect = { center.x - NODE_W * 0.5f, center.y - NODE_H * 0.5f, NODE_W, NODE_H };
    Color fill   = is_critical ? (Color){ 255, 224, 224, 255 } : (Color){ 245, 247, 250, 255 };
    Color border = is_critical ? (Color){ 200,  40,  40, 255 } : (Color){  60,  72,  88, 255 };
    Color text   = (Color){ 20, 24, 32, 255 };

    DrawRectangleRounded(rect, 0.12f, 6, fill);
    DrawRectangleRoundedLinesEx(rect, 0.12f, 6, is_critical ? 2.5f : 1.5f, border);

    char buf[64];
    int x = (int)(rect.x + 10);
    snprintf(buf, sizeof(buf), "%c  (%dd)", a->id, a->duration);
    DrawText(buf, x, (int)(rect.y +  8), 18, text);
    DrawText(a->name, x, (int)(rect.y + 30), 14, text);
    snprintf(buf, sizeof(buf), "ES %-3d  EF %-3d", r->earliest_start, r->earliest_finish);
    DrawText(buf, x, (int)(rect.y + 52), 13, text);
    snprintf(buf, sizeof(buf), "LS %-3d  LF %-3d", r->latest_start, r->latest_finish);
    DrawText(buf, x, (int)(rect.y + 68), 13, text);
    snprintf(buf, sizeof(buf), "Slack %d%s", r->total_float, is_critical ? "  *" : "");
    DrawText(buf, x, (int)(rect.y + 86), 13,
             is_critical ? (Color){ 180, 30, 30, 255 } : text);
}

void render_run(const Activity *items, const CPMResult *results,
                int count, const int *topo_order, int project_duration) {
    if (count <= 0) return;

    int max_rank = 0;
    Pos *positions = compute_layout(items, topo_order, count, &max_rank);
    if (!positions) { fprintf(stderr, "render: out of memory\n"); return; }

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);
    InitWindow(WINDOW_W, WINDOW_H, "CPM - Critical Path Method");
    SetTargetFPS(60);

    float graph_w = (max_rank + 1) * COL_SPACING + MARGIN;
    Camera2D camera = {
        .zoom = 1.0f,
        .offset = { WINDOW_W * 0.5f, WINDOW_H * 0.5f },
        .target = { graph_w * 0.5f, WINDOW_H * 0.5f },
    };

    while (!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 d = GetMouseDelta();
            camera.target.x -= d.x / camera.zoom;
            camera.target.y -= d.y / camera.zoom;
        }
        float wheel = GetMouseWheelMove();
        if (wheel != 0.0f) {
            camera.zoom *= 1.0f + wheel * 0.1f;
            if (camera.zoom < 0.2f) camera.zoom = 0.2f;
            if (camera.zoom > 4.0f) camera.zoom = 4.0f;
        }
        if (IsKeyPressed(KEY_R)) {
            camera.zoom = 1.0f;
            camera.target = (Vector2){ graph_w * 0.5f, WINDOW_H * 0.5f };
        }
        camera.offset = (Vector2){ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f };

        BeginDrawing();
        ClearBackground((Color){ 18, 22, 30, 255 });

        BeginMode2D(camera);
        for (int i = 0; i < count; ++i) {
            const Activity *succ = &items[i];
            for (int k = 0; k < succ->dep_count; ++k) {
                int p = find_activity(items, count, succ->deps_on_ids[k]);
                bool crit = (results[p].total_float == 0) && (results[i].total_float == 0)
                            && results[p].earliest_finish == results[i].earliest_start;
                draw_edge((Vector2){ positions[p].x, positions[p].y },
                          (Vector2){ positions[i].x, positions[i].y }, crit);
            }
        }
        for (int i = 0; i < count; ++i) {
            draw_node(&items[i], &results[i], (Vector2){ positions[i].x, positions[i].y });
        }
        EndMode2D();

        char hud[64];
        snprintf(hud, sizeof(hud), "Project duration: %d", project_duration);
        DrawRectangle(0, 0, GetScreenWidth(), 34, (Color){ 30, 36, 48, 230 });
        DrawText(hud, 12, 8, 20, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    free(positions);
}
