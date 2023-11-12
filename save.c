#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/inventory.h"
#include "include/monster.h"
#include "include/player.h"

void save(int vie, int mana, char* name, char* playerName, char** playerImg, int PlayerimgHeight, int nbMonstres, monstre* monstres, inventory playerInventory){
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
            printf("Erreur lors de l'ouverture du fichier.\n");
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
    fprintf(f,"ManaJoueur:%d\n",mana);
    fprintf(f,"ImgJoueur:\n");
    for (int i = 0; i < PlayerimgHeight; i++) {
        fprintf(f, "%s", playerImg[i]);
        if (i < PlayerimgHeight - 1) {
            fprintf(f, "\n"); // Séparez les lignes de l'image
        }
    }
    fprintf(f,"\n");
    fprintf(f,"\n");
    fprintf(f,"Monstres : \n");
    for(int i = 0; i < nbMonstres; i++){
        fprintf(f,"Monstre : %d\n",(i+1));
        fprintf(f,"NomMonstre:%s\n",monstres[i].name);
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
        fprintf(f,"\n");
        fprintf(f,"imgHeight:%d\n",monstres[i].imgHeight);
    }
    for(int i = 0; i < playerInventory.armors->inventorySpace; i++){
        fprintf(f,"ArmorName:%s\n",playerInventory.armors[i].name);
        fprintf(f,"ArmorDef:%d\n",playerInventory.armors[i].def);
        fprintf(f,"ArmorinventorySpace:%d\n",playerInventory.armors[i].inventorySpace);
        fprintf(f,"WeaponName:%d\n", GetIntWeapon(playerInventory.weapons[i].name));
        fprintf(f,"WeaponDmgMin:%d\n",playerInventory.weapons[i].dmgMin);
        fprintf(f,"WeaponDmgMax:%d\n",playerInventory.weapons[i].dmgMax);
        fprintf(f,"WeaponProperty:%d\n",playerInventory.weapons[i].property);
        fprintf(f,"WeaponActions:%d\n",playerInventory.weapons[i].actions);
        fprintf(f,"BagName:%s\n",playerInventory.bags[i].name);
        fprintf(f,"BagUtilitySpace:%d\n",playerInventory.bags[i].utilitySpace);
        fprintf(f,"Utilities:\n");
    }
    for(int j = 0; j < 7; j++){
        fprintf(f,"%d\n",playerInventory.utilities[j]);
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

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }

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

char* getNameSave(char* name){
    char filename[255];
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    strcpy(filename,name);
    strcat(filename,".txt");
    char* nom;
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        printf("Erreur");
    }
    else{
        char ligne[100];
        if(fgets(ligne, sizeof(ligne), f) != NULL){
            if(sscanf(ligne, "NomJoueur:%s",nom) != 1){
                printf("Erreur");
            }
        }
        else{
            printf("Le fichier est vide ou ne contient pas la valeur de vie.");
        }
        fclose(f);
    }
    fclose(f);
    return nom;
}

int getVieSave(char* name){
    char filename[255];
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    strcpy(filename,name);
    strcat(filename,".txt");
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        printf("Erreur");
    }
    else {
        char line[256];
        while (fgets(line, sizeof(line), f) != NULL) {
            if (strstr(line, "VieJoueur:") != NULL) {
                char *valueStr = strchr(line, ':') + 1;
                fclose(f);
                return atoi(valueStr);
            }
        }
        fclose(f);
        return -1;
    }
    fclose(f);
    //never happens
    return 0;
}

int getManaSave(char* name){
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
    else {
        char line[256];
        while (fgets(line, sizeof(line), f) != NULL) {
            if (strstr(line, "ManaJoueur:") != NULL) {
                char *valueStr = strchr(line, ':') + 1;
                 fclose(f);
                return atoi(valueStr);
            }
        }
        fclose(f);
        return -1;
    }
    fclose(f);
    //never happens
    return 0;
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
            if (sscanf(ligne, "Monstre : %d", &monstreID) == 1) {
                nbMonstre++;
            }
        }
    }
    fclose(file);
    return nbMonstre;
}

monstre* GetMonstres(char *name, int nbMonstres) {
    char filename[255];
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    strcpy(filename, name);
    strcat(filename, ".txt");
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    monstre *tableauMonstres = (monstre *)malloc(nbMonstres * sizeof(monstre));
    int currentMonstreIndex = -1;
    char line[256];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "Monstre :") != NULL) {
            // Nouveau monstre trouvé, passer à l'index suivant
            currentMonstreIndex++;
            tableauMonstres[currentMonstreIndex].inventory = malloc(sizeof(inventory));
            initMonsterInventory(tableauMonstres[currentMonstreIndex].inventory);
            generateRandomLoot(tableauMonstres[currentMonstreIndex].inventory);
            continue;
        }

        if (strstr(line, "NomMonstre:") != NULL) {
            line[strcspn(line, "\n")] = '\0';
            char *valueStr = strchr(line, ':') + 1;
            tableauMonstres[currentMonstreIndex].name = strdup(valueStr);
        }
        if (strstr(line, "VieMax:") != NULL) {
            line[strcspn(line, "\n")] = '\0';
            char *valueStr = strchr(line, ':') + 1;
            tableauMonstres[currentMonstreIndex].vieMax = atoi(valueStr);
        }
        if (strstr(line, "VieMonstre:") != NULL) {
            line[strcspn(line, "\n")] = '\0';
            char *valueStr = strchr(line, ':') + 1;
            tableauMonstres[currentMonstreIndex].vie = atoi(valueStr);
        }
        if (strstr(line, "image:") != NULL) {
            // Réinitialiser le tableau pour stocker les lignes de l'image
            tableauMonstres[currentMonstreIndex].image = NULL;
            tableauMonstres[currentMonstreIndex].imgHeight = 0;

            // Lire les lignes de l'image et les ajouter au tableau
            while (fgets(line, sizeof(line), file) != NULL && strlen(line) > 1) {
                // Supprimer le caractère de nouvelle ligne à la fin de la ligne
                line[strcspn(line, "\n")] = '\0';

                tableauMonstres[currentMonstreIndex].image = realloc(tableauMonstres[currentMonstreIndex].image, (tableauMonstres[currentMonstreIndex].imgHeight + 1) * sizeof(char *));
                tableauMonstres[currentMonstreIndex].image[tableauMonstres[currentMonstreIndex].imgHeight] = strdup(line);
                tableauMonstres[currentMonstreIndex].imgHeight++;
            }
        }
        if (strstr(line, "imgHeight:") != NULL) {
            line[strcspn(line, "\n")] = '\0';
            char *valueStr = strchr(line, ':') + 1;
            tableauMonstres[currentMonstreIndex].imgHeight = atoi(valueStr);
        }
    }

    fclose(file);

    return tableauMonstres;
}

