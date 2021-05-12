#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

#define HERO_X 0
#define HERO_y 99

#define HERO_WIDTH 102
#define HERO_HEIGHT 126

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "flighters");

    Texture2D texture = LoadTexture("resources/image/shoot.png");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Rectangle clip = {HERO_X, HERO_y, HERO_WIDTH, HERO_HEIGHT};
        Vector2 position = {(SCREEN_WIDTH - HERO_WIDTH) / 2, SCREEN_HEIGHT - HERO_HEIGHT};
        DrawTextureRec(texture, clip, position, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}