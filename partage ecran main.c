#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL.h"
#include"SDL/SDL_ttf.h"
#include"player.h"
#include"fnc.h"
#include "load.h"
#include "time.h"
#include "vie.h"
#include "clock.h"
#include "score.h"
#include"collisiontrigo.h"
#include"DJ.h"
#include"warning.h"
#include"colors.h"
#include"boss1.h"
#include"saut.h"
#include"jeu.h"
#include"svld.h"














int main()
{
SDL_Surface *ecran,*map,*map2;
SDL_Rect camera,posmap2;
SDL_Event event;
Mix_Music *bgmusic;
int sprite=1;
int k=0,k2=0,k3=0;
int variable=0;
int collision=0,collision2=0,collision3=0,collision4=0,collision5=0,collision22=0,collision33=0,collision44=0,collision55=0,collision6=0,collision66=0,collision7=0,collision77=0,collision8=0,collision88=0,collision9=0,collision99=0,collision10=0,collision11=0,collision12=0,collision100=0,collision111=0,collision122=0,collisiontotale=0,collisiontotale2=0;
player perso,perso2;
entite_sec entit_sec,karhba,karhba2,karhba3,karhba4,serak,serak2,entit_sec2,karhba5,karhba6,karhba7,karhba8;
vie v,v2;
score scor,scor2;
tempss temp2,temp3;
warnin warn1,warn2,warn3,warn4,warn5,warn6,warn7,warn8;
int warntotal=0,warntotal2=0;
boss1 b,b2;
Mix_Chunk *sfx;
Sprite s;
Uint8 keys;
int input=0;
InitSprite(&s);


posmap2.x=900;
posmap2.y=0;
warn1=init_warning(warn1,600,340);
warn2=init_warning(warn2,600,340);
warn3=init_warning(warn3,600,450);
warn4=init_warning(warn4,600,450);
////
warn5=init_warning(warn1,1500,340);
warn6=init_warning(warn2,1500,340);
warn7=init_warning(warn3,1500,450);
warn8=init_warning(warn4,1500,450);
///

entit_sec=entite_initialiser(1,entit_sec,"PICS/karhba",500);
srand(time(NULL));
karhba=entite_initialiser(1,karhba,"PICS/karhba ymin",340);
karhba2=entite_initialiser2(1,karhba2,"PICS/44",340);
karhba3=entite_initialiser2(1,karhba3,"PICS/karhba",500);
karhba4=entite_initialiser2(1,karhba4,"PICS/karhba",500);
//////////////////////////////////
entit_sec2=entite_initialiser(1,entit_sec,"PICS/karhba",500);
karhba5=entite_initialiser(1,karhba,"PICS/karhba ymin",340);
karhba6=entite_initialiser2(1,karhba2,"PICS/44",340);
karhba7=entite_initialiser2(1,karhba3,"PICS/karhba",500);
karhba8=entite_initialiser2(1,karhba4,"PICS/karhba",500);


///////////////
//karhba4=entite_initialiser3(1,karhba4,"PICS/44",340);
//karhba5=entite_initialiser3(1,karhba5,"PICS/karhba",500);
serak=entite_initialiser2(1,serak,"PICS/serak",280);
serak2=entite_initialiser2(1,serak2,"PICS/serak",280);






//4500
camera.x=0;
         camera.y=0;
camera.w=900;
camera.h=600;


SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
TTF_Init();

SDL_WM_SetCaption("527A",NULL);

ecran=SDL_SetVideoMode(1800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); 
//music
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
bgmusic=Mix_LoadMUS("run.mp3");
Mix_VolumeMusic(MIX_MAX_VOLUME);
                Mix_PlayMusic(bgmusic,1);

//
sfx=Mix_LoadWAV("sound/ping_danger.wav");

 

map=IMG_Load("stage1.png");
map2=IMG_Load("stage1.png");
b=init_boss1(b);
b2=init_boss1(b2);


temp2=inisaliser_temp_decompteur(temp2,1);
temp3=inisaliser_temp_decompteur(temp3,1);
scor=intialiser_score(scor);
scor2=intialiser_score(scor2);

v=init_vie(v);
v2=init_vie(v2);
perso2=init_player2(perso2);
perso=init_player(perso);
v=init_vie(v);
v2.position.x+=900;


Mix_VolumeChunk(sfx, MIX_MAX_VOLUME/4);


//load

//load (&perso,&temp2 ,&camera,&v,variable);


///////

//SDL_EnableKeyRepeat(50,50);
do
{
collisiontotale=0;
sprite=sprite_perso(sprite,2,ecran,&s,perso);
SDL_BlitSurface(map,&camera,ecran,NULL);

if(temp2.maxtemp<=288)
k2=run(ecran,k2,"RUN1","png",54);


k=gestion_colors(ecran,k,temp2,"run","jpg",208,1);
k--;

////////////////////////INPUT
int  inp[10] ;
 for(int lala=0;lala<10;lala++)
 	{inp[lala]=0;}

while(SDL_PollEvent(&event))
{//1

switch(event.type)
{//2
	case SDL_KEYDOWN :
	//{//3

 switch(event.key.keysym.sym)
            {//4
		case SDLK_RIGHT:
        inp[0]=1;
		break;
		
		case SDLK_LEFT:
        inp[1]=1;
		break;

		case SDLK_UP:
        inp[2]=1;
		break;
		
		case SDLK_DOWN:
		        inp[3]=1;
		break;


             

case SDLK_z:
		        inp[5]=1;

break;

case SDLK_q:
		        inp[6]=1;

break;

case SDLK_s:
		        inp[7]=1;

break;

case SDLK_d:
		        inp[8]=1;
break;


		}//4
	break;
//}//3
 case SDL_KEYUP:
                                        switch(event.key.keysym.sym) {
                                                case SDLK_UP:
                                                        inp[2] = 0;
                                                        break;
                                                case SDLK_LEFT:
                                                        inp[1] = 0;
                                                        break;
                                                case SDLK_DOWN:
                                                        inp[3] = 0;
                                                        break;
                                                case SDLK_RIGHT:
                                                        inp[0] = 0;
                                                        break;
                                       
                                                  case SDLK_SPACE:
	                                                    inp[4]=0;
                                                      break ; 
                                                  case SDLK_z:
		        inp[5]=0;

break;

case SDLK_q:
		        inp[6]=0;

break;

case SDLK_s:
		        inp[7]=0;

break;

case SDLK_d:
		        inp[8]=0;


break;

case SDLK_k:
		        inp[9]=0;
break;  

                                        }
                                        break;

}//2
}//1s

  if(inp[0]==1){	
	input=2;
if (perso.fix.x>=750){perso.fix.x=750;}
else {perso=jouer(perso,2);
		perso.fix.x+=perso.vitesse;
		s.x+=17;
}
  }
  if(inp[1]==1){

  		input=1;
	if(perso.fix.x>-55)
		perso.fix.x-=17;
		s.x-=17;
  }                   
  if(inp[2]==1){			input=4;
if(perso.fix.y==340)
		perso.fix.y=280;

else if(perso.fix.y==420)
		perso.fix.y=340;
		
}              
  if(inp[3]==1){			
  				input=3;
		if(perso.fix.y==280)
		perso.fix.y=340;
		else if(perso.fix.y==340)
		perso.fix.y=420;
}                 
  if(   inp[4]==1){	input=20;
}          
if(inp[5]==1) {
		
input=4000;
if(perso2.fix.y==340)
		perso2.fix.y=280;

else if(perso2.fix.y==420)
		perso2.fix.y=340;

		}

if(inp[6]==1) {
  if(perso2.fix.x<=750){perso2.fix.x=750;}
else{input=1000;
	input=1;
	if(perso2.fix.x>845) //-55
		perso2.fix.x-=17;
		//s2.x-=17;
}		}

if(inp[7]==1)
 {
input=3000;
	if(perso2.fix.y==280)
		perso2.fix.y=340;
	else  if(perso2.fix.y==340)
		perso2.fix.y=420;
 }
if(inp[8]==1) {
input=2000;

perso2=jouer(perso2,2);
		perso2.fix.x+=perso2.vitesse;
		//s2.x+=17;

	}
if(inp[9]==1) {
input=20000;


}

//////////////////////////////////////////////
//perso=deplacementreel(input,perso,&s,&keys);
animation_player(sprite,perso,ecran,&s,input);

//perso2=deplacementreel2(input,perso2,&s,&keys);
//animation_player(sprite,perso2,ecran,&s,input);

	
		
/*
*/
//serak.rect.x=entite_afficher(ecran,serak,camera,1,+15);

karhba.rect.x=entite_afficher(ecran,karhba,camera,1,-27);
karhba2.rect.x=entite_afficher(ecran,karhba2,camera,1,-27);
entit_sec.rect.x=entite_afficher(ecran,entit_sec,camera,1,-30);
karhba3.rect.x=entite_afficher(ecran,karhba3,camera,1,-30);

//////////////////////
/*karhba5.rect.x=entite_afficher(ecran,karhba5,camera,1,-27);
karhba6.rect.x=entite_afficher(ecran,karhba6,camera,1,-27);
entit_sec2.rect.x=entite_afficher(ecran,entit_sec2,camera,1,-30);
karhba7.rect.x=entite_afficher(ecran,karhba7,camera,1,-30);*/
///////////////////////

temp3.position_temp.x=400+900;
temp3=gestion_temps_decompteur(0,0,temp3,ecran,1000);
temp2=gestion_temps_decompteur(0,0,temp2,ecran,1000);
scor=gestion_score(0,0,0,0,scor,ecran,0);
//

warntotal=(warn1.x || warn2.x || warn3.x || warn4.x);

if(warntotal && (!(warn1.playing || warn2.playing || warn3.playing || warn4.playing)) )
{
  Mix_PlayChannel(1 ,sfx, 0);
}
////////////////
/*warntotal2=(warn5.x || warn6.x || warn7.x || warn8.x);

if(warntotal2 && (!(warn5.playing || warn6.playing || warn7.playing || warn8.playing)) )
{
  Mix_PlayChannel(1 ,sfx, 0);
}*/
///////////////////////
if(camera.x<5000)
{

warn1=gestion(camera,warn1,ecran,karhba.rect.x,sfx);
warn2=gestion(camera,warn2,ecran,karhba2.rect.x,sfx);
warn3=gestion(camera,warn3,ecran,karhba3.rect.x,sfx);
warn4=gestion(camera,warn4,ecran,entit_sec.rect.x,sfx);


collision2=collission(perso.fix,karhba.rect,340);
collision4=collission(perso.fix,karhba2.rect,340);
collision3=collission(perso.fix,entit_sec.rect,420);
collision5=collission(perso.fix,karhba3.rect,420);
/*
warn5=gestion(camera,warn1,ecran,karhba5.rect.x,sfx);
warn6=gestion(camera,warn2,ecran,karhba6.rect.x,sfx);
warn7=gestion(camera,warn3,ecran,karhba7.rect.x,sfx);
warn8=gestion(camera,warn4,ecran,entit_sec2.rect.x,sfx);


collision22=collission(perso2.fix,karhba5.rect,340);
collision44=collission(perso2.fix,karhba6.rect,340);
collision33=collission(perso2.fix,entit_sec2.rect,420);
collision55=collission(perso2.fix,karhba7.rect,420);
*/



}



warn1.playing=0;
warn2.playing=0;
warn3.playing=0;
warn4.playing=0;

////
/*warn5.playing=0;
warn6.playing=0;
warn7.playing=0;
warn8.playing=0;*/


////
if(b.trashpos.y==380)

collision6=collission(perso.fix,b.trashpos,280);
//printf("COOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOL\n");

if(b.trashpos.y==450)
collision7=collission(perso.fix,b.trashpos,340);

if(b.trashpos.y==520)
collision8=collission(perso.fix,b.trashpos,420);

collision9=(collision7 || collision8 || collision6);
//boss


collision10=collission(perso.fix,b.pos,420);
collision11=collission(perso.fix,b.pos,340);
collision12=(collision10 || collision11);

/////////////

//collision6=collission(perso.fix,serak.rect,280);

//printf("**\n");

collisiontotale=(collision2==1 || collision3==1 || collision4==1 || collision5==1 || collision9==1  || collision12==1);
//collisiontotale2=(collision22==1 || collision33==1 || collision44==1 || collision55==1 );

v=updatevie(v,collisiontotale,ecran); 


//v2=updatevie(v2,collisiontotale,ecran); 

if(camera.x>=5000)
{
karhba.rect.x=50000;
karhba2.rect.x=50000;
karhba3.rect.x=50000;
entit_sec.rect.x=50000;
//
karhba5.rect.x=50000;
karhba6.rect.x=50000;
karhba7.rect.x=50000;
entit_sec2.rect.x=50000;
//


///
}

if(collisiontotale==1)
{
perso.fix.x=0;
perso.fix.y=280;

}
////
/*if(collisiontotale2==1)
{
perso.fix.x=900;
perso.fix.y=280;

}*/

///


if(collision6==1)
{
serak.rect.x=6000;
collision6=0;
}
//printf("*****************\ncollision2=%d\n perso.x=%d perso.y=%d \n karhba.x=%d karhba.y=%d \n karhba2=%d,%d \n",collision2,perso.pos.x,perso.pos.y,karhba.rect.x,karhba.rect.y,entit_sec.rect.x,entit_sec.rect.y);
displayvie(v,ecran);
//affichedj(map,ecran);

//boss

if(camera.x>=5000)
{
b=gestion_boss1(perso.fix,b,camera);
b=attack1(b);
b=attack2(b,collision9);
afficher_boss1(b,ecran);

}

//

//printf("TRASH.Y=%d \n",b.trashpos.y);
//printf("b.pos.x : (%d) \n",b.pos.x);
//printf("P.JUMPING = %d \n",perso.jumpin);
printf("vitesse = %f \n",perso.vitesse);
printf("acceleration = %f \n",perso.acceleration);



//PLAYER2 
//*************************************************************************************
//k=gestion_colors2(ecran,k,temp3,"run","jpg",208,1);


SDL_BlitSurface(map2,&camera,ecran,&posmap2);
k=gestion_colors2(ecran,k,temp3,"run","jpg",208,1);

if(temp3.maxtemp<=288)
k3=run2(ecran,k3,"RUN1","png",54);
//perso2=deplacementreel2(input,perso2,&s,&keys);
animation_player(sprite,perso2,ecran,&s,input);
displayvie(v2,ecran);

//serak2.rect.x=entite_afficher2(ecran,serak2,camera,1,+15);


karhba5.rect.x=entite_afficher2(ecran,karhba5,camera,1,-27);

karhba6.rect.x=entite_afficher2(ecran,karhba6,camera,1,-27);
entit_sec2.rect.x=entite_afficher2(ecran,entit_sec2,camera,1,-30);
karhba7.rect.x=entite_afficher2(ecran,karhba7,camera,1,-30);
////////////////
warntotal2=(warn5.x || warn6.x || warn7.x || warn8.x);

if(warntotal2 && (!(warn5.playing || warn6.playing || warn7.playing || warn8.playing)) )
{
  Mix_PlayChannel(1 ,sfx, 0);
}
///////////////////////
if(camera.x<5000)
{


warn5=gestion(camera,warn5,ecran,karhba5.rect.x,sfx);
warn6=gestion(camera,warn6,ecran,karhba6.rect.x,sfx);
warn7=gestion(camera,warn7,ecran,karhba7.rect.x,sfx);
warn8=gestion(camera,warn8,ecran,entit_sec2.rect.x,sfx);


collision22=collission(perso2.fix,karhba5.rect,340);
collision44=collission(perso2.fix,karhba6.rect,340);
collision33=collission(perso2.fix,entit_sec2.rect,420);
collision55=collission(perso2.fix,karhba7.rect,420);




}
warn5.playing=0;
warn6.playing=0;
warn7.playing=0;
warn8.playing=0;
////
if(b2.trashpos.y==380)

collision66=collission(perso2.fix,b2.trashpos,280);
//printf("COOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOL\n");

if(b2.trashpos.y==450)
collision7=collission(perso2.fix,b2.trashpos,340);

if(b2.trashpos.y==520)
collision88=collission(perso2.fix,b2.trashpos,420);

collision99=(collision77 || collision88 || collision66);
//boss


collision100=collission(perso2.fix,b2.pos,420);
collision111=collission(perso2.fix,b2.pos,340);
collision122=(collision100 || collision111);

collisiontotale2=(collision22==1 || collision33==1 || collision44==1 || collision55==1 || collision99==1  || collision122==1);

v2=updatevie(v2,collisiontotale2,ecran); 
if(camera.x>=5000)
{
karhba5.rect.x=50000;
karhba6.rect.x=50000;
karhba7.rect.x=50000;
entit_sec2.rect.x=50000;
//
karhba5.rect.x=50000;
karhba6.rect.x=50000;
karhba7.rect.x=50000;
entit_sec2.rect.x=50000;
//


///
}
if(collisiontotale2==1)
{
perso2.fix.x=900;
perso2.fix.y=280;

}




//boss

if(camera.x>=5000)
{
b2=gestion_boss11(perso2.fix,b2,camera);
b2=attack11(b2);
b2=attack22(b2,collision99);
afficher_boss11(b2,ecran);

}
///******************************************************************************************

SDL_Flip(ecran);
//perso.fix.x+=10;
//if(collisiontotale==1)
/*if(perso.fix.x>=850)
{
camera.x+=900;
perso.fix.x=0;
}*/


if(temp2.maxtemp<=288)
camera.x+=10;
else 
camera.x+=5;
SDL_Delay(10);

//printf("camera.x=%d\n",camera.x);
//printf("karhna3.x=%d\n",karhba3.rect.x);

}while(camera.x<16100 && v.val<3);

SDL_Delay(2000);

}
