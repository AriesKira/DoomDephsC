#ifndef PLAYER_H 
#define PLAYER_H

typedef struct joueur {
    char* nom;
    int vieMax;
    int vie;
    char **image;
    int imgHeight;
    int* spellBook;
    int mana;
    inventory* inventory;
} joueur;

void initPlayerImage(struct joueur *j);
void createJoueur(struct joueur *a, int vie, int puissance);

#endif