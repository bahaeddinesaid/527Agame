#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include"minimap.h"

minimap init_minimap(SDL_Surface *map)
{
minimap mm;
mm.pos.x=380;
mm.pos.y=20;
mm.p.pos.x=380;
mm.p.pos.y=20;
mm.image=rotozoomSurface(map,0,0.03,0.03);
mm.p.image=IMG_Load("PICS/cursor/1.png");
mm.p.image=rotozoomSurface(mm.p.image,0,0.5,1);
return mm;

}



minimap gestion_minimap(minimap mm,SDL_Surface *screen,SDL_Rect camera)
{
mm.p.pos.x=380+((camera.x +320)* 0.03);
SDL_BlitSurface(mm.image,NULL,screen,&mm.pos);
SDL_BlitSurface(mm.p.image,NULL,screen,&mm.p.pos);
return mm;

}
