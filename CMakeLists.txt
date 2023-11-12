cmake_minimum_required(VERSION 3.26)
project(doomdephsC C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(doomdephsC
        include/fights.h
        include/inventory.h
        include/monster.h
        include/player.h
        include/userInterface.h
        include/save.h
        fights.c
        inventory.c
        main.c
        monster.c
        player.c
        userInterface.c
        save.c
        )
