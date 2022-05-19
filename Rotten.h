#ifndef SNAKE_ROTTEN_H
#define SNAKE_ROTTEN_H

#include "Fruit.h"

class Snake;
class BodyPart;
class Rotten : public Fruit{
    void changeListLifeTime(BodyPart* bodyPart, int change, BodyPart* afore = NULL);
public:
    Rotten(int lifetime = 10, int nutritionValue = -1, char shape = 'R', EconioColor color = COL_BROWN)
    : Fruit(shape, color, nutritionValue, lifetime) {};
    Rotten(const Rotten& rotten) : Fruit(rotten.getShape(), rotten.getColor(), rotten.getNutritionValue(), rotten.getLifeTime()) {};
    ~Rotten(){};

    void eatenBy(Snake* snake);
};
#endif //SNAKE_ROTTEN_H
