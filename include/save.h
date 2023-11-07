#ifndef SAVE_H
#define SAVE_H

void save(int vie, char* name, int nbMonstres, monstre* monstres);
char **getSaves();
int GetNbSaves();
int getVieSave(char* name);
int GetNbMonstre(char* name);
monstre* GetMonstres(char* name, int *nombreDeMonstres);

#endif //SAVE_H
