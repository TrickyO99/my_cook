/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

void	close_game(t_window *window)
{
	sfRenderWindow_close(window->window);
}

void	list_func_menu_game(void(*pntrfunc[])(t_window*))
{
	pntrfunc[0] = &start_menu;
	pntrfunc[1] = &game_menu;
	pntrfunc[2] = &play_game;
	pntrfunc[3] = &close_game;
	pntrfunc[4] = &settings;
	pntrfunc[5]	= &how_to_play;
}

void	start_game(void)
{
	int tab[6] = 	{START_MENU, GAME_MENU, PLAY_MENU,
					LEAVE_MENU, OPTION_MENU, CUSTOM_MENU};
	int x = 0;
	t_window window;
	void (*pntrfunc[6])(t_window*);
	sfMusic	*theme = sfMusic_createFromFile("assets/sound/theme.ogg");

	window_set(&window);
	list_func_menu_game(pntrfunc);
	sfMusic_play(theme);
	sfMusic_setLoop(theme, sfTrue);
	while (sfRenderWindow_isOpen(window.window) && x < 6) {
		if (tab[x] == window.menu) {
			pntrfunc[x](&window);
		}
		x = x + 1;
		if (x == 6)
			x = 0;
	}
	sfMusic_stop(theme);
	sfMusic_destroy(theme);
}

int	main(int ac, char **av)
{
	if (ac >= 2) {
		if (error_msg(av) == 0) {
			return (0);
		} else {
			return (84);
		}
	}
	start_game();
	my_putstr("\nThanks for playing !\n\n");
	return (0);
}