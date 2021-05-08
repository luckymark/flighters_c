//
// Created by luckymark on 2021/5/8.
//

#include "raylib.h"
#include "sky.h"

void draw_sky(Texture2D *sky) {
    DrawTexture(*sky, 0, 0, RAYWHITE);
}