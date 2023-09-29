#include <stdio.h>
#include <stdlib.h>

struct joueur{
    char* nom;
    int vieMax;
    int vie;
    int puissance;
};

struct monstre{
    int vie;
    int vieMax;
    int pMax;
    int pMin;
    int def;
};

int main() {
    // Génère un nombre de monstre aléatoire
    int nbMonstre;
    nbMonstre = rand() % 10;
    struct monstre monstres[nbMonstre];
    // Initialise les monstres avec des statistiques aléatoires
    for(int i = 0; i < nbMonstre; i++){
        struct monstre a;
        a.vieMax = rand() % 100;
        a.vie = a.vieMax;
        a.pMax = rand() % 5;
        a.pMin = rand() % a.pMax;
        a.def = rand() % 100;
        monstres[i] = a; // Stock les monstres dans le tableau monstres
    }
    // Programme pour afficher les monstres
    /*for(int i = 0; i < nbMonstre; i++){
        printf("Monstre %d\n",i);
        printf("Vie max : %d\n",monstres[i].vieMax);
        printf("Vie : %d\n",monstres[i].vie);
        printf("Puissance max : %d\n",monstres[i].pMax);
        printf("Puissance min : %d\n",monstres[i].pMin);
        printf("Defense : %d\n",monstres[i].def);
    }*/
    printf("Choississez votre nom : \n");
    char* nom = malloc(sizeof(char) * 10);
    scanf("%s",&nom);
    struct joueur a;
    a.nom = nom;
    a.vieMax = 1000;
    a.vie = a.vieMax;
    a.puissance = 5;
    int estMort = 0;
    int stop = 0;
    int nbAttaque = 0;
    int index = 0;
    int tour = 0;
    printf("Affrontez %d monstres\n",nbMonstre);
    while(estMort == 0 || index != nbMonstre){
        if(tour == 0){
            printf("Vous combatez le monstre %d sa vie est de %d\n",index,monstres[index].vie);
            while(stop == 0){
                printf("1 pour attaquer / 2 pour fuir\n");
                int choice;
                scanf("%d",&choice);
                if(choice == 1){
                    if(monstres[index].vie <= 0){
                        printf("Vous aves vaincu le monstre %d\n",index);
                        index++;
                    }
                    monstres[index].vie -= a.puissance;
                    printf("La vie du monstre %d est de %d\n",index,monstres[index].vie);
                }
                else if(choice == 2){
                    printf("Vous arretez d'attaquer\n");
                    tour = 1;
                    stop = 1;
                }
            }
        }
        else if(tour == 1){
            for(int i = 0; i < nbMonstre ;i++){
                printf("le monstre %d vous attaque et vous inflige %d degats\n",i,monstres[i].pMax);
                a.vie -= monstres[i].pMax;
                printf("Votre vie est dorenavant de %d\n",a.vie);
            }
            tour = 0;
            stop = 0;
        }
        if(a.vie < 0) {
            printf("Vous etes mort\n");
            estMort = 1;
        }
    }
    free(nom);
    return 0;
}

//aazfhazoifazhfazof
//exaple gil


