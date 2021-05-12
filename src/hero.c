//
// Created by luckymark on 2021/4/27.
//

#include <stdlib.h>
#include "raylib.h"
#include "hero.h"
#include "bullet.h"
#include "global.h"


void fire(Hero *hero);

void insert(Bullet *bullets[], Bullet *bullet);

Hero *create_hero(const int screen_width, const int screen_height) {
    Hero *hero = (Hero *) malloc(sizeof(Hero));

    hero->texture = &texture;
    hero->clip = (Rectangle) {HERO_X, HERO_Y, HERO_WIDTH, HERO_HEIGHT};

    hero->position = (Vector2) {(screen_width - HERO_WIDTH) / 2, screen_height - HERO_HEIGHT};
    hero->color = RED;

    for (int i = 0; i < MAX_HERO_BULLETS; i++) {
        hero->bullets[i] = NULL;
    }

    return hero;
}

void draw_hero(Hero *hero) {
    DrawTextureRec(*hero->texture, hero->clip, hero->position, hero->color);
    for (int i = 0; i < MAX_HERO_BULLETS; i++) {
        if (hero->bullets[i]) {
            draw_bullet(hero->bullets[i]);
        }
    }
}

void update_by_keypressed(const int screen_width, Hero *hero) {
    if (IsKeyDown(KEY_RIGHT) && hero->position.x < screen_width - HERO_WIDTH) {
        hero->position.x += HERO_SPEED;
    }
    if (IsKeyDown(KEY_LEFT) && hero->position.x > 0) {
        hero->position.x -= HERO_SPEED;
    }

    if (IsKeyDown(KEY_SPACE)) {
        fire(hero);
    }
}

void fire(Hero *hero) {
    Bullet *bullet = create_bullet(hero);
    insert(hero->bullets, bullet);
}

void insert(Bullet *bullets[], Bullet *bullet) {
    for (int i = 0; i < MAX_HERO_BULLETS; i++) {
        if (!bullets[i]) {
            bullets[i] = bullet;
            return;
        }
    }
}

void update_by_tick(Hero *hero) {
    for (int i = 0; i < MAX_HERO_BULLETS; i++) {
        Bullet *pBullet = hero->bullets[i];
        if (pBullet) {
            pBullet->position.y -= pBullet->speed;
            if (pBullet->position.y < 0) {
                free(pBullet);
                hero->bullets[i] = NULL;
            }
        }
    }
}