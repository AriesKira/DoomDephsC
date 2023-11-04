#ifndef FIGHTS_H 
#define FIGHTS_H

#define INVENTORY_SPACE j->inventory->armors[0].inventorySpace
#define UTILITIES_CAPACITY j->inventory->bags[0].utilitySpace
#define PLAYER_MAX_DMG j->inventory->weapons[0].dmgMax
#define PLAYER_MIN_DMG j->inventory->weapons[0].dmgMin
#define PLAYER_DEF j->inventory->armors[0].def
#define PLAYER_HP j->vie
#define PLAYER_MAX_HP j->vieMax
#define PLAYER_ACTIONS j->inventory->weapons[0].actions
#define PLAYER_NAME j->name
#define PLAYER_CURRENT_WEAPON j->inventory->weapons[0]
#define PLAYER_CURRENT_ARMOR j->inventory->armors[0]
#define PLAYER_CURRENT_BAG j->inventory->bags[0]

//Target monster
#define MONSTER_NAME monstres[target].name
#define MONSTER_MAX_HP monstres[target].vieMax
#define MONSTER_HP monstres[target].vie
#define MONSTER_MAX_DMG monstres[target].inventory->weapons[0].dmgMax
#define MONSTER_MIN_DMG monstres[target].inventory->weapons[0].dmgMin
#define MONSTER_DEF monstres[target].inventory->armors[0].def
#define MONSTER_NAME monstres[target].name
#define MONSTER_IMAGE monstres[target].image
#define MONSTER_ARMOR monstres[target].inventory->armors[0].name
#define MONSTER_WEAPON monstres[target].inventory->weapons[0].name
#define MONSTER_BAG monstres[target].inventory->bags[0].name

//Monster turn
#define PLAYING_MONSTER_MAX_DMG monstres[attacker].inventory->weapons[0].dmgMax
#define PLAYING_MONSTER_MIN_DMG monstres[attacker].inventory->weapons[0].dmgMin
#define PLAYING_MONSTER_DEF monstres[attacker].inventory->armors[0].def
#define PLAYING_MONSTER_HP monstres[attacker].vie
#define PLAYING_MONSTER_MAX_HP monstres[attacker].vieMax
#define PLAYING_MONSTER_NAME monstres[attacker].name
#define PLAYING_MONSTER_IMAGE monstres[attacker].image
#define PLAYING_MONSTER_ARMOR monstres[attacker].inventory->armors[0].name
#define PLAYING_MONSTER_WEAPON monstres[attacker].inventory->weapons[0].name
#define PLAYING_MONSTER_BAG monstres[attacker].inventory->bags[0].name


int finalDamage(int maxDmg, int minDmg, int def);
int fight(monstre* monstres,int nbMonstre,joueur* j);

#endif