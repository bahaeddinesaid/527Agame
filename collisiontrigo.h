#ifndef COLLISIONTRIGO_INCLUDED
#define COLLISIONTRIGO_INCLUDED


void capsule (SDL_Surface *ecran);
void question (SDL_Surface *ecran);
int Collision_trigonometrique_circ_circ(SDL_Rect position_personnage,SDL_Rect position_objet,int y);
int Collision_trigonometrique_inscr_iscr(SDL_Rect position_personnage,SDL_Rect position_objet);
int gestion_collision(SDL_Rect rect_perso,SDL_Rect rect_objet,int y);
int collission(SDL_Rect p,SDL_Rect e,int y);


#endif
