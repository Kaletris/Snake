#include "Fruit.h"
#include "Snake.h"
#include <iostream>

void Fruit::eatenBy(Snake* snake) {
    snake->changeLength(nutritionValue);
    delete this;
}

void Fruit::draw() const {
    econio_textcolor(color);
    std::cout << shape;
    econio_textcolor(COL_RESET);
}
