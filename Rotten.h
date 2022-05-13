#ifndef SNAKE_ROTTEN_H
#define SNAKE_ROTTEN_H

#include "Fruit.h"

class Snake;
class Rotten : public Fruit{
public:
    Rotten(int lifetime = 1, int nutritionValue = -1, colour color = white) : Fruit(lifetime, nutritionValue, color){};
    Rotten(const Rotten& rotten) : Fruit(rotten.getLifeTime(), rotten.getNutritionValue(), rotten.getColor()){};
    ~Rotten(){};

    void eatenBy(Snake snake);
};
#endif //SNAKE_ROTTEN_H
