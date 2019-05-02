#ifndef _AI_H
#define _AI_H


typedef struct ennemie
{

int image;
int direction;
SDL_Rect pos,poszolat,affiche;
SDL_Surface *tab[16],*tab2[12],*tab3[20],*zolat[8];
int etat;
int etat2,etat3,etat4,etat5;
int p1,p2,zol;
int attack;
int test;
int collision;


}ennemie;

ennemie initialiser_ennemie(ennemie e);
ennemie deplacer_ennemie(SDL_Rect camera,ennemie e ,SDL_Surface *ecran, SDL_Rect pos,SDL_Rect positionperso,int input);






#endif
