#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <cstdlib>
#include "econio.h"

#define konnyuLista "dicsoseglistaKonnyu.txt"
#define kozepesLista "dicsoseglistaKozepes.txt"
#define nehezLista "dicsoseglistaNehez.txt"

typedef enum Menu {
    fomenu,
    kilepomenu,
    jatekvalasztomenu,
    ranglistamenu,
    kilepes,
    konnyuJatek,
    kozepesJatek,
    nehezJatek,
    konnyuRanglista,
    kozepesRanglista,
    nehezRanglista
} Menu;

enum Nehezseg {
    konnyu,
    kozepes,
    nehez
};

class Koordinata{
    int x;
    int y;
public:
    Koordinata(int x = 0, int y = 0) : x(x), y(y){};
    Koordinata(const Koordinata& koordinata) : x(koordinata.x), y(koordinata.y){};
    ~Koordinata(){};

    int getX() const{return x;};
    int getY() const{return y;};
    void setX(const int newX = 0){x = newX;};
    void setY(const int newY = 0){y = newY;};
    void move(int newX, int newY){x = newX; y = newY;};
};

bool operator==(const Koordinata& a, const Koordinata& b){
    return a.getX() == b.getX() && a.getY() == b.getY();

}

class Eredmeny{
    char* nev;
    int pontszam;
    Eredmeny* next;
public:
    Eredmeny(char* nev = (char*)"MyName", int pontszam = 0, Eredmeny* next = NULL) : nev(nev), pontszam(pontszam), next(next){};
    Eredmeny(const Eredmeny& eredmeny) : nev(eredmeny.nev), pontszam(eredmeny.pontszam), next(eredmeny.next){};
    ~Eredmeny(){};
};

/*
void menu_navigacio_kiiras();

Menu menu_fomenu_vezerles(Koordinata);

void menu_fomenu_kiiras();

Menu menu_kilepes_megerosites_vezerles(Koordinata);

void menu_kilepes_megerosites_kiiras();

Menu menu_uj_jatek_menu_vezerles(Koordinata);

void menu_uj_jatek_menu_kiiras();

Menu menu_ranglista_vezerles(Koordinata);

void menu_ranglista_kiiras();
*/
#endif //MAIN_CPP_MENU_H
