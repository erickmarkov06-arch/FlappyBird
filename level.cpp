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
void Level::move(int distance){
    for(int i = 0; i < NUMBER_OF_PIPES; i++){
        pipes[i].movePipe(distance);
    }
}