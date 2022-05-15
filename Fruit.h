#ifndef SNAKE_FRUIT_H
#define SNAKE_FRUIT_H

#include "Object.h"
#include "econio.h"

enum colour {white, red, green};

class Fruit : public Object {
    int nutritionValue;
    colour color;
public:
    Fruit(int lifeTime = 1, int nutritionValue = 1, colour color = white) : Object(lifeTime), nutritionValue(nutritionValue), color(color){};
    Fruit(const Fruit& fruit): Object(fruit.getLifeTime()), nutritionValue(fruit.nutritionValue), color(fruit.color){};
    ~Fruit();

    virtual void eatenBy(Snake* snake);

    int getNutritionValue() const {return nutritionValue;};
    colour getColor() const {return color;};
};

#endif //SNAKE_FRUIT_H
