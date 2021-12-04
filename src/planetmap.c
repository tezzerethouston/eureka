#include <ncurses.h>
#include <stdlib.h>
#include "screen.h"

screenmap	*new_planet() {
screenmap	*sm;
char	**firstscreen;

sm = malloc(sizeof(screenmap));
firstscreen = malloc(sizeof(char*)*18);
for (int i=0; i<18; i++)
	firstscreen[i] = malloc(68);
for (int i=0; i<18; i++)
	for (int j=0; j<68; j++)
		if ((rand()%100)==1)
			firstscreen[i][j] = 'o';
		else firstscreen[i][j] = '.';
sm->up = NULL;
sm->down = NULL;
sm->left = NULL;
sm->right = NULL;
sm->screen = firstscreen;
return sm; }

void	free_planet(screenmap *sm) {
for (int i=0; i<18; i++)
	free(sm->screen[i]);
free(sm->screen);
free(sm);
return ; }
