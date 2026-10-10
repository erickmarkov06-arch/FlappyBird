#pragma once

const int PIPE_WIDTH = 50;

class Pipe{
    private:
        int gap;
        int topHeight;
        int x;
    public:
        Pipe();
        Pipe(int x);
        void randomGap();
        int getGap();
        void setGap(int newGap);
        void drawPipe();
        void topHeightCalc();
        void movePipe(int distance);
        void reset();
        void update();
        int getX();
        
};