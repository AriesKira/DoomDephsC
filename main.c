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
    nbMonstre = rand() % 10 + 1;
    // Création d'un tableau de monstre
    monstre * monstres = malloc(sizeof(monstre)*nbMonstre);
    // Création d'un joueur et monstre
    joueur j;
    //vide le terminal
    clearTerminal();
    //initialisation des monstre
    createMonstres(nbMonstre,monstres);
    //initialisation du joueur
    
    clearTerminal();
    createJoueur(&j,100,5);

    if (fight(monstres,nbMonstre,&j)) {
        printf("Vous avez gagné !\n");
    } else {
        printf("Vous avez perdu !\n");
    }
    

    free(j.image);
    for(int i = 0; i < nbMonstre; i++) {
        free(monstres[i].image);
    }

    free(j.inventory->armors);
    free(j.inventory->weapons);
    free(j.inventory->bags);


    return 0;
}


