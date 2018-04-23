/*
** EPITECH PROJECT, 2018
** fonc game2
** File description:
** fon_game2.
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

sfVector2f	convert_sfvector2i_to_sfvector2f(sfVector2i vec2i)
{
	sfVector2f pos;

	pos.x = (float) vec2i.x;
	pos.y = (float) vec2i.y;
	return (pos);
}

void	display_and_cursor(t_window *window)
{
	sfVector2i vec2i = get_mouse_pos(window->window);
	sfVector2f pos = convert_sfvector2i_to_sfvector2f(vec2i);

	sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
	sfSprite_setPosition(window->cursor, pos);
	sfRenderWindow_drawSprite(window->window, window->cursor, NULL);
	sfRenderWindow_display(window->window);
}

int	mouse_on_the_sprite(sfSprite *sprite, sfRenderWindow *window)
{
	sfVector2i pos_s = get_sprite_pos(sprite);
	sfFloatRect loc_s = sfSprite_getGlobalBounds(sprite);
	sfVector2i pos_m = sfMouse_getPositionRenderWindow(window);

	if (pos_m.x > pos_s.x && pos_m.x < (pos_s.x + loc_s.width) &&
		pos_m.y > pos_s.y && pos_m.y < (pos_s.y + loc_s.height)) {
		return (1);
	} else {
		return (0);
	}
}

void	set_pos_sprite(sfSprite *sprite, float x, float y)
{
	sfVector2f pos;

	pos.x = x;
	pos.y = y;
	sfSprite_setPosition(sprite, pos);
}

void	aff_good_rect(sfSprite *sp, sfIntRect rb, sfIntRect rh,
	sfRenderWindow *window, int b)
{
	if (mouse_on_the_sprite(sp, window) == 1 && b == 0) {
		sfSprite_setTextureRect(sp, rh);
	} else if (b == 0) {
		sfSprite_setTextureRect(sp, rb);
	}
	sfRenderWindow_drawSprite(window, sp, NULL);
}