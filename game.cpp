#include "game.h"
#include "raylib.h"

const double GRAVITY = 0.5;

Game::Game() : bird(200, 200, 0)
{
    gamestate = NOT_STARTED;
    speed = 3;
    score = 0;
    collision = false;
    level = Level();
    useSprites = true;
    birdTexture = LoadTexture("assets/bird.png");


}
void Game::update()
{
    if (gamestate == NOT_STARTED)
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            gamestate = PLAYING;
        }
        if (IsKeyPressed(KEY_T)){
            useSprites = !useSprites;
        }
    }
    else if (gamestate == PLAYING)
    {
        if (speed * 1.001 > 8.0)
        {
            speed = 8.0;
        }
        else
        {
            speed = speed * 1.001;
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            bird.jump();
        }
        score = level.checkIfPassed(bird.getX());
        collision = level.checkCollision(bird.getX(), bird.getY(), BIRD_SIZE);
        bird.update(GRAVITY);
        level.update(speed);
        if (collision || IsKeyPressed(KEY_R))
        {
            gamestate = GAME_OVER;
        }
    }
    else if (gamestate == GAME_OVER)
    {
        if (IsKeyPressed(KEY_R))
        {
            bird = Bird(200, 200, 0);
            level = Level();
            speed = 3;
            score = 0;
            collision = false;
            gamestate = NOT_STARTED;
        }
    }
}
void Game::draw()
{
    BeginDrawing();
    if (gamestate == NOT_STARTED)
    {
        ClearBackground(RAYWHITE);
        DrawText("PRESS SPACE TO START\nT TO TOGGLE SPRITES", 100, 200, 50, BLACK);
        if(useSprites == true){
            DrawText("SPRITES ON",100, 300, 50, BLACK );
        }else{
            DrawText("SPRITES OFF",100, 300, 50, BLACK );
        }
    }
    if (gamestate == PLAYING)
    {
        ClearBackground(RAYWHITE);
        bird.drawBird(useSprites, birdTexture);
        level.draw();
        DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);
    }
    if (gamestate == GAME_OVER)
    {
        ClearBackground(RAYWHITE);
        level.draw();
        bird.drawBird(useSprites, birdTexture);
        DrawText(TextFormat("GAME OVER!\n\nYOUR SCORE: %d \n\n\n\nR TO RESET", score), 200, 50, 50, BLACK);
    }
    EndDrawing();
}
Game::~Game() {UnloadTexture(birdTexture); }
