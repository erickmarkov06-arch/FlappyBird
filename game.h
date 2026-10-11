#pragma once
#include "bird.h"
#include "level.h"
#include "raylib.h"

class Game
{
private:
    double speed;
    bool collision;
    int score;
    Bird bird;
    Level level;
    bool useSprites;
    enum GAMESTATE
    {
        NOT_STARTED,
        PLAYING,
        GAME_OVER
    };
    GAMESTATE gamestate;
    Texture2D birdTexture;
public:
    Game();
    void update();
    void draw();
    ~Game();
    
};