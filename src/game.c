#include <ncurses.h>
#include "game.h"

int	game (char a) {
char	c;
WINDOW	*spaceship, *dialog;

spaceship = newwin(10, 30, 10, 1);
dialog = newwin(6, 70, 20, 1);

// === DISPLAY ===
erase();
refresh();
box(spaceship, 0, 0);
wrefresh(spaceship);
box(dialog, 0, 0);
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
