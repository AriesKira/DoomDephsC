#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

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
    i->bags[0].utilitySpace = 2;
    i->utilities = malloc(sizeof(int)* 7);
    for (int j = 0; j < 7; j++) {
        if (j == 0 || j == 3) {
            i->utilities[j] = 1;
        }else if(j == 6) {
            i->utilities[j] = 50;
        }else {
            i->utilities[j] = 0;
        }
        printf("%d - %d\n",j,i->utilities[j]);
    }
    /*utilities array slots : 0 = small hp potion, 1 = medium hp potion, 2 = high hp potion, 3 = small mp potion, 4 = medium mp potion, 5 = high mp potion,
    6 = gold ; gold is uncapped, potions are capped at bag[0]->utilitySpace ; player starts with 50 gold and 1 low hp potion and mp potion;
    player can carry multiple equipement items but equip only one; player can carry armor[0]->inventorySpace equipement items in his bag; it starts at
    2, but can be upgraded with bags;

    if equipement item name is null then it's an empty inventory space where he can store the item type he found in the dungeon;
    */
}

/*

FUNCTION EmptyEquipementSpace

returns 1 if it is an empty equipement space, 0 if not
*/

int emptyEquipementSpace(char *name) {
    if(strcmp(name,"null") == 0) {
        return 1;
    }
    return 0;
}

/*

FUNCTION EmptyUtilitySpace

returns 1 if it is an empty utility space, 0 if not
*/

int emptyUtilitySpace(int utility) {
    if(utility == 0) {
        return 1;
    }
    return 0;
}