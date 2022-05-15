#include "Head.h"
#include "Snake.h"
#include "Table.h"
#include <iostream>
#include "Tile.h"

void Head::draw() const {
    std::cout << 'H';
}

void Head::eatenBy(Snake* snake) {
    snake->kill();
}

void Head::move() {
    tryEat(tile->adjacent(dir)->getObject());
}

void Head::tryEat(Object *object) {
    object->eatenBy(snake);
}
