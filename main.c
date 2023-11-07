#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/userInterface.h"
#include "include/fights.h"

int main() {
    // Génère un nombre de monstre aléatoire
    srand(time(NULL));
    int nbMonstre;
    int levels = 3;
    nbMonstre = 8;//rand() % 10 + 1;
    // Création d'un tableau de monstre
    
    // Création d'un joueur et monstre
    joueur j;
    //vide le terminal
    clearTerminal();
    //initialisation des monstre
    
    //initialisation du joueur
    
    clearTerminal();
    createJoueur(&j,100,5);
    for (int i = 0 ; i < levels ; i++) {
        monstre * monstres = malloc(sizeof(monstre)*nbMonstre);
        createMonstres(nbMonstre,monstres);
        if (fight(monstres,nbMonstre,&j)) {
            printf("Vous avez gagné !\n");
        } else {
            printf("Vous avez perdu !\n");
        }
        delayPlayer();
    }

    
    

    free(j.image);

    free(j.inventory->armors);
    free(j.inventory->weapons);
    free(j.inventory->bags);


    return 0;
}


