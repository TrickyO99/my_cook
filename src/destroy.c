/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** destroy
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/struct.h"

void	destroy_game_menu(t_game_menu *menu)
{
	sfSprite_destroy(menu->play_b);
	sfSprite_destroy(menu->play_h);
	sfSprite_destroy(menu->custom_h);
	sfSprite_destroy(menu->custom_b);
	sfSprite_destroy(menu->option_b);
	sfSprite_destroy(menu->option_h);
	sfSprite_destroy(menu->leave_b);
	sfSprite_destroy(menu->leave_h);
	sfSprite_destroy(menu->back);
}

void	destroy_game_gui(t_game_gui *gui)
{
	sfSprite_destroy(gui->back);
	sfSprite_destroy(gui->pause);
	sfSprite_destroy(gui->b_pause);
	sfSprite_destroy(gui->b_leave);
	sfSprite_destroy(gui->b_restart);
	sfSprite_destroy(gui->b_resume);
	sfSprite_destroy(gui->b_serve);
	sfSprite_destroy(gui->back_end);
	sfText_destroy(gui->t_point);
	sfText_destroy(gui->t_time);
	sfText_destroy(gui->aff_point);
	sfClock_destroy(gui->times);
	sfClock_destroy(gui->clock_serve);
}

void	destroy_sprite_game(t_sprite *sprite)
{
	sfSprite_destroy(sprite->lower_bun);
	sfSprite_destroy(sprite->r_lower_bun);
	sfSprite_destroy(sprite->upper_bun);
	sfSprite_destroy(sprite->r_upper_bun);
	sfSprite_destroy(sprite->steak);
	sfSprite_destroy(sprite->r_steak);
	sfSprite_destroy(sprite->salad);
	sfSprite_destroy(sprite->r_salad);
	sfSprite_destroy(sprite->cheese);
	sfSprite_destroy(sprite->r_cheese);
	sfSprite_destroy(sprite->onion);
	sfSprite_destroy(sprite->r_onion);
	sfSprite_destroy(sprite->tomato);
	sfSprite_destroy(sprite->r_tomato);
	sfSprite_destroy(sprite->bacon);
	sfSprite_destroy(sprite->r_bacon);
	sfSprite_destroy(sprite->plate);
}

void	destroy_sprite_and_game(t_game_gui *gui, t_sprite *sprite)
{
	destroy_game_gui(gui);
	destroy_sprite_game(sprite);
}