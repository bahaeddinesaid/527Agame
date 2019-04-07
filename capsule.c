#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "capsule.h"

int collision(SDL_Rect p,SDL_Rect e)
{
int verif =1;

int ga, gb; int da, db; int ta, tb; int ba, bb;
 
ga = e.x; da = e.x + e.w; ta = e.y; ba = e.y + e.h; 
//Calculate the sides of rect B
gb = p.x; db = p.x + p.w; tb = p.y; bb = p.y + p.h;
//If any of the sides from A are outside of B
if((( ba < tb )||( ta > bb ))||(( da < gb )||( ga > db ) ))
{ verif= 0; }  
return verif;
}
