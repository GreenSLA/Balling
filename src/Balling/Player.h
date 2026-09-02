#pragma once

#include <raylib.h>

//
// Created by sroma on 29.05.2026.
//

struct Player {
    Vector2 Position; // Позиция
    Vector2 Velocity = Vector2(0, 0); // Скорость

    Color FillColor; // Цвет
    Color OutlineColor = Color(255, 255, 255, 1); // Цвет обводки
    float OutlineThickness = 2.f; // ширина обводки

    static constexpr float Acceleration = 600.f; // на 600 пикселей в секунду увеличивается скорость (ускорение)
    static constexpr float MaxSpeed = 300.f; // Макс скорость пикселей в секунду
    static constexpr float Friction = 8.f; // Коэффициент затухания

    explicit Player(
        Vector2 playerPosition = Vector2(0, 0),
        Color fillColor = Color(
            GetRandomValue(0, 255),
            GetRandomValue(0, 255),
            GetRandomValue(0, 255),
            1)) : Position(playerPosition),
                     FillColor(fillColor)
    {
    }
};