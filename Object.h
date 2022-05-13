#ifndef SNAKE_OBJECT_H
#define SNAKE_OBJECT_H
class Snake;

class Object{
    int lifetime;
public:
    Object(int lifetime = 1) : lifetime(lifetime) {};
    Object(const Object& object) :lifetime(object.lifetime){};
    virtual ~Object(){};
    void changeLifetime(int lifetime = 0){lifetime = lifetime;};
    virtual void eatenBy(Snake snake) = 0;
    int getLifeTime() const{return lifetime;};
};
#endif //SNAKE_OBJECT_H