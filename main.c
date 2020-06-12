
/**
* @file main.c
* @brief Testing Program.
* @author Mahdi
* @version 1
* @date JUIN 09, 2020
*
* Testing program for personnage collision
*
*/
#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"perso.h"
void main(void){

	SDL_Surface *screen =NULL, *background=NULL, *collisionbackground=NULL;

	perso hero,hero2;
	backg background1,background2;

	SDL_Rect posback;

	posback.x=0;
	posback.y=0;

 	initialiser_background(&background1,0);
 	initialiser_background(&background2,300);

	int running=1;

	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode (900,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

	initialiser(&hero,1,50);
	initialiser(&hero2,2,350);

	SDL_Event event;

	while(running){
		afficher_background(background1,screen);
		afficher_background(background2,screen);
		collision_background(background1.calque,hero.positionperso,background1.posbackground,&hero,0);
		collision_background(background2.calque,hero2.positionperso,background2.posbackground,&hero2,30);
		SDL_PollEvent(&event);
		hero.nimage=animation(&hero,&event);
		hero2.nimage=animation2(&hero2,&event);
		afficher_personnage(&hero,screen);
		afficher_personnage(&hero2,screen);
		SDL_Flip(screen);
		usleep(20000);
	}
}