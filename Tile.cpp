#include "Tile.h"
#include "iostream"
#include "Object.h"
#include "Table.h"

void Tile::draw() const {
    if(ob == NULL){
        std::cout << ' ';
        return;
    }
    ob->draw();
}

Tile* Tile::adjacent(Direction dir) {
    return table->adjacent(dir, this);
}

Object *Tile::getObject() const {
    return ob;
}
