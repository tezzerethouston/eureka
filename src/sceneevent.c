#include <ncurses.h>
#include <time.h>
#include "sceneevent.h"
#include "game.h"
#include "draw.h"

void	sceneevent(int scene, int I) {
clock_t	tstart;
int	i, j;
FILE	*f;
char	spaceshipmap[8][28];

switch(scene) {
case 1:
	switch(I) {
	case 2:	//lights flicker
		wattron(spaceship, A_REVERSE);
		box(spaceship, 0, 0);
		for (i=1; i<9; i++)
			mvwprintw(spaceship, i, 1, "                            ");
		wrefresh(spaceship);
		tstart=clock();
		while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.1);
		wattroff(spaceship, A_REVERSE);
		box(spaceship, 0, 0);
		for (i=1; i<9; i++)
			mvwprintw(spaceship, i, 1, "                            ");
		wrefresh(spaceship);
		tstart=clock();
		while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.06);
		wattron(spaceship, A_REVERSE);
		box(spaceship, 0, 0);
		draw_spaceship();
		wrefresh(spaceship);
		tstart=clock();
		while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.18);
		wattroff(spaceship, A_REVERSE);
		box(spaceship, 0, 0);
		draw_spaceship();
		wrefresh(spaceship);
		break;
}} return; }
