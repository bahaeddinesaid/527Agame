#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "clock.h"

tempss inisaliser_temp_compteur (tempss temp,int diff)
{
if(diff==1)
{
temp.heur1=0;
temp.minute1=0;
temp.seconde1=0;

temp.tempactuel=0;
SDL_Color textcolor={33, 33, 33} ;  /*couleurNoire = {33, 33, 33}, couleurBlanche = {255, 255, 255}, rose = {85.1, 50.6, 57.3},violet = {146, 87, 226} */
temp.temp=NULL;

temp.tempprecedent=0;
strcpy(temp.chaine,"");
temp.position_temp.x=400;
temp.position_temp.y=0;
temp.police=TTF_OpenFont("texte.ttf",40);
temp.imgtemp=IMG_Load("img.jpg");
temp.position_imgtemp.x=400;
temp.position_imgtemp.y=0;
temp.maxtemp=300;  
    return temp;
}
else if(diff==2)
{
temp.heur1=0;
temp.minute1=0;
temp.seconde1=0;

temp.tempactuel=0;
SDL_Color textcolor={33, 33, 33} ;  /*couleurNoire = {33, 33, 33}, couleurBlanche = {255, 255, 255}, rose = {85.1, 50.6, 57.3},violet = {146, 87, 226} */
temp.temp=NULL;

temp.tempprecedent=0;
strcpy(temp.chaine,"");
temp.position_temp.x=400;
temp.position_temp.y=0;
temp.police=TTF_OpenFont("arial.ttf",40);
temp.imgtemp=IMG_Load("img.jpg");
temp.position_imgtemp.x=400;
temp.position_imgtemp.y=0;
temp.maxtemp=600;  
    return temp;
}

}

tempss gestion_temps_compteur(int pause_time_disc,int pause_time_pause,tempss temp,SDL_Surface *ecran)
{              
      if((pause_time_disc==0)&&(pause_time_pause==0)&&(temp.maxtemp!=0))     
   {    //      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));   

        temp.tempactuel = SDL_GetTicks();
        if (temp.tempactuel - temp.tempprecedent >=1000)
        {

            temp.seconde1 += 1;
           
            if(temp.seconde1 == 60)
            {
               temp.seconde1 = 0;
               temp.minute1+=1;
            }
            if(temp.minute1==60)
            {
               temp.seconde1 =0;
              
               temp.minute1 =0;
               temp.heur1+=1;
            }
            if(temp.heur1==60)
            {
               temp.seconde1 = 0;
               
               temp.minute1 =0;
               temp.heur1=0;

            }

            sprintf(temp.chaine, "%02d : %02d : %02d ",temp.heur1,temp.minute1,temp.seconde1 );
              
           temp.temp = TTF_RenderText_Solid(temp.police, temp.chaine, temp.textcolor);
           temp.tempprecedent=temp.tempactuel;
        }
     
            
        SDL_BlitSurface(temp.temp, NULL, ecran, &temp.position_temp);
        
    return temp;
  }
return temp;           
}

void free_temps(tempss temp)
{
TTF_CloseFont(temp.police);
TTF_Quit();
SDL_FreeSurface(temp.temp);
SDL_FreeSurface(temp.imgtemp);
printf("free temps => done \n");
}

tempss inisaliser_temp_decompteur  (tempss temp,int diff )
{
if(diff==1)
{
temp.heur1=0;
temp.minute1=4;
temp.seconde1=60;

temp.tempactuel=0;
SDL_Color textcolor={255,255,255};
temp.temp=NULL;

temp.tempprecedent=0;
strcpy(temp.chaine,"");
temp.position_temp.x=100;
temp.position_temp.y=0;
temp.police=TTF_OpenFont("texte.ttf",60);
temp.imgtemp=IMG_Load("img.jpg");
temp.position_imgtemp.x=100;
temp.position_imgtemp.y=0;
temp.maxtemp=295;
//295
    return temp;
}
else if(diff==2)
{
temp.heur1=0;
temp.minute1=9;
temp.seconde1=60;

temp.tempactuel=0;
SDL_Color textcolor={255,255,255};
temp.temp=NULL;

temp.tempprecedent=0;
strcpy(temp.chaine,"");
temp.position_temp.x=100;
temp.position_temp.y=0;
temp.police=TTF_OpenFont("texte.ttf",60);
temp.imgtemp=IMG_Load("img.jpg");
temp.position_imgtemp.x=100;
temp.position_imgtemp.y=0;
temp.maxtemp=590;
    return temp;
}

}


tempss gestion_temps_decompteur(int pause_time_disc,int pause_time_pause ,tempss temp,SDL_Surface *ecran)
{
   
 if((pause_time_disc==0)&&(pause_time_pause==0)&&(temp.maxtemp!=0))     
   {    

          //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));    
    temp.tempactuel = SDL_GetTicks();
        if (temp.tempactuel - temp.tempprecedent >=1000)
        {
            temp.seconde1-=1;
            temp.maxtemp--; 
            printf("max temp ====>  %d <===\n",temp.maxtemp);  
            if((temp.seconde1 == 0)&&(temp.maxtemp>0))
            {
               temp.seconde1 = 59;
               temp.minute1-=1;
            }
                                 

           sprintf(temp.chaine, "%02d : %02d : %02d ",temp.heur1,temp.minute1,temp.seconde1 );
           
           temp.temp = TTF_RenderText_Solid(temp.police, temp.chaine, temp.textcolor);
           temp.tempprecedent=temp.tempactuel;
        }
        
   
        SDL_BlitSurface(temp.temp, NULL, ecran, &temp.position_temp);
    
    return temp;
  }
return temp;

}
