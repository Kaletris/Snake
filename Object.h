#ifndef SNAKE_OBJECT_H
#define SNAKE_OBJECT_H
#include <iostream>

class Snake;

class Object{
    int lifetime;
public:
    Object(int lifetime = 1) : lifetime(lifetime) {};
    Object(const Object& object) :lifetime(object.lifetime){};
    virtual ~Object(){};
    virtual void changeLifeTime(int change = 0){ lifetime += change;};
    virtual void eatenBy(Snake* snake) = 0;
    virtual void draw() const = 0;
    int getLifeTime() const{return lifetime;};
};
#endif //SNAKE_OBJECT_H