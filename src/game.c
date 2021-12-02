#include <ncurses.h>
#include "game.h"
#include "dialog.h"

int	game (char a) {
char	c;
WINDOW	*spaceship, *dialog;
int	scene, I;

spaceship = newwin(10, 30, 10, 1); box(spaceship, 0, 0);
dialog = newwin(6, 70, 20, 1); box(dialog, 0, 0);
if (a=='n') { scene=1; I=0; }
else { scene=0; };

if (scene) {
	printdialog(dialog, scene, I);
}

// === DISPLAY ===
erase();
refresh();
wrefresh(spaceship);
wrefresh(dialog);
// ===============

while(1) { c=getch();
switch(c) {
	case 'q':
		goto exit;
}}

exit:
delwin(spaceship); delwin(dialog);
return 0; }
