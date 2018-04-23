/*
** EPITECH PROJECT, 2018
** game
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include <SFML/Window.h>
#include "../include/my.h"
#include "../include/struct.h"

void	input_event_game(t_window *window, t_game_gui *gui)
{
	while (sfRenderWindow_pollEvent(window->window,
		&(window->event))) {
		if ((window->event).type == sfEvtClosed) {
			sfRenderWindow_close(window->window);
		}
		if ((window->event).type == sfEvtMouseButtonReleased) {
			gui->click = 1;
		}
	}
}

void	pause_game_click(t_game_gui *gui, t_window *window)
{
	if (gui->m_pause == 1) {
		if (mouse_on_the_sprite(gui->b_resume,
			window->window) == 1) {
			gui->m_pause = 0;
		}
		if (mouse_on_the_sprite(gui->b_restart,
			window->window) == 1) {
			gui->restart = 1;
		}
		if (mouse_on_the_sprite(gui->b_leave, window->window) == 1) {
			window->menu = GAME_MENU;
		}
	}
}

void	check_pause_or_serve_game(t_game_gui *gui, t_window *window)
{
	if (mouse_on_the_sprite(gui->b_pause, window->window) == 1 &&
	gui->m_pause == 0) {
		gui->m_pause = 1;
	} else if (mouse_on_the_sprite(gui->b_serve, window->window) == 1 &&
		gui->m_pause == 0 && gui->action_serve == 0) {
		gui->serve = 1;
	}
}

void	if_click_game(t_window *window, t_sprite *sprite, t_game_gui *gui)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		gui->m_pause = 1;
	}
	if (gui->click == 1) {
		check_pause_or_serve_game(gui, window);
		pause_game_click(gui, window);
		if (gui->m_pause == 0) {
			click_game_burger(sprite, window);
		}
		gui->click = 0;
	}
}

void	play_game(t_window *window)
{
	t_sprite sprite;
	t_game_gui gui;

	sprite_set_hamburger(&sprite);
	set_game_gui(&gui);
	while (sfRenderWindow_isOpen(window->window) &&
		window->menu == PLAY_MENU) {
		input_event_game(window, &gui);
		aff_sprite_game(&gui, &sprite, window);
		display_and_cursor(window);
		if_click_game(window, &sprite, &gui);
		action_game(&gui, &sprite);
	}
	destroy_sprite_and_game(&gui, &sprite);
}