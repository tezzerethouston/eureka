#include <ncurses.h>
#include "display.h"
#include "draw.h"
#include "dialog.h"

WINDOW	*spaceship, *dialog, *portrait;
WINDOW	*hswarning, *actions, *planet;
WINDOW	*inventory, *hpdisplay, *fcontrol;
WINDOW	*windshield;

void	display_init() {
spaceship = newwin(10, 30, 11, 5);
dialog = newwin(6, 70, 20, 1);
portrait = newwin(5, 11, 16, 1);
hswarning = newwin(3, 25, 11, 46);
actions = newwin(6, 25, 1, 46);
planet = newwin(20, 70, 1, 1);
inventory = newwin(7, 15, 3, 71);
hpdisplay = newwin(3, 15, 1, 71);
fcontrol = newwin(12, 37, 2, 1);
windshield = newwin(7, 37, 3, 1);
return ; }

void	display_end() {
delwin(spaceship);
delwin(dialog);
delwin(portrait);
delwin(hswarning);
delwin(actions);
delwin(planet);
delwin(inventory);
delwin(hpdisplay);
delwin(fcontrol); delwin(windshield);
return ; }

void	refresh_fcontrol() {
box(fcontrol, 0, 0);
box(windshield, 0, 0);
mvwprintw(fcontrol, 0, 10, " Flight Control ");
mvwaddch(windshield, 2, 2, '+');
mvwaddch(windshield, 1, 30, '*');
mvwaddch(windshield, 2, 33, '+');
wattron(windshield, COLOR_PAIR(10));
mvwprintw(windshield, 3, 11, "               ");
mvwprintw(windshield, 4, 6, "                         ");
mvwprintw(windshield, 5, 3, "                               ");
wattroff(windshield, COLOR_PAIR(10));
mvwprintw(fcontrol, 8, 10, "Planet Amarada");
mvwprintw(fcontrol, 9, 1, "Hostility: 0   Foraging: 5");
mvwprintw(fcontrol, 10, 1, "Hyperspace drive: Reloading 000/100");
mvwprintw(fcontrol, 11, (int)(3*37/4), " f ");
wrefresh(fcontrol);
wrefresh(windshield);
return ; }

void	erase_fcontrol() {
werase(fcontrol);
wrefresh(fcontrol);
return ; }

void	refresh_hp(int hp) {
box(hpdisplay, 0, 0);
mvwprintw(hpdisplay, 1, 1, "HP ");
wattron(hpdisplay, COLOR_PAIR(20));
wprintw(hpdisplay, "10/10     ");
wattroff(hpdisplay, COLOR_PAIR(20));
wrefresh(hpdisplay);
return ; }

void	refresh_inventory(item (*inv)[10]) {
box(inventory, 0, 0);
for (int i=0; i<10; i++) {
	if (inv[i]->c==0) break;
	wmove(inventory, i+1, 1);
	switch(inv[i]->c) {
		case 'o':
			wprintw(inventory, "red berry  ");
			break; }
	waddch(inventory, (char)(inv[i]->n+'0')); }
wrefresh(inventory);
return ; }

void	refresh_planet(int ply, int plx, char **planetmap) {
werase(planet);
draw_planet(planet, planetmap);
box(planet, 0, 0);
draw_character(planet, ply, plx, 2);
wrefresh(planet);
return ; }

void	refresh_actions(char c) {
box(actions, 0, 0);
mvwprintw(actions, 1, 1, "q- quit");
mvwprintw(actions, 2, 1, "wasd- move");
switch(c) {
	case 'T':	//teleporter
		mvwprintw(actions, 3, 1, "t- teleport");
		break;
	case 'F':	//flight control
		mvwprintw(actions, 3, 1, "f- navigate");
		break;
	case 'o':	//berry
		mvwprintw(actions, 3, 1, "p- pick up (berry)");
		break;
	default:
		mvwprintw(actions, 3, 1, "                  ");
		break;
}
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
draw_character(spaceship, ply, plx, 1);
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

void	blink_hswarning() {
wattron(hswarning, A_REVERSE);
box(hswarning, 0, 0);
wattroff(hswarning, A_REVERSE);
mvwprintw(hswarning, 1, 1, " HYPERSPACE WARNING!!! ");
wrefresh(hswarning);
return ; }

void	erase_hswarning() {
werase(hswarning);
wrefresh(hswarning);
return ; }
