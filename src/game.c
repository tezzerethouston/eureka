#include <ncurses.h>
#include "game.h"
#include "display.h"

int	game (char a) {
char	c;
int	scene, I;

c=0;
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

// === DISPLAY ===
if (scene==1 && I<=1) box_spaceship();
else refresh_spaceship();
refresh_dialog(scene, I);
// ===============
c=getch(); }

exit:
display_end();
return 0; }
