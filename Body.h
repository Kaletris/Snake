#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H
#include <cstddef>
#include "Object.h"
#include "Enums.h"

class Snake;
class BodyPart;
class Tile;

class Body{
public:
    BodyPart* first;
    Body(BodyPart* first = NULL) : first(first){};
    Body(const Body& body) : first(body.first){};
    ~Body();

    void setFirst(BodyPart* newFirst){first = newFirst;};
};

class BodyPart : public Object{
    Snake* snake;
    Tile* tile;
    bool full;
public:
    BodyPart* next;
    BodyPart(Snake* snake, Tile* tile, int lifetime = 0, bool full = false, BodyPart* next = NULL) : Object(lifetime), snake(snake), tile(tile), full(full), next(next) {};
    BodyPart(const BodyPart& bodyPart) : Object(bodyPart.getLifeTime()), snake(bodyPart.snake), tile(bodyPart.tile), full(bodyPart.full), next(bodyPart.next){};
    ~BodyPart();

    void removeBodyPart();
    void changeLifetime(int change = 0);

    void eatenBy(Snake *snake);
    void draw() const;
};

#endif //SNAKE_BODY_H
