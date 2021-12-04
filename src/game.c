#include <ncurses.h>
#include "game.h"
#include "display.h"
#include "ressources.h"
#include "screen.h"
#include "planetmap.h"

void	teleport();
void	teleport() { return ; }

int	scene, I;
int	actions_open;
char	mode;
int	ply, plx;

//___game_main_______________________
int	game(char a) {
char	c;
screenmap	*planet1;

// INITIALIZATIONS
c = 0;
ply = 3; plx = 13;
if (a=='n') { scene=1; I=0; }
else { scene=0; };
mode = 'S';	//spaceship mode

display_init();
load_ressources();
planet1 = new_planet();

// === MAIN LOOP =
while(logic(c)) {
if (scene==1 && I==5)
	ply = 1;
display(planet1);
c=getch(); }

// === FREEING ===
free_planet(planet1);
display_end();
return 0; }

//___logic_______________________
int	logic(char c) {
switch(c) {
	//actions
	case ' ':
		if (scene) I++;
		break;
	case 't':	//teleport
		if (get_atpos(ply, plx)=='T')
			teleport();
			if (mode=='S') {
				mode = 'P';
				erase_spaceship(); }
			else if (mode=='P') mode = 'S';
		break;
	case 'f':	//navigate
		if (get_atpos(ply, plx)=='F')
			teleport();
		break;

	//movement
	case 'a':	//left
		if (!scene)
		       switch(mode) {
		       case 'S':
				if (get_atpos(ply, plx-1)!='|'
				&& get_atpos(ply, plx-1)!='_')
					plx--;
				break;
			case 'P':
				if (plx>0) plx--;
				break; }
		break;
	case 'd':	//right
		if (!scene)
		       switch(mode) {
		       case 'S':
				if (get_atpos(ply, plx+1)!='|'
				&& get_atpos(ply, plx+1)!='_')
					plx++;
				break;
			case 'P':
				if (plx<67) plx++;
				break; }
		break;
	case 'w':	//up
		if (!scene)
		       switch(mode) {
		       case 'S':
				if (get_atpos(ply-1, plx)!='|'
				&& get_atpos(ply-1, plx)!='_')
					ply--;
				break;
			case 'P':
				if (ply>0) ply--;
				break; }
		break;
	case 's':	//down
		if (!scene)
		       switch(mode) {
		       case 'S':
				if (get_atpos(ply+1, plx)!='|'
				&& get_atpos(ply+1, plx)!='_')
					ply++;
				break;
			case 'P':
				if (ply<17) ply++;
				break; }
		break;

	//misc/others
	case 'q':
		return 0; }
return 1; }

//___display_______________________
void	display(screenmap *planet1) {
if (mode=='S') {
	if (scene==1 && I<=1)
		box_spaceship();
	else if (scene==1 && I==2)
		refresh_spaceship2(ply, plx);
	else if (scene) {
		refresh_spaceship2(ply, plx);
		refresh_portrait2(); }
	else refresh_spaceship2(ply, plx);
	if (scene) { if (!refresh_dialog(scene, I)) {
		scene = 0; I = 0;
		erase_dialog(); erase_portrait();
		refresh_spaceship2(ply, plx);
		refresh_actions2(ply, plx); }}
	else refresh_actions2(ply, plx);
} else if (mode=='P') {
	refresh_planet(ply, plx, planet1->screen);
	refresh_actions(planet1->screen[ply][plx]);
}
return ; }
