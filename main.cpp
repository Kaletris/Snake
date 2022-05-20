#include <iostream>
#include "Poisonous.h"
#include "Rotten.h"
#include "Table.h"
#include "Head.h"
#include "Body.h"
#include "Snake.h"
#include "Enums.h"
#include "menu.h"
#include "GameModes.h"

#ifdef _WIN32

#include "windows.h"

#else
#include <unistd.h>
#endif

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    econio_rawmode();
    srand(time(NULL));
    Menu menu = mainMenu;
    while (menu != exitMenu) {
        switch (menu) {
            case mainMenu:
                menu = main_menu_navigation();
                break;
            case escMenu:
                menu = esc_menu_navigation();
                break;
            case gameSetMenu:
                menu = game_set_menu_navigation();
                break;
            case fameMenu:
                menu = fame_menu_navigation();
                break;
            case fixMode:
                startFixGame();
                menu = mainMenu;
                break;
            case normalMode:
                startNormalGame();
                menu = main_menu_navigation();
                break;
            default:
                throw std::logic_error("Undefined menu!");
        }
    }

    return 0;
}