game:background.o main.o enigme1.o enigme2.o enigme3.o clock.o score.o player.o vie.o collisiontrigo.o entitesec1.o menu.o load.o fnc.o
	gcc background.o main.o enigme1.o enigme2.o enigme3.o clock.o score.o player.o vie.o  collisiontrigo.o entitesec1.o  menu.o load.o fnc.o -o game  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm -g 

main.o:main.c
	gcc main.c -c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

background.o:background.c
	gcc background.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

engime3.o:enigme3.c
	gcc enigme3.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

engime2.o:enigme2.c
	gcc enigme2.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

engime1.o:enigme1.c
	gcc enigme1.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

load.o:load.c
	gcc load.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

clock.o:clock.c
	gcc clock.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

entitesec1.o:entitesec1.c
	gcc entitesec1.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

vie.o:vie.c
	gcc vie.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

score.o:score.c
	gcc score.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

player.o:player.c
	gcc player.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

collisiontrigo.o:collisiontrigo.c
	gcc collisiontrigo.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

fnc.o:fnc.c
	gcc fnc.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g

menu.o:menu.c
	gcc menu.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm  -g
