cmake_minimum_required(VERSION 3.20)
project(Snake)

set(CMAKE_CXX_STANDARD 11)

add_executable(Snake main.cpp Object.h Table.h Snake.h Head.h Body.h Tile.h Fruit.h Rotten.h Poisonous.h Table.cpp Head.cpp Body.cpp econio.h econio.cpp Tile.cpp Snake.cpp Enums.h Ticker.cpp Ticker.h gtest_lite.h memtrace.cpp memtrace.h Fruit.cpp Poisonous.cpp Rotten.cpp menu.cpp menu.h)

set( CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++" )

add_definitions(-DMEMTRACE)