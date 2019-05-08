#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "player.h"
#include "jeu.h"


player jouer(player per,int input)
{
	int done = 0;
int keysHeld[323] = {0};
	

	

	


	// program Game loop



			if(input==3)
				per.moving=1; //move

			if(input==4)
				per.moving=0;
				

			
			// exit if right is pressed
			

if(input==2)
{				
per.acceleration+=0.05;				
}
//				per.direction=0; //right direction
if(per.vitesse<=17)
per.vitesse+=per.velocity/per.dt+per.acceleration;

				//i++;
			//}

		 // end of message processing
		//i=i%4;
		/*//Blit the bachground to the backbuffer
		blitBackground(&Backg,screen);

		//Blit personne to screen
		if(!per.moving)
			i=0;
		if(per.direction == 0)
			SDL_BlitSurface(per.image[i],NULL,screen,&per.position);
			
*/

	per.dt=SDL_GetTicks()-per.tempsactuel;	

if(per.acceleration<0)
per.acceleration=0;
		//SDL_Flip(screen);
		

		
//printf("veo = %f\n",per.velocity);
	

	                // free loaded bitmap

	/*freePersonne(&per);
	freeBackground(&Backg);
	

    TTF_Quit();	*/
	return per;
}
