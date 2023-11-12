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
#include "include/game.h"

int main() {
    srand(time(NULL));
    char **saves;
    if(getSaves() == 0){
        printf("Aucune sauvegarde");
    }
    else{
        saves = getSaves();
    }
    int savechoice;
    int sauvegarde;
    int nbMonstre;
    int level = 0;
    joueur j;

   printf("1 : Creer une nouvelle partie / 2 : Chargez une partie existante / 3 : Quitter\n");
    do {
        savechoice = getchar() - '0';
    } while (savechoice < 1 || savechoice > 3);


    if(savechoice == 1){
        savechoice = 0;
        //initialisation du joueur        
        clearTerminal();
        createJoueur(&j);
    } else if (savechoice == 2) {
        monstre * monstres;
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
        monstres = GetMonstres(saves[sauvegarde],nbMonstre);
        loadSavedPlayer(&j,getNameSave(saves[sauvegarde]),getVieSave(saves[sauvegarde]),getManaSave(saves[sauvegarde]),saves[sauvegarde]);   //createJoueur(&a,"test",100, getVieSave(saves[sauvegarde]),5);
    }else {
        return 0;
    }

    clearTerminal();
    
    int gameResult;
    do {
        gameResult = startGame(&j,level,savechoice,&saves,sauvegarde);
        level++;
    } while (gameResult == 1 && level != 5);
    
    delayPlayer();
    
    if (gameResult == 1) {
        printf("\033[1;32m");
        printf("Vous avez gagné !\n");
        printf("\033[0m");
    }else if (gameResult == 0) {
        printf("\033[1;31m");
        printf("Vous avez perdu !\n");
        printf("\033[0m");
    }else if (gameResult == 2) {
        printf("\033[1;34m");
        printf("Vous avez sauvegardé et quitté !\n");
        printf("\033[0m");
    }else if (gameResult == 3) {
        printf("Vous avez quitté !\n");
    }
    

    free(j.image);

    free(j.inventory->armors);
    free(j.inventory->weapons);
    free(j.inventory->bags);


    return 0;
}


