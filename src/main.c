#include "raylib.h"
#include "hero.h"
#include "sky.h"

Texture2D texture;
Texture2D sky_texture;
const int screen_width = 480;
const int screen_height = 800;

int main() {
    InitWindow(screen_width, screen_height, "Flighters");
    InitAudioDevice();

    Music music = LoadMusicStream("resources/sound/game_music.ogg");
    PlayMusicStream(music);

    texture = LoadTexture("resources/image/shoot.png");
    sky_texture = LoadTexture("resources/image/background.png");

    Hero *hero = create_hero(screen_width, screen_height);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        UpdateMusicStream(music);

        draw_sky(&sky_texture);
        update_by_keypressed(screen_width, hero);
        update_by_tick(hero);

        draw_hero(hero);

        EndDrawing();
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

