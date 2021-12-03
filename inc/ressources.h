#ifndef RESSOURCES_H
# define RESSOURCES_H

void	load_ressources();

char	get_atpos(int y, int x);

void	refresh_spaceship2(int ply, int plx);
void	refresh_spaceship_reverse2();
void	refresh_portrait2();
int	refresh_actions2(int ply, int plx);

#endif
