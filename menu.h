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
    easyMode,
    normalMode,
    hardMode,
    easyList,
    normalList,
    hardList
} Menu;

enum Difficulty {
    easy,
    normal,
    hard
};

class Koordinate{
    int x;
    int y;
public:
    Koordinate(int x = 0, int y = 0) : x(x), y(y){};
    Koordinate(const Koordinate& koordinate) : x(koordinate.x), y(koordinate.y){};
    ~Koordinate(){};

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
/*
bool operator==(const Koordinate& a, const Koordinate& b){
    return a.getX() == b.getX() && a.getY() == b.getY();

}*/

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

Menu menu_navigation();

#endif //MAIN_CPP_MENU_H
