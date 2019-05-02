#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_rotozoom.h>
#include "ai.h"

ennemie initialiser_ennemie(ennemie e)
{

e.collision=0;
e.attack=0;
e.test=0;
 e.direction=1;
e.etat=0;
 e.pos.x=900;
 e.pos.y=280;
 e.pos.w=100;
e.affiche.x=3600;
e.affiche.y=280;
 e.pos.h=200;
e.poszolat.x=e.pos.x;
e.poszolat.y=e.pos.y+(e.pos.h/2);

 e.tab[0] = IMG_Load("walk/0.png");
 e.tab[0]=rotozoomSurface(e.tab[0],0,0.1383125,0.1607717);
 e.tab[1] = IMG_Load("walk/1.png");
 e.tab[1]=rotozoomSurface(e.tab[1],0,0.1383125,0.1607717);
 e.tab[2] = IMG_Load("walk/2.png");
  e.tab[2]=rotozoomSurface(e.tab[2],0,0.1383125,0.1607717);
 e.tab[3] = IMG_Load("walk/3.png");
 e.tab[3]=rotozoomSurface(e.tab[3],0,0.1383125,0.1607717);
 e.tab[4] = IMG_Load("walk/4.png");
  e.tab[4]=rotozoomSurface(e.tab[4],0,0.1383125,0.1607717);
 e.tab[5] = IMG_Load("walk/5.png");
  e.tab[5]=rotozoomSurface(e.tab[5],0,0.1383125,0.1607717);
 e.tab[6] = IMG_Load("walk/6.png");
  e.tab[6]=rotozoomSurface(e.tab[6],0,0.1383125,0.1607717);
 e.tab[7] = IMG_Load("walk/7.png");
  e.tab[7]=rotozoomSurface(e.tab[7],0,0.1383125,0.1607717);
 e.tab[8] = IMG_Load("walk/8.png");
  e.tab[8]=rotozoomSurface(e.tab[8],0,0.1383125,0.1607717);
 e.tab[9] = IMG_Load("walk/9.png");
  e.tab[9]=rotozoomSurface(e.tab[9],0,0.1383125,0.1607717);
 e.tab[10] = IMG_Load("walk/10.png");
  e.tab[10]=rotozoomSurface(e.tab[10],0,0.1383125,0.1607717);
 e.tab[11] = IMG_Load("walk/11.png");
  e.tab[11]=rotozoomSurface(e.tab[11],0,0.1383125,0.1607717);
 e.tab[12] = IMG_Load("walk/12.png");
 e.tab[12]=rotozoomSurface(e.tab[12],0,0.1383125,0.1607717);
 e.tab[13] = IMG_Load("walk/13.png");
 e.tab[13]=rotozoomSurface(e.tab[13],0,0.1383125,0.1607717);
 e.tab[14] = IMG_Load("walk/14.png");
 e.tab[14]=rotozoomSurface(e.tab[14],0,0.1383125,0.1607717);
 e.tab[15] = IMG_Load("walk/15.png");
 e.tab[15]=rotozoomSurface(e.tab[15],0,0.1383125,0.1607717);
/********************************************************************************************************************/
 e.tab2[0] = IMG_Load("YJRI/0.png");
 e.tab2[0]=rotozoomSurface(e.tab2[0],0,0.1494,0.1626);
 e.tab2[1] = IMG_Load("YJRI/1.png");
 e.tab2[1]=rotozoomSurface(e.tab2[1],0,0.1494,0.1626);
 e.tab2[2] = IMG_Load("YJRI/2.png");
 e.tab2[2]=rotozoomSurface(e.tab2[2],0,0.1494,0.1626);
 e.tab2[3] = IMG_Load("YJRI/3.png");
 e.tab2[3]=rotozoomSurface(e.tab2[3],0,0.1494,0.1626);
 e.tab2[4] = IMG_Load("YJRI/4.png");
 e.tab2[4]=rotozoomSurface(e.tab2[4],0,0.1494,0.1626);
 e.tab2[5] = IMG_Load("YJRI/5.png");
 e.tab2[5]=rotozoomSurface(e.tab2[5],0,0.1494,0.1626);
 e.tab2[6] = IMG_Load("YJRI/6.png");
 e.tab2[6]=rotozoomSurface(e.tab2[6],0,0.1494,0.1626);
 e.tab2[7] = IMG_Load("YJRI/7.png");
 e.tab2[7]=rotozoomSurface(e.tab2[7],0,0.1494,0.1626);
 e.tab2[8] = IMG_Load("YJRI/8.png");
 e.tab2[8]=rotozoomSurface(e.tab2[8],0,0.1494,0.1626);
 e.tab2[9] = IMG_Load("YJRI/9.png");
 e.tab2[9]=rotozoomSurface(e.tab2[9],0,0.1494,0.1626);
 e.tab2[10] = IMG_Load("YJRI/10.png");
 e.tab2[10]=rotozoomSurface(e.tab2[10],0,0.1494,0.1626);
 e.tab2[11] = IMG_Load("YJRI/11.png");
 e.tab2[11]=rotozoomSurface(e.tab2[11],0,0.1494,0.1626);
/******************************************************************************************************************************/
 e.tab3[0] = IMG_Load("attack1/1.png");
 e.tab3[0]=rotozoomSurface(e.tab3[0],0,1.5*0.1018,0.1642 ); /*    0.1018,0.1642        */
 e.tab3[1] = IMG_Load("attack1/2.png");
 e.tab3[1]=rotozoomSurface(e.tab3[1],0,1.5*0.1018,0.1642);
 e.tab3[2] = IMG_Load("attack1/3.png");
 e.tab3[2]=rotozoomSurface(e.tab3[2],0,1.5*0.1018,0.1642);
 e.tab3[3] = IMG_Load("attack1/4.png");
 e.tab3[3]=rotozoomSurface(e.tab3[3],0,1.5*0.1018,0.1642);
 e.tab3[4] = IMG_Load("attack1/5.png");
 e.tab3[4]=rotozoomSurface(e.tab3[4],0,1.5*0.1018,0.1642);
 e.tab3[5] = IMG_Load("attack1/6.png");
 e.tab3[5]=rotozoomSurface(e.tab3[5],0,1.5*0.1018,0.1642);
 e.tab3[6] = IMG_Load("attack1/7.png");
 e.tab3[6]=rotozoomSurface(e.tab3[6],0,1.5*0.1018,0.1642);
 e.tab3[7] = IMG_Load("attack1/8.png");
 e.tab3[7]=rotozoomSurface(e.tab3[7],0,1.5*0.1018,0.1642);
 e.tab3[8] = IMG_Load("attack1/9.png");
 e.tab3[8]=rotozoomSurface(e.tab3[8],0,1.5*0.1018,0.1642);
 e.tab3[9] = IMG_Load("attack1/10.png");
 e.tab3[9]=rotozoomSurface(e.tab3[9],0,1.5*0.1018,0.1642);
 e.tab3[10] = IMG_Load("attack1/11.png");
 e.tab3[10]=rotozoomSurface(e.tab3[10],0,1.5*0.1018,0.1642);
 e.tab3[11] = IMG_Load("attack1/12.png");
 e.tab3[11]=rotozoomSurface(e.tab3[11],0,1.5*0.1018,0.1642);
 e.tab3[12] = IMG_Load("attack1/13.png");
 e.tab3[12]=rotozoomSurface(e.tab3[12],0,1.5*0.1018,0.1642);
 e.tab3[13] = IMG_Load("attack1/14.png");
 e.tab3[13]=rotozoomSurface(e.tab3[13],0,1.5*0.1018,0.1642);
 e.tab3[14] = IMG_Load("attack1/15.png");
 e.tab3[14]=rotozoomSurface(e.tab3[14],0,1.5*0.1018,0.1642);  
 e.tab3[15] = IMG_Load("attack1/16.png");
 e.tab3[15]=rotozoomSurface(e.tab3[15],0,1.5*0.1018,0.1642);
 e.tab3[16] = IMG_Load("attack1/17.png");
 e.tab3[16]=rotozoomSurface(e.tab3[16],0,1.5*0.1018,0.1642);
 e.tab3[17] = IMG_Load("attack1/18.png");
 e.tab3[17]=rotozoomSurface(e.tab3[17],0,1.5*0.1018,0.1642);
 e.tab3[18] = IMG_Load("attack1/19.png");
 e.tab3[18]=rotozoomSurface(e.tab3[18],0,1.5*0.1018,0.1642);
 e.tab3[19] = IMG_Load("attack1/20.png");
 e.tab3[19]=rotozoomSurface(e.tab3[19],0,1.5*0.1018,0.1642);
 /*******************************************************************************************************************************/
e.zolat[0]= IMG_Load("zolat/1.png");
e.zolat[0]=rotozoomSurface(e.zolat[0],0,0.23474,1);
e.zolat[1]= IMG_Load("zolat/2.png");
e.zolat[1]=rotozoomSurface(e.zolat[0],45,0.23474,1);
e.zolat[2]= IMG_Load("zolat/3.png");
e.zolat[2]=rotozoomSurface(e.zolat[0],90,0.23474,1);
e.zolat[3]= IMG_Load("zolat/4.png");
e.zolat[3]=rotozoomSurface(e.zolat[0],135,0.23474,1);
e.zolat[4]= IMG_Load("zolat/5.png");
e.zolat[4]=rotozoomSurface(e.zolat[0],180,0.23474,1);
e.zolat[5]= IMG_Load("zolat/6.png");
e.zolat[5]=rotozoomSurface(e.zolat[0],225,0.23474,1);
e.zolat[6]= IMG_Load("zolat/7.png");
e.zolat[6]=rotozoomSurface(e.zolat[0],250,0.23474,1);
e.zolat[7]= IMG_Load("zolat/8.png");
e.zolat[7]=rotozoomSurface(e.zolat[0],295,0.23474,1);


 /*************************************************************************************************************************/
 e.p1=0;
 e.p2=0;
 e.etat=8;
 e.etat2=6;
 e.etat3=0; 
 e.etat4=0;
 e.etat5=10;
 e.zol=0;

return e;
}

