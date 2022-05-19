#include "Fruit.h"
#include "Poisonous.h"
#include "Snake.h"

void Poisonous::eatenBy(Snake *snake) {
    snake->kill();
    delete this;
}
