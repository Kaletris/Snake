#include <iostream>
#include "Poisonous.h"
#include "Rotten.h"
#include "Table.h"
#include "Head.h"
#include "Body.h"
#include "Snake.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    Snake snake(1);
    Table table(10, 10);
    table.drawTable();
    table.spawnSnake(snake);
    table.drawTable();


    return 0;
}
