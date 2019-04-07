#ifndef PLAYER_H
#define PLAYER_H

typedef struct 
{
SDL_Surface *tab[13];
SDL_Rect pos;
SDL_Rect fix;
}player;

player  init_player(player p);

void animation_player(int move,player p,SDL_Surface *ecran );

void free_player(player p);
int sprite_perso(int i,int input,SDL_Surface *screen,player perso);
int deplacementvirtuel(int input,player perso);
player deplacementreel(int input,player perso);



#endif
