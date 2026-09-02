#pragma once

//
// Created by sroma on 23.05.2026.
//


struct Global {
    static constexpr auto WindowName = "Balling";
    static constexpr float VirtualWidth = 1600.0f;
    static constexpr float VirtualHeight = 800.0f;
    static constexpr float CenterX = VirtualWidth / 2.0f;
    static constexpr float CenterY = VirtualHeight / 2.0f;
    int WindowWidth = 0;
    int WindowHeight = 0;
    float Scale = 1.0f; // Отношение одного физического пикселя к виртуальному,
};