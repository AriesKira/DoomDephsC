#ifndef PLAYER_H 
#define PLAYER_H

typedef struct spells {
    char* name;
    int dmg;
}spells;

typedef struct joueur {
    char* nom;
    int vieMax;
    int vie;
    char **image;
    int imgHeight;
    spells* spellBook;
    int mana;
    int manaMax;
    int spellbookSize;
    inventory* inventory;
}joueur;

void initPlayerImage(struct joueur *j);
void createJoueur(struct joueur *a);

#endif