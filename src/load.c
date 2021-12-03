#include <ncurses.h>
#include "load.h"

void	load_spaceshipmap(char (*spaceshipmap)[][28]) {
FILE	*f = fopen("asset/map/spaceship", "r");
for (int i=0; i<8; i++) {
	for (int j=0; j<28; j++)
		(*spaceshipmap)[i][j] = getc(f);
	getc(f); }
fclose(f);
return ; }

void	load_portrait(char (*portrait_sabrina)[][9]) {
FILE	*f = fopen("asset/ascii/sabrina", "r");
for (int i=0; i<3; i++) {
	for (int j=0; j<9; j++)
		(*portrait_sabrina)[i][j] = getc(f);
	getc(f); }
fclose(f);
return ; }
