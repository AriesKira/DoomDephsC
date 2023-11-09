#include <stdlib.h>
#include <stdio.h>

#include "include/map.h"


/*

FUNCTION generateMap

*/

void generateMap(int level,map * map,joueur * j) {
    int MAP_WIDTH;
    int MAP_HEIGHT;

    switch (level) {
        case 0:
            /*
            
            MAP 1
            01234567890
           0#####B#####
           1#### M##S #
           2####      #
           3# M   #####
           4# #########
           5# #########
           6#  M     X#
           7###########

            # = 0 (wall) ; ' ' = 1 (path); X = 2(player); M = 3(monster); S = 4(shop); B = 5(boss)
            No boss for now
            */
            MAP_WIDTH = 11;
            MAP_HEIGHT = 8;

            map->map = malloc(sizeof(int*)*MAP_HEIGHT);
            for (int i = 0; i < MAP_HEIGHT; i++){
                map->map[i] = malloc(sizeof(int)*MAP_WIDTH);
            }
            
            for (int i = 0; i < MAP_HEIGHT; i++){
                for (int j = 0; j < MAP_WIDTH; j++){
                    map->map[i][j] = 0;
                }
            }

            map->map[0][5] = 5;
            map->map[1][5] = 3;
            map->map[1][4] = 1;
            map->map[1][8] = 4;
            map->map[2][4] = 1;
            map->map[2][5] = 1;
            map->map[2][6] = 1;
            map->map[2][7] = 1;
            map->map[2][8] = 1;
            map->map[2][9] = 1;
            map->map[3][1] = 1;
            map->map[3][2] = 3;
            map->map[3][3] = 1;
            map->map[3][4] = 1;
            map->map[3][5] = 1;
            map->map[4][1] = 1;
            map->map[5][1] = 1;
            map->map[6][1] = 1;
            map->map[6][2] = 1;
            map->map[6][3] = 3;
            map->map[6][4] = 1;
            map->map[6][5] = 1;
            map->map[6][6] = 1;
            map->map[6][7] = 1;
            map->map[6][8] = 1;
            map->map[6][9] = 2;
            j->posX = 9;
            j->posY = 6;
            break;
        
        case 1 :

            /*
            
            MAP 2

             012345678901234567890
            0
            1
            2
            3
            4
            5
            6
            7
            8
            9
            */
            break;

        case 2 :
            break;
        
        case 3 :
            break;
        
        case 4 :
            break;
        
    }

    map->height = MAP_HEIGHT;
    map->width = MAP_WIDTH;
    map->level = level +1 ;
    return map;
}