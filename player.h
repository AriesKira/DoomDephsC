struct joueur{
    char* nom;
    int vieMax;
    int vie;
    int puissance;
};



/*

FUNCTION INITIALISER JOUEUR

*/

char* nom = malloc(sizeof(char) * 10);
scanf("%s",&nom);

a.nom = nom;
a.vieMax = 1000;
a.vie = a.vieMax;
a.puissance = 5;
