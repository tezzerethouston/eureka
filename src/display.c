#include <ncurses.h>
#include "display.h"
#include "draw.h"
#include "dialog.h"

WINDOW	*spaceship, *dialog, *portrait, *hswarning;

void	display_init() {
spaceship = newwin(10, 30, 11, 5);
dialog = newwin(6, 70, 20, 1);
portrait = newwin(5, 11, 16, 1);
hswarning = newwin(3, 25, 11, 45);
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

void	refresh_spaceship(int ply, int plx) {
wattroff(spaceship, A_REVERSE);
box(spaceship, 0, 0);
draw_spaceship(spaceship);
draw_character(spaceship, ply, plx);
wrefresh(spaceship);
return ; }

void	refresh_spaceship_reverse() {
wattron(spaceship, A_REVERSE);
box(spaceship, 0, 0);
draw_spaceship(spaceship);
wrefresh(spaceship);
return ; }

int	refresh_dialog(int scene, int I) {
int	rv;
box(dialog, 0, 0);
rv = printdialog(dialog, scene, I);
wrefresh(dialog);
return rv; }

void	erase_dialog() {
werase(dialog);
wrefresh(dialog);
return ; }

void	refresh_portrait() {
box(portrait, 0, 0);
draw_portrait(portrait);
wrefresh(portrait);
return ; }

void	erase_portrait() {
werase(portrait);
wrefresh(portrait);
return ; }

void	refresh_hswarning() {
box(hswarning, 0, 0);
mvwprintw(hswarning, 1, 1, " HYPERSPACE WARNING!!! ");
wrefresh(hswarning);
return ; }

void	erase_hswarning() {
werase(hswarning);
wrefresh(hswarning);
return ; }
