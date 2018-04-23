/*
** EPITECH PROJECT, 2018
** aff serve burger
** File description:
** aff_serve_burger
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

int	move_burger_cook_game(t_sprite *sprite, t_window *window, int speed)
{
	sfVector2f pos;

	pos.x = 800;
	pos.y = 800;
	pos.x = pos.x + speed;
	aff_burger(sprite, sprite->cook, 120, pos, window->window);
	return ((int) pos.x);
}

void	serve_action_go(t_game_gui *gui, t_window *window,
	t_sprite *sprite, int speed)
{
	int x = move_burger_cook_game(sprite, window, (int) speed);

	if (x > 1920) {
		gui->action_serve = 2;
	}
}

int	nb_of_point_game(char *str)
{
	int p = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] != 'x') {
			p = p + 1;
		}
		i = i + 1;
	}
	return (p);
}

void	point_or_not(t_sprite *sprite, t_game_gui *gui)
{
	int point = nb_of_point_game(sprite->expect);

	if (compare_str(sprite->cook, sprite->expect) == 1) {
		gui->point = gui->point + point;
		gui->g_recipes = gui->g_recipes + 1;
	} else if ((gui->point - point) > 0) {
		gui->point = gui->point - point;
		gui->f_recipes = gui->f_recipes + 1;
	} else {
		gui->point = 0;
		gui->f_recipes = gui->f_recipes + 1;
	}
}

void	aff_serve_burger_game(t_game_gui *gui, t_sprite *sprite,
	t_window *window)
{
	sfTime temp = sfClock_getElapsedTime(gui->clock_serve);
	float tempo = sfTime_asMilliseconds(temp);
	float speed = 10 * (tempo / 2);

	if (gui->action_serve == 1) {
		serve_action_go(gui, window, sprite, speed);
	} else if (gui->action_serve == 2) {
		point_or_not(sprite, gui);
		my_strcpy(sprite->cook, "xxxxxxxx");
		gui->action_serve = 3;
		sfClock_restart(gui->clock_serve);
		set_rect_sprite_hamburger_r(sprite, sprite->rect_no);
		sprite->expect = rand_burger();
		gui->action_serve = 0;
	}
}