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
    Tile* nextTile = tile->adjacent(dir);
    tryEat(nextTile->getObject());
    nextTile->clear();
    nextTile->set(this);
    Tile* previousTile = this->tile;
    this->tile = nextTile;
    previousTile->clear();
    auto length = snake->getLength();
    auto first = snake->body.first;
    BodyPart* newBodyPart = new BodyPart(length, first);
    previousTile->set(newBodyPart);
}

void Head::tryEat(Object *object) {
    if(object != NULL){
        object->eatenBy(snake);
    }
}
