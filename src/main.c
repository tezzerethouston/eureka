#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
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

init_color(COLOR_GREEN, 161, 671, 530);
init_color(COLOR_RED, 682, 149, 188);
init_pair(1, COLOR_BLUE, COLOR_BLACK);	//character
init_pair(2, COLOR_BLUE, COLOR_GREEN);
init_pair(10, COLOR_WHITE, COLOR_GREEN);	//prairie
init_pair(12, COLOR_RED, COLOR_GREEN);	//berry red

srand(time(0));

menu:
erase();
printw("\n");
printw(" Sabrina's Endeavour\n\n");
printw(" n- new game\n");
printw(" q- quit\n");
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
