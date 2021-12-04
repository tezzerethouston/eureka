#include "inventory.h"
#include "item.h"
#include "display.h"

item	inv[10];

void	inventory_init() {
for (int i=0; i<10; i++)
	inv[i].c = 0;
return ; }

void	inventory_add(char c) {
for (int i=0; i<10; i++) {
	if (inv[i].c==c) {
		inv[i].n++;
		break; }
	else if (inv[i].c==0) {
		inv[i].c = c;
		inv[i].n = 1;
		break; }
} return ; }

void	refresh_inventory2() {
refresh_inventory(&inv);
return ; }
