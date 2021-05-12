//
// Created by luckymark on 2021/4/27.
//

#ifndef FLIGHTERS_ECS_HERO_H
#define FLIGHTERS_ECS_HERO_H

#include "raylib.h"
#include "bullet.h"

#define HERO_WIDTH 102
#define HERO_HEIGHT 126

#define HERO_X 0
#define HERO_Y 99

#define HERO_SPEED 2.0f

#define MAX_HERO_BULLETS 1000

typedef struct tag_hero {
    Texture2D *texture;
    Rectangle clip;
    Vector2 position;
    Color color;
    struct tag_bullet *bullets[MAX_HERO_BULLETS];
} Hero;

Hero *create_hero(const int screen_width, const int screen_height);

void update_by_keypressed(const int screen_width, Hero *hero);

void draw_hero(Hero *hero);

void update_by_tick(Hero *hero);

#endif //FLIGHTERS_ECS_HERO_H
