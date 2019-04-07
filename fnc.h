#ifndef FNC_H_
#define FNC_H_

typedef struct
{
SDL_Rect rect;
int pics;
int unicite;
SDL_Surface *img[20];
}entite_sec;

entite_sec entite_initialiser(int pics,entite_sec entite,char schema[50],int y);
entite_sec entite_initialiser2(int pics,entite_sec entite,char schema[50],int y);
int entite_gstion(int i,entite_sec entite);
int entite_afficher(SDL_Surface *screen,entite_sec entite,SDL_Rect camera,int i,int vitesse);

#endif
