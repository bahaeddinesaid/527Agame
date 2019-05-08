#ifndef WARNING_H_INCLUDED
#define WARNING_H_INCLUDED
typedef struct
{
SDL_Surface *img[11];
SDL_Rect rect;
int playing;
int nb;
int x;

}warnin;
warnin init_warning(warnin warn,int x,int y);
warnin gestion(SDL_Rect camera,warnin warn,SDL_Surface *screen,int x,Mix_Chunk *sfx);

#endif
