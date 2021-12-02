#include <ncurses.h>
#include <time.h>
#include "sceneevent.h"
#include "game.h"

void	sceneevent(int scene, int I) {
clock_t	tstart, tend, tdiff;

switch(scene) {
case 1:
	switch(I) {
	case 2:	//lights flicker
		tstart=clock();
		wattron(spaceship, A_REVERSE);
		box(spaceship, 0, 0);
		wrefresh(spaceship);
		while((tdiff=(tend=clock())-tstart)<100);
		wattroff(spaceship, A_REVERSE);
		box(spaceship, 0, 0);
		wrefresh(spaceship);
		break;
}} return ; }
