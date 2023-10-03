#include <stdio.h>
#include <stdlib.h>

struct monstre{
    int vie;
    int vieMax;
    int pMax;
    int pMin;
    int def;
};

void createMonstres(struct monstre *a, int nbMonstre, struct monstre* monstres){
    // Initialise les monstres avec des statistiques aléatoires
    for(int i = 0; i < nbMonstre; i++){
        a->vieMax = rand() % 100;
        a->vie = a->vieMax;
        a->pMax = rand() % 5;
        a->pMin = rand() % a->pMax;
        a->def = rand() % 100;
        monstres[i] = *a; // Stock les monstres dans le tableau monstres
    }
}

