#include "Fruit.h"
#include "Poisonous.h"
#include "Snake.h"
#include "Rotten.h"


void Rotten::eatenBy(Snake *snake) {
    snake->changeLength(getNutritionValue());
}
