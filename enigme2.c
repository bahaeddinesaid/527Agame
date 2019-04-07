#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <string.h>
#include"clock.h"

tempss enigme2(tempss temp2,int done[])

{

    int win=0,produit1,produit2,produit3,somme,result,debut=0,quantite1,quantite2,quantite3,prix1,prix2,prix3,nbre=0;
    char *name;
    char *mot;
    name=calloc(20,sizeof(char));
    mot=calloc(6,sizeof(char));
    char produits[18][20]= {{"ma9arouna_randa"},{"zit"},{"5obez"},{"Coca-Cola"},{"florida"},{"yaghoret_vitalait"},{"jus_tropico"},{"prince"},{"Pile"},{"Ooredoo"},{"oumou_nadhif"},{"malsou9a"},{"7okajben_vitalait"},{"rayeb_delice"},{"ma2_safia"},{"Tmatem_Sicam"},{"7lib_delice"},{"3adham"}};

    SDL_Surface *ecran=NULL,*ligne=NULL,*texteproduit1=NULL,*texteproduit2=NULL,*zoneSaisie=NULL,*feuille=NULL;
    SDL_Surface *bg=NULL,*amstoura=NULL,*feuilleDesprix=NULL,*stylo=NULL;
    SDL_Surface *nomproduit1=NULL,*nomproduit2=NULL,*texteproduit3=NULL,*nomproduit3=NULL,*textetemp=NULL;
    SDL_Rect positiontextproduit2,positiontextproduit1,poszoneSaisie,posfeuille,posbg,posligne,positiontextproduit3;
    SDL_Rect posamstoura,posprix,posstylo,posnomproduit1,posnomproduit2,posnomproduit3,positiontextemp;
    SDL_Event event;
    TTF_Font *police = NULL,*police2 = NULL;
    SDL_Color couleurNoire = {33, 33, 33}, couleurBlanche = {255, 255, 255}, rose = {85.1, 50.6, 57.3},violet = {146, 87, 226};
    SDL_Color maron = {110,75,55}, bleu = {8,74,74},bleutemp = {0,0,53};
    int continuer = 1;
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    char temps[20]="",produit1ab[500]="",produit2ab[500]="",produit3ab[500]="",sommetab[500]="kk",nomp1[500]="",nomp2[500]= "",nomp3[500]= "";
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    ecran = SDL_SetVideoMode(900, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){printf("%s",Mix_GetError()); }
    Mix_Chunk *correct,*wrong; 
    correct = Mix_LoadWAV("sound/correct.wav");
    wrong = Mix_LoadWAV("sound/wrong.wav");
    /* Chargement de la police */
    police = TTF_OpenFont("ok.ttf", 50);
    police2 = TTF_OpenFont("arial.ttf", 22);
   

    textetemp = TTF_RenderText_Shaded(police2, temps, couleurNoire, couleurBlanche);
    texteproduit1 = TTF_RenderText_Shaded(police, produit1ab, couleurBlanche, couleurNoire);
    texteproduit2 = TTF_RenderText_Shaded(police, produit2ab, couleurBlanche, couleurNoire);
    texteproduit3 = TTF_RenderText_Shaded(police, produit3ab, couleurBlanche, couleurNoire);
    nomproduit1 = TTF_RenderText_Shaded(police2, nomp1, couleurBlanche, couleurNoire);
    nomproduit2 = TTF_RenderText_Shaded(police2, nomp2, couleurBlanche, couleurNoire);
    nomproduit3 = TTF_RenderText_Shaded(police2, nomp3, couleurBlanche, couleurNoire);

    feuille=IMG_Load("img/feuille.png");
    bg=IMG_Load("img/BG.png");
    amstoura=IMG_Load("img/3amstoura.png");
    ligne=IMG_Load("img/ligne.png");
    stylo=IMG_Load("img/stylo.png");
    feuilleDesprix=IMG_Load("img/prix.png");

    posprix.x = 0;
    posprix.y = 0;
    posligne.x = 0;
    posligne.y = 0;

//////////////////////////////////////////////////////////////////////////////
    srand(time(NULL));
    produit1=rand() % 18 + 0;// valeur in the range 100000-200000
    produit2=rand() % 18 + 0;// valeur in the range 100000-170000
    produit3=rand() % 18 + 0;// valeur in the range 100000-170000

    printf("produit  %s \n",produits[produit1]);
    printf("produit  %s \n",produits[produit2]);
    printf("produit  %s \n",produits[produit3]);
    printf("\n");
    quantite1=rand() % 3 + 1;
    quantite2=rand() % 3 + 1;
    quantite3=rand() % 3 + 1;

    printf("quantite %d \n",quantite1);
    printf("quantite %d \n",quantite2);
    printf("quantite %d \n",quantite3);
    while(quantite1==quantite2)
    {
        quantite1=rand() % 3 + 1;
        quantite2=rand() % 3 + 1;
        quantite3=rand() % 3 + 1;
    }

    while(produit1==produit2 || produit2==produit3)
    {
        produit1=rand() % 18 + 0;// valeur in the range 100000-200000
        produit2=rand() % 18 + 0;// valeur in the range 100000-170000
        produit3=rand() % 18 + 0;// valeur in the range 100000-170000
    }

    printf("\n");
////////////////////////////////////////////////
    if(produit1==0)
    {
        prix1=500;//ma9arouna
        strcpy(nomp1,"Ma9arouna_randa");
    }
    if(produit1==1)
    {
        prix1=1100;//zit
        strcpy(nomp1,"Zit");
    }
    if(produit1==2)
    {
        prix1=200;//5obez
        strcpy(nomp1,"5obez");
    }
    if(produit1==3)
    {
        prix1=2400;//gazouz
        strcpy(nomp1,"Coca-Cola");
    }
    if(produit1==4)
    {
        prix1=50;//florida
        strcpy(nomp1,"Florida");
    }
    if(produit1==5)
    {
        prix1=400;//yaghort
        strcpy(nomp1,"yaghoret_vitalait");
    }
    if(produit1==6)
    {
        prix1=800;//jus
        strcpy(nomp1,"jus_tropico");
    }
    if(produit1==7)
    {
        prix1=350;//prince
        strcpy(nomp1,"Prince");
    }
    if(produit1==8)
    {
        prix1=300;//Pilet
        strcpy(nomp1,"Pila");
    }
    if(produit1==9)
    {
        prix1=1250;//ooredoo
        strcpy(nomp1,"Ticket_Ooredoo");
    }
    if(produit1==10)
    {
        prix1=600;//oumou
        strcpy(nomp1,"oumou_nadhif");
    }
    if(produit1==11)
    {
        prix1=90;//malsou9a
        strcpy(nomp1,"malsou9a");
    }
    if(produit1==12)
    {
        prix1=1850;//7okajben
        strcpy(nomp1,"7okajben_vitalait");
    }
    if(produit1==13)
    {
        prix1=920;//Rayeb
        strcpy(nomp1,"rayeb_delice");
    }
    if(produit1==14)
    {
        prix1=700;//ma2
        strcpy(nomp1,"ma2_safia");
    }
    if(produit1==15)
    {
        prix1=1725;//Tmatem_Sicam_400_G
        strcpy(nomp1,"Tmatem_Sicam");
    }
    if(produit1==16)
    {
        prix1=1120;//7lib
        strcpy(nomp1,"7lib_delice");
    }
    if(produit1==17)
    {
        prix1=250;//3adhem
        strcpy(nomp1,"3adham");
    }
///////////////////////////////////////////////////////////////////
    if(produit2==0)
    {
        prix2=500;//ma9arouna
        strcpy(nomp2,"Ma9arouna_randa");
    }
    if(produit2==1)
    {
        prix2=1100;//zit
        strcpy(nomp2,"Zit");
    }
    if(produit2==2)
    {
        prix2=200;//5obez
        strcpy(nomp2,"5obez");
    }
    if(produit2==3)
    {
        prix2=2400;//gazouz
        strcpy(nomp2,"Coca-Cola");
    }
    if(produit2==4)
    {
        prix2=50;//florida
        strcpy(nomp2,"Florida");
    }
    if(produit2==5)
    {
        prix2=400;//yaghort
        strcpy(nomp2,"yaghoret_vitalait");
    }
    if(produit2==6)
    {
        prix2=800;//jus
        strcpy(nomp2,"jus_tropico");
    }
    if(produit2==7)
    {
        prix2=350;//prince
        strcpy(nomp2,"Prince");
    }
    if(produit2==8)
    {
        prix2=300;//Pilet
        strcpy(nomp2,"Pila");
    }
    if(produit2==9)
    {
        prix2=1250;//ooredoo
        strcpy(nomp2,"Ticket_Ooredoo");
    }
    if(produit2==10)
    {
        prix2=600;//oumou
        strcpy(nomp2,"oumou_nadhif");
    }
    if(produit2==11)
    {
        prix2=90;//malsou9a
        strcpy(nomp2,"malsou9a");
    }
    if(produit2==12)
    {
        prix2=1850;//7okajben
        strcpy(nomp2,"7okajben_vitalait");
    }
    if(produit2==13)
    {
        prix2=920;//Rayeb
        strcpy(nomp2,"rayeb_delice");
    }
    if(produit2==14)
    {
        prix2=700;//ma2
        strcpy(nomp2,"ma2_safia");
    }
    if(produit2==15)
    {
        prix2=1725;//Tmatem_Sicam_400_G
        strcpy(nomp2,"Tmatem_Sicam");
    }
    if(produit2==16)
    {
        prix2=1120;//7lib
        strcpy(nomp2,"7lib_delice");
    }
    if(produit2==17)
    {
        prix2=250;//3adhem
        strcpy(nomp2,"3adham");
    }
///////////////////////////////////////////////////////////////////
    if(produit3==0)
    {
        prix3=500;//ma9arouna
        strcpy(nomp3,"Ma9arouna_randa");
    }
    if(produit3==1)
    {
        prix3=1100;//zit
        strcpy(nomp3,"Zit");
    }
    if(produit3==2)
    {
        prix3=200;//5obez
        strcpy(nomp3,"5obez");
    }
    if(produit3==3)
    {
        prix3=2400;//gazouz
        strcpy(nomp3,"Coca-Cola");
    }
    if(produit3==4)
    {
        prix3=50;//florida
        strcpy(nomp3,"Florida");
    }
    if(produit3==5)
    {
        prix3=400;//yaghort
        strcpy(nomp3,"yaghoret_vitalait");
    }
    if(produit3==6)
    {
        prix3=800;//jus
        strcpy(nomp3,"jus_tropico");
    }
    if(produit3==7)
    {
        prix3=350;//prince
        strcpy(nomp3,"Prince");
    }
    if(produit3==8)
    {
        prix3=300;//Pilet
        strcpy(nomp3,"Pila");
    }
    if(produit3==9)
    {
        prix3=1250;//ooredoo
        strcpy(nomp3,"Ticket_Ooredoo");
    }
    if(produit3==10)
    {
        prix3=600;//oumou
        strcpy(nomp3,"oumou_nadhif");
    }
    if(produit3==11)
    {
        prix3=90;//malsou9a
        strcpy(nomp3,"malsou9a");
    }
    if(produit3==12)
    {
        prix3=1850;//7okajben
        strcpy(nomp3,"7okajben_vitalait");
    }
    if(produit3==13)
    {
        prix3=920;//Rayeb
        strcpy(nomp3,"rayeb_delice");
    }
    if(produit3==14)
    {
        prix3=700;//ma2
        strcpy(nomp3,"ma2_safia");
    }
    if(produit3==15)
    {
        prix3=1725;//Tmatem_Sicam_400_G
        strcpy(nomp3,"Tmatem_Sicam");
    }
    if(produit3==16)
    {
        prix3=1120;//7lib
        strcpy(nomp3,"7lib_delice");
    }
    if(produit3==17)
    {
        prix3=250;//3adhem
        strcpy(nomp3,"3adham");
    }
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
    printf("\n");
    printf("quantite %d %s a %d\n",quantite1,produits[produit1],prix1);
    printf("quantite %d %s a %d\n",quantite2,produits[produit2],prix2);
    printf("quantite %d %s a %d\n",quantite3,produits[produit3],prix3);
///////////////////////////////////////////////////////////////////
    somme=(quantite1*prix1)+(quantite2*prix2)+(quantite3*prix3);
    printf("somme %d\n",somme);  

    while (continuer && nbre!=3)
    {
temp2=gestion_temps_decompteur(0,0,temp2,ecran);
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            SDL_WaitEvent(&event);
            switch(event.key.keysym.sym)
            {
            case SDLK_BACKSPACE:
                printf("Effacer\n");
                int casee = 0,longeur;
                longeur=strlen(name);
                longeur--;
                while(name[casee] != '\0')
                {
                    if(casee >=longeur)
                    {
                        name[casee] = name[casee+1];
                    }
                    casee++;
                }
                break;
            case SDLK_RETURN:
            {
                if(debut==0)
                {
                    if (strcmp(name,sommetab)==0)
                    {
                        printf("Vous avez gagne dans %d s!\n",compteur);
                        compteur=0;
                        nbre++;
                        printf("Nombre %d\n",nbre);                        
                        Mix_PlayChannel(1, correct, 0);
                        printf("Bravo!\n");
                        printf("Votre Saisie %s\n",name);
                        printf("Resultat %s\n",sommetab);
                        if(nbre==3)
                        {
                        debut=1;
                        win=1;
                        }
                       if(nbre<3)
                        {
                        produit1=rand() % 10 + 0;// valeur in the range 100000-200000
                        produit2=rand() % 10 + 0;// valeur in the range 100000-170000
                        produit3=rand() % 18 + 0;// valeur in the range 100000-170000
                        while((produit1==produit2) || (produit2==produit3))
                        {
                            produit1=rand() % 18 + 0;// valeur in the range 100000-200000
                            produit2=rand() % 18 + 0;// valeur in the range 100000-170000
                            produit3=rand() % 18 + 0;// valeur in the range 100000-170000
                        }
                        quantite1=rand() % 3 + 1;
                        quantite2=rand() % 3 + 1;
                        quantite3=rand() % 3 + 1;

                        while(quantite1==quantite2)
                        {
                            quantite1=rand() % 3 + 1;
                            quantite2=rand() % 3 + 1;
                            quantite3=rand() % 3 + 1;
                        }
                        //debut=0;
                        }
                    }
                    if (strcmp(name,sommetab)!=0)
                    {
                        Mix_PlayChannel(1, wrong, 0);
                        printf("False !\n");
                        printf("Essayez encore [N'abandonnez pas]\n");
                        compteur=0;
                        produit1=rand() % 10 + 0;// valeur in the range 100000-200000
                        produit2=rand() % 10 + 0;// valeur in the range 100000-170000
                        produit3=rand() % 18 + 0;// valeur in the range 100000-170000
                        while((produit1==produit2) || (produit2==produit3))
                        {
                            produit1=rand() % 18 + 0;// valeur in the range 100000-200000
                            produit2=rand() % 18 + 0;// valeur in the range 100000-170000
                            produit3=rand() % 18 + 0;// valeur in the range 100000-170000
                        }
                        quantite1=rand() % 3 + 1;
                        quantite2=rand() % 3 + 1;
                        quantite3=rand() % 3 + 1;

                        while(quantite1==quantite2)
                        {
                            quantite1=rand() % 3 + 1;
                            quantite2=rand() % 3 + 1;
                            quantite3=rand() % 3 + 1;
                        }
                        debut=0;
                        memset (name,0, sizeof (char));
                        name=calloc(20,sizeof(char));
                    }
                }

////////////////////////////////////////////////
////////////////////////////////////////////////
                if(produit1==0)
                {
                    prix1=500;//ma9arouna
                    strcpy(nomp1,"Ma9arouna_randa");
                }
                if(produit1==1)
                {
                    prix1=1100;//zit
                    strcpy(nomp1,"Zit");
                }
                if(produit1==2)
                {
                    prix1=200;//5obez
                    strcpy(nomp1,"5obez");
                }
                if(produit1==3)
                {
                    prix1=2400;//gazouz
                    strcpy(nomp1,"Coca-Cola");
                }
                if(produit1==4)
                {
                    prix1=50;//florida
                    strcpy(nomp1,"Florida");
                }
                if(produit1==5)
                {
                    prix1=400;//yaghort
                    strcpy(nomp1,"yaghoret_vitalait");
                }
                if(produit1==6)
                {
                    prix1=800;//jus
                    strcpy(nomp1,"jus_tropico");
                }
                if(produit1==7)
                {
                    prix1=350;//prince
                    strcpy(nomp1,"Prince");
                }
                if(produit1==8)
                {
                    prix1=300;//Pilet
                    strcpy(nomp1,"Pila");
                }
                if(produit1==9)
                {
                    prix1=1250;//ooredoo
                    strcpy(nomp1,"Ticket_Ooredoo");
                }
                if(produit1==10)
                {
                    prix1=600;//oumou
                    strcpy(nomp1,"oumou_nadhif");
                }
                if(produit1==11)
                {
                    prix1=90;//malsou9a
                    strcpy(nomp1,"malsou9a");
                }
                if(produit1==12)
                {
                    prix1=1850;//7okajben
                    strcpy(nomp1,"7okajben_vitalait");
                }
                if(produit1==13)
                {
                    prix1=920;//Rayeb
                    strcpy(nomp1,"rayeb_delice");
                }
                if(produit1==14)
                {
                    prix1=700;//ma2
                    strcpy(nomp1,"ma2_safia");
                }
                if(produit1==15)
                {
                    prix1=1725;//Tmatem_Sicam_400_G
                    strcpy(nomp1,"Tmatem_Sicam");
                }
                if(produit1==16)
                {
                    prix1=1120;//7lib
                    strcpy(nomp1,"7lib_delice");
                }
                if(produit1==17)
                {
                    prix1=250;//3adhem
                    strcpy(nomp1,"3adham");
                }
///////////////////////////////////////////////////////////////////
                if(produit2==0)
                {
                    prix2=500;//ma9arouna
                    strcpy(nomp2,"Ma9arouna_randa");
                }
                if(produit2==1)
                {
                    prix2=1100;//zit
                    strcpy(nomp2,"Zit");
                }
                if(produit2==2)
                {
                    prix2=200;//5obez
                    strcpy(nomp2,"5obez");
                }
                if(produit2==3)
                {
                    prix2=2400;//gazouz
                    strcpy(nomp2,"Coca-Cola");
                }
                if(produit2==4)
                {
                    prix2=50;//florida
                    strcpy(nomp2,"Florida");
                }
                if(produit2==5)
                {
                    prix2=400;//yaghort
                    strcpy(nomp2,"yaghoret_vitalait");
                }
                if(produit2==6)
                {
                    prix2=800;//jus
                    strcpy(nomp2,"jus_tropico");
                }
                if(produit2==7)
                {
                    prix2=350;//prince
                    strcpy(nomp2,"Prince");
                }
                if(produit2==8)
                {
                    prix2=300;//Pilet
                    strcpy(nomp2,"Pila");
                }
                if(produit2==9)
                {
                    prix2=1250;//ooredoo
                    strcpy(nomp2,"Ticket_Ooredoo");
                }
                if(produit2==10)
                {
                    prix2=600;//oumou
                    strcpy(nomp2,"oumou_nadhif");
                }
                if(produit2==11)
                {
                    prix2=90;//malsou9a
                    strcpy(nomp2,"malsou9a");
                }
                if(produit2==12)
                {
                    prix2=1850;//7okajben
                    strcpy(nomp2,"7okajben_vitalait");
                }
                if(produit2==13)
                {
                    prix2=920;//Rayeb
                    strcpy(nomp2,"rayeb_delice");
                }
                if(produit2==14)
                {
                    prix2=700;//ma2
                    strcpy(nomp2,"ma2_safia");
                }
                if(produit2==15)
                {
                    prix2=1725;//Tmatem_Sicam_400_G
                    strcpy(nomp2,"Tmatem_Sicam");
                }
                if(produit2==16)
                {
                    prix2=1120;//7lib
                    strcpy(nomp2,"7lib_delice");
                }
                if(produit2==17)
                {
                    prix2=250;//3adhem
                    strcpy(nomp2,"3adham");
                }
///////////////////////////////////////////////////////////////////
                if(produit3==0)
                {
                    prix3=500;//ma9arouna
                    strcpy(nomp3,"Ma9arouna_randa");
                }
                if(produit3==1)
                {
                    prix3=1100;//zit
                    strcpy(nomp3,"Zit");
                }
                if(produit3==2)
                {
                    prix3=200;//5obez
                    strcpy(nomp3,"5obez");
                }
                if(produit3==3)
                {
                    prix3=2400;//gazouz
                    strcpy(nomp3,"Coca-Cola");
                }
                if(produit3==4)
                {
                    prix3=50;//florida
                    strcpy(nomp3,"Florida");
                }
                if(produit3==5)
                {
                    prix3=400;//yaghort
                    strcpy(nomp3,"yaghoret_vitalait");
                }
                if(produit3==6)
                {
                    prix3=800;//jus
                    strcpy(nomp3,"jus_tropico");
                }
                if(produit3==7)
                {
                    prix3=350;//prince
                    strcpy(nomp3,"Prince");
                }
                if(produit3==8)
                {
                    prix3=300;//Pilet
                    strcpy(nomp3,"Pila");
                }
                if(produit3==9)
                {
                    prix3=1250;//ooredoo
                    strcpy(nomp3,"Ticket_Ooredoo");
                }
                if(produit3==10)
                {
                    prix3=600;//oumou
                    strcpy(nomp3,"oumou_nadhif");
                }
                if(produit3==11)
                {
                    prix3=90;//malsou9a
                    strcpy(nomp3,"malsou9a");
                }
                if(produit3==12)
                {
                    prix3=1850;//7okajben
                    strcpy(nomp3,"7okajben_vitalait");
                }
                if(produit3==13)
                {
                    prix3=920;//Rayeb
                    strcpy(nomp3,"rayeb_delice");
                }
                if(produit3==14)
                {
                    prix3=700;//ma2
                    strcpy(nomp3,"ma2_safia");
                }
                if(produit3==15)
                {
                    prix3=1725;//Tmatem_Sicam_400_G
                    strcpy(nomp3,"Tmatem_Sicam");
                }
                if(produit3==16)
                {
                    prix3=1120;//7lib
                    strcpy(nomp3,"7lib_delice");
                }
                if(produit3==17)
                {
                    prix3=250;//3adhem
                    strcpy(nomp3,"3adham");
                }
///////////////////////////////////////////////////////////////////
                somme=(quantite1*prix1)+(quantite2*prix2)+(quantite3*prix3);

                printf("\n");
                printf("quantite %d %s a %d \n",quantite1,produits[produit1],prix1);
                printf("quantite %d %s a %d\n",quantite2,produits[produit2],prix2);
                printf("quantite %d %s a %d\n",quantite3,produits[produit3],prix3);

                printf("somme %d\n",somme);  
                        memset (name,0, sizeof (char));
                        name=calloc(20,sizeof(char));
            }
            break;

            case SDLK_KP0:
                strcpy(mot,"0");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("0\n");
                }
                break;
            case SDLK_KP1:
                strcpy(mot,"1");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("1\n");
                }
                break;
            case SDLK_KP2:
                strcpy(mot,"2");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("2\n");
                }
                break;
            case SDLK_KP3:
                strcpy(mot,"3");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("3\n");
                }
                break;
            case SDLK_KP4:
                strcpy(mot,"4");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("4\n");
                }
                break;
            case SDLK_KP5:
                strcpy(mot,"5");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("5\n");
                }
                break;
            case SDLK_KP6:
                strcpy(mot,"6");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("6\n");
                }
                break;
            case SDLK_KP7:
                strcpy(mot,"7");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("7\n");
                }
                break;
            case SDLK_KP8:
                strcpy(mot,"8");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("8\n");
                }
                break;
            case SDLK_KP9:
                strcpy(mot,"9");
                if(strlen(name)<5)
                {
                    strcat(name,mot);
                    printf("9\n");
                }
                break;
            }
            break;

        }

        if(debut==0)
        {

            /////////////////////////////////////////
            somme=(quantite1*prix1)+(quantite2*prix2)+(quantite3*prix3);
            tempsActuel = SDL_GetTicks();
            if (tempsActuel - tempsPrecedent >= 100) /* Si 100ms au moins se sont \E9coul\E9es */
            {
                compteur += 1; /* On rajoute 100ms au compteur */
                sprintf(temps, "%d", compteur); /* On \E9crit dans la cha\EEne "temps" le nouveau temps */
                sprintf(produit1ab, "%d ", quantite1);
                sprintf(produit2ab, "%d ", quantite2);
                sprintf(produit3ab, "%d ", quantite3);
                sprintf(sommetab,"%d", somme);

                SDL_FreeSurface(textetemp);
                SDL_FreeSurface(texteproduit1);
                SDL_FreeSurface(texteproduit2);
                SDL_FreeSurface(texteproduit3);
                textetemp = TTF_RenderText_Shaded(police2, temps, couleurNoire, couleurBlanche);

                texteproduit1 = TTF_RenderText_Shaded(police, produit1ab, bleu, couleurBlanche);
                SDL_SetColorKey(texteproduit1, SDL_SRCCOLORKEY, SDL_MapRGB(texteproduit1->format, 255, 255, 255));
                texteproduit2 = TTF_RenderText_Shaded(police, produit2ab, bleu, couleurBlanche);
                SDL_SetColorKey(texteproduit2, SDL_SRCCOLORKEY, SDL_MapRGB(texteproduit2->format, 255, 255, 255));
                texteproduit3 = TTF_RenderText_Shaded(police, produit3ab, bleu, couleurBlanche);
                SDL_SetColorKey(texteproduit3, SDL_SRCCOLORKEY, SDL_MapRGB(texteproduit3->format, 255, 255, 255));

                nomproduit1 = TTF_RenderText_Shaded(police2, nomp1, couleurNoire, couleurBlanche);
                SDL_SetColorKey(nomproduit1, SDL_SRCCOLORKEY, SDL_MapRGB(nomproduit1->format,  255, 255, 255));
                nomproduit2 = TTF_RenderText_Shaded(police2, nomp2, couleurNoire, couleurBlanche);
                SDL_SetColorKey(nomproduit2, SDL_SRCCOLORKEY, SDL_MapRGB(nomproduit2->format,  255, 255, 255));
                nomproduit3 = TTF_RenderText_Shaded(police2, nomp3, couleurNoire, couleurBlanche);
                SDL_SetColorKey(nomproduit3, SDL_SRCCOLORKEY, SDL_MapRGB(nomproduit3->format,  255, 255, 255));

                tempsPrecedent = tempsActuel; /* On met \E0 jour le tempsPrecedent */
                if(compteur>100)
                {
                    compteur=0;
                    memset (name,0, sizeof (char));
                    name=calloc(20,sizeof(char));
                    produit1=rand() % 10 + 0;// valeur in the range 100000-200000
                    produit2=rand() % 10 + 0;// valeur in the range 100000-170000
                    produit3=rand() % 18 + 0;// valeur in the range 100000-170000
                    while((produit1==produit2) || (produit2==produit3))
                    {
                        produit1=rand() % 18 + 0;// valeur in the range 100000-200000
                        produit2=rand() % 18 + 0;// valeur in the range 100000-170000
                        produit3=rand() % 18 + 0;// valeur in the range 100000-170000
                    }
                    quantite1=rand() % 3 + 1;
                    quantite2=rand() % 3 + 1;
                    quantite3=rand() % 3 + 1;


                    while(quantite1==quantite2)
                    {
                        quantite1=rand() % 3 + 1;
                        quantite2=rand() % 3 + 1;
                        quantite3=rand() % 3 + 1;
                    }
////////////////////////////////////////////////
                    if(produit1==0)
                    {
                        prix1=500;//ma9arouna
                        strcpy(nomp1,"Ma9arouna_randa");
                    }
                    if(produit1==1)
                    {
                        prix1=1100;//zit
                        strcpy(nomp1,"Zit");
                    }
                    if(produit1==2)
                    {
                        prix1=200;//5obez
                        strcpy(nomp1,"5obez");
                    }
                    if(produit1==3)
                    {
                        prix1=2400;//gazouz
                        strcpy(nomp1,"Coca-Cola");
                    }
                    if(produit1==4)
                    {
                        prix1=50;//florida
                        strcpy(nomp1,"Florida");
                    }
                    if(produit1==5)
                    {
                        prix1=400;//yaghort
                        strcpy(nomp1,"yaghoret_vitalait");
                    }
                    if(produit1==6)
                    {
                        prix1=800;//jus
                        strcpy(nomp1,"jus_tropico");
                    }
                    if(produit1==7)
                    {
                        prix1=350;//prince
                        strcpy(nomp1,"Prince");
                    }
                    if(produit1==8)
                    {
                        prix1=300;//Pilet
                        strcpy(nomp1,"Pila");
                    }
                    if(produit1==9)
                    {
                        prix1=1250;//ooredoo
                        strcpy(nomp1,"Ticket_Ooredoo");
                    }
                    if(produit1==10)
                    {
                        prix1=600;//oumou
                        strcpy(nomp1,"oumou_nadhif");
                    }
                    if(produit1==11)
                    {
                        prix1=90;//malsou9a
                        strcpy(nomp1,"malsou9a");
                    }
                    if(produit1==12)
                    {
                        prix1=1850;//7okajben
                        strcpy(nomp1,"7okajben_vitalait");
                    }
                    if(produit1==13)
                    {
                        prix1=920;//Rayeb
                        strcpy(nomp1,"rayeb_delice");
                    }
                    if(produit1==14)
                    {
                        prix1=700;//ma2
                        strcpy(nomp1,"ma2_safia");
                    }
                    if(produit1==15)
                    {
                        prix1=1725;//Tmatem_Sicam_400_G
                        strcpy(nomp1,"Tmatem_Sicam");
                    }
                    if(produit1==16)
                    {
                        prix1=1120;//7lib
                        strcpy(nomp1,"7lib_delice");
                    }
                    if(produit1==17)
                    {
                        prix1=250;//3adhem
                        strcpy(nomp1,"3adham");
                    }
///////////////////////////////////////////////////////////////////
                    if(produit2==0)
                    {
                        prix2=500;//ma9arouna
                        strcpy(nomp2,"Ma9arouna_randa");
                    }
                    if(produit2==1)
                    {
                        prix2=1100;//zit
                        strcpy(nomp2,"Zit");
                    }
                    if(produit2==2)
                    {
                        prix2=200;//5obez
                        strcpy(nomp2,"5obez");
                    }
                    if(produit2==3)
                    {
                        prix2=2400;//gazouz
                        strcpy(nomp2,"Coca-Cola");
                    }
                    if(produit2==4)
                    {
                        prix2=50;//florida
                        strcpy(nomp2,"Florida");
                    }
                    if(produit2==5)
                    {
                        prix2=400;//yaghort
                        strcpy(nomp2,"yaghoret_vitalait");
                    }
                    if(produit2==6)
                    {
                        prix2=800;//jus
                        strcpy(nomp2,"jus_tropico");
                    }
                    if(produit2==7)
                    {
                        prix2=350;//prince
                        strcpy(nomp2,"Prince");
                    }
                    if(produit2==8)
                    {
                        prix2=300;//Pilet
                        strcpy(nomp2,"Pila");
                    }
                    if(produit2==9)
                    {
                        prix2=1250;//ooredoo
                        strcpy(nomp2,"Ticket_Ooredoo");
                    }
                    if(produit2==10)
                    {
                        prix2=600;//oumou
                        strcpy(nomp2,"oumou_nadhif");
                    }
                    if(produit2==11)
                    {
                        prix2=90;//malsou9a
                        strcpy(nomp2,"malsou9a");
                    }
                    if(produit2==12)
                    {
                        prix2=1850;//7okajben
                        strcpy(nomp2,"7okajben_vitalait");
                    }
                    if(produit2==13)
                    {
                        prix2=920;//Rayeb
                        strcpy(nomp2,"rayeb_delice");
                    }
                    if(produit2==14)
                    {
                        prix2=700;//ma2
                        strcpy(nomp2,"ma2_safia");
                    }
                    if(produit2==15)
                    {
                        prix2=1725;//Tmatem_Sicam_400_G
                        strcpy(nomp2,"Tmatem_Sicam");
                    }
                    if(produit2==16)
                    {
                        prix2=1120;//7lib
                        strcpy(nomp2,"7lib_delice");
                    }
                    if(produit2==17)
                    {
                        prix2=250;//3adhem
                        strcpy(nomp2,"3adham");
                    }
///////////////////////////////////////////////////////////////////
                    if(produit3==0)
                    {
                        prix3=500;//ma9arouna
                        strcpy(nomp3,"Ma9arouna_randa");
                    }
                    if(produit3==1)
                    {
                        prix3=1100;//zit
                        strcpy(nomp3,"Zit");
                    }
                    if(produit3==2)
                    {
                        prix3=200;//5obez
                        strcpy(nomp3,"5obez");
                    }
                    if(produit3==3)
                    {
                        prix3=2400;//gazouz
                        strcpy(nomp3,"Coca-Cola");
                    }
                    if(produit3==4)
                    {
                        prix3=50;//florida
                        strcpy(nomp3,"Florida");
                    }
                    if(produit3==5)
                    {
                        prix3=400;//yaghort
                        strcpy(nomp3,"yaghoret_vitalait");
                    }
                    if(produit3==6)
                    {
                        prix3=800;//jus
                        strcpy(nomp3,"jus_tropico");
                    }
                    if(produit3==7)
                    {
                        prix3=350;//prince
                        strcpy(nomp3,"Prince");
                    }
                    if(produit3==8)
                    {
                        prix3=300;//Pilet
                        strcpy(nomp3,"Pila");
                    }
                    if(produit3==9)
                    {
                        prix3=1250;//ooredoo
                        strcpy(nomp3,"Ticket_Ooredoo");
                    }
                    if(produit3==10)
                    {
                        prix3=600;//oumou
                        strcpy(nomp3,"oumou_nadhif");
                    }
                    if(produit3==11)
                    {
                        prix3=90;//malsou9a
                        strcpy(nomp3,"malsou9a");
                    }
                    if(produit3==12)
                    {
                        prix3=1850;//7okajben
                        strcpy(nomp3,"7okajben_vitalait");
                    }
                    if(produit3==13)
                    {
                        prix3=920;//Rayeb
                        strcpy(nomp3,"rayeb_delice");
                    }
                    if(produit3==14)
                    {
                        prix3=700;//ma2
                        strcpy(nomp3,"ma2_safia");
                    }
                    if(produit3==15)

                    {
                        prix3=1725;//Tmatem_Sicam_400_G
                        strcpy(nomp3,"Tmatem_Sicam");
                    }
                    if(produit3==16)
                    {
                        prix3=1120;//7lib
                        strcpy(nomp3,"7lib_delice");
                    }
                    if(produit3==17)
                    {
                        prix3=250;//3adhem
                        strcpy(nomp3,"3adham");
                    }
///////////////////////////////////////////////////////////////////
                    printf("Lwa9et wefa ! \n");
                    printf("\n");
                    printf("quantite %d %s a %d\n",quantite1,produits[produit1],prix1);
                    printf("quantite %d %s a %d\n",quantite2,produits[produit2],prix2);
                    printf("quantite %d %s a %d\n",quantite3,produits[produit3],prix3);
                    somme=(quantite1*prix1)+(quantite2*prix2)+(quantite3*prix3);
                    printf("somme %d\n",somme);  
                }
            }

            posbg.x = 0;
            posbg.y = 0;
            posfeuille.x = 0;
            posfeuille.y = 0;
            posstylo.x =0;
            posstylo.y =0;
            posamstoura.x = 0;
            posamstoura.y = 0;

            positiontextemp.x = 73;
            positiontextemp.y = 48;

            positiontextproduit1.x = 565;
            positiontextproduit1.y = 235;

            posnomproduit1.x = 600;
            posnomproduit1.y = 245;

            positiontextproduit2.x = 570;
            positiontextproduit2.y = 295;

            posnomproduit2.x = 600;
            posnomproduit2.y = 307;

            positiontextproduit3.x = 570;
            positiontextproduit3.y = 370;

            posnomproduit3.x = 600;
            posnomproduit3.y = 385;

            poszoneSaisie.x=695;
            poszoneSaisie.y=415;


            SDL_BlitSurface(bg,NULL,ecran,&posbg);
            SDL_BlitSurface(feuilleDesprix, NULL, ecran, &posprix);
            SDL_BlitSurface(feuille, NULL, ecran, &posfeuille);
            SDL_BlitSurface(ligne, NULL, ecran, &posligne);
            SDL_BlitSurface(stylo, NULL, ecran, &posstylo);
            SDL_BlitSurface(amstoura, NULL, ecran, &posamstoura);
            SDL_BlitSurface(textetemp, NULL, ecran, &positiontextemp); /* Blit du texte contenant le temps */
            SDL_BlitSurface(texteproduit1, NULL, ecran, &positiontextproduit1);
            SDL_BlitSurface(texteproduit2, NULL, ecran, &positiontextproduit2);
            SDL_BlitSurface(nomproduit1, NULL, ecran, &posnomproduit1);
            SDL_BlitSurface(nomproduit2, NULL, ecran, &posnomproduit2);
            SDL_BlitSurface(texteproduit3, NULL, ecran, &positiontextproduit3);
            SDL_BlitSurface(nomproduit3, NULL, ecran, &posnomproduit3);
            zoneSaisie=TTF_RenderText_Blended(police,name,couleurNoire);
            SDL_BlitSurface(zoneSaisie,NULL,ecran,&poszoneSaisie);
            SDL_Flip(ecran);
        }
    }

    if(nbre==3)
    {
     done[1]=1;
     //return done ;
return temp2;
    }    

    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(textetemp);
    SDL_FreeSurface(texteproduit1);
    SDL_FreeSurface(texteproduit2);
    SDL_FreeSurface(texteproduit3);
    SDL_FreeSurface(nomproduit1);
    SDL_FreeSurface(nomproduit2);
    SDL_FreeSurface(nomproduit3);
    SDL_FreeSurface(zoneSaisie);

  // return win;  
done[1]=0;
return temp2;
 
}


