#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "collisiontrigo.h"


int Collision_trigonometrique_circ_circ(SDL_Rect position_personnage,SDL_Rect position_objet,int y)
{
   float p_x,p_y,p_r;
   float obj_x,obj_y,obj_r;
   float d1,d2;
position_personnage.x=position_personnage.x%900;
printf("1  : %d \n",position_personnage.x);
//position_objet.x=position_objet.x%900;
printf("2 : %d \n",position_objet.x);

   p_x=position_personnage.x+(position_personnage.w/2);
   p_y=position_personnage.y+(position_personnage.h/2);
   p_r=sqrt((position_personnage.w/2)*(position_personnage.w/2)+(position_personnage.h/2)*(position_personnage.h/2));

   obj_x=position_objet.x+(position_objet.w/2);
   obj_y=position_objet.y+(position_objet.h/2);
   obj_r=sqrt((position_objet.w/2)*(position_objet.w/2)+(position_objet.h/2)*(position_objet.h/2));

   d2=p_r+obj_r;
   d1=sqrt((p_x-obj_x)*(p_x-obj_x)+(p_y-obj_y)*(p_y-obj_y));

   //printf("d2 rayon perso + rayon obj  => %f \n",d2);
  // printf("d1 distance entre centre des deu objet => %f \n",d1);
   //printf("position personnage=%d\n",position_personnage.x);
   if (d1<=d2)
    return 1; /* collision */
   else
    return 0; /* pas de  collision  */
      
}

int Collision_trigonometrique_inscr_iscr(SDL_Rect position_personnage,SDL_Rect position_objet)
{
   float p_x,p_y,p_r;
   float obj_x,obj_y,obj_r;
   float d1,d2;
position_personnage.x=position_personnage.x%900;
   p_x=position_personnage.x+(position_personnage.w/2);
   p_y=position_personnage.y+(position_personnage.h/2);
   if(position_personnage.w<position_personnage.h) {p_r=((position_personnage.w)/2);}
   else{p_r=((position_personnage.h)/2);}

   obj_x=position_objet.x+(position_objet.w/2);
   obj_y=position_objet.y+(position_objet.h/2);
   if (position_objet.w<position_objet.h){obj_r=((position_objet.w)/2);}
   else{obj_r=((position_objet.h)/2);}

   d2=p_r+obj_r;
   d1=sqrt((p_x-obj_x)*(p_x-obj_x)+(p_y-obj_y)*(p_y-obj_y));

   //printf("d2 rayon perso + rayon obj  => %f \n",d2);
  // printf("d1 distance  entre centre des deu objet => %f \n",d1);
   
   if (d1<=d2)
    return 1; /* collision */
   else
    return 0; /* pas de  collision  */
      
}

/*****************************************************************************************************/

/*int collision_trigo(SDL_Surface *perso  ,SDL_Surface *enemie,SDL_Rect posp,SDL_Rect pose )
{

int ra,rb,xb,xa,ya,yb,distance;
ra=(perso->w)/2;
xa=(posp.x+(perso->w/2));
ya=(posp.y+(perso->h/2));
rb=(enemie->w)/2;
xb=(pose.x+(enemie->w/2));
yb=(pose.y+(enemie->h/2));
distance=sqrt((xa-xb)*(xa-xb)+( ya+yb)*( ya+yb));
if(distance<=ra+rb)
{
return 1 ;
}
else
{
return 0;
}
}*/

/*int collision_trigo(SDL_Surface *P,SDL_Surface *E,SDL_Rect posP,SDL_Rect posE)
{
cercle C1,C2;
int d ;
C1.x=posP.x+P->w/2;
C1.y=posP.y+P->h/2;

C2.x=posE.x+E->w/2;
C2.y=posE.y+E->h/2;


C1.rayon=P->h/2;
C2.rayon=E->h/2;


d =sqrt((C1.x-C2.x)*(C1.x-C2.x) + (C1.y-C2.y)*(C1.y-C2.y));
   if (d > (C1.rayon + C2.rayon))

      return 0;

   else

      return 1;
}*/

/****************************************************************************************************/

/****************************************************************************************/
void capsule (SDL_Surface *ecran)
{
SDL_Surface *Menu_[1000],*back=NULL;
    SDL_Rect position,positionback;
back=IMG_Load("black.png");
char menu[500];
position.x=500;
position.y=500;
positionback.x=0;
positionback.y=0;
int j=1;

 for (j=1; j<=99; j++)
{
sprintf(menu,"capsule/%d.png",j);	
Menu_[j]=IMG_Load(menu);

//SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(Menu_[j],NULL,ecran,&position);
SDL_Flip(ecran);
//SDL_Delay(40);
SDL_FreeSurface(Menu_[j]);
}

}

void question (SDL_Surface *ecran)
{
SDL_Surface *Menu,*back=NULL;
SDL_Rect position,positionback;
back=IMG_Load("black.png");
char menu[500]="capsulee/1.png";
position.x=1200;
position.y=280;
positionback.x=0;
positionback.y=0;
int j=1;

Menu==IMG_Load(menu);

//SDL_BlitSurface(back,NULL,ecran,&positionback);
SDL_BlitSurface(Menu,NULL,ecran,&position);
//SDL_Flip(ecran);
//SDL_Delay(40);
//SDL_FreeSurface(Menu_[j]);
}



int gestion_collision(SDL_Rect rect_perso,SDL_Rect rect_objet,int y)
{

if(Collision_trigonometrique_circ_circ(rect_perso,rect_objet,y))
{
printf("\n*******************************************************collision\n");
return Collision_trigonometrique_circ_circ(rect_perso,rect_objet,y);
}
else 
return 0;
}



int collission(SDL_Rect p,SDL_Rect e,int y)
{
int verif =1;
p.x=p.x;
p.y=p.y;

e.x=e.x;
e.y=e.y;
int ga, gb; int da, db; int ta, tb; int ba, bb;
 
ga = e.x; da = e.x + e.w;
//Calculate the sides of rect B
//printf("*****************ga=%d\n",ga);
gb = p.x+100; db = p.x + p.w-100;
//If any of the sides from A are outside of B
//printf("*****************gb=%d\n",gb);
if((( da < gb )||( ga > db ) ) || (p.y!=y) )
{ verif= 0; }  

/*if( (! (  (p.x-e.x<150) && (p.x-e.x>-150 ) )) || (p.y!=y) )
//|| (0<=e.x-p.x && e.x-p.x<p.w)) || ((0<=p.y-e.y && p.y-e.y<p.h)|| (0<=e.y-p.y && e.x-p.y<p.h))
{verif=0;}*/

return verif;
}



