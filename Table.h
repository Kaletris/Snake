#ifndef SNAKE_TABLE_H
#define SNAKE_TABLE_H

#include "Tile.h"
#include "Snake.h"
#include "Fruit.h"

class Table{
    int height;
    int width;
    Tile** tiles;
public:
    Table(int height = 10, int width = 10)
        : height(height), width(width){
        tiles[height][width];
    };
    Table(const Table& table){};
    ~Table(){};

    Snake spawnSnake(Snake snake);
    Fruit  spawnFruit();
    int getHeight() const;
    int getWidth() const;
};

#endif //SNAKE_TABLE_H
