#ifndef SNAKE_FRUIT_H
#define SNAKE_FRUIT_H

#include "Object.h"
#include "econio.h"

class Tile;

class Fruit : public Object {
    int nutritionValue;
    char shape;
    EconioColor color;
    Tile* tile;
public:
    Fruit(char shape = 'F', EconioColor color = COL_YELLOW, int nutritionValue = 1, int lifeTime = 10)
        : Object(lifeTime), nutritionValue(nutritionValue), shape(shape), color(color), tile(NULL){};
    Fruit(const Fruit& fruit): Object(fruit.getLifeTime()), nutritionValue(fruit.nutritionValue), shape(fruit.shape), color(fruit.color){};
    ~Fruit(){};

    void setTile(Tile* newTile);
    virtual void eatenBy(Snake* snake);
    void draw() const;
    void changeLifeTime(int change) override;
    int getNutritionValue() const {return nutritionValue;};
    char getShape() const {return shape;};
    EconioColor getColor() const {return color;};
    void wasEaten(){delete this;};
};

#endif //SNAKE_FRUIT_H
