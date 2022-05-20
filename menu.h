#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <cstdlib>
#include "econio.h"

#define konnyuLista "dicsoseglistaKonnyu.txt"
#define kozepesLista "dicsoseglistaKozepes.txt"
#define nehezLista "dicsoseglistaNehez.txt"

typedef enum Menu {
    mainMenu,
    escMenu,
    gameSetMenu,
    fameMenu,
    exitMenu,
    fixMode,
    normalMode,
    fixList,
    normalList
} Menu;
/*
enum Difficulty {
    easy,
    normal,
    hard
};
*/
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

class Result{
    char* name;
    int points;
    Result* next;
public:
    Result(char* nev = (char*)"MyName", int points = 0, Result* next = NULL) : name(nev), points(points), next(next){};
    Result(const Result& result) : name(result.name), points(result.points), next(result.next){};
    ~Result(){};
};

void wtite_navigation();

void write_main_menu();
Menu main_menu_navigation();

void write_esc_menu();
Menu esc_menu_navigation();

void write_game_set_menu();
Menu game_set_menu_navigation();

void write_fame_menu();
Menu fame_menu_navigation();



#endif //MAIN_CPP_MENU_H
