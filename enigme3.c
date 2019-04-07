#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL.h"
#include"SDL/SDL_ttf.h"
#include<time.h>
#include<math.h>
#include<string.h>
#include"clock.h"


tempss enigme3(tempss temp2,int done[])
{
SDL_Event event;
SDL_Surface *screen,*Hfond,*Gfond,*cursor,*qst,*proposition1,*proposition2,*proposition3,*loading;
SDL_Rect rcursor,pqst,rprop1,rprop2,rprop3,rloading;
TTF_Font *police; 
char pourcentage[20],question[50][500],prop1[50][100],prop2[50][100],prop3[50][100];
SDL_Color color={0,0,0};
int rndm,loop=0,win=0,essai=0,unicite[6],i,unique=0;

//////FENTRE+INIT
///////////////////////////////////////////////////////////////////////////////////
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
SDL_WM_SetCaption("ENIGME3",NULL);

if(SDL_Init(SDL_INIT_VIDEO)!=0) //verifier l Init video
{
printf("Unable to initialize SDL : %s \n ",SDL_GetError());
return temp2;
}


screen=SDL_SetVideoMode(900,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
///////////////////////////////////////////////////////////////////////////////////////////
//LOAD INIT
loading=IMG_Load("enigme3/0.png");
///////////////


//OPEN txt position

police = TTF_OpenFont("enigme3/Xanadu.ttf",18);
//TTF_SizeText(police,question[1],&x,&y);
pqst.x=210;
pqst.y=180;

rprop1.x=400;
rprop1.y=310;

rprop2.x=400;
rprop2.y=353;

rprop3.x=400;
rprop3.y=402;
///




////questions 

strcpy(question[1],"When did Tunisia gain its independence?");
strcpy(question[2],"Who is this person on the right of the screen?");
strcpy(question[3],"Who is this person on the left of the screen?");
strcpy(question[4],"Who is the first president of Tunisia?");
strcpy(question[5],"Who is the founder of Carthage?");
strcpy(question[6],"How did Hannibal die ?");
strcpy(question[7],"When was farhat hached murdered ?");
strcpy(question[8],"What is the capital of Hafsids?");
strcpy(question[9],"What is the first population that occupied Tunisia?");
strcpy(question[10],"What is the last colonized Tunisian city?");
strcpy(question[11],"when was the Great Mosque found by Oqba Ibn Nafi?");
strcpy(question[12],"The first Tunisian woman graduated as a doctor:");
strcpy(question[13],"In which year did Habib Bourguiba become president?");
strcpy(question[14],"Which country controlled Tunisia in 1881?");
strcpy(question[15],"Which Tunisian city was razed by the Romans in 146 BC?");
strcpy(question[16],"When did the Arabs conquer Tunisia?");
strcpy(question[17],"Where is Africa's oldest Synagogue?");
strcpy(question[18],"Which one of these cities has never been a capital? ");
strcpy(question[19],"Who in the last Bey that controlled Tunisia ?");
strcpy(question[20],"the 3 series of wars between Rome and Carthage are :");
///geo
strcpy(question[21],"Where in Africa is Tunisia located?");
strcpy(question[22],"Which is the only sea which borders Tunisia?");
strcpy(question[23],"Which is Tunisia's principal natural resource?");
strcpy(question[24],"The highest point in Tunisia is Mount:");
strcpy(question[25],"Ichkeul National Park is in :");
strcpy(question[26],"Mosque of Ezzitouna is in :");
strcpy(question[27],"In which coastal town is *Sebastian's Villa located?");
strcpy(question[28],"A group of seven islands next to Sfax :");
strcpy(question[29],"The opening sequence of *Star Wars* at :");
strcpy(question[30],"What is the name of Chott el Jerid's town??");
strcpy(question[31],"What type of Roman building is found in Jam?");
strcpy(question[32],"the main tourist attraction of Kairouan is:");
strcpy(question[33],"Animportant Roman town situated in northern Tunisia:");
strcpy(question[34],"Which country is to the west of Tunisia?");
strcpy(question[35],"Match : Archaeology/Tourism/Industry :");
strcpy(question[36],"How many kilometres of coastline does Tunisia have?");
strcpy(question[37],"What kind of terrain does Tunisia have??");
strcpy(question[38],"What is the Height of El Chaanbi ?");
strcpy(question[39],"Tunisia is limited by Libya to?");
strcpy(question[40],"It's the smallest state ...");
strcpy(question[41],"Which island is too close to Tunisia?");





//Proposition
strcpy(prop1[1],"1936");
strcpy(prop2[1],"1987");
strcpy(prop3[1],"1956");


strcpy(prop1[2],"Ibn Khaldoun");
strcpy(prop2[2],"Habib Bourguiba");
strcpy(prop3[2],"Farhat Hached");

strcpy(prop1[3],"Abdelaziz Thaalbi");
strcpy(prop2[3],"Abou el Kacem Chebbi");
strcpy(prop3[3],"Tahar Haddad");

strcpy(prop1[4],"Mohammed Ghannouchi");
strcpy(prop2[4],"Habib Bourguiba");
strcpy(prop3[4],"Ahmed Nejib Chebbi");

strcpy(prop1[5],"Queen Elissa");
strcpy(prop2[5],"Hannibal Barca");
strcpy(prop3[5],"Hamilcar Barca");

strcpy(prop1[6],"By a Carthaginian");
strcpy(prop2[6],"By a Roman ");
strcpy(prop3[6],"Suicide");

strcpy(prop1[7],"1958");
strcpy(prop2[7],"1952");
strcpy(prop3[7],"1956");

strcpy(prop1[8],"Kairouan");
strcpy(prop2[8],"Tunis");
strcpy(prop3[8],"Mahdia");

strcpy(prop1[9],"Phoenicians");
strcpy(prop2[9],"Berbers");
strcpy(prop3[9],"Mousterians");

strcpy(prop1[10],"Sfax");
strcpy(prop2[10],"Kairouan");
strcpy(prop3[10],"La Goulette");

strcpy(prop1[11],"640");
strcpy(prop2[11],"670");
strcpy(prop3[11],"690");

strcpy(prop1[12],"Alia Menchari");
strcpy(prop2[12],"Aziza Othmana");
strcpy(prop3[12],"Wahida Ben Cheikh");

strcpy(prop1[13],"1987");
strcpy(prop2[13],"1992");
strcpy(prop3[13],"1956");

strcpy(prop1[14],"Italy");
strcpy(prop2[14],"France");
strcpy(prop3[14],"Spain");

strcpy(prop1[15],"Carthage");
strcpy(prop2[15],"Damascus");
strcpy(prop3[15],"Alexandria");

strcpy(prop1[16],"291");
strcpy(prop2[16],"325");
strcpy(prop3[16],"647");

strcpy(prop1[17],"Djerba");
strcpy(prop2[17],"Tunis");
strcpy(prop3[17],"Kairouan");

strcpy(prop1[18],"Mahdia");
strcpy(prop2[18],"Djerba");
strcpy(prop3[18],"Carthage");

strcpy(prop1[19],"Moncef Bey");
strcpy(prop2[19],"Ahmed II Bey");
strcpy(prop3[19],"Lamine Bey");

strcpy(prop1[20],"Punic Wars");
strcpy(prop2[20],"The Battle of Actium");
strcpy(prop3[20],"Caesar's Civil War");
//GEO
strcpy(prop1[21],"Eastern Africa");
strcpy(prop2[21],"Southern Africa");
strcpy(prop3[21],"Northern Africa");

strcpy(prop1[22],"Red Sea");
strcpy(prop2[22],"Caspian Sea");
strcpy(prop3[22],"Mediterranean Sea");


strcpy(prop1[23],"Natural Gas");
strcpy(prop2[23],"Petroleum");
strcpy(prop3[23],"Zinc");


strcpy(prop1[24],"Chambi");
strcpy(prop2[24],"La Galit");
strcpy(prop3[24],"Gharsah");

strcpy(prop1[25],"East");
strcpy(prop2[25],"North");
strcpy(prop3[25],"South");

strcpy(prop1[26],"Tunis");
strcpy(prop2[26],"Hammamet");
strcpy(prop3[26],"Jerba");

strcpy(prop1[27],"Hammamet");
strcpy(prop2[27],"Bizerte");
strcpy(prop3[27],"Sousse");

strcpy(prop1[28],"Iles Kerkennah");
strcpy(prop2[28],"Iles de Jerba");
strcpy(prop3[28],"Gabes Islands");

strcpy(prop1[29],"Ksar Ouled Soltane");
strcpy(prop2[29],"Matmata");
strcpy(prop3[29],"Nefta");

strcpy(prop1[30],"Tamerza");
strcpy(prop2[30],"Nefta");
strcpy(prop3[30],"Tozeur");

strcpy(prop1[31],"Baths");
strcpy(prop2[31],"Amphitheatre");
strcpy(prop3[31],"Temple");

strcpy(prop1[32],"Great Mosque");
strcpy(prop2[32],"Temple of Apollo");
strcpy(prop3[32],"Belvedere Zoo");

strcpy(prop1[33],"Bulla Regia");
strcpy(prop2[33],"Thuburbo Majus");
strcpy(prop3[33],"Dougga");

strcpy(prop1[34],"Sudan");
strcpy(prop2[34],"Algeria");
strcpy(prop3[34],"Egypt");

strcpy(prop1[35],"Sfax / Sousse / Sbeitla");
strcpy(prop2[35],"Sfax / Sbeitla / Sousse");
strcpy(prop3[35],"Sbeitla / Sousse / Sfax");

strcpy(prop1[36],"987 km");
strcpy(prop2[36],"1,148 km");
strcpy(prop3[36],"2,648 km");

strcpy(prop1[37],"Mountains in the north to desert in the south");
strcpy(prop2[37],"Jungle in the south and desert in the north");
strcpy(prop3[37],"Very mountainous");

strcpy(prop1[38],"1 544 m");
strcpy(prop2[38],"1 640 m");
strcpy(prop3[38],"1 801 m");

strcpy(prop1[39],"North South");
strcpy(prop2[39],"Southeast");
strcpy(prop3[39],"Northeast");

strcpy(prop1[40],"From Central Africa");
strcpy(prop2[40],"From southern Africa");
strcpy(prop3[40],"From the Maghreb");

strcpy(prop1[41],"Malta");
strcpy(prop2[41],"Jamaica");
strcpy(prop3[41],"The Canaries");


//LOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP
top :
loop=0;
unique=1;
//CURSOR pos
if(essai<5)
{
rcursor.x=280;
rcursor.y=299;
}
///

///RECT  GEO
if(essai>=5)
{
pqst.x=500;
pqst.y=150;

rprop1.x=500;
rprop1.y=270;

rprop2.x=500;
rprop2.y=340;

rprop3.x=500;
rprop3.y=410;


rcursor.x=460;
rcursor.y=260;
}
///////////////////////////////
cursor=IMG_Load("enigme3/cursor.png");

Hfond=IMG_Load("enigme3/Hfond.png");
Gfond=IMG_Load("enigme3/Gfond.png");


if(essai<5)
SDL_BlitSurface(Hfond,NULL,screen,NULL);
else if(essai>=5)
SDL_BlitSurface(Gfond,NULL,screen,NULL);

SDL_BlitSurface(cursor,NULL,screen,&rcursor);
SDL_Flip(screen);
//AFFICHER TXT////////////////////////////////////
/////RNDM UNICITE
srand(time(NULL));
do
{
if(essai<5)
	{rndm=rand()%20+1;
	for(i=0;i<essai && unique!=1;i++)
	{
	if(rndm==unicite[i])
	unique=1;
	printf("rndm= %d \n",rndm);
	printf("  uniqueH= %d\n   i=%d \n  ",unique,i);
	}
	}
else if(essai>=5)
	{
	rndm=rand()%21+21;
	for(i=5;i<essai && unique!=1;i++)
	{
	if(rndm==unicite[i])
	unique=1;
printf("  uniqueG= %d\n",unique);
	}
	}
}while(unique!=1);
unicite[essai]=rndm;


//////
//MAKE IN SURFACE
qst=TTF_RenderText_Solid(police,question[rndm],color);
proposition1=TTF_RenderText_Solid(police,prop1[rndm],color);
proposition2=TTF_RenderText_Solid(police,prop2[rndm],color);
proposition3=TTF_RenderText_Solid(police,prop3[rndm],color);
///////
  SDL_BlitSurface(qst, NULL,screen,&pqst);
	SDL_BlitSurface(proposition1, NULL,screen,&rprop1);
	SDL_BlitSurface(proposition2, NULL,screen,&rprop2);
	SDL_BlitSurface(proposition3, NULL,screen,&rprop3);
	SDL_BlitSurface(loading,NULL,screen,NULL);
            SDL_Flip(screen);



/////MOVE CURSOR

while(loop==0)
	{
while(SDL_PollEvent(&event) && loop==0)
		{ 
switch(event.type)
			{
case SDL_QUIT:
loop=1;
essai=10;
break;

case SDL_KEYDOWN:
switch(event.key.keysym.sym)
				{
				case SDLK_UP :
				if(essai<5)
				{
				if(rcursor.y>299)
				rcursor.y-=47;
				}
				else if(essai>=5)
				{
				if(rcursor.y>280)
				{printf("done up 2\n rcursor.y=%d\n",rcursor.y);
				rcursor.y-=70;}
				}
				break;
				case SDLK_DOWN:
				if(essai<5)
				{
				
				if(rcursor.y<393)
				rcursor.y+=47;
				}
				else if(essai>=5)
				{
				if(rcursor.y<400)
				rcursor.y+=70;
				}
				
				break;
				case SDLK_RETURN:
loop=1;
essai++;

switch(rndm)
{

case 1 :
if(rcursor.y==393)
{
printf("win \n");
win++;
}
break;

case 2 : 
if(rcursor.y==299)
{
printf("win \n");
win++;

}
break;

case 3 : 
if(rcursor.y==346)
{
printf("win \n");
win++;

}
break;


case 4 : 
if(rcursor.y==346)
{
printf("win \n");
win++;

}
break;


case 5 : 
if(rcursor.y==299)
{
printf("win \n");
win++;

}
break;

case 6 : 
if(rcursor.y==393)
{
printf("win \n");
win++;
}
break;

case 7 : 
if(rcursor.y==346)
{
printf("win \n");
win++;
}
break;

case 8 : 
if(rcursor.y==346)
{
printf("win \n");
win++;
}
break;

case 9 : 
if(rcursor.y==393)
{
printf("win \n");
win++;
}
break;

case 10 : 
if(rcursor.y==299)
{
printf("win \n");
win++;
}
break;

case 11 : 
if(rcursor.y==346)
{
printf("win \n");
win++;
}
break;

case 12 : 
if(rcursor.y==393)
{
printf("win \n");
win++;
}
break;

case 13 : 
if(rcursor.y==299)
{
printf("win \n");
win++;
}
break;

case 14 : 
if(rcursor.y==346)
{
printf("win \n");
win++;
}
break;

case 15 : 
if(rcursor.y==299)
{
printf("win \n");
win++;
}
break;

case 16 : 
if(rcursor.y==393)
{
printf("win \n");
win++;
}
break;

case 17 : 
if(rcursor.y==393)
{
printf("win \n");
win++;
}
break;

case 18 : 
if(rcursor.y==346)
{
printf("win \n");
win++;
}
break;

case 19 : 
if(rcursor.y==393)
{
printf("win \n");
win++;
}
break;

case 20 : 
if(rcursor.y==299)
{
printf("win \n");
win++;
}
break;

//geooo 

case 21 :
if(rcursor.y==400)
{
printf("win \n");
win++;
}
break;

case 22 : 
if(rcursor.y==400)
{
printf("win \n");
win++;

}
break;

case 23 : 
if(rcursor.y==330)
{
printf("win \n");
win++;

}
break;


case 24 : 
if(rcursor.y==260)
{
printf("win \n");
win++;

}
break;


case 25 : 
if(rcursor.y==330)
{
printf("win \n");
win++;

}
break;

case 26 : 
if(rcursor.y==260)
{
printf("win \n");
win++;
}
break;

case 27 : 
if(rcursor.y==260)
{
printf("win \n");
win++;
}
break;

case 28 : 
if(rcursor.y==260)
{
printf("win \n");
win++;
}
break;

case 29 : 
if(rcursor.y==330)
{
printf("win \n");
win++;
}
break;

case 30 : 
if(rcursor.y==400)
{
printf("win \n");
win++;
}
break;

case 31 : 
if(rcursor.y==330)
{
printf("win \n");
win++;
}
break;

case 32 : 
if(rcursor.y==260)
{
printf("win \n");
win++;
}
break;

case 33 : 
if(rcursor.y==400)
{
printf("win \n");
win++;
}
break;

case 34 : 
if(rcursor.y==330)
{
printf("win \n");
win++;
}
break;

case 35 : 
if(rcursor.y==400)
{
printf("win \n");
win++;
}
break;

case 36 : 
if(rcursor.y==330)
{
printf("win \n");
win++;
}
break;

case 37 : 
if(rcursor.y==260)
{
printf("win \n");
win++;
}
break;

case 38 : 
if(rcursor.y==260)
{
printf("win \n");
win++;
}
break;

case 39 : 
if(rcursor.y==330)
{
printf("win \n");
win++;
}
break;

case 40 : 
if(rcursor.y==330)
{
printf("win \n");
win++;
}
break;

case 41 : 
if(rcursor.y==260)
{
printf("win \n");
win++;
}
break;
	
	
	}

				break;

				}
sprintf(pourcentage,"enigme3/%d.png",win);
loading=IMG_Load(pourcentage);
if(essai<5)
SDL_BlitSurface(Hfond,NULL,screen,NULL);
else
SDL_BlitSurface(Gfond,NULL,screen,NULL);

SDL_BlitSurface(cursor,NULL,screen,&rcursor);
 SDL_BlitSurface(qst, NULL,screen,&pqst);
	SDL_BlitSurface(proposition1, NULL,screen,&rprop1);
	SDL_BlitSurface(proposition2, NULL,screen,&rprop2);
	SDL_BlitSurface(proposition3, NULL,screen,&rprop3);
SDL_BlitSurface(loading,NULL,screen,NULL);
SDL_Flip(screen);

			}
		}
	}
if(essai<=9)
{
printf("essai=%d \n win = %d \n",essai,win);
goto top;
}

if(win>=5)
done[2]=1;
else
done[2]=0;
return temp2;


}
