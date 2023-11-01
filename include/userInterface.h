#ifndef INTERFACE_H
#define INTERFACE_H

#define ACTION_PROMPT 1
//PLAYER_ATTACK_PROMPTS
#define TARGET_PROMPT 2
#define ATTACKT_TYPE_PROMPT 3
#define MONSTER_KILLED 4
#define MONSTER_DAMAGED 5
#define LIST_SPELLS 6
#define MONSTER_SPELL_KILLED 7
#define MONSTER_SPELL_DAMAGED 8
#define SPELL_NOT_ENOUGH_MANA 9
//UTILITY_PROMPTS
#define LIST_UTILITIES_PROMPT 10
#define UTILITY_USED 11
//MONSTER_ATTACK_PROMPTS
#define PLAYER_KILLED 12
#define PLAYER_DAMAGED 13

void clearTerminal();
void printPlayerImage(joueur *j);
void printMonsterImage(monstre *m);
void printMain(joueur *j, monstre *m,...);
char* getUtilityName(int index);
void printPlayerArmors(joueur * j);
void printPlayerWeapons(joueur * j);
void printPlayerBags(joueur * j);
void printPlayerUtilities(joueur *j);
void printPlayerInventory(joueur *j);
void printReward(monstre *m);
void printTargetList(int nbMonstre,monstre* monstres);
void flushStdin();
void delayPlayer();
int fightPrompts(int promptNb,int nbMonstre,monstre* monstres,...);
#endif