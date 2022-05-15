#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H
#include <cstddef>
#include "Object.h"
#include "Enums.h"

class Snake;
class BodyPart;

class Body{
public:
    BodyPart* first;
    BodyPart* current;
    Body(BodyPart* first = NULL, BodyPart* current = NULL) : first(first), current(NULL){};
    Body(const Body& body) : first(body.first), current(body.current){};
    ~Body(){};
};

class BodyPart : public Object{
public:
    BodyPart* next;
    BodyPart( int lifetime = 1, BodyPart* next = NULL) : Object(lifetime), next(next) {};
    BodyPart(const BodyPart& bodyPart) : Object(bodyPart.getLifeTime()), next(bodyPart.next){};
    ~BodyPart(){};

    //BodyPart* getNext() const{return next;};

    void eatenBy(Snake *snake);
    void draw() const;
};

#endif //SNAKE_BODY_H
