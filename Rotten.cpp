#include "Fruit.h"
#include "Poisonous.h"
#include "Snake.h"
#include "Rotten.h"
#include "Body.h"


void Rotten::eatenBy(Snake *snake) {
    int change = getNutritionValue();
    snake->changeLength(change);
    if(snake->body != NULL){
        changeListLifeTime(snake->body->first, change);
    }

    delete this;
}

void Rotten::changeListLifeTime(BodyPart* bodyPart, int change, BodyPart* afore) {
    if(bodyPart->next != NULL){
        changeListLifeTime(bodyPart->next, change);
    }
    changeLifetime(change);
}
