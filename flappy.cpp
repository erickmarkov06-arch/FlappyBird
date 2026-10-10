#include <raylib.h>
#include "bird.h"
#include "pipe.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

const double gravity = 0.5;

int main()
{
    srand(time(NULL));
    const int screenHight = 450;
    const int screenWidth = 800;
    InitWindow(screenWidth, screenHight, "FirstWindow");
    Bird bird = Bird(200, 200, 0);
    Pipe pipe = Pipe();

    int gap = pipe.getGap();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_SPACE))
        {
            bird.jump();
        }
        // bird.move(0, 2);
        bird.update(gravity);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        pipe.drawPipe();
        pipe.movePipe();

        DrawText(TextFormat("Gap : %d", gap), 200, 200, 20, BLUE);
        DrawRectangle(bird.getX(), bird.getY(), BIRD_SIZE, BIRD_SIZE, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}