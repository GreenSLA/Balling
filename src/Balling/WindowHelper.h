//
// Created by sroma on 23.05.2026.
//

#ifndef BALLING_WINDOWHELPER_H
#define BALLING_WINDOWHELPER_H
#include <utility>

struct Global;

// Возвращает координаты окна (X, Y), как если бы оно было отцентрировано относительно текущего монитора
inline std::pair<int, int> getCenteredWindowCoordinates(int windowWidth, int windowHeight);

// Получить ширину и высоту окна так, чтобы они влезали в экран текущего монитора с учетом разрешения
std::pair<int, int> calculateFittableWindowSize(float wantedVirtualWidthToVirtualHeightRatio = 16 / 9.f);

// Установить соотношение истинных пикселей окна к виртуальным
void setScaleForCurrentWindowSize(Global &global);

// Инициализация настроек окна и глобального объекта
void initialize(Global &g);

#endif //BALLING_WINDOWHELPER_H