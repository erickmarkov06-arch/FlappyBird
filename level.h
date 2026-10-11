#pragma once
#include "pipe.h"

const int NUMBER_OF_PIPES = 6;
const int DISTANCE_BETWEEN_PIPES = 150;
class Level{
    private:
        Pipe pipes[NUMBER_OF_PIPES];
        int distance [NUMBER_OF_PIPES - 1];
        int score = 0;
    public:
        Level();
        void draw();
        void move(double distance);
        void update(double speed);
        bool checkCollision(double birdX, double birdY, int birdSize);
        void reset();
};