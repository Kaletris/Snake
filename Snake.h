#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "Head.h"
#include "Body.h"

class Snake{
    int speed;
    int length;
    bool alive;
public:
    Head* head; //head nem lehet NULL
    Body* body; //body nem lehet NULL
    Snake(int speed = 10, int lifetime = 30, int length = 2, bool alive = true)
            : speed(speed), length(length), alive(alive), head(new Head(this, lifetime)), body(new Body()) {};
    Snake(const Snake& snake) : speed(snake.speed), length(snake.length), alive(snake.alive), head(snake.head){};
    ~Snake(){
        if(head != NULL){
            delete head;
        }
        if(body != NULL){
            delete body;
        }
    };

    void changeSpeed(int newSpeed){speed = newSpeed;};
    void changeLength(int change);
    bool isAlive() const{return alive;};
    void kill();
    int getLength() const{
        return length;
    };
    int getSpeed() const{return speed;};
    void move();
};

#endif //SNAKE_SNAKE_H
