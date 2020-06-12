/**
* @file perso.c
* @brief Testing Program.
* @author Mahdi
* @version 1
* @date JUIN 09, 2020
*
* Testing program for personnage
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <time.h>
#include<SDL/SDL_ttf.h>
#include <unistd.h>
#include "perso.h"


SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;
	char* pPosition = ( char* ) surface->pixels ;
	pPosition += ( surface->pitch * y ) ;
	pPosition += ( surface->format->BytesPerPixel * x ) ;
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}


/**
* @brief To initialize the personnage hero .
* @param hero personnage
* @param perso int for choix de personnage
* @param posperso int for position personnage
* @return Nothing
*/

void initialiser(perso *hero, int perso, int posperso){
	hero->image_perso[0]=NULL;
	hero->image_perso[1]=NULL;
	hero->image_perso[2]=NULL;
	hero->image_perso[3]=NULL;
	hero->image_perso[4]=NULL;
	hero->image_perso[5]=NULL;

	hero->image_persod[0]=NULL;
	hero->image_persod[1]=NULL;
	hero->image_persod[2]=NULL;
	hero->image_persod[3]=NULL;


if (perso==1){
	hero->image_perso[0]=IMG_Load("pos6.png");
	hero->image_perso[1]=IMG_Load("pos1.png");
	hero->image_perso[2]=IMG_Load("pos2.png");
	hero->image_perso[3]=IMG_Load("pos3.png");
	hero->image_perso[4]=IMG_Load("pos4.png");
	hero->image_perso[5]=IMG_Load("pos5.png");


	hero->image_persod[0]=IMG_Load("posd6.png");
	hero->image_persod[1]=IMG_Load("posd1.png");
	hero->image_persod[2]=IMG_Load("posd2.png");
	hero->image_persod[3]=IMG_Load("posd3.png");
	hero->image_persod[4]=IMG_Load("posd4.png");
	hero->image_persod[5]=IMG_Load("posd5.png");
}
if (perso==2){
	hero->image_perso[0]=IMG_Load("d1.png");
	hero->image_perso[1]=IMG_Load("d2.png");
	hero->image_perso[2]=IMG_Load("d3.png");
	hero->image_perso[3]=IMG_Load("d4.png");
	hero->image_perso[4]=IMG_Load("d5.png");
	hero->image_perso[5]=IMG_Load("d6.png");


	hero->image_persod[0]=IMG_Load("g1.png");
	hero->image_persod[1]=IMG_Load("g2.png");
	hero->image_persod[2]=IMG_Load("g3.png");
	hero->image_persod[3]=IMG_Load("g4.png");
	hero->image_persod[4]=IMG_Load("g5.png");
	hero->image_persod[5]=IMG_Load("g6.png");
}

	hero->positionperso.x=100;
	hero->positionperso.y=posperso;
	hero->nimage=0;
	hero->colv=0;
	hero->colhr=0;
	hero->colhl=0;
	hero->mouvement=0;
}

/**
* @brief To animation personnage1.
* @param hero personnage
* @param event SDL_Event 
* @return nimage int
*/

int animation(perso *hero, SDL_Event *event){

	int nimage=hero->nimage;
		switch (event->type)
        {
        	case SDL_KEYDOWN:
        	switch (event->key.keysym.sym)
            {
			case SDLK_RIGHT:
				if (nimage<5)
					nimage++;
				else nimage=0;
					hero->mouvement=1;
				if (hero->colhr!=1)
					hero->positionperso.x=hero->positionperso.x+5;
			break;
			case SDLK_LEFT:
				if (nimage<5)
					nimage++;
				else nimage=0;	
				if (hero->colhl!=1)
				hero->positionperso.x=hero->positionperso.x-5;	

				hero->mouvement=2;	
			break;
			case SDLK_UP: 
				nimage=0;	
				hero->positionperso.y=hero->positionperso.y-5;	
				hero->mouvement=3;
			break;	
	}
	break;
		default: nimage=0;	
			hero->mouvement=0;
}
	if (hero->colv!=1)
			hero->positionperso.y++;


		return nimage;
}

/**
* @brief To animation personnage2.
* @param hero personnage
* @param event SDL_Event 
* @return nimage int
*/
int animation2(perso *hero, SDL_Event *event){

	int nimage=hero->nimage;
		switch (event->type)
        {
        	case SDL_KEYDOWN:
        	switch (event->key.keysym.sym)
            {
			case SDLK_d:
				if (nimage<5)
					nimage++;
				else nimage=0;
					hero->mouvement=1;
				if (hero->colhr!=1)
					hero->positionperso.x=hero->positionperso.x+5;
			break;
			case SDLK_q:
				if (nimage<5)
					nimage++;
				else nimage=0;	
				if (hero->colhl!=1)
				hero->positionperso.x=hero->positionperso.x-5;	

				hero->mouvement=2;	
			break;
			case SDLK_z: 
				nimage=0;	
				hero->positionperso.y=hero->positionperso.y-5;	
				hero->mouvement=3;
			break;	
	}
	break;
		default: nimage=0;	
			hero->mouvement=0;
}
	if (hero->colv!=1)
			hero->positionperso.y++;


		return nimage;
}

/**
* @brief collision background (collision parfait).
* @param calque Surface
* @param posperso position personnage
* @param posperso position map
* @param x int
* @return nimage int
*/

void collision_background(SDL_Surface *calque,SDL_Rect posperso,SDL_Rect posmap,perso *hero,int x)
{
  SDL_Color col,col2,col3,col4;


  	col=GetPixel(calque,posperso.x+20+posmap.x,posperso.y+95+posmap.y+x);//vl
  	col2=GetPixel(calque,posperso.x+65+posmap.x,posperso.y+80+posmap.y+x);//hr
  	col3=GetPixel(calque,posperso.x+posmap.x,posperso.y+80+posmap.y+x); //hl
  	col4=GetPixel(calque,posperso.x+65+posmap.x,posperso.y+95+posmap.y+x);//vr

  	printf("%d %d\n",posperso.x+65+posmap.x,posperso.y+95+posmap.y);
 



if ((col3.r==255)&&(col3.b==255)&&(col3.g==255))
	hero->colhl=1;
else 
	hero->colhl=0;

if ((col2.r==255)&&(col2.b==255)&&(col2.g==255))
	hero->colhr=1;
else 
	hero->colhr=0;

if (((col.r==255)&&(col.b==255)&&(col.g==255))||((col4.r==255)&&(col4.b==255)&&(col4.g==255)))
	hero->colv=1;
else 
	hero->colv=0;
}

/**
* @brief To show the perso hero .
* @param screen the screen
* @param hero the personnage
* @return Nothing
*/
void afficher_personnage (perso *hero,SDL_Surface *screen){
if (hero->mouvement==1)
	SDL_BlitSurface(hero->image_perso[hero->nimage],NULL,screen,&(hero->positionperso));

if (hero->mouvement==2)
	SDL_BlitSurface(hero->image_persod[hero->nimage],NULL,screen,&(hero->positionperso));

if ((hero->mouvement==0)||(hero->mouvement==3))
	SDL_BlitSurface(hero->image_perso[hero->nimage],NULL,screen,&(hero->positionperso));
}
