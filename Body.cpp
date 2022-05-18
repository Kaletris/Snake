#include "Body.h"
#include "Snake.h"
#include "Tile.h"
#include <iostream>

void BodyPart::draw() const {
    if(full){
        std::cout << 's';
    }
    std::cout << 's';
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
    if(this == snake->body->first){
        this->tile->clear();
        this->snake->body->first = NULL;
        delete this;

        return;
    }
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