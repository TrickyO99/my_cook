/*
** EPITECH PROJECT, 2017
** set.c
** File description:
** 
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void	window_set(t_window *window)
{
	window->video.width = 1920;
	window->video.height = 1080;
	window->video.bitsPerPixel = 32;
	window->window = sfRenderWindow_create(window->video,
	"my_cook", sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window->window, 120);
	window->cursor = create_sprite("assets/cursor.png");
	window->menu = START_MENU;
	sfRenderWindow_setVerticalSyncEnabled(window->window, sfTrue);
}

void	set_start_menu(t_start_menu *start_menu)
{
	sfVector2f pos;

	start_menu->background = create_sprite("assets/back.png");
	pos.x = 350;
	pos.y = 150;
	start_menu->txt = create_texte("COOKING PAPA",
	"assets/font/name.ttf", 150, sfWhite);
	sfText_setPosition(start_menu->txt, pos);
	pos.x = 540;
	pos.y = 820;
	start_menu->press = create_texte("PRESS ANY KEY TO START",
	"assets/font/pres.ttf", 50, sfWhite);
	sfText_setPosition(start_menu->press, pos);
}