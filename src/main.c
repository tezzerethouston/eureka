#include <ncurses.h>
#include <locale.h>
#include "game.h"

int	main (int ac, char **av) {

char	c;

//setlocale(LC_ALL, "");
initscr();	//start curses mode
cbreak();	//no buffering
noecho();
//nodelay(stdscr, TRUE);	//getch doesn't wait
curs_set(0);	//no cursor
start_color();

init_pair(1, COLOR_BLUE, COLOR_BLACK);

menu:
erase();
printw("Sabrina's Endeavour\n\n");
printw("n- new game\n");
printw("q- quit\n");
refresh();

while(1) { c = getch();
switch(c) {
	case 'n':
		erase(); refresh();
		game('n');
		goto menu;
	case 'q':
		goto exit;
}}

exit:
endwin();
return 0; }
