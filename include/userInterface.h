#ifndef INTERFACE_H
#define INTERFACE_H

void clearTerminal();
void printPlayerImage(joueur *j);
void printMonsterImage(monstre *m);
void printMain(joueur *j, monstre *m);
void printPlayerInentory(joueur *j);
void printTargetList(int nbMonstre,monstre* monstres);
void delayPlayer();
void fightPrompts(int promptNb,int nbMonstre,monstre* monstres,...);
#endif