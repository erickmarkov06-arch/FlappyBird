#pragma once

const int PIPE_WIDTH = 50;

class Pipe{
    private:
        int gap;
        int topHeight;
        int x;
    public:
        Pipe();
        void randomGap();
        int getGap();
        void setGap(int newGap);
        void drawPipe();
        void topHeightCalc();
        void movePipe();
        
};