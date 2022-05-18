#ifndef SNAKE_FRUIT_H
#define SNAKE_FRUIT_H

#include "Object.h"
#include "econio.h"

class Fruit : public Object {
    int nutritionValue;
    char shape;
    EconioColor color;
public:
    Fruit(int lifeTime = 20, int nutritionValue = 1, char shape = 'F', EconioColor color = COL_YELLOW)
        : Object(lifeTime), nutritionValue(nutritionValue), shape(shape), color(color){};
    Fruit(const Fruit& fruit): Object(fruit.getLifeTime()), nutritionValue(fruit.nutritionValue), shape(fruit.shape), color(fruit.color){};
    ~Fruit(){};

    virtual void eatenBy(Snake* snake);
    void draw() const;
    int getNutritionValue() const {return nutritionValue;};
    char getShape() const {return shape;};
    EconioColor getColor() const {return color;};
};

#endif //SNAKE_FRUIT_H
