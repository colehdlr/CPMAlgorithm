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

static void draw_edge(Vector2 from, Vector2 to, bool critical) {
    Color color = critical ? (Color){ 200, 40, 40, 255 } : (Color){ 90, 90, 90, 255 };
    float thickness = critical ? 3.0f : 2.0f;
    Vector2 start = { from.x + NODE_W * 0.5f, from.y };
    Vector2 end   = { to.x   - NODE_W * 0.5f, to.y   };
    DrawLineEx(start, end, thickness, color);
}

static void draw_node(const Activity *a, const CPMResult *r, Vector2 center) {
    bool critical = (r->total_float == 0);
    Rectangle rect = { center.x - NODE_W * 0.5f, center.y - NODE_H * 0.5f, NODE_W, NODE_H };
    Color fill   = critical ? (Color){ 255, 224, 224, 255 } : (Color){ 245, 247, 250, 255 };
    Color border = critical ? (Color){ 200,  40,  40, 255 } : (Color){  60,  72,  88, 255 };
    Color text   = (Color){ 20, 24, 32, 255 };

    DrawRectangleRounded(rect, 0.12f, 6, fill);
    DrawRectangleRoundedLinesEx(rect, 0.12f, 6, critical ? 2.5f : 1.5f, border);

    char buf[64];
    int x = (int)(rect.x + 10);
    snprintf(buf, sizeof(buf), "%c  (%dd)", a->id, a->duration);
    DrawText(buf, x, (int)(rect.y +  8), 18, text);
    DrawText(a->name, x, (int)(rect.y + 30), 14, text);
    snprintf(buf, sizeof(buf), "ES %-3d  EF %-3d", r->earliest_start, r->earliest_finish);
    DrawText(buf, x, (int)(rect.y + 52), 13, text);
    snprintf(buf, sizeof(buf), "LS %-3d  LF %-3d", r->latest_start, r->latest_finish);
    DrawText(buf, x, (int)(rect.y + 68), 13, text);
    snprintf(buf, sizeof(buf), "TF %-3d FF %-3d%s", r->total_float, r->free_float, critical ? "  *" : "");
    DrawText(buf, x, (int)(rect.y + 86), 13,
             critical ? (Color){ 180, 30, 30, 255 } : text);
}

void render_run(const Activity *activities, int count, const CPMResult *results) {
    if (count <= 0) return;

    /* Layout: longest-path rank by relaxation, then assign columns/rows. */
    Vector2 *positions = calloc((size_t)count, sizeof(Vector2));
    int     *rank      = calloc((size_t)count, sizeof(int));
    if (!positions || !rank) {
        free(positions); free(rank);
        fprintf(stderr, "render: out of memory\n");
        return;
    }
    for (int pass = 0; pass < count; ++pass) {
        for (int i = 0; i < count; ++i) {
            for (int k = 0; k < activities[i].dep_count; ++k) {
                int pr = rank[activities[i].deps[k]] + 1;
                if (pr > rank[i]) rank[i] = pr;
            }
        }
    }
    int *slot = calloc((size_t)count, sizeof(int));
    if (!slot) {
        free(positions); free(rank);
        fprintf(stderr, "render: out of memory\n");
        return;
    }
    for (int i = 0; i < count; ++i) {
        int r = rank[i];
        positions[i].x = MARGIN + r * COL_SPACING + NODE_W * 0.5f;
        positions[i].y = MARGIN + NODE_H * 0.5f + slot[r] * ROW_SPACING;
        slot[r]++;
    }
    free(slot);
    free(rank);

    /* Project duration (for HUD) + camera center (for initial view / R reset). */
    int project_duration = 0;
    Vector2 center = { 0, 0 };
    for (int i = 0; i < count; ++i) {
        if (results[i].earliest_finish > project_duration) {
            project_duration = results[i].earliest_finish;
        }
        center.x += positions[i].x;
        center.y += positions[i].y;
    }
    center.x /= count;
    center.y /= count;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);
    InitWindow(WINDOW_W, WINDOW_H, "CPM - Critical Path Method");
    SetTargetFPS(60);

    Camera2D camera = {
        .zoom = 1.0f,
        .offset = { WINDOW_W * 0.5f, WINDOW_H * 0.5f },
        .target = center,
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
            camera.target = center;
        }
        camera.offset = (Vector2){ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f };

        BeginDrawing();
        ClearBackground((Color){ 18, 22, 30, 255 });

        BeginMode2D(camera);
        for (int i = 0; i < count; ++i) {
            const Activity  *succ = &activities[i];
            const CPMResult *sr   = &results[i];
            for (int k = 0; k < succ->dep_count; ++k) {
                int p = succ->deps[k];
                const CPMResult *pr = &results[p];
                bool crit = (pr->total_float == 0) && (sr->total_float == 0)
                            && (pr->earliest_finish == sr->earliest_start);
                draw_edge(positions[p], positions[i], crit);
            }
        }
        for (int i = 0; i < count; ++i) {
            draw_node(&activities[i], &results[i], positions[i]);
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
