#ifndef MAP_H
#define MAP_H

typedef struct map {
    int ** map;
    int width;
    int height;
    int level;
}map;


#include "player.h"


void generateMap(int level,map * map,joueur * joueur);
int * getAlowedMoves(map map,joueur joueur);

#endif