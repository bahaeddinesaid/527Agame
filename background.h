#ifndef BACKGROUND_INCLUDED
#define BACKGROUND_INCLUDED
#include"clock.h"
#include"score.h"
#include"player.h"

//SDL_Surface* openwindow(SDL_Surface *screen);
SDL_Surface* init_background(SDL_Surface *screen,char bg[50]);
int INPUT_STAGE1(SDL_Event event);
int scrolling(SDL_Surface *screen,SDL_Surface *stg1,int input,SDL_Rect camera,SDL_Event event);
tempss click(SDL_Surface *screen,SDL_Surface *stg1,SDL_Rect camera,tempss temp2,score scor,int *done,int x,player perso);
void discussion(SDL_Surface *screen,char background[50],char schema[100],char extension[10],char bgformat[10],int nb,SDL_Rect postxt);

#endif

