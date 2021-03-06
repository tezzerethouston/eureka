#ifndef DISPLAY_H
# define DISPLAY_H

#include "item.h"

void	display_init();
void	display_end();

void	refresh_fcontrol();
void	erase_fcontrol();
void	refresh_hp(int hp);
void	refresh_inventory(item (*inventory)[10]);
void	refresh_planet(int ply, int plx, char **planetmap);
void	refresh_actions(char c);
void	box_spaceship();
void	refresh_spaceship(int ply, int plx, char (*spaceshipmap)[8][28]);
void	refresh_spaceship_reverse(char (*spaceshipmap)[8][28]);
void	erase_spaceship();
int	refresh_dialog(int scene, int I);
void	erase_dialog();
void	refresh_portrait(char (*portrait_sabrina)[3][9]);
void	erase_portrait();
void	refresh_hswarning();
void	blink_hswarning();
void	erase_hswarning();

#endif
