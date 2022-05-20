#include <iostream>
#include <fstream>
#include "Fame.h"
#include "econio.h"
#include "menu.h"

void write_fame_save_menu(int score) {
    econio_clrscr();
    std::cout << "Congratulations, your score is: " << score << ", do you want to save it?" << std::endl;
    std::cout << "[ ] Yes please!" << std::endl;
    std::cout << "[ ] No thanks!" << std::endl;
    std::cout << std::endl;
    wtite_navigation();
}

struct Lista{
    int score;
    Lista* next;
    Lista(int score): score(score), next(NULL){};
};

void writeList(){

}

void saveScore(int score){
    std::ifstream is("ranglista.txt");
    if(!is.is_open()){
        std::ofstream os("ranglista.txt");
        os << score;
    } else {
        std::string line;
        Lista* lista = NULL;
        while(std::getline(is, line)){
            if(lista == NULL){
                lista = new Lista(std::stoi(line));
            } else {
                Lista* iter = lista;
                while (iter->next != NULL){
                    iter = iter->next;
                }
                iter->next = new Lista(std::stoi(line));
            }
        }
        is.close();
        std::ofstream os("ranglista.txt");
        Lista* iter2 = lista;
        bool wroteScore = false;
        while (iter2 != NULL){
            if(iter2->score > score || wroteScore){
                os << iter2->score << std::endl;
                iter2 = iter2->next;
            } else {
                os << score << std::endl;
                wroteScore = true;
            }
        }
        if(!wroteScore){
            os << score << std::endl;
        }
        os.close();
        iter2 = lista;
        while (iter2 != NULL){
            Lista* next = iter2->next;
            delete iter2;
            iter2 = next;
        }
    }
}

void fame_save_menu_navigation(int score) {
    Coordinate cursor(3, 1);
    write_fame_save_menu(score);
    int input = KEY_UNKNOWNKEY;
    while (input != KEY_ESCAPE && (input != KEY_ENTER || cursor.getX() == 3)) {
        input = econio_getch();
        switch (input) {
            case KEY_UP:
            case 'w':
                if (cursor.getX() == 1 || cursor.getX() == 2) {
                    cursor.move(2,1);
                    std::cout << ' ';
                    cursor.move(1, 1);
                    std::cout << 'X';
                } else {
                    std::cout << ' ';
                    cursor.move(2, 1);
                    std::cout << 'X';
                }
                break;
            case KEY_DOWN:
            case 's':
                if (cursor.getX() == 1 || cursor.getX() == 2) {
                    cursor.move(1,1);
                    std::cout << ' ';
                    cursor.move(2, 1);
                    std::cout << 'X';
                } else {
                    std::cout << ' ';
                    cursor.move(1, 1);
                    std::cout << 'X';
                }
                break;
            case KEY_RIGHT:
            case 'd':
                input = KEY_ENTER;
                break;
            case KEY_LEFT:
            case 'a':
                input = KEY_ESCAPE;
                break;
            default:
                break;
        }
    }
    if (input == KEY_ESCAPE) {
        return;
    }
    switch (cursor.getX()) {
        case 1:
            saveScore(score);
            break;
        case 2:
            return;
        default:
            throw std::logic_error("Unexpected cursor position!");
    }
}