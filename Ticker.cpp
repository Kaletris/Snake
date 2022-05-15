#include "Ticker.h"
#include <chrono>
#include <thread>
#include "Snake.h"


void Ticker::tick() {
    std::this_thread::sleep_for(std::chrono::milliseconds(ticks));

}
