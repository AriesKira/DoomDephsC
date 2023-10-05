#ifndef UI_H
#define UI_H

void clearTerminal();
void printPlayerImage(joueur *j);
void printMonsterImage(monstre *m);
void printMain(joueur *j, monstre *m);
void printTargetList(int nbMonstre);
void delayPlayer();
#endif