ennemie deplacer_ennemie(SDL_Rect camera,ennemie e ,SDL_Surface *ecran, SDL_Rect pos,SDL_Rect positionperso,int input)
{int i=0;
int d=e.pos.x-(positionperso.x+positionperso.w);
if(e.pos.y!=positionperso.y)
{
e.etat5=10;
e.etat4=0;
}
if((e.pos.y==positionperso.y) && (d<-350 && d>-900))
e.test=1;
printf("test= %d \n",e.test);
/*
e.poszolat.x=e.pos.x+e.pos.w;
e.poszolat.y=e.pos.y+(e.pos.h/2);*/
if(camera.x>=e.affiche.x-900 && camera.x<=e.affiche.x)
{
if(input==2)
{//3
if(e.pos.x>0)
e.pos.x-=5;
e.poszolat.x-=5;

}//3
else if(input==1)
{//4

e.pos.x+=5;
e.poszolat.x+=5;

}
}
//printf("XXXXXXXXXXXXXXXXXXXXdistance=%d \n",d);

//printf("distance  %d \n",d );
/*
if(((d<=0)&&(d>=-180))&&(e.pos.y==positionperso.y))
{


printf("position mt3 personnage raja3ha ltalli 9bal position .x - 200 idk \n");
printf("arrrested nhotouuuuuuuuuuuuuuuuuuuuuuu taswira  t3ibit :p \n");
printf("tchaad tchaad tchaad \n");
return e;
}*/
/*********************************************************************************************************************************/

//Attack


if(((d<=-121)&&(d>=-250)) && (e.pos.y==positionperso.y))
{


if(e.direction==1)
{
e.p1 = SDL_GetTicks();
/*if (e.p1 - e.p2 >=500 )
{*/
 // SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 33, 33));
//if(camera.x>=e.affiche.x-900 && camera.x<=e.affiche.x)
SDL_BlitSurface(e.tab3[e.etat5], NULL, ecran, &e.pos);
//printf("etat 5 attack1   %d \n",e.etat5 );
//SDL_Flip(ecran);

e.p2=e.p1;
if(e.etat5<19){e.etat5++;}
else{e.etat5=10;}

if(e.etat5==18)
e.collision=1;
return e;

}
//}
else
{
e.p1 = SDL_GetTicks();
/*if (e.p1 - e.p2 >=500 )
{*/
 // SDL_FillRect(ecran, NULL, //SDL_MapRGB(ecran->format, 33, 33, 33));
//if(camera.x>=e.affiche.x-900 && camera.x<=e.affiche.x)
SDL_BlitSurface(e.tab3[e.etat4], NULL, ecran, &e.pos);
printf("etat 4 attack1   %d \n",e.etat4 );
//SDL_Flip(ecran);
e.p2=e.p1;
if(e.etat4<9){e.etat4++;}
else{e.etat4=0;}

if(e.etat4==8)
e.collision=1;
return e;
}

//}//


printf("mna3  \n");
printf("direction %d \n",e.direction );
return e;
}
/***************************************************************************************************************************/

//RUNING LEFT 


else if((d>=-120)&&(d<=150) &&(e.pos.y==positionperso.y) )
{
if((d>=-120)&&(d<=150))
{
e.p1 = SDL_GetTicks();
/*if (e.p1 - e.p2 >=300 )
{*/
e.direction=1;	
if((e.direction==1)&&(e.pos.x>positionperso.x)){e.pos.x-=8;e.poszolat.x-=8;e.affiche.x-=8;}
else if((e.direction==1)&&(e.pos.x<=positionperso.x)){e.direction=0;if(e.zol==8){e.zol=0;}e.pos.x+=10;e.poszolat.x-=8;e.affiche.x-=8;}


 // SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 33, 33));
//if(camera.x>=e.affiche.x-900 && camera.x<=e.affiche.x)
SDL_BlitSurface(e.tab2[e.etat2], NULL, ecran, &e.pos);
/*printf("pos e :x %d \n",e.pos.x );
printf("etat running left  %d \n",e.etat2 );*/
printf("d %d \n",d );
//SDL_Flip(ecran);
e.p2=e.p1;
if(e.etat2<10){e.etat2++;}
else{e.etat2=6;}
}
//}
return e;
}
/****************************************************************************************************************************************************************************/

//RUNINING RIGHT 

else if( (d<-350 && d>-900) && e.test==1 && e.attack==0)
{
printf("-------------------------------------------------------------------\n");

/*
e.p1 = SDL_GetTicks();
  if (e.p1 - e.p2 >=300 )
{*/

e.direction=1;	
/*if((e.direction==1)&&(e.pos.x>positionperso.x)){e.pos.x-=10;}
else if((e.direction==1)&&(e.pos.x<=positionperso.x))
{e.direction=0;
e.pos.x+=10;}*/

//e.attackin=1;
//SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 33, 33));
if(e.zol==8){e.zol=0;}

if(e.zol<8)
{

e.poszolat.x+=20;
SDL_BlitSurface(e.zolat[e.zol], NULL, ecran, &e.poszolat);
e.zol++;
/*
printf("pos zolat x  %d \n",e.poszolat.x);
printf("pos zolat y %d \n",e.poszolat.y);
printf("e.zol %d \n",e.zol );*/
if(e.poszolat.x>900)
e.attack=1;
}


if(camera.x>=e.affiche.x-900 && camera.x<=e.affiche.x)
SDL_BlitSurface(e.tab2[e.etat3], NULL, ecran, &e.pos);
printf("POLICE(AFFICHE,POS) = (%d , %d ) \n",e.affiche.x,e.pos.x );
return e;
}
else if(d<=-200 && d>=-350 && e.pos.y==positionperso.y )
{

e.direction=1;	
if((e.direction==1)&&(e.pos.x>positionperso.x)){e.pos.x-=8;e.affiche.x-=8;}
else if((e.direction==1)&&(e.pos.x<=positionperso.x))
{e.direction=0;
if(e.zol==8){e.zol=0;}e.pos.x+=8;e.affiche.x+=8;}
/*
printf("pos e :x %d \n",e.pos.x );
printf("etat running  right %d \n",e.etat3 );
printf("d right %d  \n",d );*/
//SDL_Flip(ecran);

e.p2=e.p1;
if(e.etat3<4){e.etat3++;}
else{e.etat3=0;} 

if(camera.x>=e.affiche.x-900 && camera.x<=e.affiche.x)
SDL_BlitSurface(e.tab2[e.etat3], NULL, ecran, &e.pos);
printf("POLICE(AFFICHE,POS) = (%d , %d ) \n",e.affiche.x,e.pos.x );

//}


return e;
}	



/******************************************************************************************************************************************/


// walking
else
{
e.p1 = SDL_GetTicks();
//if (e.p1 - e.p2 >=500 )
//{
if((e.direction==1)&&(e.affiche.x>pos.y)){e.pos.x-=3;e.affiche.x-=3;e.poszolat.x-=3;}
else if((e.direction==1)&&(e.affiche.x<=pos.y)){e.direction=0;e.etat=0;e.pos.x+=3;e.affiche.x+=3;e.poszolat.x+=3;}
else if((e.direction==0)&&(e.affiche.x<pos.x)){e.pos.x+=3;e.affiche.x+=3;e.poszolat.x+=3;}
else {e.direction=1;e.etat=8;}

   //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 33, 33));
if(camera.x>=e.affiche.x-900 && camera.x<=e.affiche.x)
SDL_BlitSurface(e.tab[e.etat], NULL, ecran, &e.pos);
/*printf(" pos  pos e :x %d \n",e.pos.x );
printf("etat walking  %d \n",e.etat );
printf("direction %d \n",e.direction );*/

//SDL_Flip(ecran);
e.p2=e.p1;
if((e.direction==1)&&(e.etat<15)){e.etat++;} 
else if(e.etat==15){e.etat=8;}
else if((e.direction==0)&&(e.etat<7)){e.etat++;}
else{e.etat=0;}
/*
if(e.attackin==1)
{
if(e.zol==8)
e.zol=0;
if(e.zol<8)
{

e.poszolat.x+=20;
SDL_BlitSurface(e.zolat[e.zol], NULL, ecran, &e.poszolat);
e.zol++;

printf("pos zolat x  %d \n",e.poszolat.x);
printf("pos zolat y %d \n",e.poszolat.y);
printf("e.zol %d \n",e.zol );
if(e.poszolat.x>900)
e.attack=1;
}
}*/

}
//printf("//////////////////e.x,e.y || pos.x,pos.y : (%d,%d) || (%d,%d) \n ",e.pos.x,e.pos.y,pos.x,pos.y);
//printf("Camera.x,e.affiche=(%d , %d,%d) \n  ////////////",camera.x,e.affiche.x,e.pos.x);

//printf("POLICE(AFFICHE,POS) = (%d , %d ) \n",e.affiche.x,e.pos.x );
printf("drction= %d \n",e.direction);
printf(" e.affiche , posy, posx : (%d,%d,%d)\n",e.affiche.x,pos.y,pos.x);
return e;

}

//}




