#include <raylib.h>
#include "bird.h"
#include "pipe.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "level.h"

const double gravity = 0.5;

int main()
{
    srand(time(NULL));
    const int screenHight = 450;
    const int screenWidth = 800;
    InitWindow(screenWidth, screenHight, "FirstWindow");
    Bird bird = Bird(200, 200, 0);
    Pipe pipe = Pipe();
    Level level = Level();
    double speed = 3;

    int gap = pipe.getGap();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        speed = speed * 1.001;
        if(speed > 8.0){
            speed = 8.0;
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            bird.jump();
        }
        // bird.move(0, 2);
        bird.update(gravity);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //pipe.update();
        level.update(speed);
        DrawRectangle(bird.getX(), bird.getY(), BIRD_SIZE, BIRD_SIZE, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}