//
// Created by sroma on 23.05.2026.
//

#include <raylib.h>
#include <utility>
#include "Constants.h"
#include "Global.h"

std::pair<int, int> getCenteredWindowCoordinates(const int windowWidth, const int windowHeight) {
    const int monitor = GetCurrentMonitor();
    const int monitorWidth = GetMonitorWidth(monitor);
    const int monitorHeight = GetMonitorHeight(monitor);

    const float xCenter = static_cast<float>(monitorWidth - windowWidth) / 2.f;
    const float yCenter = static_cast<float>(monitorHeight - windowHeight) / 2.f;

    return {static_cast<int>(xCenter), static_cast<int>(yCenter)};
}

std::pair<int, int> calculateFittableWindowSize(const float wantedVirtualWidthToVirtualHeightRatio = 16 / 9.f) {
    int resultWindowHeight;
    int resultWindowWidth;

    const int monitor = GetCurrentMonitor();
    const int monitorWidth = GetMonitorWidth(monitor);
    const int monitorHeight = GetMonitorHeight(monitor);

    // monitorWidth / Global::VirtualWidth * Global::VirtualHeight = monitorWidth * (Global::VirtualHeight / Global::VirtualWidth) = monitorWidth * wantedVirtualWidthToVirtualHeightRatio
    // int supposedHeight = static_cast<int>(static_cast<float>(monitorWidth) / Global::VirtualWidth * Global::VirtualHeight);
    int supposedHeight = static_cast<int>(static_cast<float>(monitorWidth) * (1.f / wantedVirtualWidthToVirtualHeightRatio)); // Перевернул дробь

    if (supposedHeight <= monitorHeight) {
        resultWindowWidth = monitorWidth;
        resultWindowHeight = supposedHeight;
    }
    else {
        resultWindowHeight = monitorHeight;
        resultWindowWidth = static_cast<int>(static_cast<float>(monitorHeight) * wantedVirtualWidthToVirtualHeightRatio);
    }

    return {resultWindowWidth, resultWindowHeight};
}

void setScaleForCurrentWindowSize(Global &global) {
    const int currentWindowWidth = GetScreenWidth();

    global.Scale = static_cast<float>(currentWindowWidth) / Global::VirtualWidth;
}

void initialize(Global &g) {
    SetConfigFlags(FLAG_WINDOW_UNDECORATED); // Убираем title окна
    InitWindow(DefaultWindowWidth, DefaultWindowHeight, Global::WindowName);

    auto [supposedWidth, supposedHeight] = calculateFittableWindowSize(Global::VirtualWidth * 1.f / Global::VirtualHeight);

    SetWindowSize(supposedWidth, supposedHeight);
    setScaleForCurrentWindowSize(g);

    // По центру по X и Y осям окно располагаем
    auto [centeredX, centeredY] = getCenteredWindowCoordinates(supposedWidth, supposedHeight);
    SetWindowPosition(centeredX, centeredY);
    SetTargetFPS(144);
}