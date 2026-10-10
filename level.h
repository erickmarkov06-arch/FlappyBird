#pragma once
#include "pipe.h"

const int NUMBER_OF_PIPES = 10000;
const int DISTANCE_BETWEEN_PIPES = 100;
class Level{
    private:
        Pipe pipes[NUMBER_OF_PIPES];
        int distance [NUMBER_OF_PIPES - 1];
    public:
        Level();
        void draw();
        void move(int distance);
};