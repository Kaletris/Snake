#include "Table.h"
#include "econio.h"
#include "Rotten.h"
#include "Poisonous.h"
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
                tiles[i][j]->getObject()->changeLifeTime(-1);
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
                        if (j <= 0) {
                            return tiles[i][width - 1];
                        } else {
                            return tiles[i][j - 1];
                        }
                    case east:
                        if (j >= width - 1) {
                            return tiles[i][0];
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
            tiles[i][j]->draw();
        }
    }
}

Table::~Table() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            //tiles[i][j]->clear();
            if(tiles[i][j]->getObject() != NULL){
                tiles[i][j]->getObject()->changeLifeTime(-1000);
            }
            delete tiles[i][j];
        }
        delete[] tiles[i];
    }
    delete[] tiles;
}

Fruit* Table::makeFruit() {
    int sum = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(tiles[i][j]->getObject() == NULL){
                sum++;
            }
        }
    }
    if(sum / (double)(height * width) * 100 < 30){
        return new Fruit();
    }
    int tmp;
    tmp = rand() % 4;
    switch (tmp) {
        case 0:
        case 1:
            return new Fruit();
        case 2:
            return new Rotten();
        case 3:
            return new Poisonous();
        default:
            throw std::logic_error("Tried to make undefined Fruit");

    }

}

void Table::spawnFruit(Fruit* fruit) {

    if(fruit == NULL){
        fruit = makeFruit();

    }

    int sum = 0;
    Tile* freeTiles[height * width];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(tiles[i][j]->getObject() == NULL){
                freeTiles[sum++] = tiles[i][j];
            }
        }
    }
    if(sum <= 0){
        throw std::logic_error("Tried to spawn fruit, when there was no empty tile.");
    }
    int pos;
    pos = rand() % sum;
    freeTiles[pos]->set(fruit);
    fruit->setTile(freeTiles[pos]);
}


