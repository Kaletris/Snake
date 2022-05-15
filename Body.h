#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H
#include <cstddef>

#include "Object.h"

class Snake;

class BodyPart : public Object{
    BodyPart* next;
public:
    BodyPart( int lifetime = 1, BodyPart* p = NULL) : Object(lifetime), next(p) {};
    BodyPart(const BodyPart& bodyPart) : Object(bodyPart.getLifeTime()), next(bodyPart.next){};
    ~BodyPart(){};

    BodyPart* getNext() const;

    void eatenBy(Snake *snake);
    void draw() const;
};

class Body{
    class BodyPart;
    BodyPart* first;
    BodyPart* current;
public:
    Body(){};
    Body(const Body& body);
    ~Body(){};
    void move();
    void eatenBy(Snake snake);
    BodyPart* getFirst() const;
};

#endif //SNAKE_BODY_H
