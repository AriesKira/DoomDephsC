#ifndef INTERFACE_H
#define INTERFACE_H

#define ACTION_PROMPT 1
//PLAYER_ATTACK_PROMPTS
#define TARGET_PROMPT 2
#define ATTACKT_TYPE_PROMPT 3
#define MONSTER_KILLED 4
#define MONSTER_DAMAGED 5
//UTILITY_PROMPTS
#define LIST_UTILITIES_PROMPT 6
//MONSTER_ATTACK_PROMPTS
#define PLAYER_KILLED 7
#define PLAYER_DAMAGED 8

void clearTerminal();
void printPlayerImage(joueur *j);
void printMonsterImage(monstre *m);
void printMain(joueur *j, monstre *m,...);
char* getUtilityName(int index);
void printPlayerInventory(joueur *j);
void printReward(monstre *m);
void printTargetList(int nbMonstre,monstre* monstres);
void flushStdin();
void delayPlayer();
int fightPrompts(int promptNb,int nbMonstre,monstre* monstres,...);
#endif