#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/userInterface.h"

#define INVENTORY_SPACE j.inventory->armors[0].inventorySpace
#define PLAYER_MAX_DMG j.inventory->weapons[0].dmgMax
#define PLAYER_MIN_DMG j.inventory->weapons[0].dmgMin
#define PLAYER_DEF j.inventory->armors[0].def
#define PLAYER_HP j.vie
#define PLAYER_MAX_HP j.vieMax
#define MONSTER_MAX_HP monstres[index].vieMax
#define MONSTER_HP monstres[index].vie
#define MONSTER_MAX_DMG monstres[index].inventory->weapons[0].dmgMax
#define MONSTER_MIN_DMG monstres[index].inventory->weapons[0].dmgMin
#define MONSTER_DEF monstres[index].inventory->armors[0].def

int main() {
    // Génère un nombre de monstre aléatoire
    srand(time(NULL));
    int nbMonstre;
    nbMonstre = rand() % 10 + 1;
    // Création d'un tableau de monstre
    monstre monstres[nbMonstre];
    // Création d'un joueur et monstre
    joueur j;
    //vide le terminal
    clearTerminal();
    //initialisation des monstre
    createMonstres(nbMonstre,monstres);
    //initialisation du joueur
    printf("Choississez votre nom : \n");
    char* nom = malloc(sizeof(char) * 10);
    scanf("%s",nom);
    clearTerminal();
    createJoueur(&j,nom,100,5);
    free(nom);    
    
    printPlayerInentory(&j);
    
    
    int isDead = 0;
    int stop = 0;
    int index = 0;
    int tour = 0;
    int choice;
    printf("Affrontez %d monstres\n",nbMonstre);
    
    //fction ecoute

//fightPrompts(4,nbMonstre,monstres,index);fightPrompts(3,nbMonstre,monstres,index);
    while(isDead == 0){

        printMain(&j,&monstres[index]);

        if(tour == 0){
            fightPrompts(1,nbMonstre,monstres,&index);            
            printMain(&j, &monstres[index]);
            
            while(1){
                
                fightPrompts(2,nbMonstre,monstres,index,&choice);
                
                if(choice == 1){
                    printMain(&j, &monstres[index]);
                    int finalDamage;
                    if (PLAYER_MAX_DMG - MONSTER_DEF <= PLAYER_MIN_DMG) {
                        finalDamage = PLAYER_MIN_DMG;
                    }else {
                        finalDamage = PLAYER_MAX_DMG - MONSTER_DEF;
                    }
                    
                    if (MONSTER_HP - finalDamage <= 0) {
                        MONSTER_HP = 0;
                        fightPrompts(4,nbMonstre,monstres,index);
                        delayPlayer();
                        break;
                    }else {
                        MONSTER_HP -= finalDamage;
                        fightPrompts(3,nbMonstre,monstres,index);
                        delayPlayer();
                        break;
                    }
                    
                }else if(choice == 2) {
                    printMain(&j, &monstres[index]);
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
                    fightPrompts(6,nbMonstre,monstres,&isDead);
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

    free(a.inventory->armors);
    free(a.inventory->weapons);
    free(a.inventory->bags);


    return 0;
}


