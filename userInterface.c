#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/fights.h"

/*

FUNCTION CLEAR TERMINAL

*/

void clearTerminal() {
    printf("\033[H\033[J");
}


/*

Delay function

*/
void delay(int second){

    unsigned int retTime = time(0) + second;   // Get finishing time.
    while (time(0) < retTime); 
}


/*
FUNCTION PRINT PLAYER IMAGE

*/

void printPlayerImage(joueur *j) {
    printf("\033[0;36m");
    for(int i = 0; i < j->imgHeight; i++) {
        printf("            %s\n",j->image[i]);
    }
    printf("\033[0m");
}

/*

FONCTION PRINT MONSTER IMAGE

*/

void printMonsterImage(monstre *m) {
    printf("\033[0;31m");
    for(int i = 0; i < m->imgHeight; i++){
        printf("                                                                                                                            %s\n",m->image[i]);
    }
    printf("\033[0m");
}

/*

FUNCTION PRINT HEALTH

*/

void printHealth(joueur *j) {
    printf("\033[0;32m");
    printf("Vie :");
    for(int i = 0; i <= 100; i++) {
        if (i <= (j->vie/j->vieMax)*100) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf("\033[0;33m");
    printf(" %d/%d\n",j->vie,j->vieMax);
    printf("\033[0m");
}

/*

FUNCTION PRINT MAIN SCREEN

*/



void printMain(joueur *j, monstre *m,...) {
    va_list valist;
    va_start(valist,m);
    int lootPhase = va_arg(valist,int);
    if (lootPhase) {
        clearTerminal();
        printf("\n\n");
        printHealth(j);
        printf("\n\n\n");
        printPlayerImage(j);
        printf("\n\n\n");
    }else {
        clearTerminal();
        printf("\n\n");
        printHealth(j);
        printf("\n\n\n");
        printMonsterImage(m);
        printf("\n\n\n");
        printPlayerImage(j);
        printf("\n\n\n");
    }
    
}

/*

FUNCTION getUtilityName(int index)

*/

char* getUtilityName(int index) {
    switch (index) {
        case 0:
            return "small potion";
            break;
        case 1:
            return "medium potion";
            break;
        case 2:
            return "big potion";
            break;
        case 3:
            return "small mana potion";
            break;
        case 4:
            return "medium mana potion";
            break;
        case 5:
            return "big mana potion";
            break;
        default:
            return "Gold";
            break;
    }
}

/*

FUNCTION printPlayerInventory

*/
void printPlayerInventory(joueur *j) {
    int inventorySpace = j->inventory->armors->inventorySpace;
    printf("\033[0;36m");
    printf("------INVENTAIRE------\n\n");
    //armors
    printf("------ARMURES------\n");
    printf("\033[0m");
    for (int i = 0; i < inventorySpace; i++) {
        if (emptyEquipementSpace(j->inventory->armors[i].name)) {
            printf("%d - Empty Slot [ ]\n",i+1);
            break;
        }
        if (i == 0) {
            printf("%d - %s [*]\n",i+1,j->inventory->armors[i].name);
        }else {
            printf("%d - %s [ ]\n",i+1,j->inventory->armors[i].name);
        }
        
    }
    //weapons
    printf("\033[0;36m");
    printf("\n------ARMES------\n");
    printf("\033[0m");
    for (int i = 0; i < inventorySpace; i++) {
        if (emptyEquipementSpace(j->inventory->weapons[i].name)) {
            printf("%d - Empty Slot [ ]\n",i+1);
            break;
        }
        if (i ==0) {
            if (IS_MAGIC) {
                printf("\033[0;35m");
                printf("%d - %s [*]\n",i+1,j->inventory->weapons[i].name);
                printf("\033[0m");    
            }else {
                printf("%d - %s [*]\n",i+1,j->inventory->weapons[i].name);
            }
        }else {
            if (IS_MAGIC) {
                printf("\033[0;35m");
                printf("%d - %s [ ]\n",i+1,j->inventory->weapons[i].name);
                printf("\033[0m");    
            }else {
                printf("%d - %s [ ]\n",i+1,j->inventory->weapons[i].name);
            }
        }
        
    }
    //bags
    printf("\033[0;36m");
    printf("\n------SACS------\n");
    printf("\033[0m");
    for (int i = 0; i < inventorySpace; i++) {
        if (emptyEquipementSpace(j->inventory->bags[i].name)) {
            printf("%d - Empty Slot [ ]\n",i+1);
            break;
        }
        if (i ==0) {
            printf("%d - %s [*]\n",i+1,j->inventory->bags[i].name);
        }else {
            printf("%d - %s [ ]\n",i+1,j->inventory->bags[i].name);
        }
    }
    //utilities
    printf("\033[0;36m");
    printf("\n------OBJETS------\n");
    printf("\033[0m");
    for (int i = 0; i < 7; i++) {
        if (i == 6) {
            printf("%s - %d\n",getUtilityName(i),j->inventory->utilities[i]);
        }else {
            printf("%s - %d/%d\n",getUtilityName(i),j->inventory->utilities[i],UTILITIES_CAPACITY);
        }
        
    }
    
}

/*

FUNCTION printMonsterItem

*/

void printMonsterItem(monstre* m) {
    if (!emptyEquipementSpace(MONSTER_INVENTORY_ARMOR)) {
        printf("Armure : %s\n",MONSTER_INVENTORY_ARMOR);
        printf("Defense : %d\n",MONSTER_INVENTORY_ARMOR_DEF);
        printf("Espace d'inventaire : %d\n",MONSTER_INVENTORY_ARMOR_INVENTORY_SPACE);
    }else if (!emptyEquipementSpace(MONSTER_INVENTORY_WEAPON)) {
        printf("Arme : %s\n",MONSTER_INVENTORY_WEAPON);
        printf("Degats : %d - %d\n",MONSTER_INVENTORY_WEAPON_DMG_MIN,MONSTER_INVENTORY_WEAPON_DMG_MAX);
        printf("Actions : %d\n",MONSTER_INVENTORY_WEAPON_ACTIONS);
    }else if (!emptyEquipementSpace(MONSTER_INVENTORY_BAG)) {
        printf("Sac : %s\n",MONSTER_INVENTORY_BAG);
        printf("Espace d'utilitaires : %d\n",MONSTER_INVENTORY_BAG_UTILITY_SPACE);
    }else {
        for (int i = 0; i < 7; i++) {
            if (m->inventory->utilities[i] != 0) {
                printf("%s - %d\n",getUtilityName(i),m->inventory->utilities[i]);
            }
        }
    }


}

/*

FUNCTION printReward

*/

void printReward(monstre* m) {
    printf("\033[1;36m");
    printf("------RECOMPENSE------\n\n");
    printf("\033[0m");
    printMonsterItem(m);
    printf("\n\n");
}

/*

PRINT ENNEMY TARGET LIST

*/

void printTargetList(int nbMonstre,monstre* monstres) {

    for (int i = 0; i < nbMonstre; i++) {
        printf("%d - %s \n",i+1,monstres[i].name);
    }

}

/*

FUNCTION FLUSH STDIN

*/

void flushStdin() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
/*

FUNCTION Delay Player

*/

void delayPlayer() {
    char c;

    printf("\nAppuyez sur entrer pour continuer\n");
    flushStdin();
    do{

        c = getchar();

    } while (c != '\n' && c != EOF);
    
}

/*

FUNCTION FIGHT PROMPTS

*/

int fightPrompts(int promptNb,int nbMonstre,monstre* monstres,...) {
    va_list valist;
    va_start(valist,monstres);

    switch (promptNb) {
        case 1: {
            printf("Que souhaitez vous faire ?\n");
            printf("1 - Attaquer (cout : 1 action)\n");
            printf("2 - Utiliser un objet (cout : 1 action)\n");
            printf("3 - Afficher l'inventaire\n");
            printf("4 - Finir votre tour\n");

            int choice = 0;
            do {
                scanf("%d",&choice);
            } while (choice < 1 || choice > 4);

            return choice;
        }
        case 2: {
            int target = va_arg(valist,int);
            printf("Quel monstre souhaitez vous attaquer ?\n");
            printTargetList(nbMonstre,monstres);
            printf("%d - Annuler\n",nbMonstre+1);
            int choice = 0;
            do {
                scanf("%d",&choice);
            } while (choice < 1 || choice > nbMonstre + 1);
            if (choice == nbMonstre + 1) {
                return 0;
            }else {
                target = choice-1;
            }
            return 1;
        }
        case 3: {
            int choice = 0;
            printf("Souhaitez-vous :\n");
            printf("1 - Attaquer avec votre arme\n");
            printf("2 - Attaquer avec un sort\n");
            printf("3 - Annuler\n");
            do {
                scanf("%d",&choice);
            } while (choice < 1 || choice > 3);

            if (choice == 3) {
                return 0;
            }
            return choice;
        }
        case 4: {
            int target = va_arg(valist,int);
            int damage = va_arg(valist,int);
            printf("Vous infliger %d points de degats\n",damage); 
            printf("Vous aves vaincu %s\n",MONSTER_NAME);
            break;
        }
        case 5: {
            int target = va_arg(valist,int);
            int damage = va_arg(valist,int);
            printf("Vous infliger %d points de degats à %s\n",damage,MONSTER_NAME); 
            printf("%s a %d points de vie\n",MONSTER_NAME,MONSTER_HP);
            break;
        }
        case 6: {
            int i = va_arg(valist,int);
            joueur a = va_arg(valist,joueur);
            int damage = va_arg(valist,int);
            printf("le monstre %d vous attaque et vous inflige %d degats\n",i+1,damage);
            printf("Votre vie est dorenavant de %d\n",a.vie);
            break;
        }
        case 7: {
            int* estMort = va_arg(valist,int*);
            printf("Vous etes mort\n");
            *estMort = 1;
            break;
        }
    }

}

