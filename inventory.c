#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "include/inventory.h"
#include "include/userInterface.h"

/*

FUNCTION INIT INVENTORY

*/

void initPlayerInventory(inventory *i) {
    
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
    i->weapons[0].dmgMin = 1;
    i->weapons[0].dmgMax = 5;
    i->weapons[0].property = 0;
    i->weapons[0].actions = 2;
    i->weapons[1].name = "null";
    i->weapons[1].dmgMax = 0;
    i->weapons[1].dmgMin = 0;
    i->weapons[1].actions = 0;
    i->weapons[1].property = 0;
    i->bags = malloc(sizeof(bag)* i->armors[0].inventorySpace);
    i->bags[0].name = "Sac en laine";
    i->bags[0].utilitySpace = 2;
    i->bags[1].name = "null";
    i->bags[1].utilitySpace = 0;
    i->utilities = malloc(sizeof(int)* 7);
    for (int j = 0; j < 7; j++) {
        if (j == 0 || j == 3) {
            i->utilities[j] = 2;
        }else if(j == 6) {
            i->utilities[j] = 50;
        }else {
            i->utilities[j] = 0;
        }
    }
    /*utilities array slots : 0 = small hp potion, 1 = medium hp potion, 2 = high hp potion, 3 = small mp potion, 4 = medium mp potion, 5 = high mp potion,
    6 = gold ; gold is uncapped, potions are capped at bag[0]->utilitySpace ; player starts with 50 gold and 1 low hp potion and mp potion;
    player can carry multiple equipement items but equip only one; player can carry armor[0]->inventorySpace equipement items in his bag; it starts at
    2, but can be upgraded with bags;

    if equipement item name is null then it's an empty inventory space where he can store the item type he found in the dungeon;
    */
}

void loadPlayerInventory(joueur *j, armor *armor, weapon *weapon, bag *bag, int *utility){
    j->inventory->armors = malloc(sizeof(armor)*armor[0].inventorySpace);
    j->inventory->weapons = malloc(sizeof(weapon)*armor[0].inventorySpace);
    j->inventory->bags = malloc(sizeof(bag)*armor[0].inventorySpace);
    for(int i = 0; i < armor[0].inventorySpace; i++){
        j->inventory->armors[i] = armor[i];
        j->inventory->weapons[i] = weapon[i];
        j->inventory->bags[i] = bag[i];
    }
    j->inventory->utilities = malloc(sizeof(int)* 7);
    for (int i = 0; i < 7; i++) {
        j->inventory->utilities[i] = utility[i];
    }
}

/*

FUNCTION initMonsterInventory

*/
void initMonsterInventory(inventory* i) {
    i->armors = malloc(sizeof(armor)*1);
    i->armors[0].name = "null";
    i->armors[0].def = 0;
    i->armors[0].inventorySpace = 1;
    i->weapons = malloc(sizeof(weapon)* i->armors[0].inventorySpace);
    i->weapons[0].name = "null";
    i->weapons[0].dmgMax = 10;
    i->weapons[0].dmgMin = 0;
    i->weapons[0].actions = 0;
    i->weapons[0].property = 0;
    i->bags = malloc(sizeof(bag)* i->armors[0].inventorySpace);
    i->bags[0].name = "null";
    i->bags[0].utilitySpace = 0;
    i->utilities = malloc(sizeof(int)* 7);
    for (int j = 0; j < 7; j++) {
        i->utilities[j] = 0;
    }
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

FUNCTION GenerateRandomArmor

*/


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
            a->name = "Armure du roi Jonathan";
            a->def = rand() % 101 + 100;
            a->inventorySpace = rand() % 6 + 2;
            break;
    }
    
}

/*

FUNCTION GenerateRandomWeapon

*/

