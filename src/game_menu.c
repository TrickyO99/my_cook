/*
** EPITECH PROJECT, 2018
** menu game
** File description:
** game_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void	input_event_game_menu(t_window *window, t_game_menu *menu)
{
	while (sfRenderWindow_pollEvent(window->window, &(window->event))) {
		if ((window->event).type == sfEvtClosed) {
			sfRenderWindow_close(W);
		} else if ((window->event).type == sfEvtMouseButtonReleased) {
			menu->click = 1;
		} else {
			menu->click = 0;
		}
	}
}

void	draw_button_game_menu(t_game_menu *menu, t_window *window)
{
	sfRenderWindow_drawSprite(window->window,
	hoover2sprite(menu->play_b, menu->play_h, window), NULL);
	sfRenderWindow_drawSprite(window->window,
	hoover2sprite(menu->custom_b, menu->custom_h, window), NULL);
	sfRenderWindow_drawSprite(window->window,
	hoover2sprite(menu->option_b, menu->option_h, window), NULL);
	sfRenderWindow_drawSprite(window->window,
	hoover2sprite(menu->leave_b, menu->leave_h, window), NULL);
}

void	list_sprite_button_menu(void	*pntrfunc[], t_game_menu *menu)
{
	pntrfunc[0] = menu->play_h;
	pntrfunc[1] = menu->custom_h;
	pntrfunc[2] = menu->option_h;
	pntrfunc[3] = menu->leave_h;
}

int	change_menu_game_menu(t_game_menu *menu, t_window *window)
{
	void *pntrfunc[4];
	int go[4] = {PLAY_MENU, CUSTOM_MENU, OPTION_MENU, LEAVE_MENU};
	int i = 0;

	list_sprite_button_menu(pntrfunc, menu);
	while (i < 4) {
		if (menu->click == 1 &&
			mouse_on_the_sprite(pntrfunc[i], window->window) == 1) {
			window->menu = go[i];
			return (1);
		}
		i = i + 1;
	}
	return (0);
}

void	game_menu(t_window *window)
{
	t_game_menu menu;

	set_game_menu(&menu);
	while (sfRenderWindow_isOpen(window->window) &&
		window->menu == GAME_MENU) {
		input_event_game_menu(window, &menu);
		sfRenderWindow_drawSprite(window->window, menu.back, NULL);
		draw_button_game_menu(&menu, window);
		sfRenderWindow_drawSprite(window->window, menu.philip, NULL);
		display_and_cursor(window);
		change_menu_game_menu(&menu, window);
	}
	destroy_game_menu(&menu);
}