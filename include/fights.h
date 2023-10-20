#ifndef FIGHTS_H 
#define FIGHTS_H

#define INVENTORY_SPACE j->inventory->armors[0].inventorySpace
#define UTILITIES_CAPACITY j->inventory->bags[0].utilitySpace
#define PLAYER_MAX_DMG j->inventory->weapons[0].dmgMax
#define PLAYER_MIN_DMG j->inventory->weapons[0].dmgMin
#define PLAYER_DEF j->inventory->armors[0].def
#define PLAYER_HP j->vie
#define PLAYER_MAX_HP j->vieMax
#define MONSTER_MAX_HP monstres[index].vieMax
#define MONSTER_HP monstres[index].vie
#define MONSTER_MAX_DMG monstres[index].inventory->weapons[0].dmgMax
#define MONSTER_MIN_DMG monstres[index].inventory->weapons[0].dmgMin
#define MONSTER_DEF monstres[index].inventory->armors[0].def
#define MONSTER_NAME monstres[index].name
#define MONSTER_IMAGE monstres[index].image
#define MONSTER_ARMOR monstres[index].inventory->armors[0].name
#define MONSTER_WEAPON monstres[index].inventory->weapons[0].name
#define MONSTER_BAG monstres[index].inventory->bags[0].name


int finalDamage(int maxDmg, int minDmg, int def);
void fight(monstre* monstres,int nbMonstre,joueur* j);

#endif