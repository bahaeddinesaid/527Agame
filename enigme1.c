#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL.h"
#include"SDL/SDL_ttf.h"
#include<time.h>
#include"math.h"
#include"enigme1.h"
#include"clock.h"

tempss enigme1(tempss temp2,int done[])
{

SDL_Surface *card[14],*screen,*x[7],*fond,*curseur,*aux;
SDL_Rect rcurseur,pcard[7];
SDL_Event event2;
int pause_time_disc=0;
int pause_time_pause=0;



int loop=0,i=0,j=1,k,unicite=0,save,save2,save3,save4,save5,save6,save7;
//save 1ere  ****  save3 2eme *** save 2  3eme *** save 4 4eme
char charcard[50];
int aleatoire,tmp,rndm,win[8]; 
//Aleatoire indice , tmp auxiliere , rndm des ran()
int click=0,min;
//ENTRER / min pour tri / done WIN ?
//SONS
Mix_Music *music;
Mix_Chunk *cards;

Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
cards=Mix_LoadWAV("sound/CARD SWITCH.wav");
music=Mix_LoadMUS("sound/enigme1.mp3");
Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
Mix_VolumeChunk(cards, MIX_MAX_VOLUME/1);
                Mix_PlayMusic(music,-1);
//RECT
for(i=1;i<=7;i++)
{
pcard[i].y=150;
pcard[i].x=0+i*100;
}

rcurseur.y=90;
rcurseur.x=100;
//


SDL_Init(SDL_INIT_EVERYTHING);

SDL_WM_SetCaption("ENIGME1",NULL);

if(SDL_Init(SDL_INIT_VIDEO)!=0) //verifier l Init video
{
printf("Unable to initialize SDL : %s \n ",SDL_GetError());
done[0]=0;
return temp2;
}

screen=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);


//FOND
fond=IMG_Load("kahwa.png");

SDL_BlitSurface(fond,NULL,screen,NULL);
SDL_Flip(screen);
//TOP FOR LOOP
top :

click=0;
//LOAD CURSEUR
curseur=IMG_Load("curseur.png");
//LOADING SCREEN

for(i=1;i<=13;i++)
{
sprintf(charcard,"%d.png",i); 
card[i]=IMG_Load(charcard);
}

srand(time(NULL));

//RANDOM CARDS

//*********************************************************************************************************************************************************
aleatoire=rand()%(13)+1;
save=aleatoire;


for(i=1;i<=2;i++) //bech taabi el X
{

x[i]=card[aleatoire];
printf("random %d: %d\n",i,aleatoire);
unicite=0;
do
			{
do //YAhsr mabin 13 w 1
{
tmp=aleatoire+(rand()%1+2)*pow(-1,rand()%2+1);


}while(!(tmp<=13 && tmp>=1));
aleatoire=tmp;
//UNICITE
for(k=1;k<=i;k++)
{
if(x[k]==card[aleatoire])

		{

	unicite=0;
break;
break;
		}
else 
		{
	unicite=1;


		}
}
			}while(unicite==0);
if(i==1)
save3=aleatoire;
} //for


//////////////////FIN UNICITE
//chtar theni 
//////////////////////////////////////////////////////////////////////////////////////////
do
{
aleatoire=rand()%(13)+1;
save2=aleatoire;

for(k=1;k<=2;k++)
{
if(x[k]==card[aleatoire])
		{

	unicite=0;
break;
break;
		}
else 
		{
	unicite=1;


		}
}
			}while(unicite==0);
x[3]=card[aleatoire];
printf("random %d: %d\n",i,aleatoire);





unicite=0;
do
			{
do //YAhsr mabin 13 w 1
	{

	rndm=2*pow(-1,rand()%2+1);
	tmp=aleatoire+rndm;


	}while(!(tmp<=12 && tmp>=2));
aleatoire=tmp;

//UNICITE
for(k=1;k<=i;k++)
{





if(x[k]==card[aleatoire])
		{

	unicite=0;
break;
break;
		}
else 
		{
	unicite=1;


		}
}
			}while(unicite==0);


x[4]=card[aleatoire];
save4=aleatoire;
printf("random 4: %d\n",aleatoire);

