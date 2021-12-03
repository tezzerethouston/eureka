#include <ncurses.h>
#include <stdlib.h>
#include "screen.h"

screenmap	*new_planet() {
screenmap	*sm;
char	**firstscreen;

sm = malloc(sizeof(screenmap));
firstscreen = malloc(sizeof(char*)*20);
for (int i=0; i<20; i++)
	firstscreen[i] = malloc(70);
for (int i=0; i<20; i++)
	for (int j=0; j<70; j++)
		firstscreen[i][j] = '.';
sm->up = NULL;
sm->down = NULL;
sm->left = NULL;
sm->right = NULL;
sm->screen = firstscreen;
return sm; }

void	free_planet(screenmap *sm) {
for (int i=0; i<20; i++)
	free(sm->screen[i]);
free(sm->screen);
free(sm);
return ; }
