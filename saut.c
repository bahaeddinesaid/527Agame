#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "saut.h"
#define STAT_SOL 0
#define STAT_AIR 1



void InitSprite(Sprite* Sp)
{
	Sp->x = 320;
	Sp->y = 280;
	Sp->status = STAT_SOL;
	Sp->vx = Sp->vy = 0.0f;
}

void Render(Sprite* Sp,SDL_Surface* screen)
{
	SDL_Rect R;
	R.x = (Sint16)Sp->x;
	R.y = (Sint16)Sp->y;
	/*R.w = 20;
	R.h = 40;
	SDL_FillRect(screen,&R,SDL_MapRGB(screen->format,0,255,0));*/
        SDL_Surface *perso=NULL;
        perso=IMG_Load("detective.png");
        SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 255, 255, 255));
        SDL_BlitSurface(perso,NULL,screen,&R);
}

void Saute(Sprite* Sp,float impulsion)
{
	Sp->vy = -impulsion;
	Sp->status = STAT_AIR;
}

void ControleSol(Sprite* Sp)
{
	if (Sp->y>280.0f && Sp->y<300.0f)
	{
		Sp->y = 280.0f;
		if (Sp->vy>0)
			Sp->vy = 0.0f;
		Sp->status = STAT_SOL;
	}

		if (Sp->y>420.0f && Sp->y)
	{
		Sp->y = 420.0f;
		if (Sp->vy>0)
			Sp->vy = 0.0f;
		Sp->status = STAT_SOL;
	}
}

void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys)
{
	if (Sp->status == STAT_AIR /*&& keys[SDLK_SPACE]*/)
		factgravite/=factsautmaintenu;
	Sp->vy += factgravite;
}

int Evolue(Sprite* Sp,Uint8* keys,int jump)
{
//0.5
	float lateralspeed = 5.0f;
//0.5
	float airlateralspeedfacteur = 5.0f;
//3
	float maxhspeed = 8.0f;
	float adherance = 1.5f;
	float impulsion = 6.0f;
	float factgravite = 1.5f;
	float factsautmaintenu = 3.0f;
// controle lateral
	if (Sp->status == STAT_AIR) // (*2)
		lateralspeed*= airlateralspeedfacteur;
	if (keys[SDLK_LEFT]) // (*1)
		Sp->vx-=lateralspeed;
	else if (keys[SDLK_RIGHT])
		Sp->vx+=lateralspeed;
 
	if (Sp->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
		Sp->vx/=adherance;
// limite vitesse
	if (Sp->vx>maxhspeed) // (*4)
		Sp->vx = maxhspeed;
	if (Sp->vx<-maxhspeed)
		Sp->vx = -maxhspeed;
// saut
	if (/*keys[SDLK_SPACE] &&*/ Sp->status == STAT_SOL)
		{Saute(Sp,impulsion);
		jump=0;}
	Gravite(Sp,factgravite,factsautmaintenu,keys);
	ControleSol(Sp);
// application du vecteur à la position.
	Sp->x +=Sp->vx;
	Sp->y +=Sp->vy;
return jump;
}
