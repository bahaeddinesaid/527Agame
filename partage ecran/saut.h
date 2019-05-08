#ifndef SAUT_H_
#define SAUT_H_

typedef struct image
{
	SDL_Surface *back;//wyn chnachargo image
	SDL_Rect posPicture;// Position mta3 background
}image;

typedef struct
{
	int status;
	float x,y;
	float vx,vy;
}Sprite;

void InitSprite(Sprite* Sp);
void Render(Sprite* Sp,SDL_Surface* screen);
int Evolue(Sprite* Sp,Uint8* keys,int jump);
image init_image(char nameofpicture[100],int x,int y);
void affichage(SDL_Surface *ecran,image img);
void Music_enigme();
void sound_wrong();
void sound_correct();
void sound_win();
int verif_enigme();
void librer_image(image img);


#endif
