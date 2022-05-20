#include "Head.h"
#include "Snake.h"
#include "Table.h"
#include <iostream>
#include "Tile.h"
#include "econio.h"

void Head::draw() const {
    econio_textcolor(COL_GREEN);
    std::cout << 'H';
    econio_textcolor(COL_RESET);
}

void Head::eatenBy(Snake* snake1) {
    snake1->kill();
}

void Head::move() {
    //megnezzuk a tile-t amire lepni akarunk
    Tile* nextTile = tile->adjacent(dir);

    //megprobaljuk megenni ami rajta van (ha ures akkor nem tortenik semmi)
    tryEat(nextTile->getObject());

    //Ha meghalt a kigyo lekezeljuk
    if(!snake->isAlive()){
        return;
//        throw std::logic_error("Kigyo meghalt");
    }

    if(nextTile->getObject() != NULL){
        nextTile->clear();
    }

    //megmondjuk a kovi tile-nak hogy rajta vagyunk hogy rajta vagyunk
    nextTile->set(this);

    //megjegyezzuk a tile-t amirol eljottunk
    Tile* previousTile = this->tile;

    //ralepunk a kovetkezo tile-ra
    this->tile = nextTile;

    //lelepunk az elozo tile-rol
    previousTile->clear();

    //letrehozunk egy bodypartot a snake hosszusagank elettartamaval (body nem NULL)
    auto* newBodyPart = new BodyPart(snake, previousTile, snake->getLength(), false, snake->body->first);
    //Body elejere rakjuk
    snake->body->setFirst(newBodyPart);

    //rarakjuk a tile-ra amirol elleptunk
    previousTile->set(newBodyPart);
}

void Head::tryEat(Object *object) {
    if(object != NULL){
        object->eatenBy(snake);
        changeLifeTime(20);
    }
}

void Head::changeLifeTime(const int change) {
    Object::changeLifeTime(change);
    if(this->getLifeTime() < 0){
        snake->kill();
    }
}

void Head::changeDirection(const Direction newDir)  {
    switch (newDir) {
        case north:
            if(dir != south){
                dir = newDir;
            }
            break;
        case west:
            if(dir != east){
                dir = newDir;
            }
            break;
        case south:
            if(dir != north){
                dir = newDir;
            }
            break;
        case east:
            if(dir != west){
                dir = newDir;
            }
            break;
        default:
            throw std::logic_error("Invalid direction");
    }
}
