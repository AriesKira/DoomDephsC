struct monstre{
    int vie;
    int vieMax;
    int pMax;
    int pMin;
    int def;
    char **image;
    int imgY;
};

void initMonsterImage(struct monstre *m);

void printMonsterImage(struct monstre *m);