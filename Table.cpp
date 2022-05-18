#include "Table.h"
#include "econio.h"
#include <stdexcept>

Snake* Table::spawnSnake(Snake* snake) const {
    //tabla kozepere spawn
    int x, y;
    x = height / 2;
    y = width / 2;
    //ha nem ures kivetelt dob
    if(tiles[x][y]->getObject() != NULL){
        throw std::logic_error("Snake spawn tile wasn't empty!");
    }
    //leteszi a kigyo fejet
    tiles[x][y]->set(snake->head);
    snake->head->setTile(tiles[x][y]);
    return snake;
}

//A tabla osszes objektumanak az elettartamat 1-el csokkenti, ha eloregedett akkor megszunteti, ezek utan kirajzolja a tabla mezoit
void Table::refreshTable() {
    econio_clrscr();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            econio_gotoxy(i, j);
            if(tiles[i][j]->getObject() != NULL) {
                tiles[i][j]->getObject()->changeLifetime(-1);
            }
            tiles[i][j]->draw();
        }
    }
}

Tile *Table::adjacent(Direction dir, Tile *tile) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (tiles[i][j] == tile) {
                switch (dir) {
                    case north:
                        if (i <= 0) {
                            return tiles[height - 1][j];
                        } else {
                            return tiles[i - 1][j];
                        }
                    case south:
                        if (i >= height - 1) {
                            return tiles[0][j];
                        } else {
                            return tiles[i + 1][j];
                        }
                    case west:
                        if (i <= 0) {
                            return tiles[i][width - 1];
                        } else {
                            return tiles[i][j - 1];
                        }
                    case east:
                        if (i >= width - 1) {
                            return tiles[i][width - 1];
                        } else {
                            return tiles[i][j + 1];
                        }
                    default:
                        throw std::out_of_range("The supplied value for Direction is not a valid Direction");
                }
            }
        }
    }
    throw std::out_of_range("The tile is not found on the table");
}

void Table::drawTable() const {
    econio_clrscr();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            econio_gotoxy(i, j);
            /*
            if (tiles[i][j]->getObject() == NULL) {
                std::cout << ' ';
            } else {
                tiles[i][j]->getObject()->draw();
            }
             */
            tiles[i][j]->draw();
        }
    }
}

Table::~Table() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //tiles[i][j]->clear();
            delete tiles[i][j];
        }
        delete[] tiles[i];
    }
    delete[] tiles;
}

Tile* Table::spawnFruit(Fruit* fruit) {
    int i, j;
    do{
        i = rand() % height;
        j = rand() % width;
        if(tiles[i][j]->getObject() == NULL){
            tiles[i][j]->set(fruit);
            break;
        }
    } while (true);

    return tiles[i][j];
}
