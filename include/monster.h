#ifndef MONSTER_H 
#define MONSTER_H
typedef struct monstre {
    int vie;
    int vieMax;
    int pMax;
    int pMin;
    int def;
    char **image;
    int imgHeight;
}monstre;

void initMonsterImage(struct monstre *m);
void createMonstres(struct monstre *a, int nbMonstre, struct monstre* monstres);
void deleteMonster(int index, int *nbMonstre, monstre* monstres);

#endif