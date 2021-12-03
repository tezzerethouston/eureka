#include <ncurses.h>
#include "game.h"
#include "display.h"

int	game (char a) {
char	c;
int	scene, I;
int	ply, plx;

c = 0;
ply = 4; plx = 14;
if (a=='n') { scene=1; I=0; }
else { scene=0; };
display_init();

while(1) {
switch(c) {
	case ' ':
		if (scene) I++;
		break;
	case 'q':
		goto exit; }

if (scene==1 && I==5)
	ply = 2;

// === DISPLAY ===
if (scene==1 && I<=1)
	box_spaceship();
else if (scene==1 && I==2)
	refresh_spaceship(ply, plx);
else if (scene) {
	refresh_spaceship(ply, plx);
	refresh_portrait(); }
else refresh_spaceship(ply, plx);
if (!refresh_dialog(scene, I)) {
	scene = 0; I = 0;
	erase_dialog(); erase_portrait();
	refresh_spaceship(ply, plx); }
// ===============
c=getch(); }

exit:
display_end();
return 0; }
