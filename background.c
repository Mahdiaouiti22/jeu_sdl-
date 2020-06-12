#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"


void initialiser_background(backg *background,int posisionmap){

	background->background=NULL;
	background->calque=NULL;
	background->background=IMG_Load("background.png");
	background->calque=IMG_Load("calque.png");
	background->posbackground.x=0;
	background->posbackground.y=posisionmap;
	background->posbackground2.x=0;
	background->posbackground2.y=0;
	background->posbackground2.h=300;
	background->posbackground2.w=1200;
}

void afficher_background(backg background,SDL_Surface *screen){
	SDL_BlitSurface(background.background,&(background.posbackground2),screen,&(background.posbackground));
	//SDL_BlitSurface(background.calque,&(background.posbackground2),screen,&(background.posbackground));
}













