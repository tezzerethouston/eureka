#include <ncurses.h>
#include "draw.h"

void	draw_spaceship(WINDOW *spaceship, char (*spaceshipmap)[8][28]) {
for (int i=0; i<8; i++) {
	wmove(spaceship, i+1, 1);
	for (int j=0; j<28; j++)
		waddch(spaceship, (*spaceshipmap)[i][j]); }
return ; }

void	draw_character(WINDOW *map, int y, int x, int bg) {
wattron(map, COLOR_PAIR(bg));
mvwaddch(map, y+1, x+1, '@');
wattroff(map, COLOR_PAIR(bg));
return ; }

void	draw_portrait(WINDOW *portrait, char (*portrait_sabrina)[3][9]) {
for (int i=0; i<3; i++) {
	wmove(portrait, i+1, 1);
	for (int j=0; j<9; j++)
		waddch(portrait, (*portrait_sabrina)[i][j]); }
return ; }

void	draw_planet(WINDOW *planet, char **planetmap) {
for (int i=0; i<18; i++) {
	wmove(planet, i+1, 1);
	for (int j=0; j<68; j++)
		switch(planetmap[i][j]) {
		case '.':
			wattron(planet, COLOR_PAIR(10));
			waddch(planet, planetmap[i][j]);
			wattroff(planet, COLOR_PAIR(10));
			break;
		case 'o':
			wattron(planet, COLOR_PAIR(12));
			waddch(planet, planetmap[i][j]);
			wattroff(planet, COLOR_PAIR(12));
			break;
		case 'c':
			wattron(planet, COLOR_PAIR(11));
			waddch(planet, planetmap[i][j]);
			wattroff(planet, COLOR_PAIR(11));
			break; }}
return ; }
