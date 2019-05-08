#ifndef DJ_H
#define DJ_H


void UpdateEvents(Sint32* mousex,Sint32* mousey,char boutons[8],char key[SDLK_LAST]);
void SDL_PutPixel32(SDL_Surface *surface, int x, int y, Uint32 pixel);
void affichedj(SDL_Surface* screen,SDL_Surface* ecran);

#endif
