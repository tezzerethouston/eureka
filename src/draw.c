#include <ncurses.h>
#include "draw.h"
#include "game.h"

char	spaceshipmap[8][28];

void	load_spaceshipmap() {
FILE	*f;

f=fopen("asset/map/spaceship", "r");
for (int i=0; i<8; i++) {
	for (int j=0; j<28; j++)
		spaceshipmap[i][j] = getc(f);
	getc(f); }
fclose(f);
return ; }

void	draw_spaceship(WINDOW *spaceship) {
for (int i=0; i<8; i++) {
	wmove(spaceship, i+1, 1);
	for (int j=0; j<28; j++)
		waddch(spaceship, spaceshipmap[i][j]); }
return ; }
