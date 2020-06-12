/**
* @file perso.h
* @brief Testing Program.
* @author Mahdi
* @version 1
* @date JUIN 09, 2020
*
* Testing program for personnage collision
*
*/
#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
 #include <unistd.h>
#include <math.h>


/**
* @struct perso
* @brief struct for perso
*/
typedef struct perso
{
	SDL_Surface *image_perso[6]; /*!< Surface. */
	SDL_Surface *image_persod[6]; /*!< Surface. */
	SDL_Rect positionperso; /*!< Rectangle*/
	int nimage; /*!< entier. */
	int mouvement; /*!< entier. */
	int colv; /*!< entier. */
	int colhl; /*!< entier. */
	int colhr; /*!< entier. */
}perso;

/**
* @struct Background
* @brief struct for backround
*/

typedef struct backg{
	SDL_Surface *background; /*!< Surface. */
	SDL_Surface *calque; /*!< Surface. */
	SDL_Rect posbackground; /*!< Rectangle*/
	SDL_Rect posbackground2; /*!< Rectangle*/
}backg;


void initialiser_background(backg *background,int posisionmap);
void afficher_background(backg background,SDL_Surface *screen);
//SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
void initialiser(perso *hero,int perso,int pospersp);
void afficher_personnage (perso *hero,SDL_Surface *screen);
void collision_background(SDL_Surface *calque,SDL_Rect posperso,SDL_Rect posmap,perso *hero,int x);
int animation(perso *hero,SDL_Event *event);
int animation2(perso *hero,SDL_Event *event);

/******* background*////
#endif

