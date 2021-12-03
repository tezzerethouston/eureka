#ifndef DISPLAY_H
# define DISPLAY_H

void	display_init();
void	display_end();

void	box_spaceship();
void	refresh_spaceship(int ply, int plx);
void	refresh_spaceship_reverse();
int	refresh_dialog(int scene, int I);
void	erase_dialog();
void	refresh_portrait();
void	erase_portrait();
void	refresh_hswarning();
void	erase_hswarning();

#endif
