#include "pipe.h"
#include <raylib.h>
#include <ctime>
#include <cstdlib>

Pipe::Pipe()
{
    randomGap();
    topHeightCalc();
    x = GetScreenWidth() - 50;
    passed = false;
}
Pipe::Pipe(int x)
{
    this->x = x;
    randomGap();
    topHeightCalc();
    passed = false;
}
void Pipe::randomGap()
{
    gap = rand() % (200 - 100 + 1) + 100;
}
int Pipe::getGap()
{
    return gap;
}
void Pipe::setGap(int newGap)
{
    gap = newGap;
}
void Pipe::drawPipe(bool useSprites, Texture2D pipeCapTexture, Texture2D pipeBodyTexture)
{
    if (!useSprites)
    {
        DrawRectangle(x, 0, PIPE_WIDTH, topHeight, BLUE);
        DrawRectangle(x, topHeight + gap, PIPE_WIDTH, GetScreenHeight() - (topHeight + gap), BLUE);
    }
    else
    {
        float capH = pipeCapTexture.height;   
        float bodyH = pipeBodyTexture.height; 
        float bottomY = topHeight + gap;      

        Rectangle bodySource; 
        bodySource.x = 0;
        bodySource.y = 0;
        bodySource.width = PIPE_WIDTH;
        bodySource.height = bodyH;

        Rectangle capSource; 
        capSource.x = 0;
        capSource.y = 0;
        capSource.width = PIPE_WIDTH;
        capSource.height = capH;

        Rectangle capFlipped = capSource; 
        capFlipped.height = -capH;

        Vector2 origin; 
        origin.x = 0;
        origin.y = 0;

        Rectangle dest; 
        dest.x = x;
        dest.width = PIPE_WIDTH;
        dest.y = 0;
        dest.height = topHeight - capH;
        DrawTexturePro(pipeBodyTexture, bodySource, dest, origin, 0, WHITE);
        dest.y = topHeight - capH;
        dest.height = capH;
        DrawTexturePro(pipeCapTexture, capSource, dest, origin, 0, WHITE);
        dest.y = bottomY;
        dest.height = capH;
        DrawTexturePro(pipeCapTexture, capFlipped, dest, origin, 0, WHITE);
        dest.y = bottomY + capH;
        dest.height = GetScreenHeight() - (bottomY + capH);
        DrawTexturePro(pipeBodyTexture, bodySource, dest, origin, 0, WHITE);
    }
}
void Pipe::topHeightCalc()
{
    topHeight = rand() % (((GetScreenHeight() - 100) - gap) + 1) + 50;
}
void Pipe::movePipe(double distance)
{
    x = x - distance;
}
void Pipe::reset(int newX)
{
    randomGap();
    topHeightCalc();
    passed = false;
    x = newX;
}
double Pipe::getX()
{
    return x;
}
bool Pipe::hits(double birdX, double birdY, int birdSize)
{

    if ((birdX + birdSize > getX() && birdX < (getX() + PIPE_WIDTH)) &&
        (birdY < topHeight || birdY + birdSize > topHeight + gap))
    {
        return true;
    }

    return false;
}
bool Pipe::isPassed()
{
    return passed;
}
void Pipe::markPassed()
{
    passed = true;
}
