#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct monstre {
    int vie;
    int vieMax;
    int pMax;
    int pMin;
    int def;
    char **image;
    int imgHeight;
}monstre;


void initMonsterImage(monstre *m){

    int x = (rand() % 10 )+ 1;
    
    switch (x) {
    case 1:
        m->image = malloc(sizeof(char*) * 15);
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
        m->imgHeight = 15;
        break;
    case 2:
        m->image = malloc(sizeof(char*) * 17);
        m->image[0] = "     .-----.        ";
        m->image[1] = "   .' -   - '.      ";
        m->image[2] = "  /  .-. .-.  \\    ";
        m->image[3] = "  |  | | | |  |     ";
        m->image[4] = "   \\ \\o/ \\o/ /   ";
        m->image[5] = "  _/    ^    \\_    ";
        m->image[6] = " | \\  '---'  / |   ";
        m->image[7] = " / /`--. .--`\\ \\  ";
        m->image[8] = "/ /'---` `---'\\ \\ ";
        m->image[9] = "'.__.       .__.'   ";
        m->image[10] = "    `|     |`      ";
        m->image[11] = "     |     \\      ";
        m->image[12] = "     \\      '--.  ";
        m->image[13] = "      '.        `\\";
        m->image[14] = "        `'---.   | ";
        m->image[15] = "           ,__) /  ";
        m->image[16] = "            `..'   ";
        m->imgHeight = 17;
        break;
    case 3:
        m->image = malloc(sizeof(char*) * 21);
        m->image[0] = "     .      .                    ";
        m->image[1] = "     |\\____/|                   ";
        m->image[2] = "    (\\|----|/)                  ";
        m->image[3] = "     \\ 0  0 /                   ";
        m->image[4] = "      |    |                     ";
        m->image[5] = "   ___/\\../\\____               ";
        m->image[6] = "  /     --       \\              ";
        m->image[7] = " /  \\         /   \\            ";
        m->image[8] = "|    \\___/___/(   |             ";
        m->image[9] = "\\   /|  }{   | \\  )            ";
        m->image[10] = " \\  ||__}{__|  |  |            ";
        m->image[11] = "  \\  |;;;;;;;\\  \\ / \\_______";
        m->image[12] = "   \\ /;;;;;;;;| [,,[|======'   ";
        m->image[13] = "     |;;;;;;/ |     /           ";
        m->image[14] = "     ||;;|\\   |                ";
        m->image[15] = "     ||;;/|   /                 ";
        m->image[16] = "     \\_|:||__|                 ";
        m->image[17] = "      \\ ;||  /                 ";
        m->image[18] = "      |= || =|                  ";
        m->image[19] = "      |= /\\ =|                 ";
        m->image[20] = "      /_/  \\_\\                ";
        m->imgHeight = 21;
        break;
    case 4:
        m->image = malloc(sizeof(char*) * 9);
        m->image[0] = "   ,    ,    /\\   /\\         ";
        m->image[1] = "  /( /\\ )\\  _\\ \\_/ /_      ";
        m->image[2] = "  |\\_||_/| < \\_   _/ >       ";
        m->image[3] = "  \\______/  \\|0   0|/        ";
        m->image[4] = "    _\\/_   _(_  ^  _)_        ";
        m->image[5] = "   ( () ) /`\\|V\"\"\"V|/`\\   ";
        m->image[6] = "     {}   \\  \\_____/  /       ";
        m->image[7] = "     ()   /\\   )=(   /\\      ";
        m->image[8] = "     {}  /  \\_/\\=/\\_/  \\   ";
        m->imgHeight = 9;
        break;
    case 5:
        m->image = malloc(sizeof(char*) * 10);
        m->image[0] = "               /'.    .'\\               ";
        m->image[1] = "               \\( \\__/ )/              ";
        m->image[2] = "         ___   / (.)(.) \\   ___         ";
        m->image[3] = "    _.-\"`_  `-.|  ____  |.-`  _`\"-._   ";
        m->image[4] = " .-'.-'//||`'-.\\  V--V  /.-'`||\\'-.'-. ";
        m->image[5] = "`'-'-.// ||    / .___.  \\    || \\.-'-'`";
        m->image[6] = "      `-.||_.._|        |_.._||.-'       ";
        m->image[7] = "               \\ ((  )) /               ";
        m->image[8] = "                '.    .'                 ";
        m->image[9] = "                  `\\/`                  ";
        m->imgHeight = 10;
        break;    
    case 6:
        m->image = malloc(sizeof(char*) * 21);
        m->image[0] = "              (      )               ";
        m->image[1] = "              ~(^^^^)~               ";
        m->image[2] = "               ) @@ \\~_          |\\";
        m->image[3] = "              /     | \\        \\~ /";
        m->image[4] = "             ( 0  0  ) \\        | | ";
        m->image[5] = "              ---___/~  \\       | | ";
        m->image[6] = "               /'__/ |   ~-_____/ |  ";
        m->image[7] = "o          _   ~----~      ___---~   ";
        m->image[8] = "  O       //     |         |         ";
        m->image[9] = "         ((~\\  _|         -|        ";
        m->image[10] = "   o  O //-_ \\/ |        ~  |      ";
        m->image[11] = "        ^   \\_ /         ~  |      ";
        m->image[12] = "               |          ~ |       ";
        m->image[13] = "               |     /     ~ |      ";
        m->image[14] = "               |     (       |      ";
        m->image[15] = "                \\     \\      /\\  ";
        m->image[16] = "               / -_____-\\   \\ ~~-*";
        m->image[17] = "               |  /       \\  \\    ";
        m->image[18] = "               / /         / /      ";
        m->image[19] = "             /~  |       /~  |      ";
        m->image[20] = "             ~~~~        ~~~~       ";
        m->imgHeight = 21;
        break;
    case 7:
        m->image = malloc(sizeof(char*) * 29);
        m->image[0] = "            |    .' ,^-.               ";
        m->image[1] = "            ;`-./ .'    \\             ";
        m->image[2] = "           _ \\`--'_      \\            ";
        m->image[3] = "         .' .-'`\" '-.     :           ";
        m->image[4] = "       .' ..-'""`T-._.'    ;           ";
        m->image[5] = "       ; //O O  / _         )          ";
        m->image[6] = "       `.; .'   {' )`\"--..-'          ";
        m->image[7] = "7.         :  ;  \'                    ";
        m->image[8] = "`.\\         `{   ;                     ";
        m->image[9] = "  \\`.        7  /;_                    ";
        m->image[10] = "  :[`7.    .=`./   `-,                ";
        m->image[11] = "  `.\\/`5  / /`.`.,   :                ";
        m->image[12] = "   |[//_  `\"|  : \\  |\\.            ";
        m->image[13] = "   {=\\{_)   J :   |`.J :              ";
        m->image[14] = "   {=; |  .'  :   :  `: :`.           ";
        m->image[15] = "   |\"\\ ;j`.  /    |   | ;  j\"\"| :`.";
        m->image[16] = "   `-.';   )':  .-'   :  ;    l/ /    ";
        m->image[17] = "        `-'  `.7  ___ l_.'     `\"    ";
        m->image[18] = "               :-\"//\\`:             ";
        m->image[19] = "               |_.\\//_|              ";
        m->image[20] = "              /j }\"\"\"{ l\\         ";
        m->image[21] = "            ,'/.'     `.\\`.          ";
        m->image[22] = "           }.''   .-.   ``.{          ";
        m->image[23] = "          //    .'   `.    \\\\       ";
        m->image[24] = "         :/    /       \\    \\:      ";
        m->image[25] = "         /    /         \\    \\      ";
        m->image[26] = "        :    /           \\    :      ";
        m->image[27] = "        |   ;             :   |       ";
        m->image[28] = "        ;   |             |   |       ";
        m->imgHeight = 29;
        break;
    case 8:
        m->image = malloc(sizeof(char*) * 17);
        m->image[0] = "              __.......__                  ";
        m->image[1] = "            .-:::::::::::::-.              ";
        m->image[2] = "          .:::''':::::::''':::.            ";
        m->image[3] = "        .:::'     `:::'     `:::.          ";
        m->image[4] = "   .'\\  ::'   ^^^  `:'  ^^^   '::  /`.    ";
        m->image[5] = "  :   \\ ::   _.__       __._   :: /   ;   ";
        m->image[6] = " :     \\`: .' ___\\     /___ `. :'/     ; ";
        m->image[7] = ":       /\\   (_|_)\\   /(_|_)   /\\       ;";
        m->image[8] = ":      / .\\   __.' ) ( `.__   /. \\      ;";
        m->image[9] = ":      \\ (        {   }        ) /      ; ";
        m->image[10] = " :      `-(     .  ^\"^  .     )-'      ; ";
        m->image[11] = "  `.       \\  .'<`-._.-'>'.  /       .'  ";
        m->image[12] = "    `.      \\    \\;`.';/    /      .'   ";
        m->image[13] = "      `._    `-._       _.-'    _.'       ";
        m->image[14] = "       .'`-.__ .'`-._.-'`. __.-'`.        ";
        m->image[15] = "     .'       `.         .'       `.      ";
        m->image[16] = "   .'           `-.   .-'           `.    ";
        m->imgHeight = 17;
        break;
    case 9:
        m->image = malloc(sizeof(char*) * 25);
        m->image[0] = "                                                    __,";
        m->image[1] = "                                       __...---`````_,";
        m->image[2] = "           .-``-.     .-``-......__.-``   _.--``````  ___,";
        m->image[3] = "          ^      :   :               -`````---````````_,";
        m->image[4] = "          ^_      :  :....._                    _.-```";
        m->image[5] = "           |`|-.   `.    o  ``-.__.-`````...````";
        m->image[6] = "                `.   `...__. ,'.___.-```;:'";
        m->image[7] = "                  `._     ; ;        .:'___,";
        m->image[8] = "                     ````` ;        _...--`";
        m->image[9] = "                  __..--```       -```-.";
        m->image[10] = "         .|,|_.-``___....---```````--.._\\";
        m->image[11] = "         `-,,--```     ..---```````--.";
        m->image[12] = "                        `-.          ;).";
        m->image[13] = "                           ;        ;'..)";
        m->image[14] = " __.-`|`-./                ;       ;).        \\.-`/8e.__";
        m->image[15] = "__.   |   .                '      ;'..)       .  (88 8.__";
        m->image[16] = "__:  /|\\  :_           __ ;      ;_          _: 8  )88:__";
        m->image[17] = "   `/_|_\\'/ '-._      / /;      ;) \\     _.-' \\._/8*'";
        m->image[18] = "          '.    ``-._/  |;     ;/   \\_.-``   ,'      ";
        m->image[19] = "            `-.          \\;    ;\\         ,-'";
        m->image[20] = "               `-._     /  ;   ; \\     ,-'";
        m->image[21] = "                   `.__/    ;  ;  \\__,'";
        m->image[22] = "                             ; ;)`.";
        m->image[23] = "                              ;'..)";
        m->image[24] = "                               ;";
        m->imgHeight = 25;
        break;
    case 10:
        m->image = malloc(sizeof(char*) * 19);
        m->image[0] = "              ,,))))))));,";
        m->image[1] = "           __))))))))))))))";
        m->image[2] = " \\|/       -\\(((((''''((((((((.";
        m->image[3] = " -*-==//////((''  .     `))))))";
        m->image[4] = " /|\\      ))| o    ;-.    '(((((                                  ,(,";
        m->image[5] = "         ( `|    /  )    ;))))'                               ,_))^;(~";
        m->image[6] = "            |   |   |   ,))((((_     _____------~~~-.        %,;(;(>';'~";
        m->image[7] = "            o_);   ;    )))(((` ~---~  `::           \\      %%~~)(v;(`('~";
        m->image[8] = "                  ;    ''''````         `:       `:::|\\,__,%%    );`'; ~";
        m->image[9] = "                 |   _                )     /      `:|`----'     `-'";
        m->image[10] = "           ______/\\/~    |                 /        /";
        m->image[11] = "         /~;;.____/;;'  /          ___--,-(   `;;;/";
        m->image[12] = "        / //  _;______;'------~~~~~    /;;/\\    /";
        m->image[13] = "       //  | |                        / ;   \\;;,\\";
        m->image[14] = "      (<_  | ;                      /',/-----'  _>";
        m->image[15] = "       \\_| ||_                     //~;~~~~~~~~~";
        m->image[16] = "           `\\_|                   (,~~";
        m->image[17] = "                                   \\~\\";
        m->image[18] = "                                    ~~";
        m->imgHeight = 19;
        break;
    }


}

void createMonstres( monstre *a, int nbMonstre, monstre* monstres){
    // Initialise les monstres avec des statistiques aléatoires
    for(int i = 0; i < nbMonstre; i++){
        initMonsterImage(a);
        a->vieMax = rand() % 100;
        a->vie = a->vieMax;
        a->pMax = rand() % 5;
        a->pMin = rand() % a->pMax;
        a->def = rand() % 100;
        monstres[i] = *a; // Stock les monstres dans le tableau monstres
    }
}

void deleteMonster(int index, int *nbMonstre, monstre* monstres){
    for (int i = index; i <= *nbMonstre - 1; i++) {
        monstres[i] = monstres[i + 1];
    }
    nbMonstre--;
    realloc(monstres, (size_t)(nbMonstre) * sizeof(monstre));
}
