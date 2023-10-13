#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/monster.h"
#include "include/player.h"
#include "include/userInterface.h"


int main() {
    // Génère un nombre de monstre aléatoire
    srand(time(NULL));
    int nbMonstre;
    nbMonstre = rand() % 10 + 1;
    // Création d'un tableau de monstre
    monstre monstres[nbMonstre];
    // Création d'un joueur et monstre
    joueur a;
    //vide le terminal
    clearTerminal();
    //initialisation des monstre
    createMonstres(nbMonstre,monstres);
    //initialisation du joueur
    printf("Choississez votre nom : \n");
    char* nom = malloc(sizeof(char) * 10);
    scanf("%s",nom);
    clearTerminal();
    createJoueur(&a,nom,100,5);
    free(nom);
    clearTerminal();

    int estMort = 0;
    int stop = 0;
    int nbAttaque = 0;
    int index = 0;
    int tour = 0;
    int choice;
    printf("Affrontez %d monstres\n",nbMonstre);
    
    //fction ecoute

    while(estMort == 0){

        printMain(&a,&monstres[index]);

        if(tour == 0){
            fightPrompts(1,nbMonstre,monstres,&index);            
            printMain(&a, &monstres[index]);
            
            while(1){
                
                fightPrompts(2,nbMonstre,monstres,index,&choice);
                
                if(choice == 1){
                    printMain(&a, &monstres[index]);
                    if(monstres[index].vie <= a.puissance) {
                        fightPrompts(4,nbMonstre,monstres,index);
                        delayPlayer();
                        break;
                    }else {
                        monstres[index].vie -= a.puissance;
                        fightPrompts(3,nbMonstre,monstres,index);
                    }
                }else if(choice == 2) {
                    printMain(&a, &monstres[index]);
                    printf("Vous arretez d'attaquer\n");
                    delayPlayer();
                    stop = 1;
                    tour = 1;
                    break;
                }
            }
        }else if(tour == 1) {

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
    for(int i = 0; i < nbMonstre; i++) {
        free(monstres[i].image);
    }
    return 0;
}


