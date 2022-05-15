#include "Table.h"
#include "econio.h"
#include <stdexcept>

Snake Table::spawnSnake(Snake snake) const {
    int x, y;
    x = height / 2;
    y = width / 2;
    tiles[x][y].set(&snake.head);
    snake.head.setTile(&tiles[x][y]);
    return snake;
}

void Table::drawTable() const {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            econio_gotoxy(i, j);
            tiles[j][i].draw();
        }
    }
}

Tile *Table::adjacent(Direction dir, Tile *tile) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (&tiles[i][j] == tile) {
                switch (dir) {
                    case north:
                        if (i <= 0) {
                            return &tiles[height - 1][j];
                        } else {
                            return &tiles[i - 1][j];
                        }
                    case south:
                        if (i >= height - 1) {
                            return &tiles[0][j];
                        } else {
                            return &tiles[i + 1][j];
                        }
                    case west:
                        if (i <= 0) {
                            return &tiles[i][width - 1];
                        } else {
                            return &tiles[i][j - 1];
                        }
                    case east:
                        if (i >= width - 1) {
                            return &tiles[i][width - 1];
                        } else {
                            return &tiles[i][j + 1];
                        }
                    default:
                        throw std::out_of_range("The supplied value for Direction is not a valid Direction");
                }
            }
        }
    }

    throw std::out_of_range("The tile is not found on the table");
}
