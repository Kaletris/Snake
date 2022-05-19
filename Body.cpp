#include "Body.h"
#include "Snake.h"
#include "Tile.h"
#include <iostream>
#include "econio.h"

void BodyPart::draw() const {
    econio_textcolor(COL_GREEN);
    if (full) {
        std::cout << 'S';
    } else {
        std::cout << 's';
    }
    econio_textcolor(COL_RESET);
}

void BodyPart::eatenBy(Snake* snake1) {
    snake1->kill();
}

void BodyPart::changeLifetime(int change) {
    Object::changeLifetime(change);
    if(getLifeTime()<0){
        removeBodyPart();
    }
}

BodyPart::~BodyPart() {}

void BodyPart::removeBodyPart() {
    if(snake == NULL) throw std::logic_error("Snake NULL");
    if(snake->body == NULL) throw std::logic_error("Body NULL");
    //ha a kigyonak 1 teste van igy torli
    if(this == snake->body->first){
        this->tile->clear();
        this->snake->body->first = NULL;
        delete this;

        return;
    }
    //ha a kigyonak tobb teste van igy torli
    BodyPart* afore;
    afore = snake->body->first;
    while (afore->next != this){
        afore = afore->next;
    }
    if(this->tile == NULL) throw std::logic_error("Body NULL");
    this->tile->clear();
    delete this;
    afore->next = NULL;
}

Body::~Body(){
    BodyPart* iter;
    while(first != NULL){
        iter = first;
        first = first->next;
        delete iter;
    }
}