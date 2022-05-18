#include "Head.h"
#include "Snake.h"
#include "Table.h"
#include <iostream>
#include "Tile.h"

void Head::draw() const {
    std::cout << 'H';
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
    if(!snake->isAlive()) throw "Kigyo meghalt";

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
        changeLifetime(20);
    }
}

void Head::changeLifetime(const int change) {
    Object::changeLifetime(change);
    if(this->getLifeTime() < 0){
        snake->kill();
    }
}
