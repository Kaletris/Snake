#ifndef SNAKE_TILE_H
#define SNAKE_TILE_H

#include <cstddef>
class Object;

class Tile{
    Object* has;
public:
    Tile(Object* has = NULL) : has(has){};
    Tile(const Tile& tile) : has(tile.has){};
    ~Tile(){};

    void draw() const;
    void set(Object* object);
    Object* getObject() const;
};

#endif //SNAKE_TILE_H
