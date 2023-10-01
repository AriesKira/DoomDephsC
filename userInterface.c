#include <stdio.h>
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

FUNCTION PRINT PLAYER IMAGE

*/

void printPlayerImage(joueur *j) {
    for(int i = 0; i < j->imgHeight; i++) {
        printf("%s\n",j->image[i]);
    }
}

/*

FONCTION PRINT MONSTER IMAGE

*/

void printMonsterImage(monstre *m) {

    for(int i = 0; i <= m->imgHeight; i++){
        printf("                                                                                                    %s\n",m->image[i]);
    }
}

/*

FUNCTION PRINT HEALTH

*/

void printHealth(joueur *j) {
    printf("Vie :");
    printf("\033[0;31m");
    for(int i = 0; i <= j->vieMax; i++) {
        if (i <= j->vie) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf("\033[0m");
    printf(" %d/%d\n",j->vie,j->vieMax);
}

/*

FUNCTION PRINT MAIN SCREEN

*/



void printMain(joueur *j, monstre *m) {
    clearTerminal();
    printHealth(j);
    printf("\n\n\n");
    printMonsterImage(m);
    printf("\n\n\n");
    printPlayerImage(j);
    printf("\n\n\n");
}

