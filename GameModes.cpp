#include "GameModes.h"
#include "Snake.h"
#include "Table.h"
#include "Poisonous.h"
#include "Rotten.h"
#include "Fame.h"

void handleGameInputs(Snake& snake, Table& table, bool makeFruits = false){
    int input;
    Direction dir;
    while (snake.isAlive() && input != EOF && input != KEY_ESCAPE) {
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
        if(makeFruits){
            int tmp = rand() % 4;
            if(tmp == 0){
                table.spawnFruit();
            }
        }
    }
}



void startFixGame() {
    Snake snake;
    Table table(6, 6);
    table.spawnSnake(&snake);
    snake.move();
    Fruit *greenApple = new Fruit('A', COL_LIGHTGREEN, 1, 20);
    Fruit *banana = new Fruit('B', COL_YELLOW, 2, 20);
    Poisonous *poisonousApple = new Poisonous('A', COL_RED, 1, 20);
    Rotten *rottenBanana = new Rotten(20, -3, 'B', COL_BROWN);
    table.tiles[1][1]->set(poisonousApple);
    table.tiles[0][2]->set(greenApple);
    table.tiles[5][3]->set(banana);
    table.tiles[4][4]->set(rottenBanana);
    table.refreshTable();
    handleGameInputs(snake, table);
}

void startNormalGame() {
    Snake snake;
    Table table(6, 6);
    table.spawnSnake(&snake);
    snake.move();
    for (int i = 0; i < 3; ++i) {
        table.spawnFruit();
    }
    table.refreshTable();
    handleGameInputs(snake, table, true);
    fame_save_menu_navigation(snake.getLength());
}
