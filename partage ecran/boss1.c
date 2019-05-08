#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"boss1.h"
#include "clock.h"
#include"math.h"
#include"time.h"

boss1 init_boss1(boss1 b)
{
b.angle=3;
b.pos.x=2000;
b.pos.y=320;
b.img=IMG_Load("PICS/boss/1.png");
b.testattack1=0;
b.tempactuel=0;
b.tempactuel2=0;
b.tempprecedent=0;
b.trashpos.x=600;
b.trashpos.y=520;
b.trashimg=IMG_Load("PICS/poubelle.png");
b.randy[1]=380;
b.randy[2]=450;
b.randy[3]=520;
b.start=0;
return b;
}

boss1 init_boss11(boss1 b)
{
b.angle=3;
b.pos.x=2000;
b.pos.y=320;
b.img=IMG_Load("PICS/boss/1.png");
b.testattack1=0;
b.tempactuel=0;
b.tempactuel2=0;
b.tempprecedent=0;
b.trashpos.x=1500;
b.trashpos.y=520;
b.trashimg=IMG_Load("PICS/poubelle.png");
b.randy[1]=380;
b.randy[2]=450;
b.randy[3]=520;
b.start=0;
return b;
}


boss1 gestion_boss1(SDL_Rect perso,boss1 b,SDL_Rect camera)
{

if(camera.x>=5000 && camera.x<=5100)
{b.start=1;
b.pos.x=0;
}
if(camera.x>5000 && b.pos.x<600 && b.testattack1==0 && b.start==1)
{b.img=IMG_Load("PICS/boss/1.png");
b.pos.x+=20;}



/*if(perso.y==340)
b.pos.y=340;
if(perso.y==420)
b.pos.y=500;*/
printf("start = %d \n",b.start);
return b;


}

boss1 gestion_boss11(SDL_Rect perso,boss1 b,SDL_Rect camera)
{

if(camera.x>=5000 && camera.x<=5100)
{b.start=1;
b.pos.x=900;
}
if(camera.x>5000 && b.pos.x<1500 && b.testattack1==0 && b.start==1)
{b.img=IMG_Load("PICS/boss/1.png");
b.pos.x+=20;}



/*if(perso.y==340)
b.pos.y=340;
if(perso.y==420)
b.pos.y=500;*/
printf("start = %d \n",b.start);
return b;


}


boss1 attack1(boss1 b)
{
if(b.pos.x>550 && b.pos.x<600)
{b.tempprecedent = SDL_GetTicks();
b.tempactuel = SDL_GetTicks();}

if(b.pos.x==600)
b.tempactuel = SDL_GetTicks();


        if (b.pos.x==600 && (b.tempactuel - b.tempprecedent >=6000))
        {
b.img=IMG_Load("PICS/boss/2.png");
printf("haw dkhlna\n");
b.testattack1=1;
b.tempprecedent=b.tempactuel;
}

if((b.testattack1==1 && b.pos.x!=0))
b.pos.x-=25;
else if(b.pos.x==0)
b.testattack1=0;
printf("b.x=%d *******************\n",b.pos.x);
////printf("test=%d \n",b.testattack1);
//printf("temp.tempactuel=%d \n temp.tempprecedent=%d \n",b.tempactuel,b.tempprecedent);



return b;
}

boss1 attack11(boss1 b)
{
if(b.pos.x>1450 && b.pos.x<1500)
{b.tempprecedent = SDL_GetTicks();
b.tempactuel = SDL_GetTicks();}

if(b.pos.x==1500)
b.tempactuel = SDL_GetTicks();


        if (b.pos.x==1500 && (b.tempactuel - b.tempprecedent >=6000))
        {
b.img=IMG_Load("PICS/boss/2.png");
printf("haw dkhlna\n");
b.testattack1=1;
b.tempprecedent=b.tempactuel;
}

if((b.testattack1==1 && b.pos.x!=900))
b.pos.x-=25;
else if(b.pos.x==900)
b.testattack1=0;
printf("b.x=%d *******************\n",b.pos.x);
////printf("test=%d \n",b.testattack1);
//printf("temp.tempactuel=%d \n temp.tempprecedent=%d \n",b.tempactuel,b.tempprecedent);



return b;
}

boss1 attack2(boss1 b,int test)
{
srand(time(NULL));
b.tempactuel2=SDL_GetTicks();
if(b.pos.x==600)
{
if(b.trashpos.x>0 && test==0)
{

//b.angle += 0.05;
//b.trashpos.x+=200 * cos(b.angle);
//b.trashpos.y+=sin(b.angle)*500;
printf("angle=%f \n",b.angle);
printf("y=%d\n",b.trashpos.y);



b.trashpos.x-=25;

}


else if((b.trashpos.x<=0) || test==1)
{
b.trashpos.x=600;
//
b.trashpos.y=b.randy[rand()%3+1];
}


}


return b;

}


boss1 attack22(boss1 b,int test)
{
srand(time(NULL));
b.tempactuel2=SDL_GetTicks();
if(b.pos.x==1500)
{
if(b.trashpos.x>900 && test==0)
{

//b.angle += 0.05;
//b.trashpos.x+=200 * cos(b.angle);
//b.trashpos.y+=sin(b.angle)*500;
printf("angle=%f \n",b.angle);
printf("y=%d\n",b.trashpos.y);



b.trashpos.x-=25;

}


else if((b.trashpos.x<=900) || test==1)
{
b.trashpos.x=1500;
//
b.trashpos.y=b.randy[rand()%3+1];
}


}


return b;

}




void afficher_boss1(boss1 b,SDL_Surface *screen)
{
SDL_BlitSurface(b.img,NULL,screen,&b.pos);
if(b.pos.x==600)
SDL_BlitSurface(b.trashimg,NULL,screen,&b.trashpos);

}




void afficher_boss11(boss1 b,SDL_Surface *screen)
{
SDL_BlitSurface(b.img,NULL,screen,&b.pos);
if(b.pos.x==1500)
SDL_BlitSurface(b.trashimg,NULL,screen,&b.trashpos);

}
