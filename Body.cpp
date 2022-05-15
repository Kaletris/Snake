#include "Body.h"
#include "Snake.h"
#include <iostream>

void BodyPart::draw() const {
    std::cout << 's';
}

void BodyPart::eatenBy(Snake *snake) {
    snake->kill();
}