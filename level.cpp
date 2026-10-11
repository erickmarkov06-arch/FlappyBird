#include "level.h"
#include "pipe.h"

Level::Level(){
    for(int i = 0; i < NUMBER_OF_PIPES - 1; i++){
        distance[i] =  DISTANCE_BETWEEN_PIPES;
    }
    pipes[0] = Pipe();
    for(int i = 1; i < NUMBER_OF_PIPES; i++){
        pipes[i] = Pipe(distance[i - 1] + PIPE_WIDTH + pipes[i - 1].getX());
    }
}
void Level::draw(){
    for(int i = 0; i < NUMBER_OF_PIPES; i ++){
        pipes[i].drawPipe();
    }
}
void Level::move(double distance){
    for(int i = 0; i < NUMBER_OF_PIPES; i++){
        pipes[i].movePipe(distance);
    }
}
void Level::update(double speed){
        move(speed);
        double highestX = pipes[0].getX();
        for(int i = 1; i < NUMBER_OF_PIPES ; i ++){
            if(pipes[i].getX() > highestX){
                highestX = pipes[i].getX();
            }
        }
        int newX = (highestX + DISTANCE_BETWEEN_PIPES + PIPE_WIDTH);
        for(int i = 0; i < NUMBER_OF_PIPES; i++){
            if(pipes[i].getX() + PIPE_WIDTH < 0){
                pipes[i].reset(newX);
            }
        }
        
}
bool Level::checkCollision(double birdX, double birdY, int birdSize){
    bool collision = false;
    for(int i = 0; i < NUMBER_OF_PIPES; i++){
        collision = pipes[i].hits(birdX, birdY, birdSize);
        if(collision == true){
            return true;
        }
    }
    return collision;
}
void Level::reset(){
    
}