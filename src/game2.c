#include <ncurses.h>
#include "game2.h"
#include "display.h"

char	spaceshipmap[8][28];
char	portrait_sabrina[3][9];

void	load_ressources() {
load_spaceshipmap();
load_portrait();
return ; }

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

void	refresh_spaceship2(int ply, int plx) {
refresh_spaceship(ply, plx, &spaceshipmap);
return ; }

void	refresh_spaceship_reverse2() {
refresh_spaceship_reverse(&spaceshipmap);
return ; }

void	refresh_portrait2() {
refresh_portrait(&portrait_sabrina);
return ; }
