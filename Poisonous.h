#ifndef SNAKE_POISONOUS_H
#define SNAKE_POISONOUS_H

#include "Fruit.h"

class Poisonous : public Fruit{
public:
    Poisonous(char shape = 'P', EconioColor color = COL_RED, int nutritionValue = 0, int lifetime = 10) : Fruit(shape,
                                                                                                                color,
                                                                                                                nutritionValue,
                                                                                                                lifetime) {};
    Poisonous(const Poisonous& poisonous) : Fruit(poisonous.getShape(), poisonous.getColor(),
                                                  poisonous.getNutritionValue(), poisonous.getLifeTime()) {};
    ~Poisonous(){};

    void eatenBy(Snake* snake);
};

#endif //SNAKE_POISONOUS_H