if(rndm==2)
rndm--;
else if(rndm==-2)
rndm++;
else
{

///////////////////
do
{
	for(k=1;k<=4;k++)
	{


if(aleatoire-1>=1 && aleatoire-1<=13)
	rndm=-1;

else if(aleatoire+1>=1 && aleatoire+1<=13)
	rndm=+1;

else if(aleatoire-2>=1 && aleatoire-2<=13)
	rndm=-2;

else if(aleatoire+2>=1 && aleatoire+2<=13)
	rndm=+2;
	



		if(x[k]==card[save2+rndm])
			{

			unicite=0;
			break;
			break;
			}
		else 
			{
			unicite=1;


			}
	}

/////
	
}while(unicite==0);
}




x[5]=card[aleatoire+rndm];
save5=aleatoire+rndm;
printf("random 5: %d\n",aleatoire+rndm);

//CHTAR theleth
////////////////////////////////////////
///KEN NEKSA EL +1 || -1



//CARD 6
k=1;
if(save>save3)
aleatoire=save-1;
else if(save<save3)
aleatoire=save+1;
x[6]=card[aleatoire];
save6=aleatoire;
printf("random 6: %d\n",aleatoire);

//CARD 7
k=4;
unicite=0;
		if(save2<save4)
		{
	do
	{

if(x[k]==card[save2+1])
unicite=1;
k++;
	}while(unicite==0 && k<=5);
if(unicite==0)
aleatoire=save2+1;
		}
/*if(aleatoire>13)
aleatoire=save2-2;
}*/



else
{
k=4;
unicite=0;
do
{
if(x[k]==card[save2-1])
unicite=1;
k++;
}while(unicite==0 && k<=5);
if(unicite==0)
aleatoire=save2-1;
}
/*if(aleatoire<1)
aleatoire=save2+2;
}*/


x[7]=card[aleatoire];
save7=aleatoire;
printf("random 7: %d\n",aleatoire);


