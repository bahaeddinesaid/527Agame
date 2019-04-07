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

o.affiche.x=1800;
o.affiche.y=420;


return o;
}

int capsule1 (SDL_Surface *ecran,objet o,SDL_Rect camera,int input,int collision,int x)
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
strcpy(o.objet,"capsulee/1.png");	
o.Objet[1]=IMG_Load(o.objet);
//printf("object.x=%d\n",o.position.x);
//SDL_BlitSurface(back,NULL,ecran,&positionback);
if(collision==0 && x==0)
{SDL_BlitSurface(o.Objet[1],NULL,ecran,&o.position);}


//SDL_Flip(ecran);

}//2

return o.position.x;
}//close
