#include <ncurses.h>
#include <time.h>
#include "sceneevent.h"
#include "game.h"
#include "display.h"

void	sceneevent(int scene, int I) {
clock_t	tstart;
WINDOW	*overlay;
overlay = newwin(10, 30, 10, 1);

switch(scene) {
case 1:
	switch(I) {
	case 2:	//lights flicker
		wattron(overlay, A_REVERSE);
		box(overlay, 0, 0);
		for (int i=1; i<9; i++)
			mvwprintw(overlay, i, 1, "                            ");
		redrawwin(overlay);
		wrefresh(overlay);
		tstart=clock();
		while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.1);
		wattroff(overlay, A_REVERSE);
		box(overlay, 0, 0);
		for (int i=1; i<9; i++)
			mvwprintw(overlay, i, 1, "                            ");
		redrawwin(overlay);
		wrefresh(overlay);
		tstart=clock();
		while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.06);
		delwin(overlay);
		refresh_spaceship_reverse();
		tstart=clock();
		while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.18);
		refresh_spaceship();
		break;
}} return; }