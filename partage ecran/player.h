#ifndef PLAYER_H
#define PLAYER_H
#include"saut.h"
typedef struct 
{

SDL_Surface *tab[13];
SDL_Rect pos;
SDL_Rect fix;
int jumpin;
int moving;
float vitesse;
float acceleration;
	float velocity;
int tempsactuel;
Uint32 dt;


}player;

player  init_player(player p);
player  init_player2(player p);

void animation_player(int move,player p,SDL_Surface *ecran,Sprite* Sp,int input);

void free_player(player p);
int sprite_perso(int i,int input,SDL_Surface *screen,Sprite* Sp,player perso);
int deplacementvirtuel(int input,player perso);
player deplacementreel(int input,player perso,Sprite *Sp,Uint8* keys);
int deplacementvirtuel2(int input,player perso);
player deplacementreel2(int input,player perso,Sprite *Sp,Uint8* keys);


#endif
