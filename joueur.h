#ifndef PROJETC_JOUEUR_H
#define PROJETC_JOUEUR_H

struct joueur{
    char* nom;
    int vieMax;
    int vie;
    int puissance;
};

void createJoueur(struct joueur *a, char* nom, int vie, int puissance);

#endif //PROJETC_JOUEUR_H
