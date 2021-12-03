#ifndef DISPLAY_H
# define DISPLAY_H

void	display_init();
void	display_end();

int	refresh_actions(char c);
void	erase_actions();
void	box_spaceship();
void	refresh_spaceship(int ply, int plx, char (*spaceshipmap)[8][28]);
void	refresh_spaceship_reverse(char (*spaceshipmap)[8][28]);
int	refresh_dialog(int scene, int I);
void	erase_dialog();
void	refresh_portrait(char (*portrait_sabrina)[3][9]);
void	erase_portrait();
void	refresh_hswarning();
void	erase_hswarning();

#endif
