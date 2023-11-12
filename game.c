#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/fights.h"
#include "include/userInterface.h"
#include "include/save.h"
#include "include/map.h"
#include "include/game.h"

/*

FUNCTION startGame
0 = lost ; 1 = win; 2 = SaveAndQuit; 3 = Quit

*/

int startGame(joueur * j, int level,int savechoice,char ***saves,int saveIndex) {
    int* alowedMoves = malloc(sizeof(int) * 4); // 0 = up, 1 = down, 2 = left, 3 = right
    map map;
    int nbMonstresInLevel = getNbMonstresInLevel(level);
    int choice;
    int BossIsAlive = 1;
    generateMap(level,&map,j);

    //BossIdAlive parce que j'avais prévu les boss mais pas eu le temps car tt seul
    while (1) {
        clearTerminal();
        printDonjon(map);
        
        alowedMoves = getAlowedMoves(map,*j);

        printOptions(alowedMoves);

        do {
            choice = getchar();
        } while (choice != 'z' && choice != 'q' && choice != 's' && choice != 'd' && choice != 'i' && choice != 'p' && choice != 'l');

        switch (choice) {
            case 'z':
                if (alowedMoves[0]) { //up
                    if (map.map[j->posY - 1][j->posX] == 3) {//Monsters
                        int monsterOnSpace = findNbOfMonsterOnSpace(nbMonstresInLevel,map);
                        monstre * monstres =  malloc(sizeof(monstre) * monsterOnSpace);
                        createMonstres(monsterOnSpace,monstres);
                        if (fight(monstres,monsterOnSpace,j,savechoice,saves,saveIndex)) {
                            nbMonstresInLevel -= monsterOnSpace;
                            map.map[j->posY - 1][j->posX] = 2;
                            map.map[j->posY][j->posX] = 6;
                            j->posY--;
                        }else {
                            return 0;
                        }

                    }else if (map.map[j->posY - 1][j->posX] == 4) {//Shop
                        //shop(j);
                    }else if (map.map[j->posY - 1][j->posX] == 5) {//Exit
                        if (nbMonstresInLevel > 0) {
                            printf("Vous devez tuer tous les monstres avant de pouvoir sortir !\n");
                            delayPlayer();
                        }else {
                            return 1;
                        }
                    }else {
                        map.map[j->posY][j->posX] = 6;
                        map.map[j->posY - 1][j->posX] = 2;
                        j->posY--;
                    }
                }else {
                    printf("Vous ne pouvez pas aller dans cette direction !\n");
                    delayPlayer();
                }
                break;
            
            case 'q':
                if (alowedMoves[2]) { //left
                    if (map.map[j->posY][j->posX - 1] == 3) {//Monsters
                        int monsterOnSpace = findNbOfMonsterOnSpace(nbMonstresInLevel,map);
                        monstre * monstres =  malloc(sizeof(monstre) * monsterOnSpace);
                        createMonstres(monsterOnSpace,monstres);
                        if (fight(monstres,monsterOnSpace,j,savechoice,saves,saveIndex)) {
                            nbMonstresInLevel -= monsterOnSpace;
                            map.map[j->posY][j->posX - 1] = 2;
                            map.map[j->posY][j->posX] = 6;
                            j->posX--;
                        }else {
                            return 0;
                        }

                    }else if (map.map[j->posY][j->posX - 1] == 4) {//Shop
                        //shop(j);
                    }else if (map.map[j->posY][j->posX - 1] == 5) {//Exit
                        if (nbMonstresInLevel > 0) {
                            printf("Vous devez tuer tous les monstres avant de pouvoir sortir !\n");
                            delayPlayer();
                        }else {
                            return 1;
                        }
                    }else {
                        map.map[j->posY][j->posX] = 6;
                        map.map[j->posY][j->posX - 1] = 2;
                        j->posX--;
                    }
                }else {
                    printf("Vous ne pouvez pas aller dans cette direction !\n");
                    delayPlayer();
                }
                break;

            case 's':
                if (alowedMoves[1]) { //down
                    if (map.map[j->posY + 1][j->posX] == 3) {//Monsters
                        int monsterOnSpace = findNbOfMonsterOnSpace(nbMonstresInLevel,map);
                        monstre * monstres =  malloc(sizeof(monstre) * monsterOnSpace);
                        createMonstres(monsterOnSpace,monstres);
                        if (fight(monstres,monsterOnSpace,j,savechoice,saves,saveIndex)) {
                            nbMonstresInLevel -= monsterOnSpace;
                            map.map[j->posY + 1][j->posX]= 2;
                            map.map[j->posY][j->posX] = 6;
                            j->posY++;
                        }else {
                            return 0;
                        }

                    }else if (map.map[j->posY + 1][j->posX] == 4) {//Shop
                        //shop(j);
                    }else if (map.map[j->posY + 1][j->posX] == 5) {//Exit
                        if (nbMonstresInLevel > 0) {
                            printf("Vous devez tuer tous les monstres avant de pouvoir sortir !\n");
                            delayPlayer();
                        }else {
                            return 1;
                        }
                    }else {
                        map.map[j->posY][j->posX] = 6;
                        map.map[j->posY + 1][j->posX] = 2;
                        j->posY++;
                    }
                }else {
                    printf("Vous ne pouvez pas aller dans cette direction !\n");
                    delayPlayer();
                }
                break;
            
            case 'd':
                if (alowedMoves[3]) { //right
                    if (map.map[j->posY][j->posX + 1] == 3) {//Monsters
                        int monsterOnSpace = findNbOfMonsterOnSpace(nbMonstresInLevel,map);
                        monstre * monstres =  malloc(sizeof(monstre) * monsterOnSpace);
                        createMonstres(monsterOnSpace,monstres);
                        if (fight(monstres,monsterOnSpace,j,savechoice,saves,saveIndex)) {
                            nbMonstresInLevel -= monsterOnSpace;
                            map.map[j->posY][j->posX + 1]= 2;
                            map.map[j->posY][j->posX] = 6;
                            j->posX++;
                        }else {
                            return 0;
                        }

                    }else if (map.map[j->posY][j->posX + 1] == 4) {//Shop
                        //shop(j);
                    }else if (map.map[j->posY][j->posX + 1] == 5) {//Exit
                        if (nbMonstresInLevel > 0) {
                            printf("Vous devez tuer tous les monstres avant de pouvoir sortir !\n");
                            delayPlayer();
                        }else {
                            return 1;
                        }
                    }else {
                        map.map[j->posY][j->posX] = 6;
                        map.map[j->posY][j->posX + 1] = 2;
                        j->posX++;
                    }
                }else {
                    printf("Vous ne pouvez pas aller dans cette direction !\n");
                    delayPlayer();
                }
                break;
            case 'i':
                printPlayerInventory(j);
                delayPlayer();
                break;
            case 'p':
                //int sauvegarde = GetNbSaves();
                //save(PLAYER->vie,"test",nbMonstresInLevel,monstres);
                return 2;
            case 'l':
                return 3;
        }


    }
    return 1;
}

