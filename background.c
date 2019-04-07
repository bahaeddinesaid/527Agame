#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL.h"
#include"SDL/SDL_ttf.h"
#include"background.h"
#include"enigme1.h"
#include"enigme2.h"
#include"enigme3.h"
#include <time.h>
#include"clock.h"
#include"score.h"
#include"player.h"
#include "menu.h"
#include "load.h"
#include"player.h"

/*SDL_Surface* openwindow(SDL_Surface *screen)
{

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
TTF_Init();

SDL_WM_SetCaption("527A",NULL);

screen=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); 
return screen;

}*/



SDL_Surface* init_background(SDL_Surface *screen,char bg[50])
{
SDL_Surface *stg1;
SDL_Rect camera;


stg1=IMG_Load(bg);





return stg1;

}





int INPUT_STAGE1(SDL_Event event)
{
int input=0;



while(SDL_PollEvent(&event))
{
switch(event.type)
        {

case SDL_QUIT:
input=-1;
return input;
break;
case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_LEFT:
	input=1;
	return input;
	break;
	
	     case SDLK_RIGHT:
	input=2;
	return input;
	break;
	case SDLK_RETURN:
	input=10;
	return input;
	break;

     case SDLK_UP:
	input=4;
	return input;
	break;


     case SDLK_DOWN:
	input=3;
	return input;
	break;
	  }

	}

}



}



int scrolling(SDL_Surface *screen,SDL_Surface *stg1,int input,SDL_Rect camera,SDL_Event event)
{




switch(input)
				{//5

					case 1 :
					printf("pos : %d \n",camera.x);
					if(camera.x>658)
					camera.x-=5;

					break;

                                       case 2 :
					printf("pos : %d \n",camera.x);
					if(camera.x<6720)
					{camera.x+=5;
					}
                                        break;


				}//5

	


//Animation de character 


return camera.x;

}//1








////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void discussion(SDL_Surface *screen,char background[50],char schema[100],char extension[10],char bgformat[10],int nb,SDL_Rect postxt)
{//1
int i=0;
char parole[100],bgchar[100];
SDL_Surface *dis[30];
SDL_Surface *bg;
SDL_Event event;


sprintf(bgchar,"%s.%s",background,bgformat);
bg=IMG_Load(bgchar);
top:
while(i<=nb)
	{//2

i++;
sprintf(parole,"%s%d.%s",schema,i,extension);

					dis[i]=IMG_Load(parole);


					SDL_BlitSurface(bg,NULL,screen,NULL);
					SDL_BlitSurface(dis[i],NULL,screen,&postxt);
                                        SDL_Flip(screen);
//events
while(SDL_WaitEvent(&event))
{//3
switch(event.type)
        {//4

case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {//5
	case SDLK_RETURN:
SDL_FreeSurface(dis[i]);
	goto top;
	break;
	    }//5
          }//4

  
        }//3

}

}//1


/////////////

tempss click(SDL_Surface *screen,SDL_Surface *stg1,SDL_Rect camera,tempss temp2,score scor,int done[],int x,player perso)
{
if(perso.fix.y==280)
{SDL_Surface *txt[10];
SDL_Rect postxt;
Mix_Chunk *sfx;
image_menu bonus,loading;

int o;
//

postxt.y=450;
postxt.x=130;
//
txt[1]=IMG_Load("serveur.png");
txt[2]=IMG_Load("talb-el-rkik.png");
txt[3]=IMG_Load("worker.png");
txt[4]=IMG_Load("zzz.png");
//son
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
//

if(camera.x>=1170 && camera.x<=1280 && done[0]==0)
{
loading=init_menu(loading,75,"loading/",1,"png");
afficher_looading(loading,screen);
discussion(screen,"kahwa","enigme1/D","png","png",4,postxt);
temp2=enigme1(temp2,done);
if(done[0]==1)
{
scor=gestion_score(done[0],done[1],done[2],done[3],scor,screen,x);
discussion(screen,"kahwa","enigme1/S","png","png",2,postxt);
loading=init_menu(loading,75,"loading/",1,"png");
afficher_looading(loading,screen);
bonus=init_menu(bonus,30,"+5000/",1,"png");
afficher_bonus(bonus,screen,stg1,camera,perso,"sound/bonus.wav");
}
}

if(camera.x>=1445 && camera.x<=1500)//ysarbi
{
sfx=Mix_LoadWAV("sound/chicha.wav");
o=1;
}

if(camera.x>=1600 && camera.x<=1630)
{
sfx=Mix_LoadWAV("sound/money.wav");
o=2;
}

if(camera.x>=3225 && camera.x<=3280)
{
sfx=Mix_LoadWAV("sound/building.wav");
o=3;
}
if(camera.x>=3830 && camera.x<=3915)
{
sfx=Mix_LoadWAV("sound/snoring.wav");
o=4;
}


if(camera.x>=2610 && camera.x<=2840 && done[1]==0)
{
loading=init_menu(loading,75,"loading/",1,"png");
afficher_looading(loading,screen);
discussion(screen,"img/BG","enigme2/D","png","png",11,postxt);
temp2=enigme2(temp2,done);
if(done[1]==1)
{
scor=gestion_score(done[0],done[1],done[2],done[3],scor,screen,x);
discussion(screen,"img/BG","enigme2/S","png","png",1,postxt);
bonus=init_menu(bonus,30,"+5000/",1,"png");
afficher_bonus(bonus,screen,stg1,camera,perso,"sound/bonus.wav");
}

loading=init_menu(loading,75,"loading/",1,"png");
afficher_looading(loading,screen);

}
if(camera.x>=4340 && camera.x<=4395 && done[2]==0)
{
loading=init_menu(loading,75,"loading/",1,"png");
afficher_menu(loading,screen);
discussion(screen,"enigme3/Hfond","enigme3/D","png","png",7,postxt);
temp2=enigme3(temp2,done);
printf("done2=%d\n",done[2]);
if(done[2]==1)
{
scor=gestion_score(done[0],done[1],done[2],done[3],scor,screen,x);
discussion(screen,"enigme3/Gfond","enigme3/S","png","png",3,postxt);
bonus=init_menu(bonus,30,"+5000/",1,"png");
afficher_bonus(bonus,screen,stg1,camera,perso,"sound/bonus.wav");
}
loading=init_menu(loading,75,"loading/",1,"png");
afficher_looading(loading,screen);
}

if(o<=4 && o>=1)
{
Mix_VolumeChunk(sfx, MIX_MAX_VOLUME/1);
                Mix_PlayChannel(1 ,sfx, 0);
SDL_BlitSurface(txt[o],NULL,screen,&postxt);
SDL_Flip(screen);

SDL_Delay(3000);
Mix_CloseAudio();
}}
return temp2;
}




