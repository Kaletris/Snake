#ifndef SNAKE_TABLE_H
#define SNAKE_TABLE_H

#include "Tile.h"
#include "Snake.h"
#include "Fruit.h"
#include "Enums.h"

class Table{
    int height;
    int width;
public:
    Tile*** tiles;
    Table(int height = 10, int width = 10)
        : height(height), width(width) {
        tiles = new Tile**[height];
        for (int i = 0; i < height; i++) {
            tiles[i] = new Tile*[width];

            for (int j = 0; j < width; j++) {
                tiles[i][j] = new Tile(this);
            }
        }
    };
    Table(const Table& table){};
    ~Table();

    int getHeight() const {return height;};
    int getWidth() const {return width;};

    void refreshTable();
    void drawTable() const;
    Tile* adjacent(Direction dir, Tile* tile) const;

    Snake* spawnSnake(Snake* snake = new Snake()) const;
    Tile * spawnFruit(Fruit* fruit = new Fruit());

};

#endif //SNAKE_TABLE_H
