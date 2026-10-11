#pragma once

const int PIPE_WIDTH = 50;

class Pipe{
    private:
        int gap;
        int topHeight;
        double x;
    public:
        Pipe();
        Pipe(int x);
        void randomGap();
        int getGap();
        void setGap(int newGap);
        void drawPipe();
        void topHeightCalc();
        void movePipe(double distance);
        void reset(int newX);
        void update();
        double getX();
        bool hits(double birdX, double birdY, int birdSize);
};