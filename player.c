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

void initPlayerImage(joueur *j) {

    int choice = 0;

    printf("Choississez votre personnage : \n");
    printf("1 - Batman\n");
    printf("2 - Superman\n");
    printf("3 - Darth Vader\n");
    
    scanf("%d",&choice);

    switch (choice) {
    case 1:
        j->image = malloc(sizeof(char*)*25);
        j->image[0] = "           |    |              _.-7            ";
        j->image[1] = "           |\\.-.|             ( ,(_           ";
        j->image[2] = "           | a a|              \\  \\,         ";
        j->image[3] = "           ) [\"||          _.--' \\  \\\\     ";
        j->image[4] = "        .-'  '-''-..____.-'    ___)  )\\       ";
        j->image[5] = "       F   _/-``-.__;-.-.--`--' . .' \\_L_     ";
        j->image[6] = "      |   l  {~~} ,_\\  '.'.      ` __.' )\\   ";
        j->image[7] = "      (    -.;___,;  | '- _       :__.'( /     ";
        j->image[8] = "      | -.__ _/_.'.-'      '-._ .'      \\\\   ";
        j->image[9] = "      |     .'   |  -- _                 '\\,  ";
        j->image[10] = "      |  \\ /--,--{ .    '---.__.       .'  .'";
        j->image[11] = "      J  ;/ __;__]. '.-.            .-' )_/   ";
        j->image[12] = "      J  (-.     '\\'. '. '-._.-.-'--._ /     ";
        j->image[13] = "      |  |  '. .' | \\' '.    ._       \\     ";
        j->image[14] = "      |   \\   T   |  \\  '. '._  '-._    '.  ";
        j->image[15] = "      F   J   |   |  '.    .  '._   '-,_.--`  ";
        j->image[16] = "      F   \\   \\   F .  \\    '.   '.  /     ";
        j->image[17] = "     J     \\  |  J   \\  '.   '.    '/       ";
        j->image[18] = "     J      '.L__|    .   \\    '    |        ";
        j->image[19] = "     |   .    \\  |     \\   '.   '. /        ";
        j->image[20] = "     |    '    '.|      |    ,-.  (           ";
        j->image[21] = "     F   | ' ___  ',._   .  /   '. \\         ";
        j->image[22] = "     F   (.'`|| (-._\\ '.  \\-      '-\\      ";
        j->image[23] = "     \\ .-'  ( L `._ '\\ '._ (                ";
        j->image[24] = "     /'  |  /  '-._\\      ''\\               ";
        j->imgHeight = 25;
        break;
    case 2:
        j->image = malloc(sizeof(char*)*18);
        j->image[0] = "            .=.                 ";
        j->image[1] = "           ;c =\\               ";
        j->image[2] = "         __|  _/                ";
        j->image[3] = "       .'-'-._/-'-._            ";
        j->image[4] = "      /..   ____    \\          ";
        j->image[5] = "     /' _  [<_->] )  \\         ";
        j->image[6] = "    (  / \\--\\_>/-/'._ )       ";
        j->image[7] = "     \\-;_/\\__;__/ _/ _/       ";
        j->image[8] = "      '._}|==o==\\{_\\/         ";
        j->image[9] = "       /  /-._.--\\  \\_        ";
        j->image[10] = "      // /   /|   \\ \\ \\     ";
        j->image[11] = "     / | |   | \\;  |  \\ \\   ";
        j->image[12] = "    / /  | :/   \\: \\   \\_\\ ";
        j->image[13] = "   /  |  /.'|   /: |    \\ \\  ";
        j->image[14] = "   |  |  |--| . |--|     \\_\\ ";
        j->image[15] = "   / _/   \\ | : | /___--._) \\";
        j->image[16] = "  |_(---'-| >-'-| |       '-'  ";
        j->image[17] = "         /_/     \\_\\         ";
        j->imgHeight = 18;
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
        j->image[7] = "       ':     //   ./ |oUU| \\.'  :\\      ";
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
    default:
        printf("Choix invalide\n");
        printf("Fin du programme\n");
        exit(0);
        break;
    }
}


void createJoueur(struct joueur *a, char* nom, int vie, int puissance){
    initPlayerImage(a);
    a->nom = nom;
    a->vieMax = vie;
    a->vie = a->vieMax;
    a->puissance = puissance;
}


