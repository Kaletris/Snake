#include <iostream>
#include "Poisonous.h"
#include "Rotten.h"
#include "Table.h"
#include "Head.h"
#include "Body.h"
#include "Snake.h"
#include "Enums.h"
#include "menu.h"
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
    /*
    Menu menu = mainMenu;
    Koordinate kursor;
    switch (menu) {
        case escMenu:

    }
*/
    Snake snake;
    Table table(6, 6);
    table.spawnSnake(&snake);
    Fruit* greenApple = new Fruit('A', COL_LIGHTGREEN, 1, 20);
    Fruit* banana = new Fruit('B', COL_YELLOW, 2, 20);
    Poisonous* poisonousApple= new Poisonous('A', COL_RED, 1, 20);
    Rotten* rottenBanana = new Rotten(20, -3, 'B', COL_BROWN);
    table.tiles[1][1]->set(poisonousApple);
    table.tiles[0][2]->set(greenApple);
    table.tiles[5][3]->set(banana);
    table.tiles[4][4]->set(rottenBanana);
     /*
    snake.move();
    for (int i = 0; i < 3; ++i) {
        table.spawnFruit();
    }*/
    table.refreshTable();
    int input;
    Direction dir;
    while (snake.isAlive() && input != EOF && input != KEY_ESCAPE){
        input = econio_getch();
        switch (input) {
            case KEY_UP:
            case 'w':
                dir = north;
                snake.head->changeDirection(dir);
                snake.move();
                econio_clrscr();
                table.refreshTable();
                break;
            case KEY_LEFT:
            case 'a':
                dir = west;
                snake.head->changeDirection(dir);
                snake.move();
                econio_clrscr();
                table.refreshTable();
                break;
            case KEY_DOWN:
            case 's':
                dir = south;
                snake.head->changeDirection(dir);
                snake.move();
                econio_clrscr();
                table.refreshTable();
                break;
            case KEY_RIGHT:
            case 'd':
                dir = east;
                snake.head->changeDirection(dir);
                snake.move();
                econio_clrscr();
                table.refreshTable();
                break;
            default:
                break;
        }
    }
    /*
//    char a;
//    std::cin >> a;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    for(int i = 0; i < 10; ++i){
        table.spawnFruit();
    }
//    std::cin >> a;
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(west);

//    std::cin >> a;
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(east);
//    std::cin >> a;
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(west);
//    std::cin >> a;
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(east);
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(west);
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(north);
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(east);
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(east);
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.head->changeDirection(west);
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    snake.move();
    table.refreshTable();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
*/

    return 0;
}