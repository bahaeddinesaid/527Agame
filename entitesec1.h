#ifndef ENTITESEC1_H
#define ENTITESEC1_H

typedef struct 
{

SDL_Rect position;
SDL_Rect affiche;
SDL_Surface *Objet[1000];
char objet[500];
int seule;
int compteur;
int ta,tp;
}objet;



objet init_objet(objet o);
objet capsule1 (SDL_Surface *ecran,objet o,SDL_Rect camera,int input,int collision,int x);


#endif
