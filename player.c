#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "player.h"


player  init_player(player p)
{
 p.tab[0] = IMG_Load("perso/1.png");
 p.tab[1] = IMG_Load("perso/2.png");
 p.tab[2] = IMG_Load("perso/3.png");
 p.tab[3] = IMG_Load("perso/4.png");
 p.tab[4] = IMG_Load("perso/5.png");
 p.tab[5] = IMG_Load("perso/6.png");
 p.tab[6] = IMG_Load("perso/7.png");
 p.tab[7] = IMG_Load("perso/8.png");
 p.tab[8] = IMG_Load("perso/9.png");
 p.tab[9] = IMG_Load("perso/10.png");
 p.tab[10] = IMG_Load("perso/11.png");
 p.tab[11] = IMG_Load("perso/12.png");
 p.tab[12] = IMG_Load("perso/13.png");
/*background*/
 p.pos.x=655;
 p.pos.y=280;
p.fix.h=168;
p.fix.w=234;
p.fix.x=320;
p.fix.y=280;
return p;
}

void animation_player(int move,player p,SDL_Surface *ecran )
{
     //  SDL_BlitSurface(p.tab[6], NULL, ecran, &p.pos);/*backkkground*/

       SDL_BlitSurface(p.tab[move], NULL, ecran, &(p.fix));
       //SDL_Flip(ecran);
}

void free_player(player p)
{int i=0;
for(i = 0; i < 7 ; i++)
    SDL_FreeSurface(p.tab[i]);

}


int sprite_perso(int i,int input,SDL_Surface *screen,player perso)
{
if(input==1)
   {             if((i >=11 || i<7))
                i=6 ;
                (perso.pos).x-=5;
                i++; 
        }
                

else if(input==2){
                if((i >=5))
                i = 0;
		perso.pos.x+=5;
                i++;}
else 
//i=12;

//printf("i=%d\n",i);
       animation_player(i,perso,screen);


//SDL_Geticks
return i;
}
        
int deplacementvirtuel(int input,player perso)
{
       switch(input)
				{//5

					case 1 :
					//printf("pos perso=%d\n",perso.pos.x);
					if(perso.pos.x>655)
					perso.pos.x-=5;

					break;

                                       case 2 :
					//printf("pos perso=%d\n",perso.pos.x);
					if(perso.pos.x<6720)
					{perso.pos.x+=5;
					}
                                        break; 

}
return perso.pos.x;

}





player deplacementreel(int input,player perso)
{
       switch(input)
				{//5

					case 3 :
					if(perso.fix.y==280)
					{perso.fix.y=340;
					perso.pos.y=340;}
					else if(perso.fix.y==340)
					{perso.fix.y=420;
					perso.pos.y=420;}
                                   
					break;

                                       case 4 :
					
					if(perso.fix.y==420)
					{perso.fix.y=340;
					perso.pos.y=340;}
					else if(perso.fix.y==340)
					{perso.fix.y=280;
					perso.pos.y=340;}
                                        break; 

}

//printf("y=%d\n",perso.fix.y);
return perso;

}








