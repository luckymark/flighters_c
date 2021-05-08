//
// Created by luckymark on 2021/4/27.
//

#include "sky.h"
#include <stdlib.h>
#include "raylib.h"
#include "hero.h"


Hero *create_hero(const int screen_width, const int screen_height, Texture2D *texture) {
    Hero *hero = (Hero *) malloc(sizeof(Hero));

    hero->texture = texture;
    hero->clip = (Rectangle) {HERO_X, HERO_Y, HERO_WIDTH, HERO_HEIGHT};

    hero->position = (Vector2) {(screen_width - HERO_WIDTH) / 2, screen_height - HERO_HEIGHT};
    hero->color = RED;

    return hero;
}

void draw_hero(Hero *hero) {
    DrawTextureRec(*hero->texture, hero->clip, hero->position, hero->color);
}

void update_by_keypressed(const int screen_width, Hero *hero) {
    if (IsKeyDown(KEY_RIGHT) && hero->position.x < screen_width - HERO_WIDTH) {
        hero->position.x += HERO_SPEED;
    }
    if (IsKeyDown(KEY_LEFT) && hero->position.x > 0) {
        hero->position.x -= HERO_SPEED;
    }
}