#include <ncurses.h>

int	main (int ac, char **av) {

char	c;

initscr();	//start curses mode
cbreak();	//no buffering
noecho();
//nodelay(stdscr, TRUE);	//getch doesn't wait
curs_set(0);	//no cursor

erase();
printw("Sabrina's Endeavour\n\n");
printw("q- quit\n\n");
refresh();

while(1) { c = getch();
switch(c) {
	case 'q':
		goto exit;
}}

exit:
endwin();
return 0; }
