#include <ncurses.h>
#include "ressources.h"
#include "display.h"
#include "load.h"

char	spaceshipmap[8][28];
char	portrait_sabrina[3][9];

void	load_ressources() {
load_spaceshipmap(&spaceshipmap);
load_portrait(&portrait_sabrina);
return ; }

char	get_atpos(int y, int x) {
return spaceshipmap[y][x]; }

void	refresh_spaceship2(int ply, int plx) {
refresh_spaceship(ply, plx, &spaceshipmap);
return ; }

void	refresh_spaceship_reverse2() {
refresh_spaceship_reverse(&spaceshipmap);
return ; }

void	refresh_portrait2() {
refresh_portrait(&portrait_sabrina);
return ; }

void	refresh_actions2(int ply, int plx) {
refresh_actions(spaceshipmap[ply][plx]);
return ; }
