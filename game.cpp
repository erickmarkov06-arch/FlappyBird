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
    
    
}
void Game::update()
{
    if (gamestate == NOT_STARTED)
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            gamestate = PLAYING;
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
        DrawText("PRESS SPACE TO START", 100, 200, 50, BLACK);
    }
    if (gamestate == PLAYING)
    {
        ClearBackground(RAYWHITE);
        DrawRectangle(bird.getX(), bird.getY(), BIRD_SIZE, BIRD_SIZE, GREEN);
        level.draw();
        DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);
    }
    if (gamestate == GAME_OVER)
    {
        ClearBackground(RAYWHITE);
        level.draw();
        DrawRectangle(bird.getX(), bird.getY(), BIRD_SIZE, BIRD_SIZE, GREEN);
        DrawText(TextFormat("GAME OVER!\n\nYOUR SCORE: %d \n\n\n\nR TO RESET", score), 200, 50, 50, BLACK);
    }
    EndDrawing();
}
