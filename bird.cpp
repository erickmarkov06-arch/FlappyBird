#include "bird.h"
#include <raylib.h>

Bird::Bird(double startX, double startY, double startV){
    x = startX;
    y = startY;
    velocity = startV;
}
void Bird::jump(){
    setV(-8);
}
double Bird::getX(){
    return x;
}
double Bird::getY(){
    return y;
}
void Bird::setX(double newX){
    x = newX;
}
void Bird::setY(double newY){
    y = newY;
}
void Bird::move(double moveX, double moveY){
    x += moveX;
    y += moveY;
}
void Bird::update(double gravity){
    velocity = velocity + gravity;
    y = velocity + y;
    if(y > GetScreenHeight() - BIRD_SIZE){
        y = GetScreenHeight()- BIRD_SIZE;
    }
    if(y <= 0){
        y = 0;
    }
}
void Bird::setV(double newV){
    velocity = newV;
}