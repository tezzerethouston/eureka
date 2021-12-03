#include <ncurses.h>
#include "dialog.h"
#include "sceneevent.h"

void	printdialog(WINDOW *w, int scene, int I) {
FILE	*f;
char	c;
werase(w); box(w, 0, 0);
mvwprintw(w, 5, 60, " space ");
if (scene==1 && I>1) mvwprintw(w, 0, 11, " Sabrina ");

f = fopen("asset/scene/1", "r");
for(int i=0; i<I; i++) while(getc(f)!='\n');
wmove(w, 1, 1);
for (int i=0; (c=getc(f))!='\n'; i++) {
	if (!i && c=='#') {
		sceneevent(scene, I);
		break; }
	//	while(getc(f)!='\n');
	//	c=getc(f); }
	waddch(w, c);
}

fclose(f);
return ; }
