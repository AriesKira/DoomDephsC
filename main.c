#include <stdio.h>
#include <stdlib.h>
#include "monstre.h"
#include "joueur.h"

int main() {
    // Génère un nombre de monstre aléatoire
    int nbMonstre;
    nbMonstre = rand() % 10;

    struct monstre monstres[nbMonstre];
    struct monstre b;
    // Initialise les monstres avec des statistiques aléatoires
    createMonstres(&b,nbMonstre, monstres);

    printf("Choississez votre nom : \n");
    char* nom = malloc(sizeof(char) * 10);
    scanf("%s",&nom);

    struct joueur a;
    createJoueur(&a,nom,1000,5);

    int estMort = 0;
    int stop = 0;
    int nbAttaque = 0;
    int index = 0;
    int tour = 0;

    printf("Affrontez %d monstres\n",nbMonstre);
    while(estMort == 0){
        if(tour == 0){
            printf("Choissisez un monstre a combatttre\n");
            scanf("%d",&index);
            if(monstres[index].vie < a.puissance){
                printf("Ce monstre est mort,\n");
            }
            else{
                printf("Vous combatez le monstre %d sa vie est de %d\n",index,monstres[index].vie);
                while(stop == 0){
                    printf("1 pour attaquer / 2 pour fuir\n");
                    int choice;
                    scanf("%d",&choice);
                    if(choice == 1){
                        if(monstres[index].vie < a.puissance){
                            printf("Vous aves vaincu le monstre %d Choississez un monstre \n",index);
                            scanf("%d",&index);
                            if(monstres[index].vie < a.puissance){
                                printf("Ce monstre est mort,\n");
                                break;
                            }
                        }
                        if(monstres[index].vie > a.puissance){
                            monstres[index].vie -= a.puissance;
                            printf("La vie du monstre %d est de %d\n",index,monstres[index].vie);
                        }
                    }
                    else if(choice == 2){
                        printf("Vous arretez d'attaquer\n");
                        tour = 1;
                        stop = 1;
                    }
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

