#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*

INITIALISATION De l'image du monstre

                 /\
                 ||
   ____ (((+))) _||_
  /.--.\  .-.  /.||.\
 /.,   \\(0.0)// || \\
/;`";/\ \\|m|//  ||  ;\
|:   \ \__`:`____||__:|
|:    \__ \T/ (@~)(~@)|
|:    _/|     |\_\/  :|
|:   /  |     |  \   :|
|'  /   |     |   \  '|
 \_/    |     |    \_/
        |     |
        |_____|
        |_____|

*/
//x =  23  y = 14

void initMonsterImage(struct monstre *m){
    int x = 1;//(rand() % 10 )+ 1;
    
    switch (x) {
    case 1:
        m->image = malloc(sizeof(char*) * 14);
        m->image[0] = "                 /\\        ";
        m->image[1] = "                 ||         ";
        m->image[2] = "   ____ (((+))) _||_        ";
        m->image[3] = "  /.--.\\  .-.  /.||.\\     ";
        m->image[4] = " /.,   \\\\(0.0)// || \\\\  ";
        m->image[5] = "/;`\";/\\ \\\\|m|//  ||  ;\\";
        m->image[6] = "|:   \\ \\__`:`____||__:|   ";
        m->image[7] = "|:    \\__ \\T/ (@~)(~@)|   ";
        m->image[8] = "|:    _/|     |\\_\\/  :|   ";
        m->image[9] = "|:   /  |     |  \\   :|    ";
        m->image[10] = "|'  /   |     |   \\  '|   ";
        m->image[11] = " \\_/    |     |    \\_/   ";
        m->image[12] = "        |     |            ";
        m->image[13] = "        |_____|            ";
        m->image[14] = "        |_____|            ";
        m->imgY = 14;
        break;
    case 2:
        
        break;
    case 3:
            
        break;

    case 4:
            
        break;

    case 5:
                
        break;    
    case 6:
                    
        break;
    case 7:
        
        break;
    case 8:

        break;
    case 9:

        break;
    case 10:

        break;
    default:
        initMonsterImage(m);
        break;
    }


}

/*

FONCTION AFFICHER MONSTRE

*/

void printMonsterImage(struct monstre *m) {

    for(int i = 0; i <= m->imgY; i++){
        printf("%s\n",m->image[i]);
    }
}

/*

FUNCTION INITIALISER MONSTRE

*/
/*
for(int i = 0; i < nbMonstre; i++){
        struct monstre a;
        a.vieMax = rand() % 100;
        a.vie = a.vieMax;
        a.pMax = rand() % 5;
        a.pMin = rand() % a.pMax;
        a.def = rand() % 100;
        monstres[i] = a; // Stock les monstres dans le tableau monstres
    }

/*


*/