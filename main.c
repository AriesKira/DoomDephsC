#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/monster.h"
#include "include/player.h"
#include "include/userInterface.h"
#include "include/save.h"


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


    while(estMort == 0){

        printMain(&a,&monstres[index]);

        if(tour == 0){
            fightPrompts(1,nbMonstre,monstres,&index);
            printMain(&a, &monstres[index]);

            while(1){

                fightPrompts(2,nbMonstre,monstres,index,&choice);

                if(choice == 1){
                    printMain(&a, &monstres[index]);
                    if(monstres[index].vie <= -1) {
                        deleteMonster(index,&nbMonstre,monstres);
                        fightPrompts(4,nbMonstre,monstres,index);
                        delayPlayer();
                        break;
                    }
                    else{
                        monstres[index].vie -= a.puissance;
                        fightPrompts(3,nbMonstre,monstres,index);
                    }
                }
                else if(choice == 2) {
                    printMain(&a, &monstres[index]);
                    printf("Vous arretez d'attaquer\n");
                    delayPlayer();
                    stop = 1;
                    tour = 1;
                    break;
                }
                else if(choice == 3) {
                    if(savechoice == 1){
                        char name[100];
                        printf("Choississez un nom pour votre sauvegarde : ");
                        scanf("%s",name);
                        save(a.vie,name,nbMonstre,monstres);
                    }
                    else{
                        printf("1 pour ecraser la precedente sauvegarde / 2 pour creer une nouvelle sauvegarde");
                        int newSaveChoice;
                        scanf("%d",&newSaveChoice);
                        if(newSaveChoice == 1){
                            save(a.vie,saves[sauvegarde],nbMonstre,monstres);
                        }
                        else{
                            char name[100];
                            printf("Choississez un nom pour votre sauvegarde : ");
                            scanf("%s",name);
                            save(a.vie,name,nbMonstre,monstres);
                        }
                    }
                }
            }
        }
        else if(tour == 1) {

            for(int i = 0; i < nbMonstre ;i++){
                printMain(&a,&monstres[index]);
                a.vie -= monstres[i].pMax;
                fightPrompts(5,nbMonstre,monstres,i,a);
                delayPlayer();
                if (a.vie <= 0) {
                    fightPrompts(6,nbMonstre,monstres,&estMort);
                    break;
                }
            }

            tour = 0;
        }
    }

    free(a.image);
    free(b.image);
    for(int i = 0; i < nbMonstre; i++) {
        free(monstres[i].image);
    }
    return 0;
}


