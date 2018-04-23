/*
** EPITECH PROJECT, 2018
** aff ing r burger
** File description:
** aff_burger_r_ing
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

void	aff_burger_r_ing(t_sprite *sprite, sfRenderWindow *window)
{
	void(*pntrfunc[8]);
	int i = 0;

	list_sprite_r_hamburger(pntrfunc, sprite);
	while (i < 8) {
		sfRenderWindow_drawSprite(window, pntrfunc[i], NULL);
		i = i + 1;
	}
}