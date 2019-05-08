#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include"warning.h"

warnin init_warning(warnin warn,int x,int y)
{
char ch[50];
int i;

for(i=1;i<=10;i++)
{
sprintf(ch,"warning/%d.png",i);
warn.img[i]=IMG_Load(ch);
//warn.img[i]=rotozoomSurface(warn.img[i],0,0.2,0.5);
}
warn.rect.x=x;
warn.rect.y=y;
warn.nb=1;
warn.playing=0;
warn.x=0;

return warn;

}

warnin gestion(SDL_Rect camera,warnin warn,SDL_Surface *screen,int x,Mix_Chunk *sfx)
{
warn.x=0;
if(warn.nb<=9)
{warn.nb++;
}
//if(warn.nb==2)
                //Mix_PlayChannel(1,sfx,0);
else
warn.nb=1;
if(camera.x+900- x<450 && camera.x+900 - x >0)
{

SDL_BlitSurface(warn.img[warn.nb],NULL,screen,&warn.rect);
warn.x=1;
}
printf("nb=%d\n",warn.nb);

return warn;

}
