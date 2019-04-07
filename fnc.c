#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "fnc.h"


entite_sec entite_initialiser(int pics,entite_sec entite,char schema[50],int y)
{
int i;
char entitee[50];
entite.pics=pics;

entite.rect.x=rand()%2400+900;

//printf("rndm=%d",entite.rect.x);
entite.rect.y=y;
entite.rect.w=467;

for(i=1;i<=pics;i++)
{

sprintf(entitee,"%s/%d.png",schema,i); 

entite.img[i]=IMG_Load(entitee);

}
return entite;
}

int entite_gstion(int i,entite_sec entite)
{
if(i<5)
i++;
return i;
}






entite_sec entite_initialiser2(int pics,entite_sec entite,char schema[50],int y)
{
int i;
char entitee[50];
entite.pics=pics;

entite.rect.x=rand()%2400+2400;

//printf("rndm=%d",entite.rect.x);
entite.rect.y=y;
entite.rect.w=467;

for(i=1;i<=pics;i++)
{

sprintf(entitee,"%s/%d.png",schema,i); 

entite.img[i]=IMG_Load(entitee);

}
return entite;
}













int entite_afficher(SDL_Surface *screen,entite_sec entite,SDL_Rect camera,int i,int vitesse)
{ 
entite.rect.x=entite.rect.x+vitesse;
if(entite.rect.x<=0)
entite.rect.x=6000;
else if(entite.rect.x>=6000)
{entite.rect.x=0;
entite.rect.x-=1000;}
//printf("*karhba=%d\n",entite.rect.x);
//if(entite.rect.x<=-(entite.rect.w+900)+camera.x && entite.rect.x>=+(entite.rect.w+900)+camera.x);
SDL_BlitSurface(entite.img[i],NULL,screen,&entite.rect);
return entite.rect.x;
}


