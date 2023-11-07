#ifndef PLAYER_H 
#define PLAYER_H

typedef struct joueur{
    char* nom;
    int vieMax;
    int vie;
    char **image;
    int imgHeight;
    inventory* inventory;
}joueur;

void initPlayerImage(struct joueur *j);
<<<<<<< HEAD
void createJoueur(struct joueur *a, char* nom, int vieMax, int vie, int puissance);
=======
void createJoueur(struct joueur *a, int vie, int puissance);
>>>>>>> main

#endif