armor* GetArmors(char* name){
    char filename[255];
    int len = strlen(name);

    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    strcpy(filename, name);
    strcat(filename, ".txt");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    char line[256];

    armor* armors = (armor*)malloc(2 * sizeof(armor));
    if (armors == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        exit(1);
    }

    // Retour au début du fichier
    fseek(file, 0, SEEK_SET);

    // Lecture des données du fichier
    int armorIndex = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "ArmorName:", 10) == 0) {
            armors[armorIndex].name = strdup(line + 10);
            if (armors[armorIndex].name == NULL) {
                fprintf(stderr, "Erreur d'allocation mémoire pour le nom de l'arme.\n");
                exit(1);
            }
            char *newline = strchr(armors[armorIndex].name, '\n');
            if (newline != NULL) {
                *newline = '\0';
            }
        }
        else if (strncmp(line, "ArmorDef:", 9) == 0) {
            sscanf(line + 9, "%d", &armors[armorIndex].def);
        }
        else if (strncmp(line, "ArmorinventorySpace:", 20) == 0) {
            sscanf(line + 20, "%d", &armors[armorIndex].inventorySpace);
            armorIndex++;
        }
    }
    fclose(file);
    return armors;
}


weapon* GetWeapons(char* name){
    char filename[255];
    int len = strlen(name);

    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    strcpy(filename, name);
    strcat(filename, ".txt");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    char line[256];

    weapon* weapons = (weapon*)malloc(2 * sizeof(weapon));
    if (weapons == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_SET);

    int weaponIndex = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "WeaponName:", 11) == 0) {
            int tmp;
            sscanf(line + 11, "%d", &tmp);
            weapons[weaponIndex].name = GetNameWeapon(tmp);
        }
        else if (strncmp(line, "WeaponDmgMin:", 13) == 0) {
            sscanf(line + 13, "%d", &weapons[weaponIndex].dmgMin);
        }
        else if (strncmp(line, "WeaponDmgMax:", 13) == 0) {
            sscanf(line + 13, "%d", &weapons[weaponIndex].dmgMax);
        }
        else if (strncmp(line, "WeaponProperty:", 15) == 0) {
            sscanf(line + 15, "%d", &weapons[weaponIndex].property);
        }
        else if (strncmp(line, "WeaponActions:", 14) == 0) {
            sscanf(line + 14, "%d", &weapons[weaponIndex].actions);
            weaponIndex++;
        }
    }
    fclose(file);
    return weapons;
}

bag* GetBags(char* name){
    char filename[255];
    int len = strlen(name);

    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    strcpy(filename, name);
    strcat(filename, ".txt");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    char line[256];

    bag* bags = (bag*)malloc(2 * sizeof(bag));
    if (bags == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        exit(1);
    }

    // Retour au début du fichier
    fseek(file, 0, SEEK_SET);

    // Lecture des données du fichier
    int bagIndex = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "BagName:", 8) == 0) {
            bags[bagIndex].name = strdup(line + 8);
            if (bags[bagIndex].name == NULL) {
                fprintf(stderr, "Erreur d'allocation mémoire pour le nom de l'arme.\n");
                exit(1);
            }
            char *newline = strchr(bags[bagIndex].name, '\n');
            if (newline != NULL) {
                *newline = '\0';
            }
        }
        else if (strncmp(line, "BagUtilitySpace:", 16) == 0) {
            sscanf(line + 16, "%d", &bags[bagIndex].utilitySpace);
            bagIndex++;
        }
    }
    fclose(file);
    return bags;
}

int* GetUtilities(char* name){
    char filename[255];
    int len = strlen(name);

    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    strcpy(filename, name);
    strcat(filename, ".txt");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "Utilities:") != NULL) {
            break;
        }
    }

    int* result = (int*)malloc(7 * sizeof(int));
    if (result == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire");
        fclose(file);
        return NULL; // Indicateur d'erreur
    }

    // Read 7 integers after "Utilities:"
    for (int i = 0; i < 7; i++) {
        if (fgets(line, sizeof(line), file) == NULL) {
            fprintf(stderr, "Erreur de lecture du fichier");
            free(result);
            fclose(file);
            return NULL; // Indicateur d'erreur
        }
        // Use sscanf to extract the first integer from the line
        sscanf(line, "%d", &result[i]);
    }

    fclose(file);
    return result;
}