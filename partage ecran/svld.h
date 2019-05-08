#ifndef SVLD_H
#define SVLD_H
#include <SDL/SDL.h>
#include "vie.h"
#include "score.h"
#include "player.h"
#include "clock.h"
typedef struct 
{
SDL_Rect pos;
SDL_Rect camera;
int vie;
int s1;
int m1;
int h1;

}sav;

void save (player p, tempss temp , SDL_Rect camera,vie v,int done);
void load (player *p, tempss *temp , SDL_Rect *camera,vie *v,int done);



#endif
