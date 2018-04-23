/*
** EPITECH PROJECT, 2018
** add_burger_ing.c
** File description:
** find_ing_to_add_burger
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

void	list_sprite_r_hamburger(void	*pntrfunc[], t_sprite *sprite)
{
	pntrfunc[0] = sprite->r_lower_bun;
	pntrfunc[1] = sprite->r_upper_bun;
	pntrfunc[2] = sprite->r_cheese;
	pntrfunc[3] = sprite->r_onion;
	pntrfunc[4] = sprite->r_bacon;
	pntrfunc[5] = sprite->r_steak;
	pntrfunc[6] = sprite->r_salad;
	pntrfunc[7] = sprite->r_tomato;
}

void	change_color_ring_burger(sfSprite *sprite, t_sprite *sprite_s)
{
	sfIntRect rect = sfSprite_getTextureRect(sprite);

	if (rect.left == 0) {
		sfSprite_setTextureRect(sprite, sprite_s->rect_on);
	} else {
		sfSprite_setTextureRect(sprite, sprite_s->rect_no);
	}
}

char	find_ing_to_add_burger(sfRenderWindow *window, t_sprite *sprite)
{
	char *str = "abcdefgh";
	int x = 0;
	sfVector2i m_pos = get_mouse_pos(window);
	sfVector2i s_pos;
	void *pntrfunc[8];

	list_sprite_r_hamburger(pntrfunc, sprite);
	while (x < 8) {
		s_pos = get_sprite_pos(pntrfunc[x]);
		if (m_pos.x > s_pos.x && m_pos.x < (s_pos.x + 75) &&
			m_pos.y > s_pos.y && m_pos.y < (s_pos.y + 75)) {
			change_color_ring_burger(pntrfunc[x], sprite);
			return (str[x]);
		}
		x = x + 1;
	}
	return ('x');
}

char	*sup_char_str(char *str, int x)
{
	while (str[x] != '\0') {
		str[x] = str[x + 1];
		x = x + 1;
	}
	str[7] = 'x';
	str[8] = '\0';
	return (str);
}

char	*perso_burger(char *zip, char c)
{
	int x = 0;
	char *str = malloc(sizeof(char) * 8);

	my_strcpy(str, zip);
	while (str[x] != 'x' && str[x] != '\0') {
		if (str[x] == c) {
			return (sup_char_str(str, x));
		}
		x = x + 1;
	}
	if (str[x] == '\0') {
		return (str);
	} else {
		str[x] = c;
		return (str);
	}
}