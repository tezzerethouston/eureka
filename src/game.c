#include <ncurses.h>
#include "game.h"
#include "load.h"
#include "display.h"
#include "ressources.h"
#include "screen.h"
#include "planetmap.h"
#include "inventory.h"

void	teleport();
void	teleport() { return ; }

int	scene, I;
int	actions_open, fcontrol_open;
char	mode;
int	ply, plx;

//___game_main_______________________
int	game(char a) {
char	c;
screenmap	*planet1;

// INITIALIZATIONS
c = 0;
ply = 3; plx = 13;
if (a=='n') { mode='S'; scene=1; I=0; }
else if (a=='l') { load(&mode, &scene, &I); scene=0; }
else { mode='S'; scene=0; };
fcontrol_open = 0;

display_init();
load_ressources();
planet1 = new_planet();
inventory_init();

// === MAIN LOOP =
while(logic(c, planet1)) {
if (scene==1 && I==5)
	ply = 1;
display(planet1);
c=getch(); }

// === FREEING ===
free_planet(planet1);
display_end();
return 0; }

//___logic_______________________
int	logic(char c, screenmap *planet1) {
FILE	*f;
switch(c) {
	//actions
	case ' ':
		if (scene) I++;
		break;
	case 't':	//teleport
		if (mode=='S' && get_atpos(ply, plx)=='T')
			if (mode=='S') {
				mode = 'P';
				erase_spaceship(); }
			else if (mode=='P') mode = 'S';
		break;
	case 'f':	//navigate
		if (mode=='S' && get_atpos(ply, plx)=='F')
			if (!fcontrol_open) fcontrol_open = 1;
			else {  erase_fcontrol();
				fcontrol_open = 0; }
	case 'p':	//pick up stuff
		if (mode=='P')
			if (planet1->screen[ply][plx]=='o') {
			inventory_add('o');
			planet1->screen[ply][plx] = '.'; }
			else if (planet1->screen[ply][plx]=='c') {
			inventory_add('c');
			planet1->screen[ply][plx] = '.'; }
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
	case 'S':	//save
		f = fopen("save", "w");
		fputc(mode, f);
		fclose(f);
		break;
	case 'q':	//quit
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
		refresh_actions2(ply, plx);
		if (fcontrol_open) refresh_fcontrol(); }}
	else {
		refresh_actions2(ply, plx);
		if (fcontrol_open) refresh_fcontrol(); }
} else if (mode=='P') {
	refresh_planet(ply, plx, planet1->screen);
	refresh_actions(planet1->screen[ply][plx]);
	refresh_hp(10);
	refresh_inventory2();
}
return ; }
