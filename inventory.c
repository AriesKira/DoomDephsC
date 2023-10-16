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
    i->weapons[0].dmgMin = 1;
    i->weapons[0].dmgMax = 5;
    i->weapons[0].property = 1;
    i->weapons[0].actions = 2;
    i->weapons[1].name = "null";
    i->weapons[1].type = 0;
    i->weapons[1].dmgMax = 0;
    i->weapons[1].dmgMin = 0;
    i->weapons[1].actions = 0;
    i->weapons[1].property = 0;
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

FUNCTION EmptyUtility

returns 1 if it is an empty utility space, 0 if not
*/

int emptyUtility(int utility) {
    if(utility == 0) {
        return 1;
    }
    return 0;
}

/*

FUNCTION GenerateRandomArmor

*/

// Arme en bois : 35
// Arme en fer : 25
// Arme en acier : 20
// Arme en diamant : 15
// Arme en cheveux de Sananes : 10
// Arme magiQUE

void generateRandomArmor(armor* a) {
    int armorRarityRand = rand() % 100 + 1;
    int armorRarity = 0;
    if (armorRarityRand <= 40) {
        armorRarity = 1;
    }else if (armorRarityRand <= 70 && armorRarityRand > 40) {
        armorRarity = 2;
    }else if (armorRarityRand <= 90 && armorRarityRand > 70) {
        armorRarity = 3;
    }else if (armorRarityRand <= 97 && armorRarityRand > 90) {
        armorRarity = 4;
    }else {
        armorRarity = 5;
    }

    switch (armorRarity) {
        case 1 :
            a->name = "Armure de cuir";
            a->def = rand() % 10 + 1;
            a->inventorySpace = 2;
            break;
        case 2 :
            a->name = "Armure de fer";
            a->def = rand() % 26 + 10;
            a->inventorySpace = 3;
            break;
        case 3 :
            a->name = "Armure d'acier";
            a->def = rand() % 16 + 35;
            a->inventorySpace = rand() % 4 + 2;
            break;
        case 4 :
            a->name = "Armure de diamant";
            a->def = rand() % 31 + 50;
            a->inventorySpace = rand() % 5 + 2;
            break;
        case 5 :
            a->name = "Armure de mithril";
            a->def = rand() % 101 + 100;
            a->inventorySpace = rand() % 6 + 2;
            break;
    }
    
}

/*

FUNCTION GenerateRandomWeapon

*/

