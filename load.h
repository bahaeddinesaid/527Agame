#ifndef LOAD_INCLUDED
#define LOAD_INCLUDED
#include "menu.h"
#include"player.h"
//image_menu init_menu(image_menu image,int j,char schema[500],int vitesse,char format[10]);
void afficher_looading(image_menu image,SDL_Surface *ecran);
void afficher_bonus(image_menu image,SDL_Surface *ecran,SDL_Surface *fond,SDL_Rect camera,player perso,char sfx[50]);
void backsound(char sfx[50],int x1,int x2,int pos);
#endif
