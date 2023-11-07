#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/userInterface.h"
#include "include/fights.h"

int main() {
    char **saves = getSaves();
    int savechoice;
    int sauvegarde;
    printf("1 : Creer une nouvelle partie / 2 : Chargez une partie existante");
    scanf("%d",&savechoice);
    int nbMonstre;
    monstre *monstres;
    joueur a;
    monstre b;
    if(savechoice == 2){
        int nbsave = GetNbSaves();
        for(int i = 0; i < nbsave; i++){
            printf("%d %s",(i+1),saves[i]);
        }
        printf("Choississez une sauvegarde\n");
        int choixSave;
        scanf("%d",&choixSave);
        sauvegarde = choixSave - 1;
        nbMonstre = GetNbMonstre(saves[sauvegarde]);
        monstres = GetMonstres(saves[sauvegarde],&nbMonstre);
        createJoueur(&a,"test",100, getVieSave(saves[sauvegarde]),5);
        clearTerminal();
    }
    else {
        // Génère un nombre de monstre aléatoire
        srand(time(NULL));
        nbMonstre = rand() % 10 + 1;
        // Création d'un tableau de monstre
        monstres = malloc(nbMonstre * sizeof(monstre));
        clearTerminal();
        //initialisation des monstre
        createMonstres(&b, nbMonstre, monstres);
        //initialisation du joueur
        printf("Choississez votre nom : \n");
        char *nom = malloc(sizeof(char) * 10);
        scanf("%s", nom);
        clearTerminal();
        createJoueur(&a, nom, 100, 100, 5);
        free(nom);
        clearTerminal();
    }
    int estMort = 0;
    int stop = 0;
    int nbAttaque = 0;
    int index = 0;
    int tour = 0;
    int choice;
    printf("Affrontez %d monstres\n",nbMonstre);

    free(j.image);
    for(int i = 0; i < nbMonstre; i++) {
        free(monstres[i].image);
    }

    free(j.inventory->armors);
    free(j.inventory->weapons);
    free(j.inventory->bags);


    return 0;
}


