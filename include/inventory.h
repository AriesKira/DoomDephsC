#ifndef INVENTORY_H
#define INVENTORY_H

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

void initInventory(inventory* i);
int emptyEquipementSpace(char *name);
int emptyUtility(int utility);

#endif