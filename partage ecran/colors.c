#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"clock.h"
#include"colors.h"

int gestion_colors(SDL_Surface *screen,int k,tempss temp,char schema[50],char ex[20],int taswira,int boucle)
{
    temp.tempactuel = SDL_GetTicks();
        if (temp.tempactuel - temp.tempprecedent >=33.333)
        {
char colorch[50];
SDL_Surface *colors;
if(k<=taswira)
k++;
else if(k>taswira && boucle==1)
k=0;
if(boucle==0 && (k>=taswira || k==-1) )
k=-1;

if(k!=-1)
{
sprintf(colorch,"%s/%d.%s",schema,k,ex);
colors=IMG_Load(colorch);
SDL_SetAlpha(colors, SDL_SRCALPHA,110);
SDL_BlitSurface(colors,NULL,screen,NULL);
SDL_FreeSurface(colors);
}


}
temp.tempprecedent=temp.tempactuel;
//printf("k=%d boucle=%d\n",k,boucle);
return k;


}

int gestion_colors2(SDL_Surface *screen,int k,tempss temp,char schema[50],char ex[20],int taswira,int boucle)
{SDL_Rect  pos;
	pos.x=900;
	pos.y=0;
    temp.tempactuel = SDL_GetTicks();
        if (temp.tempactuel - temp.tempprecedent >=33.333)
        {
char colorch[50];
SDL_Surface *colors;
if(k<=taswira)
k++;
else if(k>taswira && boucle==1)
k=0;
if(boucle==0 && (k>=taswira || k==-1) )
k=-1;

if(k!=-1)
{
sprintf(colorch,"%s/%d.%s",schema,k,ex);
colors=IMG_Load(colorch);
SDL_SetAlpha(colors, SDL_SRCALPHA,110);
SDL_BlitSurface(colors,NULL,screen,&pos);
SDL_FreeSurface(colors);
}


}
temp.tempprecedent=temp.tempactuel;
//printf("k=%d boucle=%d\n",k,boucle);
return k;


}

int run(SDL_Surface *screen,int k,char schema[50],char ex[20],int taswira)
		

		{
SDL_Rect  pos;
	pos.x=900;
	pos.y=0;
char colorch[50];
SDL_Surface *colors;
if(k<=taswira)
	{k+=2;

{
sprintf(colorch,"%s/%d.%s",schema,k,ex);
colors=IMG_Load(colorch);
//SDL_SetAlpha(colors, SDL_SRCALPHA,110);
SDL_BlitSurface(colors,NULL,screen,NULL);
//SDL_BlitSurface(colors,NULL,screen,&pos);

SDL_FreeSurface(colors);
}






	}
return k;


		}


int run2(SDL_Surface *screen,int k,char schema[50],char ex[20],int taswira)
		{
SDL_Rect  pos;
	pos.x=900;
	pos.y=0;
char colorch[50];
SDL_Surface *colors;
if(k<=taswira)
	{k+=2;

{
sprintf(colorch,"%s/%d.%s",schema,k,ex);
colors=IMG_Load(colorch);
//SDL_SetAlpha(colors, SDL_SRCALPHA,110);
SDL_BlitSurface(colors,NULL,screen,&pos);
SDL_FreeSurface(colors);
}






	}
return k;


		}