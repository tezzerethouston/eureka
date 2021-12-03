#include <ncurses.h>
#include "draw.h"

void	draw_spaceship(WINDOW *spaceship, char (*spaceshipmap)[8][28]) {
for (int i=0; i<8; i++) {
	wmove(spaceship, i+1, 1);
	for (int j=0; j<28; j++)
		waddch(spaceship, (*spaceshipmap)[i][j]); }
return ; }

void	draw_character(WINDOW *map, int y, int x) {
wattron(map, COLOR_PAIR(1));
mvwaddch(map, y+1, x+1, '@');
wattroff(map, COLOR_PAIR(1));
return ; }

void	draw_portrait(WINDOW *portrait, char (*portrait_sabrina)[3][9]) {
for (int i=0; i<3; i++) {
	wmove(portrait, i+1, 1);
	for (int j=0; j<9; j++)
		waddch(portrait, (*portrait_sabrina)[i][j]); }
return ; }
