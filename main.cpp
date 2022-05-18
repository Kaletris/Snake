#include <iostream>
#include "Poisonous.h"
#include "Rotten.h"
#include "Table.h"
#include "Head.h"
#include "Body.h"
#include "Snake.h"
#ifdef _WIN32
#include "windows.h"
#else
#include <unistd.h>
#endif
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    Snake snake;
    Table table(3, 3);
    table.spawnSnake(&snake);
    table.drawTable();
    char a;
    std::cin >> a;
    snake.move();
    table.refreshTable();
    std::cin >> a;
    snake.move();
    table.refreshTable();
    std::cin >> a;
    snake.move();
    table.refreshTable();
    std::cin >> a;
    snake.move();
    table.refreshTable();
    std::cin >> a;

    return 0;
}