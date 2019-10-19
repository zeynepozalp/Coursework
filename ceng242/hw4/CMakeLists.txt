cmake_minimum_required(VERSION 3.14)
project(hw4)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(hw4
        Archer.cpp
        Archer.h
        Board.cpp
        Board.h
        Constants.h
        Coordinate.h
        Fighter.cpp
        Fighter.h
        Game.cpp
        Game.h
        InputParser.cpp
        InputParser.h
        Player.cpp
        Player.h
        Priest.cpp
        Priest.h
        Scout.cpp
        Scout.h
        Tank.cpp
        Tank.h
        testBoard.cpp
        testGame.cpp
        testPlayer.cpp)
