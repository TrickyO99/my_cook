/*
** EPITECH PROJECT, 2017
** struct
** File description:
** 
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef STRUCT_H_

#define STRUCT_H_
#define START_MENU	(0)
#define GAME_MENU	(1)
#define PLAY_MENU	(3)
#define CUSTOM_MENU	(4)
#define OPTION_MENU	(5)
#define LEAVE_MENU	(6)
#define G			(gui)
#define W			(window->window)

typedef struct	s_window
{
	sfRenderWindow	*window;
	sfVideoMode		video;
	sfEvent			event;
	sfSprite		*cursor;
	int				menu;
} t_window;

typedef struct	s_prite
{
	sfSprite	*lower_bun;
	sfSprite	*upper_bun;
	sfSprite	*steak;
	sfSprite	*cheese;
	sfSprite	*onion;
	sfSprite	*salad;
	sfSprite	*tomato;
	sfSprite	*bacon;
	sfSprite	*plate;
	sfIntRect	rect_no;
	sfIntRect	rect_on;
	sfSprite	*r_upper_bun;
	sfSprite	*r_steak;
	sfSprite	*r_cheese;
	sfSprite	*r_salad;
	sfSprite	*r_tomato;
	sfSprite	*r_bacon;
	sfSprite	*r_onion;
	sfSprite	*r_lower_bun;
	char		*expect;
	char		*cook;
} t_sprite;

typedef struct s_game_gui
{
	sfSprite	*back;
	sfSprite	*pause;
	sfSprite	*b_pause;
	sfSprite	*b_leave;
	sfSprite	*b_restart;
	sfSprite	*b_resume;
	sfSprite	*b_serve;
	sfIntRect	rect_b;
	sfIntRect	rect_h;
	int			click;
	int			m_pause;
	int 		serve;
	int			point;
	int			time;
	sfText		*t_point;
	sfText		*t_time;
	sfClock		*times;
	int			action_serve;
	sfClock		*clock_serve;
	int			restart;
	sfSprite	*back_end;
	sfText		*aff_point;
	int			f_recipes;
	int			g_recipes;
} t_game_gui;

typedef struct s_start_menu
{
	sfSprite	*background;
	sfText		*txt;
	sfText		*press;
} t_start_menu;

typedef struct s_game_menu
{
	sfSprite	*back;
	sfSprite	*play_b;
	sfSprite	*play_h;
	sfSprite	*custom_b;
	sfSprite	*custom_h;
	sfSprite	*option_b;
	sfSprite	*option_h;
	sfSprite	*leave_b;
	sfSprite	*leave_h;
	sfSprite	*philip;
	int click;
} t_game_menu;

#endif