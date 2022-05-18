#ifndef SNAKE_POISONOUS_H
#define SNAKE_POISONOUS_H

#include "Fruit.h"

class Poisonous : public Fruit{
public:
    Poisonous(int lifetime = 10, int nutritionValue = 0, char shape = 'P', EconioColor color = COL_RED) : Fruit(lifetime, nutritionValue, shape, color){};
    Poisonous(const Poisonous& poisonous) : Fruit(poisonous.getLifeTime(), poisonous.getNutritionValue(), poisonous.getShape(), poisonous.getColor()){};
    ~Poisonous(){};

    void eatenBy(Snake* snake);
};

#endif //SNAKE_POISONOUS_H