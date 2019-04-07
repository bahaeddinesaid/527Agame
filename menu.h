#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>




typedef struct
{
char schema[500][500];
int nb;
int vitesse;
char format[10];
SDL_Rect pos;
}image_menu;

typedef struct
{
char schema[500];
SDL_Rect rect;
}boutton;


SDL_Surface* openwindow(SDL_Surface *ecran);

/////////////////////////////////////////////////////////////////////////////////
// FCTS FOR INTRO         ********************************
image_menu init_menu(image_menu image,int j,char schema[500],int vitesse,char format[10]);
void afficher_menu(image_menu image,SDL_Surface *ecran);

boutton init_boutton(boutton b,char schema[500],float x,float y);
SDL_Surface* afficher_boutton(boutton b,SDL_Surface *ecran);

void afficher_loading(image_menu image,SDL_Surface *ecran);


//INTRO ****************************************
void intro(image_menu logo,image_menu debut,image_menu affiche,image_menu loading,SDL_Surface *ecran);


// BOUTTONS  *******************************
void bouttons(boutton logofb,boutton soundon,boutton soundoff,SDL_Surface *ecran);



//CHOICE ********************************************
int input_menu(int i,SDL_Event event,int choose,int continuer);
int update_menu(int input,int i,SDL_Surface *ecran);


//SOUNDS *********************************




#endif
