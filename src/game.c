#include <ncurses.h>
#include "game.h"
#include "display.h"
#include "game2.h"

int	game (char a) {
char	c;
int	scene, I;
int	ply, plx;
int	actions_open;

c = 0;
ply = 3; plx = 13;
if (a=='n') { scene=1; I=0; }
else { scene=0; };
actions_open = 0;
display_init();
load_ressources();

while(1) {
switch(c) {
	case ' ':
		if (scene) I++;
		break;
	case 'a':	//left
		if (!scene) plx--;
		break;
	case 'd':	//right
		if (!scene) plx++;
		break;
	case 'w':	//up
		if (!scene) ply--;
		break;
	case 's':	//down
		if (!scene) ply++;
		break;
	case 'q':
		goto exit; }

if (scene==1 && I==5)
	ply = 1;

// === DISPLAY ===
if (scene==1 && I<=1)
	box_spaceship();
else if (scene==1 && I==2)
	refresh_spaceship2(ply, plx);
else if (scene) {
	refresh_spaceship2(ply, plx);
	refresh_portrait2(); }
else refresh_spaceship2(ply, plx);
if (scene) if (!refresh_dialog(scene, I)) {
	scene = 0; I = 0;
	erase_dialog(); erase_portrait();
	refresh_spaceship2(ply, plx); }
if (!refresh_actions2(ply, plx)) {
	if (actions_open) {
		erase_actions(); actions_open = 0; }}
else actions_open = 1;
// ===============
c=getch(); }

exit:
display_end();
return 0; }
