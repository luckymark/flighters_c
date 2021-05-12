//
// Created by luckymark on 2021/5/9.
//

#include "bullet.h"
#include "global.h"
#include "hero.h"
#include "raylib.h"
#include <stdlib.h>


Bullet *create_bullet(Hero *hero) {
    Bullet *bullet = (Bullet *) malloc(sizeof(Bullet));

    bullet->texture = &texture;
    bullet->clip = (Rectangle) {1004, 987, 9, 21};

    bullet->position = (Vector2) {hero->position.x + HERO_WIDTH / 2, hero->position.y - 20};
    bullet->color = YELLOW;
    bullet->speed = 2;
    return bullet;
}

void draw_bullet(Bullet *bullet) {
    DrawTextureRec(*bullet->texture, bullet->clip, bullet->position, bullet->color);
}