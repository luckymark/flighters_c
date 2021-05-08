#include "raylib.h"
#include "hero.h"
#include "sky.h"


int main() {
    const int screen_width = 480;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "Flighters");
    InitAudioDevice();

    Music music = LoadMusicStream("resources/sound/game_music.ogg");
    PlayMusicStream(music);

    Texture2D texture = LoadTexture("resources/image/shoot.png");
    Texture2D sky = LoadTexture("resources/image/background.png");

    Hero *hero = create_hero(screen_width, screen_height, &texture);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        UpdateMusicStream(music);

        update_by_keypressed(screen_width, hero);

        draw_sky(&sky);
        draw_hero(hero);

        EndDrawing();
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

