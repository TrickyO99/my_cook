/*
** EPITECH PROJECT, 2018
** action_game
** File description:
** ation_game.
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

void	serve_game(t_game_gui *gui)
{
	if (gui->serve == 1) {
		sfClock_restart(gui->clock_serve);
		gui->serve = 0;
		gui->action_serve = 1;
	} else {
		gui->serve = 0;
	}
}

void	restart_game(t_game_gui *gui, t_sprite *sprite)
{
	if (gui->restart == 1) {
		gui->time = 120;
		gui->click = 0;
		gui->m_pause = 0;
		gui->point = 0;
		gui->f_recipes = 0;
		gui->g_recipes = 0;
		gui->action_serve = 0;
		sprite->expect = rand_burger();
		my_strcpy(sprite->cook, "xxxxxxxx");
		set_rect_sprite_hamburger_r(sprite, sprite->rect_no);
		gui->restart = 0;
		set_pos_game_gui(gui);
	}
}

char	*set_end_string_game(t_game_gui *gui)
{
	char *str = malloc(sizeof(char) * 64);

	my_strcpy(str, "You've scored ");
	str = my_strcat(str, int_to_string(gui->point));
	str = my_strcat(str, " point(s) !\n\n");
	str = my_strcat(str, int_to_string(gui->g_recipes));
	str = my_strcat(str, " good recipe(s)\nand ");
	str = my_strcat(str, int_to_string(gui->f_recipes));
	str = my_strcat(str, " bad recipe(s)\n");
	return (str);
}

void	game_end(t_game_gui *gui)
{
	sfVector2f pos;

	if (gui->time == 0) {
		gui->m_pause = 1;
		pos.x = 600;
		pos.y = 550;
		sfSprite_setPosition(gui->b_restart, pos);
		pos.x = pos.x + 400;
		sfSprite_setPosition(gui->b_leave, pos);
		pos.x = pos.x - 400;
		pos.y = pos.y - 200;
		sfText_setPosition(gui->aff_point, pos);
		sfText_setString(gui->aff_point, set_end_string_game(gui));
	}
}

void	action_game(t_game_gui *gui, t_sprite *sprite)
{
	serve_game(gui);
	restart_game(gui, sprite);
	game_end(gui);
}