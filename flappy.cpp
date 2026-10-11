#include <raylib.h>
#include "bird.h"
#include "pipe.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "level.h"
#include "game.h"


const int screenHight = 450;
const int screenWidth = 800;


int main()
{
    srand(time(NULL));
    InitWindow(screenWidth, screenHight, "FirstWindow");
    Game game;
    

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        game.update();
        game.draw();
        
    }

    CloseWindow();

    return 0;
}