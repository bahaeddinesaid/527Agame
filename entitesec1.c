#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "entitesec1.h"
#include <string.h>
#include"collisiontrigo.h"
objet init_objet(objet o)
{
o.seule=0;
o.position.w=78;
o.position.h=78;
o.position.x=900;
o.position.y=500;
o.affiche.x=rand()%5000+1000;
o.affiche.x=1800;
o.affiche.y=420;

o.compteur=1;
o.ta=0;
o.tp=0;


return o;
}



objet capsule1 (SDL_Surface *ecran,objet o,SDL_Rect camera,int input,int collision,int x)
{//open


if(camera.x>=o.affiche.x-900 && camera.x<=o.affiche.x)
{//2
if(input==2)
{//3
if(o.position.x>0)
o.position.x-=5;
}//3
else if(input==1)
{//4

o.position.x+=5;
}//4				
//strcpy(o.objet,"capsulee/1.png");	
//o.Objet[o.compteur]=IMG_Load(o.objet);
//printf("object.x=%d\n",o.position.x);
//SDL_BlitSurface(back,NULL,ecran,&positionback);
o.ta = SDL_GetTicks();
if((collision==0 && x==0) && (o.ta - o.tp >=50 ))
{

sprintf(o.objet,"capsulee/%d.png",o.compteur);	
o.Objet[o.compteur]=IMG_Load(o.objet);

//SDL_Flip(ecran);
SDL_BlitSurface(o.Objet[o.compteur],NULL,ecran,&o.position);
o.compteur++;
printf("image=%d\n",o.compteur);
o.tp=o.ta;}
if(o.seule!=1)
SDL_BlitSurface(o.Objet[o.compteur],NULL,ecran,&o.position);
if(o.compteur==8){o.compteur=1;}

//SDL_Flip(ecran);

}//2

return o;
}//close
