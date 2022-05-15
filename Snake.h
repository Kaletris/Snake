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
    Body body;
    Snake(int speed = 10, int lifetime = 30, int length = 0, bool alive = true)
            : speed(speed), length(length), alive(alive), head(Head(this, lifetime)), body(Body()) {};
    Snake(const Snake& snake) : length(snake.length), speed(snake.speed), alive(snake.alive), head(snake.head){};
    ~Snake(){};

    void changeSpeed(int newSpeed){speed = newSpeed;};
    void changeLength(int newLength){length = newLength;};
    bool isAlive() const{return alive;};
    void kill();
    int getLength() const{
        return length;
    };
    int getSpeed() const{return speed;};
    void move();
};

#endif //SNAKE_SNAKE_H
