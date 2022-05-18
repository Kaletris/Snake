#include "Snake.h"


void Snake::kill() {
    alive = false;
}

void Snake::move() {
    head->move();
}

void Snake::changeLength(int change) {
    length += change;
    /*
     * //Amennyiben a kigyo osszes testresze tovabb el, nemcsak az ujonnan letrejottek
    if(length < 0) kill();
    if(body.first == NULL) return;
    BodyPart* iter = body.first;
    while (iter != NULL){
        iter->changeLifetime(change);
        iter = iter->next;
    }
     */
}
