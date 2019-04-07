#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include "menu.h"
#include "load.h"
#include"player.h"







		void afficher_looading(image_menu image,SDL_Surface *ecran)
{
SDL_Surface *Menu_[350],*bouton;
int j;
char menu[400];
boutton fixloading;

for (j=0; j<=image.nb; j+=image.vitesse)
{


//strcpy(menu,load_menu(image,j));
sprintf(menu,"%s/%d.%s",image.schema[j],j,image.format);

					Menu_[j]=IMG_Load(menu);
					SDL_BlitSurface(Menu_[j],NULL,ecran,NULL);
                                        SDL_Flip(ecran);

  SDL_FreeSurface(Menu_[j]);
printf("image %s loaded \n",menu);


} 
SDL_FreeSurface(*Menu_);

}




////////////////////////////////




		void afficher_bonus(image_menu image,SDL_Surface *ecran,SDL_Surface *fond,SDL_Rect camera,player perso,char sfx[50])
{
SDL_Surface *Menu_[350],*bouton;
int j;
char menu[400];

Mix_Chunk *Sfx;


Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
Sfx=Mix_LoadWAV(sfx);
Mix_VolumeChunk(Sfx, MIX_MAX_VOLUME/1);



Mix_PlayChannel(1 ,Sfx, 0);
for (j=0; j<=image.nb; j+=image.vitesse)
{


//strcpy(menu,load_menu(image,j));
sprintf(menu,"%s/%d.%s",image.schema[j],j,image.format);

					Menu_[j]=IMG_Load(menu);
 

SDL_BlitSurface(fond,&camera,ecran,NULL);
 sprite_perso(13,2,ecran,perso);
					SDL_BlitSurface(Menu_[j],NULL,ecran,NULL);
                                        SDL_Flip(ecran);

  SDL_FreeSurface(Menu_[j]);
printf("image %s loaded \n",menu);


} 

}











