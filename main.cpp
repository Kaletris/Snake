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
    int speed = 10;
    Snake snake(speed);
    Table table(10, 10);
    table.spawnSnake(&snake);
    table.drawTable();
/*
    std::thread([&]
                {
                    while(true)
                    {
                        // Wait ticks
                        std::this_thread::sleep_for(std::chrono::milliseconds (1000/speed*10));
                        // Call move
                        std::cout << "asd" <<std::endl;
                        //snake.head.move();
                    }
                });
*/
    int a;
    //std::cin >> a;
    snake.move();
    table.drawTable();
    std::cin >> a;
    snake.move();
    table.drawTable();
    std::cin >> a;

    return 0;
}
