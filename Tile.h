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
    Tile(Table* table = NULL) : ob(NULL), table(table){};
    Tile(const Tile& tile) : ob(tile.ob), table(tile.table){};
    ~Tile(){};

    void draw() const;
    void clear();
    void set(Object* object);
    Tile* adjacent(Direction dir);
    Object* getObject() const;
};

#endif //SNAKE_TILE_H
