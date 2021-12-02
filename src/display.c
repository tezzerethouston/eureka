#include <ncurses.h>
#include "display.h"
#include "draw.h"
#include "dialog.h"

WINDOW	*spaceship, *dialog;

void	display_init() {
spaceship = newwin(10, 30, 10, 1);
dialog = newwin(6, 70, 20, 1);
load_spaceshipmap();
return ; }

void	display_end() {
delwin(spaceship);
delwin(dialog);
return ; }

void	box_spaceship() {
box(spaceship, 0, 0);
for (int i=1; i<9; i++)
	mvwprintw(spaceship, i, 1, "                            ");
wrefresh(spaceship);
return ; }

void	refresh_spaceship() {
wattroff(spaceship, A_REVERSE);
box(spaceship, 0, 0);
draw_spaceship(spaceship);
wrefresh(spaceship);
return ; }

void	refresh_spaceship_reverse() {
wattron(spaceship, A_REVERSE);
box(spaceship, 0, 0);
draw_spaceship(spaceship);
wrefresh(spaceship);
return ; }

void	refresh_dialog(int scene, int I) {
box(dialog, 0, 0);
printdialog(dialog, scene, I);
wrefresh(dialog);
return ; }
