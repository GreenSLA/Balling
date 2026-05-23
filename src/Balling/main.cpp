#include <raylib.h>
#include "Global.h"
#include "WindowHelper.h"

int main() {
    Global global;
    initialize(global);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Green!", 0, 0, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
}
