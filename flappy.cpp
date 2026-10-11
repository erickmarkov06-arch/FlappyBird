#include <raylib.h>
#include "bird.h"
#include "pipe.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "level.h"

const double gravity = 0.5;
enum GAMESTATE
{
    NOT_STARTED,
    PLAYING,
    GAME_OVER
};

int main()
{
    srand(time(NULL));
    const int screenHight = 450;
    const int screenWidth = 800;
    InitWindow(screenWidth, screenHight, "FirstWindow");
    Bird bird = Bird(200, 200, 0);
    Level level = Level();
    double speed = 3;
    bool collison = false;
    GAMESTATE gamestate = NOT_STARTED;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (gamestate == NOT_STARTED)
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("PRESS SPACE TO START!", 75, 200, 50, BLUE);
            if (IsKeyPressed(KEY_SPACE))
            {
                gamestate = PLAYING;
            }
            EndDrawing();
        }
        if (gamestate == PLAYING)
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            speed = speed * 1.001;
            if (speed > 8.0)
            {
                speed = 8.0;
            }
            if (IsKeyPressed(KEY_SPACE))
            {
                bird.jump();
            }
            // bird.move(0, 2);
            collison = level.checkCollision(bird.getX(), bird.getY(), BIRD_SIZE);
            bird.update(gravity);
            level.draw();
            level.update(speed);

            DrawRectangle(bird.getX(), bird.getY(), BIRD_SIZE, BIRD_SIZE, GREEN);
            EndDrawing();

            if (collison || IsKeyPressed(KEY_R))
            {
                gamestate = GAME_OVER;
            }
        }
        if (gamestate == GAME_OVER)
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(bird.getX(), bird.getY(), BIRD_SIZE, BIRD_SIZE, GREEN);
            level.draw();
            DrawText("GAME OVER!\nR TO RESET", 225, 225, 40, BLACK);

            EndDrawing();
            if (IsKeyPressed(KEY_R))
            {
                bird = Bird(200, 200, 0);
                level = Level();
                speed = 3;
                collison = false;
                gamestate = NOT_STARTED;
            }
        }
    }

    CloseWindow();

    return 0;
}