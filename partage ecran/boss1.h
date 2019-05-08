#ifndef BOSS1_INCLUDED
#define BOSS1_INCLUDED

#include "clock.h"
typedef struct 
{
SDL_Rect pos,trashpos;
SDL_Surface *img,*trashimg;
int testattack1;
int tempactuel,tempactuel2;
int tempprecedent;
float angle;
int randy[4];
int start;

}boss1;


boss1 init_boss1(boss1 b);
boss1 init_boss11(boss1 b);

boss1 gestion_boss1(SDL_Rect perso,boss1 b,SDL_Rect camera);
boss1 gestion_boss11(SDL_Rect perso,boss1 b,SDL_Rect camera);

boss1 attack1(boss1 b);
boss1 attack11(boss1 b);

boss1 attack2(boss1 b,int test);
boss1 attack22(boss1 b,int test);


void afficher_boss1(boss1 b,SDL_Surface *screen);
void afficher_boss11(boss1 b,SDL_Surface *screen);

#endif
