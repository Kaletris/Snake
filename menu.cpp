#include "menu.h"
#include "iostream"
#include "econio.h"

void wtite_navigation() {
    std::cout << "You can navigate with the arrow or \"wasd\" keys!" << std::endl;
    std::cout << "Press Enter/Right Arrow/'d' to continue with the selected stuff!" << std::endl;
    std::cout << "Press the Esc/Left Arrow/'a' button to escape! " << std::endl;
}

void write_main_menu() {
    econio_clrscr();
    std::cout << "Main menu" << std::endl;
    std::cout << "[ ] New Game" << std::endl;
    std::cout << "[ ] Hall of Fame" << std::endl;
    std::cout << std::endl;
    wtite_navigation();
}
/*
Menu menu_navigation() {
    Koordinate kursor(3,1);
    write_main_menu();
    int input = KEY_DELETE;
    while (input != KEY_ESCAPE || input != KEY_ENTER){
        input = econio_getch();
        switch (input) {
            case KEY_UP:
            case 'w':
                if(kursor.getX() == 1 || kursor.getX() == 2){
                    std::cout << ' ';
                    kursor.move(1,1);
                    std::cout << 'X';
                } else {
                    std::cout << ' ';
                    kursor.move(2,1);
                    std::cout << 'X';
                }
                break;
            case KEY_DOWN:
            case 's':
                if(kursor.getX() == 1 || kursor.getX() == 2){
                    std::cout << ' ';
                    kursor.move(2,1);
                    std::cout << 'X';
                } else {
                    std::cout << ' ';
                    kursor.move(1,1);
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
}*/