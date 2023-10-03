#include <stdio.h>
#include <stdlib.h>

struct joueur{
    char* nom;
    int vieMax;
    int vie;
    int puissance;
};

void createJoueur(struct joueur *a, char* nom, int vie, int puissance){
    a->nom = nom;
    a->vieMax = vie;
    a->vie = a->vieMax;
    a->puissance = puissance;
}

