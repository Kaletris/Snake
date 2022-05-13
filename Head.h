#ifndef SNAKE_HEAD_H
#define SNAKE_HEAD_H

#include "Object.h"

class Snake;

enum direction {north, west, east, south};

class Head : public Object{
    direction dir;
public:
    Head(int lifetime = 30, direction dir = north) : Object(lifetime), dir(dir){};
    Head(const Head& head) : Object(head.getLifeTime()), dir(head.dir){};
    ~Head(){};
    void move();
    void tryEat(Object* object);
    void changeDirection(direction dir){dir = dir;};
    direction getDirection() const {return dir;};

    void eatenBy(Snake snake);
};

#endif //SNAKE_HEAD_H
