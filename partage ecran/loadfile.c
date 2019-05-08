#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "svld.h"









void load (player *p, tempss *temp , SDL_Rect *camera,vie *v,int done)
{

FILE *f=NULL;
f=fopen("jeux.txt","r+");

fscanf(f,"%hd %hd %hd %hd %d %d %d %d   ",&(*p).pos.x,&(*p).pos.y,&(*camera).x,&(*camera).y,&(*temp).seconde1,&(*temp).minute1,&(*temp).heur1,&(*v).val);

printf("%hd %hd %hd %hd %d %d %d %d   ",(*p).pos.x,(*p).pos.y,(*camera).x,(*camera).y,(*temp).seconde1,(*temp).minute1,(*temp).heur1,(*v).val);
fclose(f);

}
				

