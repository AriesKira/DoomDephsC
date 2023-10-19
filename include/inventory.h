#ifndef INVENTORY_H
#define INVENTORY_H

#define IS_MAGIC j->inventory->weapons[i].property

typedef struct armor {
    char* name;
    int def;
    int inventorySpace;
}armor;

typedef struct weapon {
    char* name;
    int dmgMin;
    int dmgMax;
    int property;
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

#include "player.h"
#include "monster.h"

void initPlayerInventory(inventory* i);
void initMonsterInventory(inventory* i);
int emptyEquipementSpace(char *name);
void generateRandomArmor(armor* a);
void generateRandomWeapon(weapon* w);
void generateRandomBag(bag* b);
void generateRandomLoot(inventory* i);
void lootMonster(joueur* j, monstre* m);

#endif