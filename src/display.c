#include <ncurses.h>
#include "display.h"
#include "draw.h"
#include "dialog.h"

WINDOW	*spaceship, *dialog, *portrait;
WINDOW	*hswarning, *actions, *planet;

void	display_init() {
spaceship = newwin(10, 30, 11, 5);
dialog = newwin(6, 70, 20, 1);
portrait = newwin(5, 11, 16, 1);
hswarning = newwin(3, 25, 11, 46);
actions = newwin(3, 25, 14, 46);
planet = newwin(20, 70, 1, 1);
return ; }

void	display_end() {
delwin(spaceship);
delwin(dialog);
delwin(portrait);
delwin(hswarning);
delwin(actions);
delwin(planet);
return ; }

void	refresh_planet(int ply, int plx, char **planetmap) {
draw_planet(planet, planetmap);
box(planet, 0, 0);
draw_character(planet, ply, plx);
wrefresh(planet);
return ; }

int	refresh_actions(char c) {
switch(c) {
	case 'T':
		box(actions, 0, 0);
		mvwprintw(actions, 1, 1, "t- teleport");
		wrefresh(actions);
		return 1;
		break;
	case 'F':
		box(actions, 0, 0);
		mvwprintw(actions, 1, 1, "f- navigate");
		wrefresh(actions);
		return 1;
		break;
}
return 0; }

void	erase_actions() {
werase(actions);
wrefresh(actions);
return ; }

void	box_spaceship() {
box(spaceship, 0, 0);
for (int i=1; i<9; i++)
	mvwprintw(spaceship, i, 1, "                            ");
wrefresh(spaceship);
return ; }

void	refresh_spaceship(int ply, int plx, char (*spaceshipmap)[][28]) {
wattroff(spaceship, A_REVERSE);
box(spaceship, 0, 0);
draw_spaceship(spaceship, spaceshipmap);
draw_character(spaceship, ply, plx);
wrefresh(spaceship);
return ; }

void	refresh_spaceship_reverse(char (*spaceshipmap)[][28]) {
wattron(spaceship, A_REVERSE);
box(spaceship, 0, 0);
draw_spaceship(spaceship, spaceshipmap);
wrefresh(spaceship);
return ; }

void	erase_spaceship() {
werase(spaceship);
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

void	refresh_portrait(char (*portrait_sabrina)[][9]) {
box(portrait, 0, 0);
draw_portrait(portrait, portrait_sabrina);
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
