/*
** EPITECH PROJECT, 2018
** settings
** File description:
** how to play
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

void	settings(t_window *window)
{
	sfSprite	*settings = create_sprite("assets/settings.png");

	while (sfRenderWindow_isOpen(W) && window->menu == OPTION_MENU) {
		sfRenderWindow_drawSprite(W, settings, NULL);
		input_event_start_menu(window);
		display_and_cursor(window);
	}
}

void	how_to_play(t_window *window)
{
	sfSprite	*htp = create_sprite("assets/how_to_play/tutorial.png");

	while (sfRenderWindow_isOpen(W) && window->menu == CUSTOM_MENU) {
		sfRenderWindow_drawSprite(W, htp, NULL);
		input_event_start_menu(window);
		display_and_cursor(window);
	}
}