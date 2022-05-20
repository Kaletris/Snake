#include "Fruit.h"
#include "Snake.h"
#include <iostream>
#include "Tile.h"

void Fruit::eatenBy(Snake* snake) {
    snake->changeLength(nutritionValue);
    tile->clear();
    delete this;
}

void Fruit::draw() const {
    econio_textcolor(color);
    std::cout << shape;
    econio_textcolor(COL_RESET);
}

void Fruit::changeLifeTime(int change) {
    Object::changeLifeTime(change);
    if (getLifeTime() < 0) {
        tile->clear();
        delete this;
    }
}

void Fruit::setTile(Tile *newTile) {
    tile = newTile;
}
