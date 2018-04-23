/*
** EPITECH PROJECT, 2018
** aff_burger
** File description:
** aff_burger
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void	aff_plate_game(t_sprite *sprite, int size,
	sfVector2f pos, sfRenderWindow *window)
{
	sfVector2f scale;
	sfSprite *zip = sfSprite_create();

	scale.x = (float) size / 75;
	scale.y = (float) size / 75;
	pos.x = pos.x - 40;
	pos.y = pos.y - 15;
	zip = sfSprite_copy(sprite->plate);
	sfSprite_setPosition(zip, pos);
	sfSprite_scale(zip, scale);
	sfRenderWindow_drawSprite(window, zip, NULL);
}

void	list_sprite_burger_ing(void	*pntrfunc[], t_sprite *sprite)
{
	pntrfunc[0] = sprite->lower_bun;
	pntrfunc[1] = sprite->upper_bun;
	pntrfunc[2] = sprite->cheese;
	pntrfunc[3] = sprite->onion;
	pntrfunc[4] = sprite->bacon;
	pntrfunc[5] = sprite->steak;
	pntrfunc[6] = sprite->salad;
	pntrfunc[7] = sprite->tomato;
}

sfSprite	*find_sprite_hamurger(t_sprite *sprite, char c)
{
	char flag[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	void *pntrfunc[8];
	int i = 0;
	sfSprite *bin = sfSprite_create();

	list_sprite_burger_ing(pntrfunc, sprite);
	while (i < 8) {
		if (flag[i] == c) {
			return (pntrfunc[i]);
		}
		i = i + 1;
	}
	return (bin);
}

void	aff_sprite_burger_part(t_sprite *sprite, char c,
	int size, sfVector2f pos, sfRenderWindow *window)
{
	sfVector2f scale;
	sfSprite *zip = sfSprite_create();

	scale.x = (float) size / 100;
	scale.y = (float) size / 100;
	zip = sfSprite_copy(find_sprite_hamurger(sprite, c));
	sfSprite_setPosition(zip, pos);
	sfSprite_scale(zip, scale);
	sfRenderWindow_drawSprite(window, zip, NULL);
}

void	aff_burger(t_sprite *sprite, char *c_burger, int size,
	sfVector2f pos, sfRenderWindow *window)
{
	aff_plate_game(sprite, size, pos, window);
	pos.y = pos.y - 33;
	aff_sprite_burger_part(sprite, c_burger[0], size, pos, window);
	pos.y = pos.y - 33;
	aff_sprite_burger_part(sprite, c_burger[1], size, pos, window);
	pos.y = pos.y - 33;
	aff_sprite_burger_part(sprite, c_burger[2], size, pos, window);
	pos.y = pos.y - 33;
	aff_sprite_burger_part(sprite, c_burger[3], size, pos, window);
	pos.y = pos.y - 33;
	aff_sprite_burger_part(sprite, c_burger[4], size, pos, window);
	pos.y = pos.y - 33;
	aff_sprite_burger_part(sprite, c_burger[5], size, pos, window);
	pos.y = pos.y - 33;
	aff_sprite_burger_part(sprite, c_burger[6], size, pos, window);
	pos.y = pos.y - 33;
	aff_sprite_burger_part(sprite, c_burger[7], size, pos, window);
}