#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "score.h"
#include"clock.h"

score intialiser_score(score s)
{
   
    SDL_Color textcolor={33, 33, 33} ; 
    strcpy(s.chaine,"");
    s.tempsActuel = 0;
    s.tempsPrecedent =0;
    s.compteur =25000;
    s.police = TTF_OpenFont("texte.ttf", 60); 
    s.position.x = 650;
    s.position.y = 0;
    s.e1=0;
    s.e2=0;
    s.e3=0;
    s.e4=0;
    s.stg1=0;
    s.stg2=0;
        return s;     
}

score gestion_score(int enig1,int enig2 , int enig3 ,int enig4 ,score s,SDL_Surface *ecran,int x)
{
      SDL_Color couleurNoire = {30, 30, 30};
      SDL_Color  couleurBlanche = {255, 255, 255};
        
      sprintf(s.chaine, "score : %04d", s.compteur); 
      s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 

      s.tempsActuel = SDL_GetTicks();
        if (s.tempsActuel - s.tempsPrecedent <= 10000) 
        { 
            s.compteur -=2;
            sprintf(s.chaine, "score : %05d", s.compteur); 
            SDL_FreeSurface(s.texte);
          // s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
           s.texte = TTF_RenderText_Solid(s.police, s.chaine, couleurBlanche);
            s.tempsPrecedent = s.tempsActuel; 
	    }/*
        SDL_BlitSurface(s.texte, NULL, ecran, &s.position);
	    SDL_Flip(ecran);*/
        if ((enig1!=0)&&(s.e1==0))
        {printf("done2\n");
         s.e1=1;
         s.compteur += 5000;
         sprintf(s.chaine, "score : %05d", s.compteur); 
         SDL_FreeSurface(s.texte);
        //s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
         s.texte = TTF_RenderText_Solid(s.police, s.chaine, couleurNoire);
         s.tempsPrecedent = s.tempsActuel; 
        }
         if ((enig2!=0)&&(s.e2==0))
        {printf("done3\n");
         s.e2=1;
         s.compteur += 5000;
         sprintf(s.chaine, "score : %05d", s.compteur); 
         SDL_FreeSurface(s.texte);
        //s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
         s.texte = TTF_RenderText_Solid(s.police, s.chaine, couleurNoire);
         s.tempsPrecedent = s.tempsActuel; 
        }
         if ((enig3!=0)&&(s.e3==0))
        {printf("done4\n");
         s.e3=1;
         s.compteur += 5000;
         sprintf(s.chaine, "score : %05d", s.compteur); 
         SDL_FreeSurface(s.texte);
         //s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
         s.texte = TTF_RenderText_Solid(s.police, s.chaine, couleurNoire);
         s.tempsPrecedent = s.tempsActuel; 
        }
         if ((enig4!=0)&&(s.e4==0))
        {printf("done5\n");
         s.e4=1;
         s.compteur += 5000;
         sprintf(s.chaine, "score : %05d", s.compteur); 
         SDL_FreeSurface(s.texte);
         //s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
         s.texte = TTF_RenderText_Solid(s.police, s.chaine, couleurNoire);
         s.tempsPrecedent = s.tempsActuel; 
        }

	
if((x!=0) && (s.e5==0))
{
s.e5=1;
 s.compteur += 1000;
         sprintf(s.chaine, "score : %05d", s.compteur); 
         SDL_FreeSurface(s.texte);
         //s.texte = TTF_RenderText_Shaded(s.police, s.chaine, couleurNoire,couleurBlanche); 
         s.texte = TTF_RenderText_Solid(s.police, s.chaine, couleurNoire);
         s.tempsPrecedent = s.tempsActuel; 
}
        

return s;
}

void afficher_score(score s,SDL_Surface *ecran)
{  // SDL_FreeSurface(s.texte);

	SDL_BlitSurface(s.texte, NULL, ecran, &s.position);
    //SDL_Flip(ecran);   
}

void free_score(score s,SDL_Surface *ecran)
{
TTF_CloseFont(s.police);
TTF_Quit();
SDL_FreeSurface(s.texte);
printf("free score => done \n");
}

int calcul_score(int val,score s,tempss temp)
{
int res=0;
res=((temp.maxtemp/60)*1000)+(val*1000)+(s.compteur);
return res;
}
