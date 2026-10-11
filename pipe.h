#pragma once
#include "raylib.h"

const int PIPE_WIDTH = 50;

class Pipe{
    private:
        int gap;
        int topHeight;
        bool passed;
        double x;
    public:
        Pipe();
        Pipe(int x);
        void randomGap();
        int getGap();
        void setGap(int newGap);
        void drawPipe(bool useSprites, Texture2D pipeCapTexture, Texture2D pipeBodyTexture);
        void topHeightCalc();
        void movePipe(double distance);
        void reset(int newX);
        double getX();
        bool hits(double birdX, double birdY, int birdSize);
        bool isPassed();
        void markPassed();
};