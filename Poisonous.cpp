#include "Fruit.h"
#include "Poisonous.h"
#include "Snake.h"
#include "Tile.h"

void Poisonous::eatenBy(Snake *snake) {
    snake->kill();
    Fruit::eatenBy(snake);
}
