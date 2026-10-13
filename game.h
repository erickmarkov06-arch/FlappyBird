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
    Texture2D backGroundTexture;
    Texture2D pipeBodyTexture;
    Texture2D pipeCapTexture;
    double backgroundX[2];
public:
    Game();
    void update();
    void draw();
    void drawBackGround();
    ~Game();
    
};