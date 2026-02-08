#include <raylib.h> // Includes the raylib header

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window"); //
    SetTargetFPS(60); // Set the desired frame rate

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update game state (e.g., check for input)
        // ...

        // Draw
        BeginDrawing();                 // Start drawing
        ClearBackground(RAYWHITE);      // Clear background to white color
        DrawText("Hello, raylib!", 190, 200, 20, LIGHTGRAY); // Draw text
        EndDrawing();                   // End drawing and swap buffers
    }

    // De-Initialization
    CloseWindow();                      // Close window and OpenGL context

    return 0;
}
