#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "player.h"
#include <string.h>
#include "clock.h"
#include "svld.h"
#include "vie.h"
#include "score.h"







void save (player p, tempss temp , SDL_Rect camera,vie v,int done1,int done2,int done3,int done4)
{
sav s;


s.pos.x=p.pos.x;
s.pos.y=p.pos.y;
s.camera.x=camera.x;
s.camera.y=camera.y;
s.s1=temp.seconde1;
s.m1=temp.minute1;
s.h1=temp.heur1;
s.vie=v.val;

FILE *f=NULL;
f=fopen("jeux.txt","w");
if(f!=NULL)
{
fprintf(f,"%d %d %d %d %d %d %d %d %d %d %d ",s.pos.x,s.pos.y,s.camera.x,s.camera.y,s.s1,s.m1,s.h1,done1,done2,done3,done4);
fclose(f);
}



}




