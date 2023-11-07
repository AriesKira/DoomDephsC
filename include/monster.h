#ifndef MONSTER_H 
#define MONSTER_H

typedef struct monstre {
    char * name;
    int vie;
    int vieMax;
    char **image;
    int imgHeight;
    inventory* inventory;
}monstre;

void initMonsterImage(struct monstre *m);
void createMonstres(int nbMonstre, struct monstre* monstres);
monstre * killMonster(monstre * monstres,int target,int nbMonstre);

#endif