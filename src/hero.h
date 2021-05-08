//
// Created by luckymark on 2021/4/27.
//

#ifndef FLIGHTERS_ECS_HERO_H
#define FLIGHTERS_ECS_HERO_H

#define HERO_WIDTH 102
#define HERO_HEIGHT 126

#define HERO_X 0
#define HERO_Y 99

typedef struct {
    Texture2D *texture;
    Rectangle clip;
    Vector2 position;
    Color color;
} Hero;

Hero *create_hero(const int screen_width, const int screen_height, Texture2D *texture);

void draw_hero(Hero *);

#endif //FLIGHTERS_ECS_HERO_H
