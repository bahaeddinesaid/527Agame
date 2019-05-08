#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL.h"
#include"SDL/SDL_ttf.h"
#include"background.h"
#include"math.h"
#include"enigme1.h"
#include"enigme2.h"
#include"enigme3.h"
#include"enigme4.h"
#include <time.h>
#include"clock.h"
#include"menu.h"
#include <SDL/SDL_rotozoom.h>
#include"score.h"
#include"player.h"
#include"vie.h"
#include "entitesec1.h"
#include"collisiontrigo.h"
#include "load.h"
#include "fnc.h"
#include "setting.h"
#include "ai.h"
#include"jeu.h"
#include"svld.h"
#include"minimap.h"
#include"stage2.h"
#include"warning.h"
#include"colors.h"
#include"boss1.h"
#include"players2.h"


int main()


{

SDL_Event event;
SDL_Surface *winscreen,*screen,*stg1; //stg1 surface background
SDL_Rect camera;
char bg[50]="PICS/stage1.png";
int input=0;
Mix_Music *bgmusic;
int stage1done=0,stage2done=0,scorefinale=0;
tempss temp2;
int pause_time_disc=0;
int pause_time_pause=0;
int k=0;
int done[4]={0,0,0,0};
score scor;
vie v;
int loadornewgame=1;
int sprite=0;
double vitesse=0;
int collision=0,collision2=0,collision3=0,collision4=0,collision5=0,collision6=0,collision7=0,collisiontotale=0;
player perso;
objet capsulee;
int seulecol=0;
entite_sec entit_sec,karhba,karhba2,karhba3;
minimap mm;
//

image_menu logo,debut,affiche,loading,level1,gameover;
boutton logofb,soundon,soundoff,fixloading;
int i=0;
int continuer=1;
int pause,choose=0;
settings parametres;

   ennemie e;
Sprite s;
Uint8* keys;

 
    SDL_Rect position;
position.x=3650;
position.y=3550;

//camera
//670
camera.x=2500;
camera.y=0;
camera.w=900;
camera.h=600;
//

//////////////////////////////////////////////////////////////////////////////////

//Ecran
screen=openwindow(screen);

//intro(logo,debut,affiche,loading,screen);

bouttons(logofb,soundon,soundoff,screen);
parametres=initialiser_settings(parametres);
//CHOICE : 
 while (continuer && input!=1000 && input!=-1000)
    {
        SDL_WaitEvent(&event);
input=input_menu(i,event,choose,continuer);
k=update_menu(input,i,screen);
if(k!=-1)
i=k;
}
printf("input = %d \n",input);
if(input==-1000)
{
SDL_Quit();
return 0;}
///

//

if(input==1000)
{

///******************************************************************************************
///					INIT  STAGE1           ****************************************
//load or new game


do
{
input=INPUT_neworload(event);
printf("input = %d \n",input);
loadornewgame=loadornew(input,event,screen,loadornewgame);


}while(input!=10);
///

level1=init_menu(level1,122,"level1/",1,"jpeg");
gameover=init_menu(gameover,29,"gameover/",1,"jpeg");
loading=init_menu(loading,100,"loading/",1,"png");
winscreen=IMG_Load("PICS/win.png");
newgame:
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
bgmusic=Mix_LoadMUS("sound/lvl.mp3");
Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
                Mix_PlayMusic(bgmusic,1);




temp2=inisaliser_temp_decompteur(temp2,1);
scor=intialiser_score(scor);
v=init_vie(v);

InitSprite(&s);


entit_sec=entite_initialiser(1,entit_sec,"PICS/karhba",500);
srand(time(NULL));
karhba=entite_initialiser(1,karhba,"PICS/karhba ymin",340);
karhba2=entite_initialiser2(1,karhba2,"PICS/44",340);
karhba3=entite_initialiser2(1,karhba3,"PICS/karhba",500);
capsulee=init_objet(capsulee);

afficher_looading(level1,screen);


stg1=init_background(screen,bg);

bgmusic=Mix_LoadMUS("Amazing Oriental Music - HD - FARAN ENSEMBLE.mp3");
Mix_PlayMusic(bgmusic,-1);
					printf("*************************\nVITESSE=%f **********************",vitesse);
mm=init_minimap(stg1);
// TOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOPPPPPPPPPPPPPPPPP
top:
if(e.collision==1 || collision6==1)
camera.x=2600;

e=initialiser_ennemie(e,camera);
Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
collision2=0;
collision3=0;
collision4=0;
collision5=0;
collisiontotale=0;

if(v.val<3)
afficher_looading(loading,screen);
perso=init_player(perso);



//**************************************************************************************************************



//*****************************************************************************************************************
//                                                    UPLOAD STAGE 1

if(loadornewgame==2)
{
load (&perso,&temp2 ,&camera,&v,&done[0],&done[1],&done[2],&done[3],&stage1done);
printf("***************\n LOADED SUCCESFULLY !! \n *********************** \n");
loadornewgame=3;
}

		while(stage1done==0 && input!=-1 && v.val!=3 && temp2.maxtemp>0){


//SDL_BlitSurface(stg1,&camera,screen,NULL);
 //SDL_Flip(screen);

	
SDL_EnableKeyRepeat(50,50);
input=0;
 while (input!=-1 && input!=10 &&  temp2.maxtemp>0 && stage1done==0)
  {
input=INPUT_STAGE1(event);
//pause menu
pause=menu_pause(screen,event,input);
if(pause==2)
goto newgame;
else if(pause==3)
//save;
{
save (perso,temp2,camera,v,done[0],done[1],done[2],done[3],stage1done);
}
else if(pause==4) 
goto exit;

//update

//vitesse=acceleration(vitesse,perso,input);
camera.x=scrolling(screen,stg1,input,camera,event,perso,vitesse);
					//printf("*************************\nVITESSE=%f **********************",vitesse);
perso.pos.x=deplacementvirtuel(input,perso);
perso=deplacementreel(input,perso,&s,keys);

sprite=sprite_perso(sprite,input,screen,&s,perso);


scor=gestion_score(done[0],done[1],done[2],done[3],scor,screen,capsulee.seule);

SDL_BlitSurface(stg1,&camera,screen,NULL);
//ZEYED
       e=deplacer_ennemie(camera,e,screen,position,perso.fix,input);

//afficher selon prio
if(perso.fix.y==280){
animation_player(sprite,perso,screen,&s,input);




karhba.rect.x=entite_afficher(screen,karhba,camera,1,-15);
karhba2.rect.x=entite_afficher(screen,karhba2,camera,1,-15);
entit_sec.rect.x=entite_afficher(screen,entit_sec,camera,1,-20);
karhba3.rect.x=entite_afficher(screen,karhba3,camera,1,-20);
}
else //if(perso.fix.y==340)
{
karhba.rect.x=entite_afficher(screen,karhba,camera,1,-15);
karhba2.rect.x=entite_afficher(screen,karhba2,camera,1,-15);
animation_player(sprite,perso,screen,&s,input);
entit_sec.rect.x=entite_afficher(screen,entit_sec,camera,1,-20);
karhba3.rect.x=entite_afficher(screen,karhba3,camera,1,-20);
}





capsulee=capsule1(screen,capsulee,camera,input,collision,capsulee.seule);
temp2=gestion_temps_decompteur(pause_time_disc,pause_time_pause,temp2,screen);

///COLLISION

//collision=gestion_collision(perso.pos,capsulee.position,420);
 collision=collission(perso.fix,capsulee.position,420);
if(collision==1)
{
capsulee.seule=1;
}
/*

collision2=collission(perso.fix,karhba.rect,340);
collision4=collission(perso.fix,karhba2.rect,340);
collision3=collission(perso.fix,entit_sec.rect,420);
collision5=collission(perso.fix,karhba3.rect,420);
*/
collision7=collission(perso.fix,e.pos,280);
collision6=collission(perso.fix,e.poszolat,280);
collisiontotale=(collision2==1 || collision3==1 || collision4==1 || collision5==1 || (collision7==0 && collision6==1)|| e.collision==1);
v=updatevie(v,collisiontotale,screen); 
//printf("*****************\ncollision2=%d\n perso.x=%d perso.y=%d \n karhba.x=%d karhba.y=%d \n karhba2=%d,%d \n",collision2,perso.pos.x,perso.pos.y,karhba.rect.x,karhba.rect.y,entit_sec.rect.x,entit_sec.rect.y);
//printf("PERSO(x,y) : (%d , %d) \n",perso.pos.x,perso.pos.y);
displayvie(v,screen);
mm=gestion_minimap(mm,screen,camera);
SDL_Flip(screen);
printf("***********POLICEPOS(x,y) : (%d,%d) \n",e.pos.x,e.pos.y);
printf("STAGE1DONE=%d \n",stage1done);
//printf("loadornew= %d \n",loadornewgame);

if(collisiontotale==1)
goto top;
//printf("pers.x=%d \n",perso.pos.x);
if(done[0]==1 && done[1]==1 && done[2]==1 && done[3]==1 )
stage1done=1;
/////////////////////////////////////







}


if(input==10)
 {
SDL_EnableKeyRepeat(0,0);
temp2=click(screen,stg1,camera,temp2,scor,done,capsulee.seule,perso,bgmusic);
}


else if(input==-1)
{
                }

}

if(stage1done!=1)
{
bgmusic=Mix_LoadMUS("sound/lvl.mp3");
Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
                Mix_PlayMusic(bgmusic,-1);
afficher_looading(gameover,screen);


}
//***********************************************************************************************************************************

if(stage1done==1)
{
SDL_BlitSurface(winscreen,NULL,screen,NULL);
scorefinale=calcul_score(3,scor,temp2);
afficher_scorefinale(scorefinale,screen);
SDL_Flip(screen);
SDL_Delay(4000);
}


stage2done=stage2(screen);
//free
exit:

Mix_FreeMusic(bgmusic);
SDL_FreeSurface(stg1);
SDL_FreeSurface(screen);

//}//if

SDL_Delay(1000);

}

printf("GAME OVER \n");
}
