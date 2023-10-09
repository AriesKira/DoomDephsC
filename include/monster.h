#ifndef MONSTER_H 
#define MONSTER_H
typedef struct monstre {
    int vie;
    int vieMax;
    int pMax;
    int pMin;
    int def;
    char **image;
    int imgY;
}monstre;

void initMonsterImage(struct monstre *m);
void createMonstres(int nbMonstre, struct monstre* monstres);

#endif