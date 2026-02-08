#include <raylib.h>

struct Global {
    static constexpr float VirtualWidth = 1600.0f;
    static constexpr float VirtualHeight = 800.0f;
    int WindowWidth = 0;
    int WindowHeight = 0;
    float Scale = 1.0f; // Отношение одного физического пикселя к виртуальному,
};

void Initialization(Global &g) {
    InitWindow(800, 600, "Balling");

    int monitor = GetCurrentMonitor();
    int monitorWidth = GetMonitorWidth(monitor);
    int monitorHeight = GetMonitorHeight(monitor);

    int supposedHeight = static_cast<int>(static_cast<float>(monitorWidth) / Global::VirtualWidth * Global::VirtualHeight);

    if (supposedHeight <= monitorHeight) {
        g.WindowWidth = monitorWidth;
        g.WindowHeight = supposedHeight;
    }
    else {
        g.WindowHeight = monitorHeight;
        g.WindowWidth = static_cast<int>(static_cast<float>(monitorHeight) / Global::VirtualHeight * Global::VirtualWidth);
    }

    g.Scale = static_cast<float>(g.WindowWidth) / Global::VirtualWidth;

    SetWindowSize(g.WindowWidth, g.WindowHeight);
    SetWindowPosition(0, 0);
    SetTargetFPS(144);
}

int main() {
    Global global;
    Initialization(global);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
}
