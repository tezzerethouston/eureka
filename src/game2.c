#include <ncurses.h>
#include "game2.h"
#include "display.h"
#include "load.h"

char	spaceshipmap[8][28];
char	portrait_sabrina[3][9];

void	load_ressources() {
load_spaceshipmap(&spaceshipmap);
load_portrait(&portrait_sabrina);
return ; }

void	refresh_spaceship2(int ply, int plx) {
refresh_spaceship(ply, plx, &spaceshipmap);
return ; }

void	refresh_spaceship_reverse2() {
refresh_spaceship_reverse(&spaceshipmap);
return ; }

void	refresh_portrait2() {
refresh_portrait(&portrait_sabrina);
return ; }

int	refresh_actions2(int ply, int plx) {
return refresh_actions(spaceshipmap[ply][plx]); }
