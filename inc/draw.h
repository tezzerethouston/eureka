#ifndef DRAW_H
# define DRAW_H

void	draw_spaceship(WINDOW *spaceship, char (*spaceshipmap)[8][28]);
void	draw_character(WINDOW *map, int y, int x);
void	draw_portrait(WINDOW *portrait, char (*portrait_sabrina)[3][9]);
void	draw_planet(WINDOW *planet, char **planetmap);

#endif
