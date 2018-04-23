/*
** EPITECH PROJECT, 2018
** set_game
** File description:
** set_game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void	sprite_set_game_gui(t_game_gui *gui)
{
	gui->b_pause = create_sprite("assets/game/pause_b.png");
	gui->b_leave = create_sprite("assets/game/leave_b.png");
	gui->b_restart = create_sprite("assets/game/restart_b.png");
	gui->b_resume = create_sprite("assets/game/resume_b.png");
	gui->b_serve = create_sprite("assets/game/serve_b.png");
	gui->back = create_sprite("assets/game/back_game.png");
	gui->pause = create_sprite("assets/game/pause_game.png");
	gui->back_end = create_sprite("assets/finish_game.png");
}

void	set_pos_game_gui(t_game_gui *gui)
{
	float	x = 820;
	float	y = 250;

	set_pos_sprite(gui->b_serve, 1550, 850);
	set_pos_sprite(gui->b_pause, 1550, 30);
	set_pos_sprite(gui->b_resume, x, y);
	y = y + 150;
	set_pos_sprite(gui->b_restart, x, y);
	y = y + 150;
	set_pos_sprite(gui->b_leave, x, y);
}

void set_rect_game_gui(t_game_gui *gui)
{
	gui->rect_b.top = 0;
	gui->rect_b.left = 0;
	gui->rect_b.width = 350;
	gui->rect_b.height = 103;
	gui->rect_h.top = 0;
	gui->rect_h.left = 350;
	gui->rect_h.width = 350;
	gui->rect_h.height = 103;
}

void	set_var_game_gui(t_game_gui *gui)
{
	sfVector2f pos;

	gui->click = 0;
	gui->m_pause = 0;
	gui->serve = 0;
	gui->point = 0;
	gui->time = 120;
	gui->t_point = create_texte("0", "assets/font/pres.ttf", 80, sfBlack);
	pos.x = 850;
	pos.y = 30;
	sfText_setPosition(gui->t_point, pos);
	gui->t_time = create_texte("2:00", "assets/font/pres.ttf", 80, sfBlack);
	pos.x = 1230;
	sfText_setPosition(gui->t_time, pos);
	gui->times = sfClock_create();
	gui->action_serve = 0;
	gui->clock_serve = sfClock_create();
	gui->restart = 0;
	gui->f_recipes = 0;
	gui->g_recipes = 0;
	gui->aff_point = create_texte(" ", "assets/font/game.ttf", 30, sfBlack);
}

void	set_game_gui(t_game_gui *gui)
{
	sprite_set_game_gui(gui);
	set_pos_game_gui(gui);
	set_rect_game_gui(gui);
	set_var_game_gui(gui);
}