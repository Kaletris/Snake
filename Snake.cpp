#include "Snake.h"


void Snake::kill() {
    head.changeLifetime(-1);
}

void Snake::move() {
    head.move();
}
