#ifndef SCREEN_H
# define SCREEN_H

typedef struct sm {
	struct sm	*up;
	struct sm	*down;
	struct sm	*left;
	struct sm	*right;
	char	**screen;
} screenmap;

#endif
