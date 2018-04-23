/*
** EPITECH PROJECT, 2018
** game2.c
** File description:
** game2
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void	aff_sprite_hamburger(t_sprite *sprite, t_window *window,
	t_game_gui *G)
{
	sfVector2f pos;

	pos.x = 150;
	pos.y = 300;
	aff_burger_r_ing(sprite, window->window);
	aff_burger(sprite, sprite->expect, 60, pos, window->window);
	pos.x = 800;
	pos.y = 800;
	if (G->action_serve == 0) {
		aff_burger(sprite, sprite->cook, 120, pos, window->window);
	} else {
		aff_serve_burger_game(G, sprite, window);
	}
}

void	aff_point_game(t_game_gui *G, sfRenderWindow *window)
{
	char *str = int_to_string(G->point);

	sfText_setString(G->t_point, str);
	sfRenderWindow_drawText(window, G->t_point, NULL);
}

void	aff_finish_screen_game(t_game_gui *G, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, G->back_end, NULL);
	aff_good_rect(G->b_restart, G->rect_b, G->rect_h, window, 0);
	aff_good_rect(G->b_leave, G->rect_b, G->rect_h, window, 0);
	sfRenderWindow_drawText(window, G->aff_point, NULL);
}

void	aff_sprite_game(t_game_gui *G, t_sprite *sprite, t_window *window)
{
	sfRenderWindow_drawSprite(window->window, G->back, NULL);
	aff_point_game(G, window->window);
	aff_time_game(G, window->window);
	aff_sprite_hamburger(sprite, window, G);
	aff_good_rect(G->b_pause, G->rect_b, G->rect_h, W, G->m_pause);
	aff_good_rect(G->b_serve, G->rect_b, G->rect_h, W, G->m_pause);
	if (G->m_pause == 1 && G->time > 0) {
		sfRenderWindow_drawSprite(window->window, G->pause, NULL);
		aff_good_rect(G->b_resume, G->rect_b, G->rect_h, W, 0);
		aff_good_rect(G->b_leave, G->rect_b, G->rect_h, W, 0);
		aff_good_rect(G->b_restart, G->rect_b, G->rect_h, W, 0);
	} else if (G->time == 0) {
		aff_finish_screen_game(G, window->window);
	}
}

void	click_game_burger(t_sprite *sprite, t_window *window)
{
	char c = find_ing_to_add_burger(W, sprite);

	sprite->cook = perso_burger(sprite->cook, c);
}