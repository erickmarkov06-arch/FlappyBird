#pragma once
#include "raylib.h"

const int BIRD_SIZE = 20;

class Bird{
    private:
        double x;
        double y;
        double velocity;
    public:
        Bird(double startX, double startY, double v);
        void jump();
        double getX();
        double getY();
        void setX(double newX);
        void setV(double newV);
        void setY(double newY);
        void move(double moveX, double moveY);
        void update(double gravity);
        void drawBird(bool sprites, Texture2D texture);
};