/*
** EPITECH PROJECT, 2018
** start menu
** File description:
** start_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void	input_event_start_menu(t_window *window)
{
	while (sfRenderWindow_pollEvent(window->window,
		&(window->event))) {
		if ((window->event).type == sfEvtClosed) {
			sfRenderWindow_close(window->window);
		}
		if (window->event.type == sfEvtKeyPressed ||
			window->event.type == sfEvtMouseButtonPressed) {
			window->menu = GAME_MENU;
		}
	}
}

void	clignotement_press_key(sfRenderWindow *window,
	sfText *text, sfClock *times)
{
	sfTime temp = sfClock_getElapsedTime(times);
	float tempo = sfTime_asSeconds(temp);

	if (tempo < 1) {
		sfRenderWindow_drawText(window, text, NULL);
	} else if (tempo > 2) {
		sfClock_restart(times);
	}
}

void	destroy_alloc_start_menu(t_start_menu *menu, sfClock *times)
{
	sfClock_destroy(times);
	sfText_destroy(menu->txt);
	sfText_destroy(menu->press);
}

void	start_menu(t_window *window)
{
	t_start_menu start_menu;
	sfClock *times = sfClock_create();

	set_start_menu(&start_menu);
	while (sfRenderWindow_isOpen(window->window) &&
		window->menu == START_MENU) {
		input_event_start_menu(window);
		sfRenderWindow_drawSprite(window->window,
		start_menu.background, NULL);
		sfRenderWindow_drawText(window->window, start_menu.txt, NULL);
		clignotement_press_key(window->window, start_menu.press, times);
		display_and_cursor(window);
	}
	destroy_alloc_start_menu(&start_menu, times);
}