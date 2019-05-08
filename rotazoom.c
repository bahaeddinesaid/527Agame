#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "rotazoom.h"

void rozom(double zoom,double angle,SDL_Surface *ecran)
{
SDL_Surface *paysage=NULL,*money=NULL;
money=IMG_Load("img/prix.png");
paysage=rotozoomSurface(money, angle, zoom, 0);
SDL_BlitSurface(paysage,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_FreeSurface (paysage);
SDL_FreeSurface (money);
}
