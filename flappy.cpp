#include <raylib.h>
#include <ctime>
#include <cstdlib>
#include "game.h"

#ifdef PLATFORM_WEB
#include <emscripten/emscripten.h>
#endif

const int screenHight = 450;
const int screenWidth = 800;

// The web loop function can't take arguments, so it reaches the game through this pointer
Game *gamePtr = nullptr;

void frame()
{
    gamePtr->update();
    gamePtr->draw();
}

int main()
{
    srand(time(NULL));
    InitWindow(screenWidth, screenHight, "FirstWindow");
    Game game;
    gamePtr = &game;

    SetTargetFPS(60);

#ifdef PLATFORM_WEB
    // The browser calls frame() every frame (0 = use the browser's refresh rate)
    emscripten_set_main_loop(frame, 0, 1);
#else
    while (!WindowShouldClose())
    {
        frame();
    }
#endif

    CloseWindow();

    return 0;
}
