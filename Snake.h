#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "Head.h"
#include "Body.h"

class Snake{
    int length;
    int speed;
    bool alive;
public:
    Head head;
    Body* body;
    Snake(int speed = 1, int length = 1, bool alive = true, int starve = 30)
            :  speed(speed), length(length), alive(alive), head(Head(starve)), body(NULL){};
    Snake(const Snake& snake) : length(snake.length), speed(snake.speed), alive(snake.alive), head(snake.head){};
    ~Snake(){};
    void changeSpeed(int speed){speed = speed;};
    void changeLength(int length){length = length;};
    bool isAlive() const{return alive;};
    void kill();
    int getLength() const{return length;};
    int getSpeed() const{return speed;};
};

#endif //SNAKE_SNAKE_H