void GenerateRandomWeapon(weapon* w) {
    int propertyRand = rand() % 100 + 1;
    int weaponType = rand() % 2 + 1;
    int weaponRarityRand = rand() % 100 + 1;
    int weaponRarity = 0;
    int property = 0;

    if (propertyRand <= 70) {
        property = 1;
    }else {
        property = 2;
    }

    if (weaponRarityRand <= 40) {
        weaponRarity = 1;
    }else if (weaponRarityRand <= 70 && weaponRarityRand > 40) {
        weaponRarity = 2;
    }else if (weaponRarityRand <= 90 && weaponRarityRand > 70) {
        weaponRarity = 3;
    }else if (weaponRarityRand <= 97 && weaponRarityRand > 90) {
        weaponRarity = 4;
    }else {
        weaponRarity = 5;
    }
    if (property == 1) {
        switch (weaponRarity) {
            case 1:
                if (weaponType == 1) {
                    w->name = "Epée en bois";
                }else {
                    w->name = "Arc en bois";
                }
                w->type = weaponType;
                w->dmgMin = 1;
                w->dmgMax = (rand() % 10 )+ 1;
                w->property = property;
                w->actions = 2;
                break;
            case 2:
                if (weaponType == 1) {
                    w->name = "Epée en fer";
                }else {
                    w->name = "Arc en fer";
                }
                w->type = weaponType;
                w->dmgMin = (rand() % 6 )+ 5; // min 5
                w->dmgMax = (rand() %  11 )+ 10;//max 20
                w->property = property;
                w->actions = (rand() % 3 )+ 2; //max 4 min 2
                break;
            case 3:
                if (weaponType == 1) {
                    w->name = "Epée en acier";
                }else {
                    w->name = "Arc en acier";
                }
                w->type = weaponType;
                w->dmgMin = (rand() % 11 )+ 10; // min 10
                w->dmgMax = (rand() % 16 )+ 20; // max 35
                w->property = property;
                w->actions =( rand() % 5 )+ 2; //max 6 min 2
                break;
            case 4:
                if (weaponType == 1) {
                    w->name = "Epée en diamant";
                }else {
                    w->name = "Arc en diamant";
                }
                w->type = weaponType;
                w->dmgMin = (rand() % 19 )+ 17; // min 17
                w->dmgMax = (rand() % 16 )+ 35; // max 50
                w->property = property;
                w->actions = (rand() % 5 )+ 4;                
                break;
            case 5:
                if (weaponType == 1) {
                    w->name = "Epée du roi Jonathan";
                }else {
                    w->name = "Arc du roi Jonathan";
                }
                w->type = weaponType;
                w->dmgMin = (rand() % 25 + 1)+ 50;
                w->dmgMax = (rand() % 150 + 1)+ 85;
                w->property = property;
                w->actions = (rand() % 15 )+ 9;
                break;
        }
    }else {
        switch (weaponRarity) {
            case 1:
                if (weaponType == 1) {
                    w->name = "Epée en herbe";
                }else {
                    w->name = "Arc en herbe";
                }
                w->type = weaponType;
                w->dmgMin = 5; // min 5
                w->dmgMax = (rand() % 11 )+ 5; // max 15
                w->property = property;
                w->actions = rand() % 2 + 2; //max 3 min 2
                break;
            case 2:
                if (weaponType == 1) {
                    w->name = "Epée de feu"; 
                }else {
                    w->name = "Arc de feu";
                }
                w->type = weaponType;
                w->dmgMin = (rand() % 11 )+ 10; // min 10
                w->dmgMax = (rand() %  15 )+ 11;//max 25
                w->property = property;
                w->actions = (rand() % 3 )+ 2; //max 4 min 2
                break;
            case 3:
                if (weaponType == 1) {
                    w->name = "Epée de glace";
                }else {
                    w->name = "Arc de glace";
                }
                w->type = weaponType;
                w->dmgMin = (rand() % 9 )+ 17; // min 25
                w->dmgMax = (rand() % 16 )+ 25; // max 40
                w->property = property;
                w->actions =( rand() % 5 )+ 2; //max 6 min 2
                break;
            case 4:
                if (weaponType == 1) {
                    w->name = "Epée de foudre";
                }else {
                    w->name = "Arc de foudre";
                }
                w->type = weaponType;
                w->dmgMin = (rand() % 16)+ 40; // min 40
                w->dmgMax = (rand() % 21 )+ 55; // max 75
                w->property = property;
                w->actions = (rand() % 5 )+ 4;                
                break;
            case 5:
                if (weaponType == 1) {
                    w->name = "Epée en cheveux du dieu Sananes";
                }else {
                    w->name = "Arc en cheveux du dieu Sananes";
                }
                w->type = weaponType;
                w->dmgMin = (rand() % 26)+ 80;
                w->dmgMax = (rand() % 151)+ 106;
                w->property = property;
                w->actions = (rand() % 15 )+ 9;
                break;
        }
    }

}





/*

FUNCTION generateRandomLoot

*/
void generateRandomLoot(inventory* i) {
    //generate random loot type; 1 = armor, 2 = weapon, 3 = bag, 4 = utility
    int type = rand() % 4 + 1;

    switch (type) {
        case 1 :
            armor a;
            generateRandomArmor(&a);
            i->armors[0] = a;
            break;
        case 2 :
            weapon w;
            generateRandomWeapon(&w);
            i->weapons[0] = w;
            break;
        case 3 :
            bag b;
            generateRandomBag(&b);
            i->bags[0] = b;
            break;
        case 4 :
            int utility = rand() % 6 + 1;
            if (utility != 6) {
                i->utilities[utility]++;
            }else {
                i->utilities[utility] += rand() % 100 + 1;
            }
            break;
    }

}
