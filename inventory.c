#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef struct armor {
    char* name;
    int def;
    int inventorySpace;
}armor;

typedef struct weapon {
    char* name;
    int type;
    int dmg;
    int actions;
}weapon;

typedef struct bag {
    char* name;
    int utilitySpace;
}bag;

typedef struct inventory {
    armor* armors;
    weapon* weapons;
    bag* bags;
    int* utilities;
}inventory;

/*

FUNCTION INIT INVENTORY

*/

void initInventory(inventory *i) {
    
    /*This function creates the players inventory when he starts the game (for the first time)*/
    i = malloc(sizeof(inventory));
    i->armors = malloc(sizeof(armor)*2);
    i->armors[0].name = "Armure de cuir";
    i->armors[0].def = 5;
    i->armors[0].inventorySpace = 2;
    i->armors[1].name = "null";
    i->armors[1].def = 0;
    i->armors[1].inventorySpace = 0;
    i->weapons = malloc(sizeof(weapon)* i->armors[0].inventorySpace);
    i->weapons[0].name = "Epée en bois";
    i->weapons[0].type = 1;
    i->weapons[0].dmg = 10;
    i->weapons[0].actions = 2;
    i->weapons[1].name = "null";
    i->weapons[1].type = 0;
    i->weapons[1].dmg = 0;
    i->weapons[1].actions = 0;
    i->bags = malloc(sizeof(bag)* i->armors[0].inventorySpace);
    i->bags[0].name = "Sac en laine";
    i->utilities = malloc(sizeof(int)* 7);
    for (int j = 0; j < 7; j++) {
        if (j == 0 || j == 2) {
            i->utilities[j] = 1;
        }else if(j == 6) {
            i->utilities[j] = 50;
        }else {
            i->utilities[j] = 0;
        }
    }
    /*utilities array slots : 0 = low hp potion, 1 = medium hp potion, 2 = high hp potion, 3 = low mp potion, 4 = medium mp potion, 5 = high mp potion,
    6 = gold ; gold is uncapped, potions are capped at bag[0].utilitySpace ; player starts with 50 gold and 1 low hp potion and mp potion
    */
}