#include <ncurses.h>
#include "draw.h"
#include "game.h"

char	spaceshipmap[8][28];
char	portrait_sabrina[3][9];

void	load_spaceshipmap() {
FILE	*f = fopen("asset/map/spaceship", "r");
for (int i=0; i<8; i++) {
	for (int j=0; j<28; j++)
		spaceshipmap[i][j] = getc(f);
	getc(f); }
fclose(f);
return ; }

void	load_portrait() {
FILE	*f = fopen("asset/ascii/sabrina", "r");
for (int i=0; i<3; i++) {
	for (int j=0; j<9; j++)
		portrait_sabrina[i][j] = getc(f);
	getc(f); }
fclose(f);
return ; }

void	draw_spaceship(WINDOW *spaceship) {
for (int i=0; i<8; i++) {
	wmove(spaceship, i+1, 1);
	for (int j=0; j<28; j++)
		waddch(spaceship, spaceshipmap[i][j]); }
return ; }

void	draw_character(WINDOW *map, int y, int x) {
wattron(map, COLOR_PAIR(1));
mvwaddch(map, y, x, '@');
wattroff(map, COLOR_PAIR(1));
return ; }

void	draw_portrait(WINDOW *portrait) {
for (int i=0; i<3; i++) {
	wmove(portrait, i+1, 1);
	for (int j=0; j<9; j++)
		waddch(portrait, portrait_sabrina[i][j]); }
return ; }
