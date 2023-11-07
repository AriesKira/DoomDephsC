#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"

void save(int vie, char* name, int nbMonstres, monstre* monstres){
    FILE *file = fopen("save.txt", "r");
    int namePresent = 0;
    if (file != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), file) != NULL) {
            if (strstr(line, name) != NULL) {
                namePresent = 1;
                break;
            }
        }
        fclose(file);
    }
    if (!namePresent) {
        file = fopen("save.txt", "a");
        if (file == NULL) {
            printf("Erreur lors de l'ouverture du fichier en mode append.\n");
            return;
        }
        fprintf(file, "%s\n", name);
        fclose(file);
    }
    char filename[255];
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    strcpy(filename,name);
    strcat(filename,".txt");
    FILE *f = fopen(filename,"w");
    fprintf(f,"VieJoueur:%d\n",vie);
    fprintf(f,"Monstres : \n");
    for(int i = 0; i < nbMonstres; i++){
        fprintf(f,"Monstre : %d\n",(i+1));
        fprintf(f,"VieMonstre:%d\n",monstres[i].vie);
        fprintf(f,"VieMax:%d\n",monstres[i].vieMax);
        //fprintf(f,"def:%d\n",monstres[i].def); Inventaire->Armures[0].def
        fprintf(f, "image:\n");
        for (int j = 0; j < monstres[i].imgHeight; j++) {
            fprintf(f, "%s", monstres[i].image[j]);
            if (j < monstres[i].imgHeight - 1) {
                fprintf(f, "\n"); // Séparez les lignes de l'image
            }
        }
        fprintf(f,"\n");
        fprintf(f,"imgHeight:%d\n",monstres[i].imgHeight);
    }
    fclose(f);
}

char **getSaves() {
    FILE *file = fopen("save.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }
    int nbLignes = 0;
    char caractere;
    while ((caractere = fgetc(file)) != EOF) {
        if (caractere == '\n') {
            nbLignes++;
        }
    }
    rewind(file);
    char **tableauSaves = (char **)malloc(nbLignes * sizeof(char *));
    for (int i = 0; i < nbLignes; i++) {
        tableauSaves[i] = NULL;
        size_t taille = 0;
        ssize_t longueurLigne = getline(&(tableauSaves[i]), &taille, file);
        if (longueurLigne == -1) {
            printf("Erreur lors de la lecture de la ligne %d.\n", i);
        }
    }
    fclose(file);
    return tableauSaves;
}

int GetNbSaves(){
    FILE *file = fopen("save.txt", "r");
    int nbsave = 0;
    char caractere;
    while ((caractere = fgetc(file)) != EOF) {
        if (caractere == '\n') {
            nbsave++;
        }
    }
    fclose(file);
    return nbsave;
}

int getVieSave(char* name){
    char filename[255];
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    strcpy(filename,name);
    strcat(filename,".txt");
    int vie = 0;
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        printf("Erreur");
    }
    else{
        char ligne[100];
        if(fgets(ligne, sizeof(ligne), f) != NULL){
            if(sscanf(ligne, "VieJoueur:%d", &vie) != 1){
                printf("Erreur");
            }
        }
        else{
            printf("Le fichier est vide ou ne contient pas la valeur de vie.");
        }
        fclose(f);
    }
    return vie;
}

int GetNbMonstre(char* name){
    char filename[255];
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    strcpy(filename,name);
    strcat(filename,".txt");
    int nbMonstre = 0;
    FILE *file = fopen(filename, "r");
    char ligne[100];
    while (fgets(ligne, sizeof(ligne), file) != NULL) {
        // Chercher "Monstre %d" dans la ligne
        if (strstr(ligne, "Monstre") != NULL) {
            int monstreID;
            if (sscanf(ligne, "Monstre %d", &monstreID) == 1) {
                nbMonstre++;
            }
        }
    }
    return nbMonstre;
}

monstre* GetMonstres(char* name, int *nbMonstres) {
    char filename[255];
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    strcpy(filename,name);
    strcat(filename,".txt");
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    int capacite = 10; // Capacité initiale du tableau
    monstre *tableauMonstres = (struct monstre *)malloc(capacite * sizeof(struct monstre));
    if (tableauMonstres == NULL) {
        fclose(file);
        printf("Erreur d'allocation mémoire.\n");
        return NULL;
    }

    char ligne[256];
    int indexMonstre = -1; // Indice du monstre actuel

    while (fgets(ligne, sizeof(ligne), file) != NULL) {
        ligne[strcspn(ligne, "\n")] = 0;

        if (strstr(ligne, "Monstre : ") != NULL) {
            indexMonstre++;
            if (indexMonstre >= capacite) {
                capacite *= 2;
                tableauMonstres = (monstre *)realloc(tableauMonstres, capacite * sizeof(struct monstre));
                if (tableauMonstres == NULL) {
                    fclose(file);
                    printf("Erreur d'allocation mémoire.\n");
                    return NULL;
                }
            }
            tableauMonstres[indexMonstre].image = NULL;
        } else if (strstr(ligne, "VieMonstre:") != NULL) {
            sscanf(ligne, "VieMonstre:%d", &tableauMonstres[indexMonstre].vie);
        } else if (strstr(ligne, "VieMax:") != NULL) {
            sscanf(ligne, "VieMax:%d", &tableauMonstres[indexMonstre].vieMax);
        } else if (strstr(ligne, "def:") != NULL) {
            //sscanf(ligne, "def:%d", &tableauMonstres[indexMonstre].def); Inventaire->Armures[0].def
        } else if (strstr(ligne, "image:") != NULL) {
            int imgHeight = 0;
            while (fgets(ligne, sizeof(ligne), file) != NULL && !strstr(ligne, "imgHeight:")) {
                ligne[strcspn(ligne, "\n")] = 0;
                tableauMonstres[indexMonstre].image = (char **)realloc(tableauMonstres[indexMonstre].image, (imgHeight + 1) * sizeof(char *));
                tableauMonstres[indexMonstre].image[imgHeight] = (char *)malloc(strlen(ligne) + 1);
                strcpy(tableauMonstres[indexMonstre].image[imgHeight], ligne);
                imgHeight++;
            }
            tableauMonstres[indexMonstre].imgHeight = imgHeight;
        }
    }

    fclose(file);
    *nbMonstres = indexMonstre + 1;
    return tableauMonstres;
}