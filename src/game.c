#include <ncurses.h>
#include "game.h"
#include "dialog.h"
#include "draw.h"

WINDOW	*spaceship, *dialog;

int	game (char a) {
char	c;
int	scene, I;

c=0;
spaceship = newwin(10, 30, 10, 1); box(spaceship, 0, 0);
dialog = newwin(6, 70, 20, 1); box(dialog, 0, 0);
if (a=='n') { scene=1; I=0; }
else { scene=0; };
load_spaceshipmap();

while(1) {
switch(c) {
	case ' ':
		if (scene) I++;
		break;
	case 'q':
		goto exit; }

// === DISPLAY ===
wrefresh(spaceship);
if (scene) printdialog(dialog, scene, I);
wrefresh(dialog);
// ===============
c=getch(); }

exit:
delwin(spaceship); delwin(dialog);
return 0; }