//***********************************************************************************************************************************************************************************
//GAMEPLAY
while(loop==0)
	{


while(SDL_PollEvent(&event2) && loop==0)
		{ 
switch(event2.type)
			{
case SDL_QUIT:
loop=1;
done[0]=0;
break;

case SDL_KEYDOWN:
switch(event2.key.keysym.sym)
				{


					case SDLK_RIGHT :
					if(rcurseur.x<pcard[7].x)
					 {j++;
					rcurseur.x=j*100;}
					
					break;
					
					case SDLK_LEFT :

					if(rcurseur.x>pcard[1].x)
					{j--;
					rcurseur.x-=100;}
					break;
					case SDLK_RETURN :
					Mix_PlayChannel(1 ,cards, 0);
					SDL_Delay(300);
					click++;
					
					
					if(click%2==1)
					{
					if(j!=7)
					k=j;
					else
					k=j-1;	
					aux=x[k];
					x[k]=x[k+1];
					x[k+1]=aux;
					
					}
					
					else
					{
					if(j!=1)
					k=j;
					else
					k=j+1;
					aux=x[k];
					x[k]=x[k-1];
					x[k-1]=aux;	
					
					}	
					printf("click=%d\n",click);				
					break;
}


}

}


SDL_BlitSurface(fond,NULL,screen,NULL);
for(i=1;i<=7;i++)
{
SDL_BlitSurface(x[i],NULL,screen,&pcard[i]);
}
SDL_BlitSurface(curseur,NULL,screen,&rcurseur);
temp2=gestion_temps_decompteur(pause_time_disc,pause_time_pause,temp2,screen);
SDL_Flip(screen);

///WIN 
//*********************************************************
if(x[1]==card[save])

	if((x[2]==card[save+1] && x[3]==card[save+2]) || (x[2]==card[save-1] && x[3]==card[save-2]))
	{
printf("PRINTF1\n");
if(x[4]==card[save2])
{if((x[5]==card[save2+1] && x[6]==card[save2+2] && x[7]==card[save2+3]) || (x[5]==card[save2-1] && x[6]==card[save2-2] && x[7]==card[save2-3]))
{
printf("victory ! \n");
done[0]=1;
Mix_FreeMusic(music);
return temp2;
}}


else if(x[4]==card[save4])
{if((x[5]==card[save4+1] && x[6]==card[save4+2] && x[7]==card[save4+3]) || (x[5]==card[save4-1] && x[6]==card[save4-2] && x[7]==card[save4-3]))
{
printf("victory ! \n");
done[0]=1;
Mix_FreeMusic(music);
return temp2;
}}


else if(x[4]==card[save5])
{if((x[5]==card[save5+1] && x[6]==card[save5+2] && x[7]==card[save5+3]) || (x[5]==card[save5-1] && x[6]==card[save5-2] && x[7]==card[save5-3]))
{
printf("victory ! \n");
done[0]=1;
Mix_FreeMusic(music);
return temp2;
}}


else if(x[4]==card[save6])
{if((x[5]==card[save6+1] && x[6]==card[save6+2] && x[7]==card[save6+3]) || (x[5]==card[save6-1] && x[6]==card[save6-2] && x[7]==card[save6-3]))
{

printf("victory ! \n");
done[0]=1;
Mix_FreeMusic(music);
return temp2;
}}


else if(x[4]==card[save7])
{if((x[5]==card[save7+1] && x[6]==card[save7+2] && x[7]==card[save7+3]) || (x[5]==card[save7-1] && x[6]==card[save7-2] && x[7]==card[save7-3]))
{
printf("victory ! \n");
done[0]=1;
Mix_FreeMusic(music);
return temp2;
}}




	
	}

//////////////////////////////////////////////////////////////////////////////
if(x[1]==card[save3])
{{
	if((x[2]==card[save3+1] && x[3]==card[save3+2]) || (x[2]==card[save3-1] && x[3]==card[save3-2]))
	{
printf("PRINTF2\n");
if(x[4]==card[save2])
if((x[5]==card[save2+1] && x[6]==card[save2+2] && x[7]==card[save2+3]) || (x[5]==card[save2-1] && x[6]==card[save2-2] && x[7]==card[save2-3]))
{
printf("victory ! \n");
done[0]=1;
Mix_FreeMusic(music);
return temp2;
}}


else if(x[4]==card[save4])
{if((x[5]==card[save4+1] && x[6]==card[save4+2] && x[7]==card[save4+3]) || (x[5]==card[save4-1] && x[6]==card[save4-2] && x[7]==card[save4-3]))
{
printf("victory ! \n");
done[0]=1;
return temp2;
Mix_FreeMusic(music);
}}


else if(x[4]==card[save5])
{if((x[5]==card[save5+1] && x[6]==card[save5+2] && x[7]==card[save5+3]) || (x[5]==card[save5-1] && x[6]==card[save5-2] && x[7]==card[save5-3]))
{
printf("victory ! \n");
done[0]=1;
return temp2;
Mix_FreeMusic(music);
}}


else if(x[4]==card[save6])
{if((x[5]==card[save6+1] && x[6]==card[save6+2] && x[7]==card[save6+3]) || (x[5]==card[save6-1] && x[6]==card[save6-2] && x[7]==card[save6-3]))
{
printf("PRINTF 2 \n");
printf("victory ! \n");
done[0]=1;
Mix_FreeMusic(music);
return temp2;
}}


else if(x[4]==card[save7])
{if((x[5]==card[save7+1] && x[6]==card[save7+2] && x[7]==card[save7+3]) || (x[5]==card[save7-1] && x[6]==card[save7-2] && x[7]==card[save7-3]))
{
printf("victory ! \n");
done[0]=1;
return temp2;
}}

	}

}


/*if(x[1]==card[save] && x[2]==card[save6] && x[3]==card[save3] && x[4]==card[save2] && x[5]==card[save7] && x[6]==card[save4] &&  x[7]==card[save5])
return 0;*/
//****************************************************************************

///
if(click>=12) 
{

goto top;
}
}
Mix_CloseAudio();
Mix_FreeMusic(music);

////////////////
done[0]=0;
printf("done=%d\n",done[0]);
return temp2;
}
