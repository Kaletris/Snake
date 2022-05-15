#ifndef SNAKE_TILE_H
#define SNAKE_TILE_H

#include <cstddef>
#include "Enums.h"
class Table;

class Object;

class Tile{
    Object* ob;
    Table* table;
public:
    Tile(Table* table) : ob(NULL), table(table){};
    Tile(const Tile& tile) : ob(tile.ob){};
    ~Tile(){};

    void draw() const;
    void set(Object* object){ob = object;};
    Tile* adjacent(Direction dir);
    Object* getObject() const;
};

#endif //SNAKE_TILE_H
