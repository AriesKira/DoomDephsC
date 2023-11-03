#ifndef INVENTORY_H
#define INVENTORY_H

#define IS_MAGIC j->inventory->weapons[i].property
#define MONSTER_INVENTORY_ARMOR m->inventory->armors[0].name
#define MONSTER_INVENTORY_ARMOR_DEF m->inventory->armors[0].def
#define MONSTER_INVENTORY_ARMOR_INVENTORY_SPACE m->inventory->armors[0].inventorySpace

#define MONSTER_INVENTORY_WEAPON m->inventory->weapons[0].name
#define MONSTER_INVENTORY_WEAPON_DMG_MIN m->inventory->weapons[0].dmgMin
#define MONSTER_INVENTORY_WEAPON_DMG_MAX m->inventory->weapons[0].dmgMax
#define MONSTER_INVENTORY_WEAPON_PROPERTY m->inventory->weapons[0].property
#define MONSTER_INVENTORY_WEAPON_ACTIONS m->inventory->weapons[0].actions

#define MONSTER_INVENTORY_BAG m->inventory->bags[0].name
#define MONSTER_INVENTORY_BAG_UTILITY_SPACE m->inventory->bags[0].utilitySpace
#define MONSTER_INVENTORY_OWNED_UTILITY m->inventory->utilities[i]

#define SMALL_HP_POTION_INDEX 0
#define MEDIUM_HP_POTION_INDEX 1
#define BIG_HP_POTION_INDEX 2
#define SMALL_MANA_POTION_INDEX 3
#define MEDIUM_MANA_POTION_INDEX 4
#define BIG_MANA_POTION_INDEX 5
#define GOLD_INDEX 6
#define UTILITIES_ARRAY_SIZE 7

#define PLAYER_INVENTORY_SPACE j->inventory->armors[0].inventorySpace
#define UTILITIES_CAPACITY j->inventory->bags[0].utilitySpace
#define PLAYER_UTILITY_OWNED j->inventory->utilities[i]
#define PLAYER_GOLD j->inventory->utilities[GOLD_INDEX]

#define PLAYER_MANA j->mana
#define PLAYER_MAX_MANA j->manaMax
#define PLAYER_SPELLBOOK_SIZE j->spellbookSize
#define PLAYER_SPELLBOOK j->spellBook

#define PLAYER_HP j->vie
#define PLAYER_MAX_HP j->vieMax


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
int hasSpace(joueur* j, int category);
int getRewardCategory(monstre* m);
int getAvailableInventorySpace(joueur* j, int x);
int getUtilityIndex(monstre* m);
void printItemsFromCategory(joueur* j, int category);
inventory saveCurrentInventory(joueur* j);
void reallocInventorySpace(joueur* j, int x);
void printLostItems(joueur * j, int newSize);
int replaceItem(joueur* j, monstre* m, int category, int index);
void lootMonster(joueur* j, monstre* m);
int magicItems(joueur* j);
int getSpellDamages(joueur *j);
int getSpellNameFromWeapon(char* weaponName);
char * getSpellName(joueur* j);
void reallocSpells(joueur* j,int nbOfSpells);
void getSpells(joueur* j);
int hasMana(joueur* j);
#endif