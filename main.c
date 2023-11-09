#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/userInterface.h"
#include "include/fights.h"
#include "include/save.h"
#include "include/map.h"


int main() {
    srand(time(NULL));
    char **saves = getSaves();
    int savechoice;
    int sauvegarde;
    int nbMonstre;
    nbMonstre = rand() % 10 + 1;
    int levels = 5;
    monstre * monstres;
    joueur j;
    map map;
    int* alowedMoves = malloc(sizeof(int) * 4); // 0 = up, 1 = down, 2 = left, 3 = right

   printf("1 : Creer une nouvelle partie / 2 : Chargez une partie existante / 3 : Quitter\n");
    do {
        savechoice = getchar() - '0';
    } while (savechoice < 1 || savechoice > 3);

    if(savechoice == 1){
        savechoice = 0;
        // Génère un nombre de monstre aléatoire
        nbMonstre = rand() % 10 + 1;
        // Création d'un tableau de monstre
        monstres = malloc(sizeof(monstre) * nbMonstre);
        clearTerminal();
        //initialisation des monstre
        createMonstres(nbMonstre,monstres);
        //initialisation du joueur
        
        clearTerminal();
        createJoueur(&j);

        generateMap(0,&map,&j);
    }
    else if (savechoice == 2) {
        int nbsave = GetNbSaves();
        for(int i = 0; i < nbsave; i++){
            printf("%d %s",(i+1),saves[i]);
        }
        printf("Choississez une sauvegarde :\n");
        int choixSave;
        do
        {
            choixSave = getchar() - '0';
        } while (choixSave < 1 || choixSave > nbsave);
        // gérer le cas ou valeur incorrecte

        sauvegarde = choixSave - 1;
        nbMonstre = GetNbMonstre(saves[sauvegarde]);
        monstres = GetMonstres(saves[sauvegarde],&nbMonstre);
        //loadSavedPlayer(&j,"test",getVieMaxSave(saves[sauvegarde]),getVieSave(saves[sauvegarde]),getInventorySave(saves[sauvegarde]));   //createJoueur(&a,"test",100, getVieSave(saves[sauvegarde]),5);

        //map = GetMap(saves[sauvegarde]);
    }else {
        return 0;
    }

    clearTerminal();
    
    int choice;
    while (nbMonstre > 0) {
        printDonjon(map,j);
        
        alowedMoves = getAlowedMoves(map,j);

        printAlowedMoves(alowedMoves);
        
        do {
            choice = getchar();
        } while (choice != 'z' && choice != 'q' && choice != 's' && choice != 'd');

        switch (choice) {
            case 'z':
                if (alowedMoves[0]) {

                }else {
                    printf("Vous ne pouvez pas aller dans cette direction !\n");
                }
                break;
            
            case 'q':
                if (alowedMoves[2]) {

                }else {
                    printf("Vous ne pouvez pas aller dans cette direction !\n");
                }
                break;

            case 's':
                if (alowedMoves[1]) {

                }else {
                    printf("Vous ne pouvez pas aller dans cette direction !\n");
                }
                break;
            
            case 'd':
                if (alowedMoves[3]) {

                }else {
                    printf("Vous ne pouvez pas aller dans cette direction !\n");
                }
                break;
        }

    }
    


    if (fight(monstres,nbMonstre,&j,savechoice,&saves,sauvegarde)) {
        printf("Vous avez gagné !\n");
    } else {
        printf("Vous avez perdu !\n");
    }
    delayPlayer();
    
    

    free(j.image);

    free(j.inventory->armors);
    free(j.inventory->weapons);
    free(j.inventory->bags);


    return 0;
}


