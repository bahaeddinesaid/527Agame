#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED

typedef struct
{
SDL_Surface *image;
SDL_Rect pos;
}point;

typedef struct
{
SDL_Surface *image;
SDL_Rect pos;
point p;

}minimap;


minimap init_minimap(SDL_Surface *map);
minimap gestion_minimap(minimap mm,SDL_Surface *screen,SDL_Rect camera);

#endif
