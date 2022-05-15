#ifndef SNAKE_HEAD_H
#define SNAKE_HEAD_H

#include <cstdlib>
#include "Object.h"
#include "Enums.h"

class Snake;
class Tile;

class Head : public Object{
    Direction dir;
    Tile* tile;
    Snake* snake;
public:
    Head(Snake* snake = NULL, int lifetime = 30, Direction dir = north) : Object(lifetime), dir(dir), tile(NULL), snake(snake){};
    Head(const Head& head) : Object(head.getLifeTime()), dir(head.dir), tile(head.tile), snake(head.snake){};
    ~Head(){};

    void changeDirection(const Direction newDir) { dir = newDir;};
    Direction getDirection() const {return dir;};
    void setTile(Tile* newTile){tile = newTile;};
    Tile* getTile() const {return tile;};

    void draw() const override;
    void move();
    void tryEat(Object* object);

    void eatenBy(Snake *snake);
};

#endif //SNAKE_HEAD_H
