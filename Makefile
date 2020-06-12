programme:main.o perso.o background.o
	gcc main.o perso.o background.o -o programme -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm -g
main.o:main.c
	gcc -c main.c -g 
perso.o:perso.c
	gcc -c perso.c -g
background.o:background.c
	gcc -c background.c -g
	