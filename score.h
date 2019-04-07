#ifndef _ENTITE_H
#define _ENTITE_H
#include"clock.h"

typedef struct 
{


TTF_Font *police;
SDL_Rect position ;  
SDL_Surface *texte;
int tempsActuel;
int  tempsPrecedent ;
int  compteur;
char chaine[20];
int e1,e2,e3,e4,e5;
int stg1,stg2;
} score ; 


score intialiser_score(score s);
score  gestion_score(int enig1,int enig2 , int enig3 ,int enig4 ,score s,SDL_Surface *ecran,int x);
void afficher_score(score s,SDL_Surface *ecran);
void free_score(score s,SDL_Surface *ecran);

int calcul_score(int val,score s,tempss temp);



#endif
