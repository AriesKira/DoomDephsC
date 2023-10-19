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
    for(int i = 0; i <= j->vieMax; i++) {
        if (i <= j->vie) {
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



void printMain(joueur *j, monstre *m) {
    clearTerminal();
    printf("\n\n");
    printHealth(j);
    printf("\n\n\n");
    printMonsterImage(m);
    printf("\n\n\n");
    printPlayerImage(j);
    printf("\n\n\n");
}

/*

FUNCTION printPlayerInventory

*/
void printPlayerInentory(joueur *j) {
    int inventorySpace = j->inventory->armors->inventorySpace;
    //armors
    printf("------ARMURES------\n");
    for (int i = 0; i < inventorySpace; i++) {
        if (emptyEquipementSpace(j->inventory->armors[i].name)) {
            break;
        }
        if (i == 0) {
            printf("%d - %s [*]\n",i+1,j->inventory->armors[i].name);
        }else {
            printf("%d - %s [ ]\n",i+1,j->inventory->armors[i].name);
        }
        
    }
    //weapons
    printf("\n------ARMES------\n");
    for (int i = 0; i < inventorySpace; i++) {
        if (emptyEquipementSpace(j->inventory->weapons[i].name)) {
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
    printf("\n------SACS------\n");
    for (int i = 0; i < inventorySpace; i++) {
        if (emptyEquipementSpace(j->inventory->bags[i].name)) {
            break;
        }
        if (i ==0) {
            printf("%d - %s [*]\n",i+1,j->inventory->bags[i].name);
        }else {
            printf("%d - %s [ ]\n",i+1,j->inventory->bags[i].name);
        }
    }
    //utilities
    printf("\n------OBJETS------\n");
    for (int i = 0; i < 7; i++) {
        printf("%d - %d\n",i+1,j->inventory->utilities[i]);
    }
    
}


/*

PRINT ENNEMY TARGET LIST

*/

void printTargetList(int nbMonstre) {

    for (int i = 0; i < nbMonstre; i++) {
        printf("%d - Monstre %d\n",i+1,i+1);
    }

}

/*

FUNCTION Delay Player

*/

void delayPlayer() {
    char c;
    printf("\nAppuyez sur entrer pour continuer\n");
    do{
        
        c = getchar();

    } while (c != '\n');
    
}

/*

FUNCTION FIGHT PROMPTS

*/

void fightPrompts(int promptNb,int nbMonstre,monstre* monstres,...) {
    va_list valist;
    va_start(valist,monstres);

    switch (promptNb) {
        case 1: {
            int val = 0;
            int* index = va_arg(valist,int*);
            printf("Choissisez un monstre a combatttre\n");
            printTargetList(nbMonstre);
            do {
                scanf("%d",&val);
            } while (val < 1 || val > nbMonstre);
            
            if (monstres[val-1].vie < 0) {
                printf("Ce monstre est mort\n");
                fightPrompts(1,nbMonstre,monstres,index);
            }
            
            *index = val-1;

            break;
        }
        case 2: {
            int index = va_arg(valist,int);
            int *choice = va_arg(valist,int*);
            int val = 0;
            printf("Vous combatez le monstre %d sa vie est de %d\n",index+1,monstres[index].vie);
            printf("1 pour attaquer / 2 pour fuir\n");

            do {
                scanf("%d",&val);
            } while (val < 1 || val > 2);
            
            *choice = val;
            break;
        }
        case 3: {
            int index = va_arg(valist,int);
            printf("La vie du monstre %d est de %d\n",index+1,monstres[index].vie);
            break;
        }
        case 4: {
            int index = va_arg(valist,int);
            printf("Vous aves vaincu le monstre %d\n",index+1);
            break;
        }
        case 5: {
            int i = va_arg(valist,int);
            joueur a = va_arg(valist,joueur);
            int damage = va_arg(valist,int);
            printf("le monstre %d vous attaque et vous inflige %d degats\n",i+1,damage);
            printf("Votre vie est dorenavant de %d\n",a.vie);
            break;
        }
        case 6: {
            int* estMort = va_arg(valist,int*);
            printf("Vous etes mort\n");
            *estMort = 1;
            break;
        }
    }

}

