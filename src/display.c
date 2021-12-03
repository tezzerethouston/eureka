#include <ncurses.h>
#include "display.h"
#include "draw.h"
#include "dialog.h"

WINDOW	*spaceship, *dialog, *portrait;

void	display_init() {
spaceship = newwin(10, 30, 11, 5);
dialog = newwin(6, 70, 20, 1);
portrait = newwin(5, 11, 16, 1);
load_spaceshipmap();
load_portrait();
return ; }

void	display_end() {
delwin(spaceship);
delwin(dialog);
delwin(portrait);
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
draw_character(spaceship, 4, 14);
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

void	refresh_portrait() {
box(portrait, 0, 0);
draw_portrait(portrait);
wrefresh(portrait);
return ; }
