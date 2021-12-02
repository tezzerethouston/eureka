#include <ncurses.h>
#include "dialog.h"

void	printdialog(WINDOW *w, int scene, int I) {
FILE	*f;
char	c;
werase(w); box(w, 0, 0); mvwprintw(w, 5, 60, " space ");

f = fopen("asset/scene/1", "r");
for(int i=0; i<I; i++) while(getc(f)!='\n');
wmove(w, 1, 1);
while((c=getc(f))!='\n') waddch(w, c);

fclose(f);
return ; }
