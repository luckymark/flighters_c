#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

#define HERO_X 0
#define HERO_y 99

#define HERO_WIDTH 102
#define HERO_HEIGHT 126

#define HERO_SPEED 0.5f

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "flighters");

    InitAudioDevice();

    Music music = LoadMusicStream("resources/sound/game_music.ogg");
    PlayMusicStream(music);

    Texture2D texture = LoadTexture("resources/image/shoot.png");
    float hero_x = (SCREEN_WIDTH - HERO_WIDTH) / 2;
    float hero_y = SCREEN_HEIGHT - HERO_HEIGHT;

    while (!WindowShouldClose()) {
        BeginDrawing();

        UpdateMusicStream(music);

        if (IsKeyDown(KEY_RIGHT)) hero_x += HERO_SPEED;
        if (IsKeyDown(KEY_LEFT)) hero_x -= HERO_SPEED;

        ClearBackground(RAYWHITE);

        Rectangle clip = {HERO_X, HERO_y, HERO_WIDTH, HERO_HEIGHT};

        Vector2 position = {hero_x, hero_y};
        DrawTextureRec(texture, clip, position, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}