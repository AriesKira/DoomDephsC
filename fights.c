#include <stdlib.h>
#include <stdio.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/fights.h"
#include "include/userInterface.h"


int finalDamage(int maxDmg, int minDmg, int def) {
    int finalDamage = 0;
    if (maxDmg - def <= minDmg) {
        finalDamage = minDmg;
    }else {
        finalDamage = maxDmg - def;
    }
    return finalDamage;
}

void fight(monstre* monstres,int nbMonstre,joueur* j) {
    
        
    int isDead = 0;
    int stop = 0;
    int index = 0;
    int tour = 0;
    int choice;

    
    while(isDead == 0){

        printMain(j,&monstres[index]);

        if(tour == 0){
            fightPrompts(1,nbMonstre,monstres,&index);            
            printMain(j, &monstres[index]);
            
            while(1){
                
                fightPrompts(2,nbMonstre,monstres,index,&choice);
                
                if(choice == 1){
                    printMain(j, &monstres[index]);
                    int damage = finalDamage(PLAYER_MAX_DMG,PLAYER_MIN_DMG,MONSTER_DEF);
                    
                    if (MONSTER_HP - damage <= 0) {
                        MONSTER_HP = 0;
                        fightPrompts(4,nbMonstre,monstres,index);
                        delayPlayer();
                        break;
                    }else {
                        MONSTER_HP -= damage;
                        fightPrompts(3,nbMonstre,monstres,index,damage);
                        delayPlayer();
                        break;
                    }
                    
                }else if(choice == 2) {
                    printMain(j, &monstres[index]);
                    printf("Vous arretez d'attaquer\n");
                    delayPlayer();
                    stop = 1;
                    tour = 1;
                    break;
                }
            }
        }else if(tour == 1) {

            for(int i = 0; i < nbMonstre ;i++){
                printMain(j,&monstres[index]);
                int damage = finalDamage(MONSTER_MAX_DMG,MONSTER_MIN_DMG,PLAYER_DEF);
                PLAYER_HP -= damage;
                fightPrompts(5,nbMonstre,monstres,i,j,damage);
                delayPlayer();            
                if (PLAYER_HP <= 0) {
                    fightPrompts(6,nbMonstre,monstres,&isDead);
                    break;
                }
            }
            
            tour = 0;
        }
    }

}