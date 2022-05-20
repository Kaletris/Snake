#include "menu.h"
#include <iostream>
#include <fstream>

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

Menu main_menu_navigation() {
    Coordinate cursor(3, 1);
    write_main_menu();
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
        return escMenu;
    }
    switch (cursor.getX()) {
        case 1:
            return gameSetMenu;
        case 2:
            return fameMenu;
        default:
            throw std::logic_error("Unexpected cursor position!");
    }
}

void write_esc_menu() {
    econio_clrscr();
    std::cout << "Are you sure you want to leave?" << std::endl;
    std::cout << "[ ] Yes" << std::endl;
    std::cout << "[ ] No" << std::endl;
    std::cout << std::endl;
    wtite_navigation();
}

Menu esc_menu_navigation() {
    Coordinate cursor(3, 1);
    write_esc_menu();
    int input = KEY_UNKNOWNKEY;
    while (input != KEY_ENTER || cursor.getX() == 3) {
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
    switch (cursor.getX()) {
        case 1:
            return exitMenu;
        case 2:
            return mainMenu;
        default:
            throw std::logic_error("Unexpected cursor position!");
    }
}

void write_game_set_menu() {
    econio_clrscr();
    std::cout << "Please choose game Mode!" << std::endl;
    std::cout << "[ ] Fix Map Mode" << std::endl;
    std::cout << "[ ] Normal Mode" << std::endl;
    std::cout << std::endl;
    wtite_navigation();
}

Menu game_set_menu_navigation() {
    Coordinate cursor(3, 1);
    write_game_set_menu();
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
        return mainMenu;
    }
    switch (cursor.getX()) {
        case 1:
            return fixMode;
        case 2:
            return normalMode;
        default:
            throw std::logic_error("Unexpected cursor position!");
    }
}

void write_fame_menu() {
    econio_clrscr();
    std::cout << "Please choose Fame List!" << std::endl;
    std::cout << "[ ] Fix Fame List" << std::endl;
    std::cout << "[ ] Normal Fame List" << std::endl;
    std::cout << std::endl;
    wtite_navigation();
}

Menu fame_menu_navigation() {
    Coordinate cursor(3, 1);
    write_fame_menu();
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
        return mainMenu;
    }
    switch (cursor.getX()) {
        case 1:
            return fixList;
        case 2:
            return normalList;
        default:
            throw std::logic_error("Unexpected cursor position!");
    }
}

