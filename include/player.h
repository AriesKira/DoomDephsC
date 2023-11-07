#ifndef PLAYER_H 
#define PLAYER_H

typedef struct joueur{
    char* nom;
    int vieMax;
    int vie;
    int puissance;
    char **image;
    int imgHeight;
}joueur;

void clearTerminal();
void initPlayerImage(struct joueur *j);
void createJoueur(struct joueur *a, char* nom, int vieMax, int vie, int puissance);

#endif