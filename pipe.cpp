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
void Pipe::drawPipe()
{
    DrawRectangle(x, 0, PIPE_WIDTH, topHeight, BLUE);
    DrawRectangle(x, topHeight + gap, PIPE_WIDTH, GetScreenHeight() - (topHeight + gap), BLUE);
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
void Pipe::update()
{
    drawPipe();
    // movePipe();
}
double Pipe::getX()
{
    return x;
}
bool Pipe::hits(double birdX, double birdY, int birdSize)
{

    if ((birdX + birdSize > getX() && birdX < (getX() + PIPE_WIDTH)) &&
        (birdY < topHeight  || birdY + birdSize > topHeight + gap))
    {
        return true;
    }

    return false;
}
bool Pipe::isPassed(){
    return passed;
}
void Pipe::markPassed(){
    passed = true;
}
