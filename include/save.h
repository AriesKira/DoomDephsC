#ifndef SAVE_H
#define SAVE_H

#include "monster.h"

void save(int vie, int mana, char* name, char* playerName, char** playerImg, int PlayerimgHeight, int nbMonstres, monstre* monstres, inventory playerInventory);
char **getSaves();
int GetNbSaves();
char* getNameSave(char* name);
int getVieSave(char* name);
int getManaSave(char* name);
int GetNbMonstre(char* name);
monstre* GetMonstres(char* name, int nombreDeMonstres);
armor* GetArmors(char* name);
weapon* GetWeapons(char* name);
bag* GetBags(char* name);
int* GetUtilities(char* name);

#endif //SAVE_H
