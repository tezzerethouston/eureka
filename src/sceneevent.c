#include <ncurses.h>
#include <time.h>
#include "sceneevent.h"
#include "game.h"
#include "display.h"

void	sceneevent(int scene, int I) {
clock_t	tstart;
WINDOW	*overlay;
overlay = newwin(10, 30, 11, 5);

switch(scene) {
case 1:
	switch(I) {
	case 8: //hyperspace
		refresh_hswarning();
		tstart=clock(); while((double)(clock()-tstart)/CLOCKS_PER_SEC<2);
		erase_hswarning();
		break;

	case 5: //walking to the flight console
		refresh_spaceship(3, 14); refresh_portrait();
		tstart=clock(); while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.5);
		refresh_spaceship(2, 14); refresh_portrait();
		break;

	case 2:	//lights flicker
		wattron(overlay, A_REVERSE);
		box(overlay, 0, 0);
		for (int i=1; i<9; i++)
			mvwprintw(overlay, i, 1, "                            ");
		redrawwin(overlay); wrefresh(overlay);
		tstart=clock(); while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.1);
		wattroff(overlay, A_REVERSE);
		box(overlay, 0, 0);
		for (int i=1; i<9; i++)
			mvwprintw(overlay, i, 1, "                            ");
		redrawwin(overlay); wrefresh(overlay); refresh_portrait();
		tstart=clock(); while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.06);
		delwin(overlay);
		refresh_spaceship_reverse(); refresh_portrait();
		tstart=clock(); while((double)(clock()-tstart)/CLOCKS_PER_SEC<0.18);
		refresh_spaceship(4, 14); refresh_portrait();
		break;
}} return; }
