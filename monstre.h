#ifndef PROJETC_MONSTRE_H
#define PROJETC_MONSTRE_H

struct monstre{
    int vie;
    int vieMax;
    int pMax;
    int pMin;
    int def;
};

void createMonstres(struct monstre *a, int nbMonstre, struct monstre* monstres);

#endif //PROJETC_MONSTRE_H