void generateRandomWeapon(weapon* w) {
    int propertyRand = rand() % 100 + 1;
    int weaponRarityRand = rand() % 100 + 1;
    int weaponRarity = 0;
    int property = 0;

    if (propertyRand <= 70) {
        property = 0;
    }else {
        property = 1;
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
    if (property == 0) {
        switch (weaponRarity) {
            case 1:
                w->name = "Epée en bois";
                w->dmgMin = 1;
                w->dmgMax = (rand() % 10 )+ 1;
                w->property = property;
                w->actions = 2;
                break;
            case 2:
                w->name = "Epée en fer";
                w->dmgMin = (rand() % 6 )+ 5; // min 5
                w->dmgMax = (rand() %  11 )+ 10;//max 20
                w->property = property;
                w->actions = (rand() % 3 )+ 2; //max 4 min 2
                break;
            case 3:
                w->name = "Epée en acier";
                w->dmgMin = (rand() % 11 )+ 10; // min 10
                w->dmgMax = (rand() % 16 )+ 20; // max 35
                w->property = property;
                w->actions =( rand() % 5 )+ 2; //max 6 min 2
                break;
            case 4:
                w->name = "Epée en diamant";
                w->dmgMin = (rand() % 19 )+ 17; // min 17
                w->dmgMax = (rand() % 16 )+ 35; // max 50
                w->property = property;
                w->actions = (rand() % 5 )+ 4;                
                break;
            case 5:
                w->name = "Epée du roi Jonathan";
                w->dmgMin = (rand() % 25 + 1)+ 50;
                w->dmgMax = (rand() % 150 + 1)+ 85;
                w->property = property;
                w->actions = (rand() % 15 )+ 9;
                break;
        }
    }else {
        switch (weaponRarity) {
            case 1:
                w->name = "Epée en herbe";
                w->dmgMin = 5; // min 5
                w->dmgMax = (rand() % 11 )+ 5; // max 15
                w->property = property;
                w->actions = rand() % 2 + 2; //max 3 min 2
                break;
            case 2:
                w->name = "Epée de feu"; 
                w->dmgMin = (rand() % 11 )+ 10; // min 10
                w->dmgMax = (rand() %  15 )+ 11;//max 25
                w->property = property;
                w->actions = (rand() % 3 )+ 2; //max 4 min 2
                break;
            case 3:
                w->name = "Epée de glace";
                w->dmgMin = (rand() % 9 )+ 17; // min 17
                w->dmgMax = (rand() % 16 )+ 25; // max 40
                w->property = property;
                w->actions =( rand() % 5 )+ 2; //max 6 min 2
                break;
            case 4:
                w->name = "Epée de foudre";
                w->dmgMin = (rand() % 15)+ 26; // min 26
                w->dmgMax = (rand() % 21 )+ 55; // max 75
                w->property = property;
                w->actions = (rand() % 5 )+ 4;                
                break;
            case 5:
                w->name = "Epée en cheveux du dieu Sananes";
                w->dmgMin = (rand() % 26)+ 80;
                w->dmgMax = (rand() % 151)+ 106;
                w->property = property;
                w->actions = (rand() % 15 )+ 9;
                break;
        }
    }

}

/*

FUNCTION GenerateRandomBag

*/
void generateRandomBag(bag* bag) {
    int bagRarityRand = rand() % 100 + 1;
    int bagRarity = 0;
    if (bagRarityRand <= 40) {
        bagRarity = 1;
    }else if (bagRarityRand <= 70 && bagRarityRand > 40) {
        bagRarity = 2;
    }else if (bagRarityRand <= 90 && bagRarityRand > 70) {
        bagRarity = 3;
    }else if (bagRarityRand <= 97 && bagRarityRand > 90) {
        bagRarity = 4;
    }else {
        bagRarity = 5;
    }

    switch (bagRarity) {
        case 1 :
            bag->name = "Sac en laine";
            bag->utilitySpace = 2;
            break;
        case 2 :
            bag->name = "Sac en cuir";
            bag->utilitySpace = 5;
            break;
        case 3 :
            bag->name = "Sac en fer";
            bag->utilitySpace = 7;
            break;
        case 4 :
            bag->name = "Sac en diamant";
            bag->utilitySpace = 10;
            break;
        case 5 :
            bag->name = "Sac du dieu Sananes";
            bag->utilitySpace = 100;
            break;
    }
}



/*

FUNCTION generateRandomLoot

*/
void generateRandomLoot(inventory* i) {
    //generate random loot type; 1 = armor, 2 = weapon, 3 = bag, 4 = utility
    int type = rand() % 4 + 1;

    switch (type) {
        case 1 :{
            armor a;
            generateRandomArmor(&a);
            i->armors[0] = a;
            break;
        }
        case 2 :{
            weapon w;
            generateRandomWeapon(&w);
            i->weapons[0] = w;
            break;
        }
        case 3 :{
            bag b;
            generateRandomBag(&b);
            i->bags[0] = b;
            break;
        }
        case 4 :{
            int utility = rand() % 6 + 1;
            if (utility != 6) {
                i->utilities[utility]++;
            }else {
                i->utilities[utility] += rand() % 100 + 1;
            }
            break;
        }
    }

}

/*

FUNCTION hasSpace
checks if the player has space in his inventory for the reward

*/

int hasSpace(joueur* j, int category) {
    switch (category) {
        case 1:
            for (int i = 0; i < j->inventory->armors[0].inventorySpace; i++) {
                if (emptyEquipementSpace(j->inventory->armors[i].name)) {
                    return 1;
                }
            }
            break;
        case 2:
            for (int i = 0; i < j->inventory->armors[0].inventorySpace; i++) {
                if (emptyEquipementSpace(j->inventory->weapons[i].name)) {
                    return 1;
                }
            }
            break;
        case 3:
            for (int i = 0; i < j->inventory->armors[0].inventorySpace; i++) {
                if (emptyEquipementSpace(j->inventory->bags[i].name)) {
                    return 1;
                }
            }
            break;
        case 4:
            for (int i = 0; i < UTILITIES_ARRAY_SIZE - 1; i++) {
                if (j->inventory->utilities[i] < UTILITIES_CAPACITY) {
                    return 1;
                }
            }
            break;
        case 5: 
            return 1;
            break;
            
    }
    return 0;
}

/*

FUNCTION GET REWARD CATEGORY


*/

int getRewardCategory(monstre* m) {
    if (!emptyEquipementSpace(MONSTER_INVENTORY_ARMOR)) {
        return 1;
    }
    if (!emptyEquipementSpace(MONSTER_INVENTORY_WEAPON)) {
        return 2;
    }
    if (!emptyEquipementSpace(MONSTER_INVENTORY_BAG)) {
        return 3;
    }
    for (int i = 0; i < UTILITIES_ARRAY_SIZE - 1; i++) {
        if (m->inventory->utilities[i] > 0) {
            return 4;
        }
    }
    if (m->inventory->utilities[6] > 0) {
        return 5;
    }
    //should never happen
    return 0;
}

/*

FUNCTION getAvailableInventorySpace

*/

int getAvailableInventorySpace(joueur* j, int x) {
    switch (x) {
        case 1:
            for (int i = 0; i < PLAYER_INVENTORY_SPACE; i++) {
                if (emptyEquipementSpace(j->inventory->armors[i].name)) {
                    return i;
                }
            }
            break;
        case 2:
            for (int i = 0; i < PLAYER_INVENTORY_SPACE; i++) {
                if (emptyEquipementSpace(j->inventory->weapons[i].name)) {
                    return i;
                }
            }
            break;
        case 3:
            for (int i = 0; i < PLAYER_INVENTORY_SPACE; i++) {
                if (emptyEquipementSpace(j->inventory->bags[i].name)) {
                    return i;
                }
            }
            break;
    }
    //should never happen
    return 0;
} 


/*

FUNCTION getUtilityIndex

*/

int getUtilityIndex(monstre* m) {
    for (int i = 0; i < UTILITIES_ARRAY_SIZE - 1; i++) {
        if (m->inventory->utilities[i] > 0) {
            return i;
        }
    }
    return 6;
}

/*

FUNCTION printItemsFromCategory

*/

void printItemsFromCategory(joueur* j, int category) {
    switch (category) {
        case 1:

            printf("----------ARMURES----------\n\n");

            for (int i = 0; i < PLAYER_INVENTORY_SPACE; i++) {
                
                if (i == 0) {
                    printf("%d - %s (DEF : %d | Espace d'inventaire : %d) [*]\n",i+1,j->inventory->armors[i].name,j->inventory->armors[i].def,j->inventory->armors[i].inventorySpace);
                }else {
                    printf("%d - %s (DEF : %d | Espace d'inventaire : %d) [ ]\n",i+1,j->inventory->armors[i].name,j->inventory->armors[i].def,j->inventory->armors[i].inventorySpace);
                }
                
            } 
            break;
        case 2:
            printf("----------ARMES----------\n\n");
            for (int i = 0; i < PLAYER_INVENTORY_SPACE; i++) {
                if (IS_MAGIC) {
                    printf("\033[0;35m");
                    if (i == 0) {
                        printf("%d - %s (DMG : %d-%d | Propriete : %d | Actions : %d) [*]\n",i+1,j->inventory->weapons[i].name,j->inventory->weapons[i].dmgMin,j->inventory->weapons[i].dmgMax,j->inventory->weapons[i].property,j->inventory->weapons[i].actions);
                    }else {
                        printf("%d - %s (DMG : %d-%d | Propriete : %d | Actions : %d) [ ]\n",i+1,j->inventory->weapons[i].name,j->inventory->weapons[i].dmgMin,j->inventory->weapons[i].dmgMax,j->inventory->weapons[i].property,j->inventory->weapons[i].actions);
                    }
                    printf("\033[0m");
                }else {
                    if (i == 0) {
                        printf("%d - %s (DMG : %d-%d | Propriete : %d | Actions : %d) [*]\n",i+1,j->inventory->weapons[i].name,j->inventory->weapons[i].dmgMin,j->inventory->weapons[i].dmgMax,j->inventory->weapons[i].property,j->inventory->weapons[i].actions);
                    }else {
                        printf("%d - %s (DMG : %d-%d | Propriete : %d | Actions : %d) [ ]\n",i+1,j->inventory->weapons[i].name,j->inventory->weapons[i].dmgMin,j->inventory->weapons[i].dmgMax,j->inventory->weapons[i].property,j->inventory->weapons[i].actions);
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < PLAYER_INVENTORY_SPACE; i++) {
                if (i == 0) {
                    printf("%d - %s (Espace d'utilitaires : %d) [*]\n",i+1,j->inventory->bags[i].name,j->inventory->bags[i].utilitySpace);
                }else {
                    printf("%d - %s (Espace d'utilitaires : %d) [ ]\n",i+1,j->inventory->bags[i].name,j->inventory->bags[i].utilitySpace);
                }
            }
            break;
    }
}

/*

FUNCTION saveCurrentInventory()

*/

inventory saveCurrentInventory(joueur* j) {
    inventory save;
    save.armors = malloc(sizeof(armor)*PLAYER_INVENTORY_SPACE);
    save.weapons = malloc(sizeof(weapon)*PLAYER_INVENTORY_SPACE);
    save.bags = malloc(sizeof(bag)*PLAYER_INVENTORY_SPACE);
    save.utilities = malloc(sizeof(int)*7);
    for (int i = 0; i < PLAYER_INVENTORY_SPACE; i++) {
        save.armors[i] = j->inventory->armors[i];
        save.weapons[i] = j->inventory->weapons[i];
        save.bags[i] = j->inventory->bags[i];
    }
    for (int i = 0; i < 7; i++) {
        save.utilities[i] = j->inventory->utilities[i];
    }
    return save;
}

/*

FUNCTION reallocInventorySpace

*/

void reallocInventorySpace(joueur* j, int x) {
    if (x > j->inventory->armors->inventorySpace) {
        int oldSize = j->inventory->armors->inventorySpace;
        inventory saveCurInv = saveCurrentInventory(j);
        
        j->inventory->armors = realloc(j->inventory->armors,sizeof(armor)*x);
        j->inventory->weapons = realloc(j->inventory->weapons,sizeof(weapon)*x);
        j->inventory->bags = realloc(j->inventory->bags,sizeof(bag)*x);

        for (int i = 0; i < oldSize; i++) {
            j->inventory->armors[i] = saveCurInv.armors[i];
            j->inventory->weapons[i] = saveCurInv.weapons[i];
            j->inventory->bags[i] = saveCurInv.bags[i];
        }

        for (int i = 0; i < 7; i++) {
            j->inventory->utilities[i] = saveCurInv.utilities[i];
        }

        for (int i = oldSize; i < x; i++) {
            j->inventory->armors[i].name = "null";
            j->inventory->armors[i].def = 0;
            j->inventory->armors[i].inventorySpace = 0;
            j->inventory->weapons[i].name = "null";
            j->inventory->weapons[i].dmgMax = 0;
            j->inventory->weapons[i].dmgMin = 0;
            j->inventory->weapons[i].actions = 0;
            j->inventory->weapons[i].property = 0;
            j->inventory->bags[i].name = "null";
            j->inventory->bags[i].utilitySpace = 0;
        }

        free(saveCurInv.armors);
        free(saveCurInv.weapons);
        free(saveCurInv.bags);
        free(saveCurInv.utilities);    

    }else {
        int oldSize = j->inventory->armors->inventorySpace;
        inventory saveCurInv = saveCurrentInventory(j);
        
        free(j->inventory->armors);
        free(j->inventory->weapons);
        free(j->inventory->bags);

        j->inventory->armors = malloc(sizeof(armor)*x);
        j->inventory->weapons = malloc(sizeof(weapon)*x);
        j->inventory->bags = malloc(sizeof(bag)*x);

        for (int i = 0; i < x; i++) {
            j->inventory->armors[i] = saveCurInv.armors[i];
            j->inventory->weapons[i] = saveCurInv.weapons[i];
            j->inventory->bags[i] = saveCurInv.bags[i];
        }

        for (int i = 0; i < 7; i++) {
            j->inventory->utilities[i] = saveCurInv.utilities[i];
        }

        free(saveCurInv.armors);
        free(saveCurInv.weapons);
        free(saveCurInv.bags);
        free(saveCurInv.utilities);

    }
    
}

/*

FUNCTION printLostItems

*/

void printLostItems(joueur * j, int newSize) {
    for (int i = newSize; i < PLAYER_INVENTORY_SPACE; i++) {
        if (!emptyEquipementSpace(j->inventory->armors[i].name)) {
            printf("%s | DEF : %d | Espace d'inventaire : %d\n",j->inventory->armors[i].name,j->inventory->armors[i].def,j->inventory->armors[i].inventorySpace);
        }
    }
    for (int i = newSize; i < PLAYER_INVENTORY_SPACE; i++) {
        if (!emptyEquipementSpace(j->inventory->weapons[i].name)) {
            if (IS_MAGIC) {
                printf("\033[0;35m");
                printf("%s | DMG : %d-%d | Propriete : %d | Actions : %d (vous perdrez le sort associé à cet objet)\n",j->inventory->weapons[i].name,j->inventory->weapons[i].dmgMin,j->inventory->weapons[i].dmgMax,j->inventory->weapons[i].property,j->inventory->weapons[i].actions);
                printf("\033[0m");
            }else {
                printf("%s | DMG : %d-%d | Actions : %d\n",j->inventory->weapons[i].name,j->inventory->weapons[i].dmgMin,j->inventory->weapons[i].dmgMax,j->inventory->weapons[i].actions);
            }
        }
    }
    for (int i = newSize; i < PLAYER_INVENTORY_SPACE; i++) {
        if (!emptyEquipementSpace(j->inventory->bags[i].name)) {
            printf("%s\n",j->inventory->bags[i].name);
        }
    }
}

/*

printLostUtilities

*/

void printLostUtilities(joueur* j, int newSize) {
    for (int i = 0; i < 6; i++) {
        if (j->inventory->utilities[i] > UTILITIES_CAPACITY) {
            printf("%s : %d\n",getUtilityName(i),j->inventory->utilities[i] - UTILITIES_CAPACITY);
        }
    }
}

/*

FUNCTION replaceItem

*/

int replaceItem(joueur* j, monstre* m, int category, int index) {
    switch (category) {
        case 1:
            if (index == 0) {
                if (PLAYER_INVENTORY_SPACE < MONSTER_INVENTORY_ARMOR_INVENTORY_SPACE) {
                    reallocInventorySpace(j,MONSTER_INVENTORY_ARMOR_INVENTORY_SPACE);
                    j->inventory->armors[index] = m->inventory->armors[0];
                    return 1;
                }else if (PLAYER_INVENTORY_SPACE > MONSTER_INVENTORY_ARMOR_INVENTORY_SPACE) {
                    printf("Remplacer l'armure actuellement équiper vas entrainer la perte des objets suivants car vous n'aurez pas\n assez de place dans votre inventaire pour les stocker :\n\n");
                    printLostItems(j,MONSTER_INVENTORY_ARMOR_INVENTORY_SPACE);
                    printf("\n\nVoulez vous continuer ?\n\n");
                    printf("1 - Oui             0 - Non\n\n");
                    int choice;
                    do {
                        choice = getchar() - '0';
                    } while (choice < 0 || choice > 1);
                    
                    if (choice) {
                        reallocInventorySpace(j,MONSTER_INVENTORY_ARMOR_INVENTORY_SPACE);
                        j->inventory->armors[index] = m->inventory->armors[0];
                        return 1;
                    }else {
                        printf("Vous n'avez pas remplacer votre armure\n");
                        return 0;
                    }
                    
                }else {
                    j->inventory->armors[index] = m->inventory->armors[0];
                    return 1;
                }
            }else {
                j->inventory->armors[index] = m->inventory->armors[0];
                return 1;
            }
            break;
        case 2:
            j->inventory->weapons[index] = m->inventory->weapons[0];
            return 1;
            break;
        case 3:
            if (index == 0) {
                if (UTILITIES_CAPACITY < m->inventory->bags[0].utilitySpace) {
                    printf("Remplacer le sac actuellement équiper vas entrainer la perte des objets suivants car vous n'aurez pas\n assez de place dans votre inventaire pour les stocker :\n\n");
                    printLostUtilities(j,m->inventory->bags[0].utilitySpace);
                    printf("\n\nVoulez vous continuer ?\n\n");
                    printf("1 - Oui             0 - Non\n\n");
                    int choice;
                    do {
                        choice = getchar() - '0';
                    } while (choice < 0 || choice > 1);
                    
                    if (choice) {
                        for (int i = 0; i < 6; i++) {
                            if (j->inventory->utilities[i] > m->inventory->bags[0].utilitySpace) {
                                j->inventory->utilities[i] = m->inventory->bags[0].utilitySpace;
                            }
                        }
                        j->inventory->bags[index] = m->inventory->bags[0];
                    }else {
                        printf("Vous n'avez pas remplacer votre sac\n");
                        return 0;
                    }
                }
            }
            return 1;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}


/*

FUNCTION lootMonster

*/
void lootMonster(joueur* j, monstre* m) {

    //print players Current Inventory
    //printPlayerInventory(j);

    //print reward
    printReward(m);

    //ask player if he wants to keep the reward
    printf("Voulez vous garder la recompense ?\n\n");
    printf("1 - Oui             0 - Non\n\n");
    int choice;
    do {
        choice = getchar() - '0';
    } while (choice < 0 || choice > 1);

    if (choice) {
        //check if he has space in his inventory for this item category (armor, weapon, bag, utility)
        if(hasSpace(j,getRewardCategory(m))) {
            //if yes add reward to inventory
            int i;
            switch (getRewardCategory(m)) {
                
                case 1:
                    i = getAvailableInventorySpace(j,1);
                    j->inventory->armors[i] = m->inventory->armors[0];
                    break;
                case 2:
                    i = getAvailableInventorySpace(j,2);
                    j->inventory->weapons[i] = m->inventory->weapons[0];
                    break;
                case 3:
                    i = getAvailableInventorySpace(j,3);
                    j->inventory->bags[i] = m->inventory->bags[0];
                    break;
                case 4:
                    i = getUtilityIndex(m);
                    if (PLAYER_UTILITY_OWNED + MONSTER_INVENTORY_OWNED_UTILITY > UTILITIES_CAPACITY) {
                        int difference = UTILITIES_CAPACITY - PLAYER_UTILITY_OWNED;
                        j->inventory->utilities[i] = UTILITIES_CAPACITY;
                        printf("Vous avez recupéré %d %s car votre sac ne vous permet pas d'en porter plus de %d\n",difference,getUtilityName(i),UTILITIES_CAPACITY);
                    }else {
                        PLAYER_UTILITY_OWNED += MONSTER_INVENTORY_OWNED_UTILITY;
                    }
                    break;
                case 5:
                    i = getUtilityIndex(m);
                    PLAYER_GOLD += MONSTER_INVENTORY_OWNED_UTILITY;
                    break;
            }
            printf("\033[0;32m");
            printf("\n\nVous avez recupere l'objet\n");
            printf("\033[0m");
            printPlayerInventory(j);
        }else {
            //ask player if he wants to replace an item in his inventory (from same category)
            if (getRewardCategory(m) == 4) {
                printf("\033[1;33m");
                printf("\n\nVous n'avez pas assez de place dans votre inventaire pour recuperer cet objet\n");
                printf("\033[0m");

            }else {
                clearTerminal();
                printMain(j,m);
                printf("\033[1;33m");
                printf("\n\nVous n'avez pas assez de place dans votre inventaire pour recuperer cet objet\n");
                printf("Souhaitez vous remplacer un objet de meme categorie ?\n\n");
                printf("1 - Oui             0 - Non\n\n");
                printf("\033[0m");
                int choice;

                do {
                    choice = getchar() - '0';
                } while (choice < 0 || choice > 1);
                
                
                if (choice) {
                    printf("Quel objet souhaitez vous remplacer ?\n\n");
                    printItemsFromCategory(j,getRewardCategory(m));

                    int choice2;
                    do {
                        choice2 = getchar() - '0';
                    }while (choice2 < 1 || choice2 > PLAYER_INVENTORY_SPACE);

                    choice2--;

                    if (replaceItem(j,m,getRewardCategory(m),choice2)) {
                        clearTerminal();
                        printMain(j,m);
                        printf("\033[0;32m");
                        printf("\n\nVous avez recupere l'objet\n");
                        printf("\033[0m");
                        printPlayerInventory(j);
                    }

                }
            }
        }
        
    }


}

/*

FUNCTION changeEquipedItem

*/

int changeEquipedItem(joueur* j, int newEquipementIndex, int category) {
    if (newEquipementIndex) {

        switch (category) {
            case 1:
                if (j->inventory->armors[newEquipementIndex].inventorySpace > j->inventory->armors[0].inventorySpace) {
                    reallocInventorySpace(j,j->inventory->armors[newEquipementIndex].inventorySpace);
                    armor temp = j->inventory->armors[0];
                    j->inventory->armors[0] = j->inventory->armors[newEquipementIndex];
                    j->inventory->armors[newEquipementIndex] = temp;
                }else if (j->inventory->armors[newEquipementIndex].inventorySpace < j->inventory->armors[0].inventorySpace) {
                    printf("Remplacer l'armure actuellement équiper vas entrainer la perte des objets suivants car vous n'aurez pas\n assez de place dans votre inventaire pour les stocker :\n\n");
                    printLostItems(j,j->inventory->armors[newEquipementIndex].inventorySpace);
                    printf("\n\nVoulez vous continuer ?\n\n");
                    printf("1 - Oui             0 - Non\n\n");
                    int choice;
                    do {
                        choice = getchar() - '0';
                    } while (choice < 0 || choice > 1);

                    if (choice) {
                        reallocInventorySpace(j,j->inventory->armors[newEquipementIndex].inventorySpace);
                        armor temp = j->inventory->armors[0];
                        j->inventory->armors[0] = j->inventory->armors[newEquipementIndex];
                        j->inventory->armors[newEquipementIndex] = temp;
                    }else {
                        printf("Vous n'avez pas remplacer votre armure\n");
                        return 0;
                    }
                    
                }else {
                    armor temp = j->inventory->armors[0];
                    j->inventory->armors[0] = j->inventory->armors[newEquipementIndex];
                    j->inventory->armors[newEquipementIndex] = temp;
                    printf("Vous avez equiper %s\n",j->inventory->armors[0].name);
                    return 1;
                }

                break;
            case 2:{
                weapon temp = j->inventory->weapons[0];
                j->inventory->weapons[0] = j->inventory->weapons[newEquipementIndex];
                j->inventory->weapons[newEquipementIndex] = temp;
                printf("Vous avez equiper %s\n",j->inventory->weapons[0].name);
                return 1;
            }
            case 3:{
                bag temp = j->inventory->bags[0];
                if (j->inventory->bags[newEquipementIndex].utilitySpace < j->inventory->bags[0].utilitySpace) {
                    printf("Remplacer le sac actuellement équiper vas entrainer la perte des objets suivants car vous n'aurez pas\n assez de place dans votre inventaire pour les stocker :\n\n");
                    printLostUtilities(j,j->inventory->bags[newEquipementIndex].utilitySpace);
                    printf("\n\nVoulez vous continuer ?\n\n");
                    printf("1 - Oui             0 - Non\n\n");
                    int choice;
                    do {
                        choice = getchar() - '0';
                    } while (choice < 0 || choice > 1);

                    if (choice) {
                        for (int i = 0 ; i < 6; i++) {
                            if (j->inventory->utilities[i] > j->inventory->bags[newEquipementIndex].utilitySpace) {
                                j->inventory->utilities[i] = j->inventory->bags[newEquipementIndex].utilitySpace;
                            }
                        }
                        j->inventory->bags[0] = j->inventory->bags[newEquipementIndex];
                        j->inventory->bags[newEquipementIndex] = temp;
                    }else {
                        printf("Vous n'avez pas remplacer votre sac\n");
                        return 0;
                    }
                }
                printf("Vous avez equiper %s\n",j->inventory->bags[0].name);
                return 1;
            }
        }
    }
    return 0;
}


/*

FUNCTION useUtility

*/

void useUtility(joueur * j,int utilityToUse) {
    switch (utilityToUse) {
        case 0:
            if (j->inventory->utilities[utilityToUse] > 0) {
                j->inventory->utilities[utilityToUse]--;
                int recovery = PLAYER_MAX_HP * 0.20;
                PLAYER_HP += recovery;
                if (PLAYER_HP > PLAYER_MAX_HP) {
                    PLAYER_HP = PLAYER_MAX_HP;
                }
                printf("Vous avez utilisé ");
                printf("\033[0;32m");
                printf("%s",getUtilityName(utilityToUse));
                printf("\033[0m");
                printf(" et vous avez récupéré %d points de vie\n",recovery);
            }else {
                printf("\033[0;36m");
                printf("Vous n'avez pas d'objet de ce type\n");
                printf("\033[0m");
            }
            break;
        case 1:
            if (j->inventory->utilities[utilityToUse] > 0) {
                j->inventory->utilities[utilityToUse]--;
                PLAYER_HP += PLAYER_MAX_HP * 0.5;
                if (PLAYER_HP > PLAYER_MAX_HP) {
                    PLAYER_HP = PLAYER_MAX_HP;
                }
                printf("Vous avez utilisé ");
                printf("\033[0;32m");
                printf("%s",getUtilityName(utilityToUse));
                printf("\033[0m");
                printf(" et vous avez récupéré la moitié de vos points de vie\n");
            }else {
                printf("\033[0;36m");
                printf("Vous n'avez pas d'objet de ce type\n");
                printf("\033[0m");
            }
            break;
        case 2:
            if (j->inventory->utilities[utilityToUse] > 0) {
                j->inventory->utilities[utilityToUse]--;
                PLAYER_HP = PLAYER_MAX_HP;
                printf("Vous avez utilisé ");
                printf("\033[0;32m");
                printf("%s",getUtilityName(utilityToUse));
                printf("\033[0m");
                printf(" et vous avez récupéré la totalité de vos points de vie\n");
            }else {
                printf("\033[0;36m");
                printf("Vous n'avez pas d'objet de ce type\n");
                printf("\033[0m");
            }
           break;
        case 3:
            if (j->inventory->utilities[utilityToUse] > 0) {
                j->inventory->utilities[utilityToUse]--;
                if (PLAYER_MANA == PLAYER_MAX_MANA) {
                    printf("Vous avez utilisé "); 
                    printf("\033[0;36m");
                    printf("%s",getUtilityName(utilityToUse));
                    printf("\033[0m");
                    printf(" mais vous aviez déja la totalité de votre mana\n");
                }else {
                    PLAYER_MANA += 1;
                    printf("Vous avez utilise "); 
                    printf("\033[0;36m");
                    printf("%s",getUtilityName(utilityToUse));
                    printf("\033[0m");
                    printf(" et vous avez récupéré 1 points de mana\n");
                }
            }else {
                printf("\033[0;36m");
                printf("Vous n'avez pas d'objet de ce type\n");
                printf("\033[0m");
            }
            break;
        case 4:
            if (j->inventory->utilities[utilityToUse] > 0) {
                j->inventory->utilities[utilityToUse]--;
                if (PLAYER_MANA == PLAYER_MAX_MANA) {
                    printf("Vous avez utilisé "); 
                    printf("\033[0;36m");
                    printf("%s",getUtilityName(utilityToUse));
                    printf("\033[0m");
                    printf("mais vous aviez déja la totalité de votre mana\n");
                }else {
                    PLAYER_MANA = PLAYER_MAX_MANA / 2;
                    printf("Vous avez utilisé "); 
                    printf("\033[0;36m");
                    printf("%s",getUtilityName(utilityToUse));
                    printf("\033[0m");
                    printf(" et vous avez récupéré la moitié de vos points de mana\n");
                }
            }else {
                printf("\033[0;36m");
                printf("Vous n'avez pas d'objet de ce type\n");
                printf("\033[0m");
            }
           break;
        case 5:
            if (j->inventory->utilities[utilityToUse] > 0) {
                j->inventory->utilities[utilityToUse]--;
                if (PLAYER_MANA == PLAYER_MAX_MANA) {
                    printf("Vous avez utilisé "); 
                    printf("\033[0;36m");
                    printf("%s",getUtilityName(utilityToUse));
                    printf("\033[0m");
                    printf(" mais vous aviez déja la totalité de votre mana\n");
                }else {
                    PLAYER_MANA = PLAYER_MAX_MANA;
                    printf("Vous avez utilisé "); 
                    printf("\033[0;36m");
                    printf("%s",getUtilityName(utilityToUse));
                    printf("\033[0m");
                    printf("et vous avez récupéré la totalité de vos points de mana\n");
                }
            }else {
                printf("\033[0;36m");
                printf("Vous n'avez pas d'objet de ce type\n");
                printf("\033[0m");
            }
            break;
    }
}


/*

FUNCTION changeGear

*/

void changeGear(joueur * j,int gearType,int gearToEquip) {

    switch (gearType) {
        case 1 :{
                weapon temp = j->inventory->weapons[0];
                j->inventory->weapons[0] = j->inventory->weapons[gearToEquip];
                j->inventory->weapons[gearToEquip] = temp;
                printf("Vous avez equiper %s\n",j->inventory->weapons[0].name);
            }
            break;
        case 2 : {
                armor temp = j->inventory->armors[0];
                if (j->inventory->armors[gearToEquip].inventorySpace > j->inventory->armors[0].inventorySpace) {
                    reallocInventorySpace(j,j->inventory->armors[gearToEquip].inventorySpace);
                    j->inventory->armors[0] = j->inventory->armors[gearToEquip];
                    j->inventory->armors[gearToEquip] = temp;
                    printf("Vous avez equiper %s\n",j->inventory->armors[0].name);
                }else if (j->inventory->armors[gearToEquip].inventorySpace < j->inventory->armors[0].inventorySpace) {
                    printf("Remplacer l'armure actuellement équiper vas entrainer la perte des objets suivants car vous n'aurez pas\n assez de place dans votre inventaire pour les stocker :\n\n");
                    printLostItems(j,j->inventory->armors[gearToEquip].inventorySpace);
                    printf("\n\nVoulez vous continuer ?\n\n");
                    printf("1 - Oui             0 - Non\n\n");
                    int choice;
                    do {
                       choice = getchar() - '0';
                    } while (choice < 0 || choice > 1);

                    if (choice) {
                        reallocInventorySpace(j,j->inventory->armors[gearToEquip].inventorySpace);
                        j->inventory->armors[0] = j->inventory->armors[gearToEquip];
                        j->inventory->armors[gearToEquip] = temp;
                    }else {
                        printf("Vous n'avez pas remplacer votre armure\n");
                    }
                }else {
                    j->inventory->armors[0] = j->inventory->armors[gearToEquip];
                    j->inventory->armors[gearToEquip] = temp;
                    printf("Vous avez equiper %s\n",j->inventory->armors[0].name);
                }
            }
            break;
        case 3 : {
            bag temp = j->inventory->bags[0];
            if (j->inventory->bags[gearToEquip].utilitySpace < j->inventory->bags[0].utilitySpace) {
                printf("Remplacer le sac actuellement équiper vas entrainer la perte des objets suivants car vous n'aurez pas\n assez de place dans votre inventaire pour les stocker :\n\n");
                printLostUtilities(j,j->inventory->bags[gearToEquip].utilitySpace);
                printf("\n\nVoulez vous continuer ?\n\n");
                printf("1 - Oui             0 - Non\n\n");
                int choice;
                do {
                    choice = getchar() - '0';
                } while (choice < 0 || choice > 1);

                if (choice) {
                    for (int i = 0 ; i < 6; i++) {
                        if (j->inventory->utilities[i] > j->inventory->bags[gearToEquip].utilitySpace) {
                            j->inventory->utilities[i] = j->inventory->bags[gearToEquip].utilitySpace;
                        }
                    }
                    j->inventory->bags[0] = j->inventory->bags[gearToEquip];
                    j->inventory->bags[gearToEquip] = temp;

                }else {
                    printf("Vous n'avez pas remplacer votre sac\n");
                }

            }else {
                j->inventory->bags[0] = j->inventory->bags[gearToEquip];
                j->inventory->bags[gearToEquip] = temp;
                printf("Vous avez equiper %s\n",j->inventory->bags[0].name);
            }
        }
            break;
    }

}


/* ----------------SPELLS---------------- */
/*

Player Spells are based on his weapons properties

if the player has magic weapons he can use spells

each magic weapon in the player's inventory gives the player 1 spell

casting a spell cost 2 actions and 2 mana

spells ignore ennemy defenses

player mana will regenerate by 1 each turn

mana will be uped by 2 each time the player levels up


*/

/*

FUNCTION hasMagic

*/

int magicItems(joueur* j) {
    int count = 0;
    for (int i = 0; i < PLAYER_INVENTORY_SPACE; i++) {
        if (IS_MAGIC) {
            count++;
        }
    }
    return count;
}

/*

FUNCTION getSpellDamages

*/

int getSpellDamages(joueur *j,int i) {
    int dmg = j->inventory->weapons[i].dmgMax * 1.5;
    return dmg;
}

/*

FUNCTION getSpellNameFromWeapon

*/

int getSpellNameFromWeapon(char* weaponName) {
    if (strcmp(weaponName,"Epée en herbe") == 0) {
        return 1;
    }else if (strcmp(weaponName,"Epée de feu") == 0) {
        return 2;
    }else if (strcmp(weaponName,"Epée de glace") == 0) {
        return 3;
    }else if (strcmp(weaponName,"Epée de foudre") == 0) {
        return 4;
    }else {
        return 5;
    }
}

/*

FUNCTION getSpellName

*/

char * getSpellName(joueur* j,int i) {
    char * name;
    for (int k = 0; k < PLAYER_INVENTORY_SPACE; k++) {
        if (IS_MAGIC) {
            switch (getSpellNameFromWeapon(j->inventory->weapons[i].name)) {
                case 1 :  
                    name = "Tanche herbe";
                    return name;
                case 2 :
                    name = "Lance flamme";
                    return name;
                case 3 :
                    name = "Lames de glace";
                    return name;
                case 4 :
                    name = "Tonnerre de Zeus";
                    return name;
                case 5 :
                    name = "Colère Sananesque";
                    return name;
            } 
        }
    }
    
    return "null";
}

/*

FUNCTION reallocSpells


*/

void reallocSpells(joueur* j,int nbOfSpells) {
    free(j->spellBook);
    j->spellBook = malloc(sizeof(spells)*nbOfSpells);
    int * spellItemIndex = malloc(sizeof(int)*nbOfSpells);
    int index = 0;
    for (int i = 0 ; i < PLAYER_INVENTORY_SPACE; i++) {
        if (IS_MAGIC) {
            spellItemIndex[index] = i;
            index ++;
        }
    }
    for (int i = 0; i < nbOfSpells; i++) {
        j->spellBook[i].name = getSpellName(j,spellItemIndex[i]);
        j->spellBook[i].dmg = getSpellDamages(j,spellItemIndex[i]);
    }
}

/*

FUNCTION getSpells

*/

void getSpells(joueur* j) {

    if (magicItems(j)) {
        reallocSpells(j,magicItems(j));
        j->spellbookSize = magicItems(j);
    }

}

/*

FUNCTION hasMana

*/

int hasMana(joueur* j) {
    if (j->mana >= 2) {
        return 1;
    }else {
        return 0;
    }
}

int GetIntWeapon(char* nameWeapon){
    if(strcmp(nameWeapon,"Epée en bois") == 0) {
        return 1;
    }
    else if(strcmp(nameWeapon,"Epée en fer") == 0) {
        return 2;
    }
    else if(strcmp(nameWeapon,"Epée en acier") == 0) {
        return 3;
    }
    else if(strcmp(nameWeapon,"Epée en diamant") == 0) {
        return 4;
    }
    else if(strcmp(nameWeapon,"Epée du roi Jonathan") == 0) {
        return 5;
    }
    else if(strcmp(nameWeapon,"Epée en herbe") == 0) {
        return 6;
    }
    else if(strcmp(nameWeapon,"Epée de feu") == 0) {
        return 7;
    }
    else if(strcmp(nameWeapon,"Epée de glace") == 0) {
        return 8;
    }
    else if(strcmp(nameWeapon,"Epée en cheveux du dieu Sananes") == 0) {
        return 9;
    }
    return 0;
}

char* GetNameWeapon(int intWeapon){
    if(intWeapon == 1) {
        return "Epée en bois";
    }
    else if(intWeapon == 2){
        return "Epée en fer";
    }
    else if(intWeapon == 3){
        return "Epée en acier";
    }
    else if(intWeapon == 4){
        return "Epée en diamant";
    }
    else if(intWeapon == 5){
        return "Epée du roi Jonathan";
    }
    else if(intWeapon == 6){
        return "Epée en herbe";
    }
    else if(intWeapon == 7){
        return "Epée de feu";
    }
    else if(intWeapon == 8){
        return "Epée de glace";
    }
    else if(intWeapon == 9){
        return "Epée en cheveux du dieu Sananes";
    }
    return "null";
}
