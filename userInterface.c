#include <stdio.h>
#include <time.h>
typedef struct monstre {
    int vie;
    int vieMax;
    int pMax;
    int pMin;
    int def;
    char **image;
    int imgHeight;
}monstre;


typedef struct joueur{
    char* nom;
    int vieMax;
    int vie;
    int puissance;
    char **image;
    int imgHeight;
}joueur;
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
    printf(" \033[0;36m");
    for(int i = 0; i < j->imgHeight; i++) {
        printf("%s\n",j->image[i]);
    }
    printf("\033[0m");
}

/*

FONCTION PRINT MONSTER IMAGE

*/

void printMonsterImage(monstre *m) {
    printf("\033[0;31m");
    for(int i = 0; i < m->imgHeight; i++){
        printf("                                                                                                    %s\n",m->image[i]);
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

    } while ((c = getchar()) != '\n');
    
}