#include "Snake.h"


void Snake::kill() {
    alive = false;
}

void Snake::move() {
    head->move();
}

void Snake::changeLength(int change) {
    length += change;
    if(length < 0){
        kill();
    }
}
