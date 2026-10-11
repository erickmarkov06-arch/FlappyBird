#pragma once
#include "bird.h"
#include "level.h"

class Game
{
private:
    double speed;
    bool collision;
    int score;
    Bird bird;
    Level level;
    enum GAMESTATE
    {
        NOT_STARTED,
        PLAYING,
        GAME_OVER
    };
    GAMESTATE gamestate;
public:
    Game();
    void update();
    void draw();
};