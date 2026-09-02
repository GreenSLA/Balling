#pragma once
#include "Player.h"

//
// Created by sroma on 29.05.2026.
//

Player createDefaultPlayerWithRandomColor(Vector2 position) {
    auto playerToCreate = Player();

    playerToCreate.Position = Vector2(position.x, position.y);
}