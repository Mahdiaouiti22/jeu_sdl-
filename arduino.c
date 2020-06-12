#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include"struct.h"


int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",&x);

    fclose(f);

    return(0);
}

void arduinoReadData(char *x)
{

    char chemin[]="/dev/ttyACM0";
    FILE*f;
    f=fopen(chemin,"r");
    char c;
    do {
    if(f == NULL)
        return(-1);
    
        fscanf(f,"%s",x);
    
}while (*x==-1);
    fclose(f);
}

int mouvment_arduino(hero evan,int *exit){

    int mouvment; 
    char x ;
    arduinoReadData(&x);
    switch (x){
            case "d":
                mouvment=1;
                break;
            case "g":
                mouvment=2;
                break;
            case "h":
                mouvment=3;
                break; 
            case "e":
                *exit=1;
                break;
             default:   mouvment=9;
             }
            printf("%d arduino\n", x);
             //printf("%d arduino arduino arduino arduino\n", k);
 return mouvment;
}

void collision_arduino(int collision,int exit){
    switch (collision){
        case 1:
            arduinoWriteData(1);
        break;
        case 2:
            arduinoWriteData(2);
        break;
        case 3:
            arduinoWriteData(3);
        break; 
        case 0:
            arduinoWriteData(0);
        break;
    }
    if(exit==1){
        arduinoWriteData(4);
    }
}