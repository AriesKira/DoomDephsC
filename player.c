#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct joueur{
    char* nom;
    int vieMax;
    int vie;
    int puissance;
    char **image;
    int imgHeight;
}joueur;


/*

FUNCTION INITIALISER PERSONNAGE DU JOUEUR

*/

/*
                       .-.
                      |_:_|
                     /(_Y_)\
.                   ( \/M\/ )
 '.               _.'-/'-'\-'._
   ':           _/.--'[[[[]'--.\_
     ':        /_'  : |::"| :  '.\
       ':     //   ./ |oUU| \.'  :\
         ':  _:'..' \_|___|_/ :   :|
           ':.  .'  |_[___]_|  :.':\
            [::\ |  :  | |  :   ; : \
             '-'   \/'.| |.' \  .;.' |
             |\_    \  '-'   :       |
             |  \    \ .:    :   |   |
             |   \    | '.   :    \  |
             /       \   :. .;       |
            /     |   |  :__/     :  \\
           |  |   |    \:   | \   |   ||
          /    \  : :  |:   /  |__|   /|
          |     : : :_/_|  /'._\  '--|_\
          /___.-/_|-'   \  \
                         '-'
*/

void initPlayerImage(joueur *j) {

    int choice = 0;
    
    printf("Choississez votre personnage : \n");
    printf("1 - Batman\n");
    printf("2 - Superman\n");
    printf("3 - Darth Vader\n");
    printf("4 - Wonder woman\n");

    scanf("%d",&choice);

    switch (choice) {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        j->image = malloc(sizeof(char*)*22);
        j->image[0] = "                       .-.                 ";
        j->image[1] = "                      |_:_|                ";
        j->image[2] = "                     /(_Y_)\\              ";
        j->image[3] = ".                   ( \\/M\\/ )            ";
        j->image[4] = " '.               _.'-/'-'\\-'._           ";
        j->image[5] = "   ':           _/.--'[[[[]'--.\\_         ";
        j->image[6] = "     ':        /_'  : |::\"| :  '.\\       ";
        j->image[7] = "       ':     //   ./ |oUU| \.'  :\\       ";
        j->image[8] = "         ':  _:'..' \\_|___|_/ :   :|      ";
        j->image[9] = "           ':.  .'  |_[___]_|  :.':\\      ";
        j->image[10] = "            [::\\ |  :  | |  :   ; : \\   ";
        j->image[11] = "             '-'   \\/'.| |.' \\  .;.' |  ";
        j->image[12] = "             |\\_    \\  '-'   :       |  ";
        j->image[13] = "             |  \\    \\ .:    :   |   |  ";
        j->image[14] = "             |   \\    | '.   :    \\  |  ";
        j->image[15] = "             /       \\   :. .;       |   ";
        j->image[16] = "            /     |   |  :__/     :  \\\\ ";
        j->image[17] = "           |  |   |    \\:   | \\   |   ||";
        j->image[18] = "          /    \\  : :  |:   /  |__|   /| ";
        j->image[19] = "          |     : : :_/_|  /'._\\  '--|_\\";
        j->image[20] = "          /___.-/_|-'   \\  \\            ";
        j->image[21] = "                         '-'              ";
        j->imgHeight = 22;
        break;
    case 4:
        /* code */
        break;

    default:
        initPlayerImage(j);
        break;
    }
}

