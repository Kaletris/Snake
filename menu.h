#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <cstdlib>
#include "econio.h"

typedef enum Menu {
    mainMenu,
    escMenu,
    gameSetMenu,
    fameMenu,
    exitMenu,
    fixMode,
    normalMode
} Menu;

class Coordinate{
    int x;
    int y;
public:
    Coordinate(int x = 0, int y = 0) : x(x), y(y){};
    Coordinate(const Coordinate& koordinate) : x(koordinate.x), y(koordinate.y){};
    ~Coordinate(){};

    int getX() const{return x;};
    int getY() const{return y;};
    void setX(const int newX = 0){x = newX;};
    void setY(const int newY = 0){y = newY;};
    void set(const int newX = 0, const int newY = 0){x = newX; y = newY;};
    void move(int newX, int newY){
        x = newX;
        y = newY;
        econio_gotoxy(x, y);
    };
};

void write_navigation();

void write_main_menu();
Menu main_menu_navigation();

void write_esc_menu();
Menu esc_menu_navigation();

void write_game_set_menu();
Menu game_set_menu_navigation();



#endif //MAIN_CPP_MENU_H
