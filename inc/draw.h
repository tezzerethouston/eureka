#ifndef DRAW_H
# define DRAW_H

void	load_spaceshipmap();
void	load_portrait();

void	draw_spaceship(WINDOW *spaceship);
void	draw_character(WINDOW *map, int y, int x);
void	draw_portrait(WINDOW *portrait);

#endif
