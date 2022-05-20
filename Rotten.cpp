#include "Fruit.h"
#include "Snake.h"
#include "Rotten.h"

void Rotten::eatenBy(Snake *snake) {
    int change = getNutritionValue();
    snake->changeLength(change);
    if(snake->body != NULL){
        changeListLifeTime(snake->body->first, change);
    }
    Fruit::eatenBy(snake);
}

void Rotten::changeListLifeTime(BodyPart* bodyPart, int change, BodyPart* afore) {
    if(bodyPart->next != NULL){
        changeListLifeTime(bodyPart->next, change);
    }
    bodyPart->changeLifeTime(change);
}
