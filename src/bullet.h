//
// Created by luckymark on 2021/5/8.
//

#ifndef FLIGHTERS_C_BULLET_H
#define FLIGHTERS_C_BULLET_H

#include "raylib.h"
#include "hero.h"

typedef struct tag_bullet {
    Texture2D *texture;
    Rectangle clip;
    Vector2 position;
    Color color;
    int speed;
} Bullet;

typedef struct tag_hero Hero;

Bullet *create_bullet(Hero *hero);

void draw_bullet(Bullet *bullet);

#endif //FLIGHTERS_C_BULLET_H
