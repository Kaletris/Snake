#ifndef SNAKE_POISONOUS_H
#define SNAKE_POISONOUS_H

#include "Fruit.h"

class Poisonous : public Fruit{
public:
    Poisonous(int lifetime = 1, int nutritionValue = 1, colour color = white) : Fruit(lifetime, nutritionValue, color){};
    Poisonous(const Poisonous& poisonous) : Fruit(poisonous.getLifeTime(), poisonous.getNutritionValue(), poisonous.getColor()){};
    ~Poisonous(){};

    void eatenBy(Snake snake);
};

#endif //SNAKE_POISONOUS_H