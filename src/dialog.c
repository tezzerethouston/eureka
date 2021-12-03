#include <ncurses.h>
#include "dialog.h"
#include "sceneevent.h"

int	printdialog(WINDOW *w, int scene, int I) {
FILE	*f;
char	c;
int	rv = 1;
werase(w); box(w, 0, 0);
mvwprintw(w, 5, 60, " space ");
if (scene==1 && I>1) mvwprintw(w, 0, 11, " Sabrina ");

f = fopen("asset/scene/1", "r");
for(int i=0; i<I; i++) while(getc(f)!='\n');
wmove(w, 1, 1);
for (int i=0; (c=getc(f))!='\n'; i++) {
	if (!i)
		if (c==EOF) {
			rv = 0;
			break; }
		else if (c=='#') {
			sceneevent(scene, I);
			break; }
	waddch(w, c);
}

fclose(f);
return rv; }
