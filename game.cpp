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
    backGroundTexture = LoadTexture("assets/background.png");
    pipeBodyTexture = LoadTexture("assets/pipe_body.png");
    pipeCapTexture = LoadTexture("assets/pipe_cap.png");


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
        drawBackGround();
        DrawText("PRESS SPACE TO START\nT TO TOGGLE SPRITES", 100, 200, 50, BLACK);
        if(useSprites == true){
            DrawText("SPRITES ON",100, 300, 50, BLACK );
        }else{
            DrawText("SPRITES OFF",100, 300, 50, BLACK );
        }
    }
    if (gamestate == PLAYING)
    {
        drawBackGround();
        level.draw(useSprites,  pipeCapTexture, pipeBodyTexture);
        bird.drawBird(useSprites, birdTexture);
        DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);
    }
    if (gamestate == GAME_OVER)
    {
        drawBackGround();
        level.draw(useSprites, pipeCapTexture, pipeBodyTexture);
        bird.drawBird(useSprites, birdTexture);
        DrawText(TextFormat("GAME OVER!\n\nYOUR SCORE: %d \n\n\n\nR TO RESET", score), 200, 50, 50, BLACK);
    }
    EndDrawing();
}
void Game::drawBackGround(){
    if(useSprites){
        DrawTexture(backGroundTexture, 0, 0, WHITE);
    }else{
        ClearBackground(RAYWHITE);
    }
}
Game::~Game() {UnloadTexture(birdTexture); UnloadTexture(backGroundTexture);UnloadTexture(pipeBodyTexture);UnloadTexture(pipeCapTexture);}
