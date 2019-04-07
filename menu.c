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


SDL_Surface* openwindow(SDL_Surface *ecran)
{

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
TTF_Init();

SDL_WM_SetCaption("527A",NULL);

ecran=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); 
return ecran;

}

		image_menu init_menu(image_menu image,int j,char schema[500],int vitesse,char format[10])
{
image.nb=j;
int i;
image.vitesse=vitesse;

for(i=1;i<=j;i++)
{
strcpy(image.schema[i],schema);
printf("%s \n i=%d",image.schema[i],i);
}
strcpy(image.format,format);

return image;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void afficher_menu(image_menu image,SDL_Surface *ecran)
{
SDL_Surface *Menu_[1200];
int j;
char menu[500];

for (j=0; j<=image.nb; j+=image.vitesse)
{
//strcpy(menu,load_menu(image,j));
sprintf(menu,"%s/%d.%s",image.schema[j],j,image.format);

					Menu_[j]=IMG_Load(menu);
Menu_[j]=rotozoomSurface(Menu_[j],0,0.46875,0.5);
					SDL_BlitSurface(Menu_[j],NULL,ecran,NULL);
                                        SDL_Flip(ecran);
  SDL_FreeSurface(Menu_[j]);
printf("image %s loaded \n",menu);


} 

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		boutton init_boutton(boutton b,char schema[500],float x,float y)
{
b.rect.x=x;
b.rect.y=y;
strcpy(b.schema,schema);
return b;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		SDL_Surface* afficher_boutton(boutton b,SDL_Surface *ecran)
{
SDL_Surface *boutton;
boutton=IMG_Load(b.schema);
SDL_BlitSurface(boutton,NULL,ecran,&b.rect);
SDL_Flip(ecran);
return boutton;
}


/////////////////////////////////////////////////////////////////////////////


		void afficher_loading(image_menu image,SDL_Surface *ecran)
{
SDL_Surface *Menu_[350],*bouton;
int j;
char menu[400];
boutton fixloading;
fixloading=init_boutton(fixloading,"/home/mypowaa/Desktop/Menu-Bus/affiche23.png",0,0);
bouton=IMG_Load(fixloading.schema);
for (j=0; j<=image.nb; j+=image.vitesse)
{


//strcpy(menu,load_menu(image,j));
sprintf(menu,"%s/%d.%s",image.schema[j],j,image.format);

					Menu_[j]=IMG_Load(menu);

SDL_BlitSurface(bouton,NULL,ecran,NULL);
					SDL_BlitSurface(Menu_[j],NULL,ecran,NULL);
                                        SDL_Flip(ecran);

  SDL_FreeSurface(Menu_[j]);
printf("image %s loaded \n",menu);


} 

}
///////////////////////////////////////////////////////////////////////////////////////////////
// ****************************************INTROO ******************************


void intro(image_menu logo,image_menu debut,image_menu affiche,image_menu loading,SDL_Surface *ecran)
{

//son
Mix_Music *logomusic;

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }

logomusic =Mix_LoadMUS("sound/logo.mp3");//chargement de la musique
                Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
                Mix_PlayMusic(logomusic,0);

//////////
logo=init_menu(logo,142,"/home/mypowaa/Desktop/Menu-Bus/logo",3,"jpg");
afficher_menu(logo,ecran);

/////////////
 Mix_PauseMusic();
                Mix_FreeMusic(logomusic);

/////////////////////


debut=init_menu(debut,315,"/home/mypowaa/Desktop/Menu-Bus/debut",3,"jpg");
afficher_menu(debut,ecran);


affiche=init_menu(affiche,23,"/home/mypowaa/Desktop/Menu-Bus/affiche",2,"jpg");
afficher_menu(affiche,ecran);


loading=init_menu(loading,285,"/home/mypowaa/Desktop/Menu-Bus/loading",3,"png");
afficher_loading(loading,ecran);

}


////////////////////////////////////////////
int input_menu(int i,SDL_Event event,int choose,int continuer)
{

if(choose==0)
 switch(event.type)
        {

case SDL_QUIT:
continuer=0;
case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_LEFT: // Flèche gauche
if(i<3)
i++;
break;

  case SDLK_RIGHT: // Flèche dropte
if(i>1)
i--;   
break;

 case SDLK_RETURN:
choose=1;         
break;
}}
if(continuer==0)
return -1;
else if(choose==1)
return 100;
else
return i;
}


//////////////////////////////////////////////////////////
int update_menu(int input,int i,SDL_Surface *ecran)
{
image_menu goingsetting,start,setting,exit;
boutton sstart,sseting,sexit;
SDL_Surface *b;
	if(input==-1)
{
SDL_Quit();
return -1;
}
	else if(input==100)
{
switch(i)
{
case 1:
start=init_menu(start,61,"/home/mypowaa/Desktop/Menu-Bus/play",2,"jpg");
afficher_menu(start,ecran);
return 1000;
break;

case 2:
 setting=init_menu(setting,61,"/home/mypowaa/Desktop/Menu-Bus/settings",2,"jpg");
afficher_menu(setting,ecran);
//////////////////////////////////////////////////
//moving to seeting

int j=0;
char menu[800];
SDL_Surface *Menu_[900];
for (j=0; j<=840; j+=4)
{
sprintf(menu,"/home/mypowaa/Desktop/baha/entry-to-settings/Composition1/%d.jpg",j);
					Menu_[j]=IMG_Load(menu);
Menu_[j]=rotozoomSurface(Menu_[j],0,0.46875,0.5);
					SDL_BlitSurface(Menu_[j],NULL,ecran,NULL);
                                        SDL_Flip(ecran);
SDL_FreeSurface(Menu_[j]);
}


///////////////////////////////////////////////////////////
break;


case 3:
exit=init_menu(exit,35,"/home/mypowaa/Desktop/Menu-Bus/exit",2,"png");
afficher_menu(exit,ecran);
return -1000;

break;
}
return -1;}

	else
{
i=input;
switch(i)
{
case 1:
sstart=init_boutton(sstart,"/home/mypowaa/Desktop/Menu-Bus/startclavier.png",0,0);
b=afficher_boutton(sstart,ecran);
SDL_FreeSurface(b);

break;

case 2:
sseting=init_boutton(sseting,"/home/mypowaa/Desktop/Menu-Bus/settingsclavier.png",0,0);
b=afficher_boutton(sseting,ecran);
SDL_FreeSurface(b);

break;


case 3:
sexit=init_boutton(sexit,"/home/mypowaa/Desktop/Menu-Bus/exitclavier.png",0,0);
b=afficher_boutton(sexit,ecran);
SDL_FreeSurface(b);
break;
}
return i;
}

}

void bouttons(boutton logofb,boutton soundon,boutton soundoff,SDL_Surface *ecran)
{

logofb=init_boutton(logofb,"/home/mypowaa/Desktop/Menu-Bus/fb.png",0,0);
afficher_boutton(logofb,ecran);

soundon=init_boutton(soundon,"/home/mypowaa/Desktop/Menu-Bus/soundon.png",0,0);
afficher_boutton(soundon,ecran);

soundoff=init_boutton(soundoff,"/home/mypowaa/Desktop/Menu-Bus/soundoff.png",0,0);
afficher_boutton(soundoff,ecran);
}








