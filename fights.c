#include <stdlib.h>
#include <stdio.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"
#include "include/fights.h"
#include "include/userInterface.h"

/*

FUNCTION finalDamage

*/

int finalDamage(int maxDmg, int minDmg, int def) {
    int finalDamage = 0;
    if (maxDmg - def <= minDmg) {
        finalDamage = minDmg;
    }else {
        finalDamage = maxDmg - def;
    }
    return finalDamage;
}

/*

FUNCTION fight

*/

int fight(monstre* monstres,int nbMonstre,joueur* j) {
    
    int target = 0;
    int playerTurn = 1;
    int choice;
    int loose = 0;
    int playerActions = 0;

    while(PLAYER_HP && nbMonstre){
        playerActions = PLAYER_ACTIONS;
        choice = 0;
        printMain(j,&monstres[target]);

        if(playerTurn && PLAYER_ACTIONS){
            choice = fightPrompts(ACTION_PROMPT,nbMonstre,monstres); //chose action      

            switch (choice) {
                case 1:
                    //Attack
                    choice = 0;
                    printMain(j,&monstres[target]);
                    choice = fightPrompts(TARGET_PROMPT,nbMonstre,monstres,&target); //chose target
                    if (!choice) {
                        break;
                    }else {
                        printMain(j,&monstres[target]);
                        choice = 0;
                        choice = fightPrompts(ATTACKT_TYPE_PROMPT,nbMonstre,monstres); //chose attack type //spell or attck
                        if (!choice) {
                            break;
                        }else if (choice == 1) { //normal attck
                            PLAYER_ACTIONS--;
                            int damage = 0;
                            damage =  finalDamage(PLAYER_MAX_DMG,PLAYER_MIN_DMG,MONSTER_DEF);
                            MONSTER_HP -= damage;
                            if (MONSTER_HP <= 0) {
                                printMain(j,&monstres[target]);
                                fightPrompts(MONSTER_KILLED,nbMonstre,monstres,target,damage);
                                delayPlayer();
                                lootMonster(j,&monstres[target]);
                                nbMonstre--;
                                monstres = killMonster(monstres,target,nbMonstre);
                                target = 0;
                            }else {
                                printMain(j,&monstres[target]);
                                fightPrompts(MONSTER_DAMAGED,nbMonstre,monstres,target,damage);
                                delayPlayer();
                            }
                            if (PLAYER_ACTIONS == 0) {
                                playerTurn = 0;
                            }
                            break;
                        }else { //spells
                            int spellToUse = 0;
                            printMain(j,&monstres[target]);
                            choice = 0;
                            choice = fightPrompts(LIST_SPELLS,nbMonstre,monstres,j,&spellToUse);
                            if (!choice) {
                                break;
                            }else {
                                if (hasMana(j)) {
                                    j->mana -= 2;
                                    PLAYER_ACTIONS--;
                                    int damage = j->spellBook[spellToUse].dmg;
                                    MONSTER_HP -= damage;
                                    if (MONSTER_HP <= 0) {
                                        printMain(j,&monstres[target]);
                                        fightPrompts(MONSTER_SPELL_KILLED,nbMonstre,monstres,target,damage,j->spellBook[spellToUse].name);
                                        delayPlayer();
                                        lootMonster(j,&monstres[target]);
                                        nbMonstre--;
                                        monstres = killMonster(monstres,target,nbMonstre);
                                        target = 0;
                                    }else {
                                        printMain(j,&monstres[target]);
                                        fightPrompts(MONSTER_SPELL_DAMAGED,nbMonstre,monstres,target,damage,j->spellBook[spellToUse].name);
                                        delayPlayer();
                                    }
                                    if (PLAYER_ACTIONS == 0) {
                                        playerTurn = 0;
                                    }
                                    break;
                                }else {
                                    printMain(j,&monstres[target]);
                                    fightPrompts(SPELL_NOT_ENOUGH_MANA,nbMonstre,monstres);
                                    delayPlayer();
                                    break;
                                }
                            }
                        }
                    }
                    break;
                case 2: {
                    //use utility
                        int utilityToUse = 0;
                        printMain(j,&monstres[target]);
                        choice = 0;
                        choice = fightPrompts(LIST_UTILITIES_PROMPT,nbMonstre,monstres,j,&utilityToUse); //chose utility to use
                        if (!choice) {
                            break;
                        }else {
                            useUtility(j,utilityToUse);
                            delayPlayer();
                        }
                    }
                    break;
                case 3:
                    //show inventory
                    printMain(j,&monstres[target]);
                    printPlayerInventory(j);
                    delayPlayer();
                    break;
                case 4:
                    //change gear
                    printMain(j,&monstres[target]);
                    choice = 0;
                    choice = fightPrompts(CHANGE_GEAR_TYPE_PROMPT,nbMonstre,monstres);
                    if (!choice) {
                        break;
                    }else {
                        int gearToEquip = 0;
                        int gearType = choice;
                        printMain(j,&monstres[target]);
                        choice = 0;
                        choice = fightPrompts(CHANGE_GEAR_PROMPT,nbMonstre,monstres,j,&gearToEquip,gearType);
                        if (!choice) {
                            break;
                        }else {
                            changeGear(j,gearType,gearToEquip);
                            delayPlayer();
                        }
                    }
                    break;
                case 5:
                    //save
                    break;
                case 6:
                    //end turn
                    playerTurn = 0;
                    break; 
            }

        }else if(!playerTurn) {
            int tmp= 0;
            for(int attacker = 0; attacker < nbMonstre ;attacker++){
                printMain(j,&monstres[attacker]);
                int damage = finalDamage(PLAYING_MONSTER_MAX_DMG,PLAYING_MONSTER_MIN_DMG,PLAYER_DEF);
                PLAYER_HP -= damage;
                if (PLAYER_HP <= 0) {
                    PLAYER_HP = 0;
                    loose = 1;
                    printMain(j,&monstres[attacker]);
                    tmp = fightPrompts(PLAYER_KILLED,nbMonstre,monstres,damage,attacker);
                    delayPlayer();
                    break;
                }else {
                    printMain(j,&monstres[attacker]);
                    tmp = fightPrompts(PLAYER_DAMAGED,nbMonstre,monstres,damage,attacker,j);
                    delayPlayer();
                }
            }
            PLAYER_ACTIONS = PLAYER_CURRENT_WEAPON.actions;
            playerTurn = 1;
        }
    }

    if (loose) {
        return 0;
    }else {
        return 1;
    }
}

