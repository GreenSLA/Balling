//
// Created by sroma on 23.05.2026.
//

#ifndef BALLING_GLOBAL_H
#define BALLING_GLOBAL_H

struct Global {
    static constexpr auto WindowName = "Balling";
    static constexpr float VirtualWidth = 1600.0f;
    static constexpr float VirtualHeight = 800.0f;
    int WindowWidth = 0;
    int WindowHeight = 0;
    float Scale = 1.0f; // Отношение одного физического пикселя к виртуальному,
};

#endif //BALLING_GLOBAL_H