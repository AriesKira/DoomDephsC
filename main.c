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
    char **saves = getSaves();
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
        monstres = GetMonstres(saves[sauvegarde],&nbMonstre);
        //loadSavedPlayer(&j,"test",getVieMaxSave(saves[sauvegarde]),getVieSave(saves[sauvegarde]),getInventorySave(saves[sauvegarde]));   //createJoueur(&a,"test",100, getVieSave(saves[sauvegarde]),5);

        //map = GetMap(saves[sauvegarde]);
        //level = getLevelSave(saves[sauvegarde]);
        //loadGame(&j,level,map,inFigh,savechoice,&saves,sauvegarde);
    }else {
        return 0;
    }

    clearTerminal();
    
    int result;

    do {
        result = startGame(&j,level,savechoice,&saves,sauvegarde);
        level++;
    } while (level < 5 || result != 0 || result != 2 || result != 3 || (result == 1 && level == 4));
    
    delayPlayer();
    
    

    free(j.image);

    free(j.inventory->armors);
    free(j.inventory->weapons);
    free(j.inventory->bags);


    return 0;
}


