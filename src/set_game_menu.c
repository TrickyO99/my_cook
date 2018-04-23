/*
** EPITECH PROJECT, 2018
** set_game_menu
** File description:
** set_game_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void	set_sprite_button_game_menu(t_game_menu *menu)
{
	menu->custom_b = create_sprite("assets/button/custom_b.png");
	menu->custom_h = create_sprite("assets/button/custom_h.png");
	menu->leave_b = create_sprite("assets/button/leave_b.png");
	menu->leave_h = create_sprite("assets/button/leave_h.png");
	menu->option_b = create_sprite("assets/button/option_b.png");
	menu->option_h = create_sprite("assets/button/option_h.png");
	menu->play_b = create_sprite("assets/button/play_b.png");
	menu->play_h = create_sprite("assets/button/play_h.png");
	menu->philip = create_sprite("assets/button/philip.png");
}

void	set_pos_button_game_menu(t_game_menu *menu)
{
	sfVector2f pos;

	pos.x = 200;
	pos.y = 235;
	sfSprite_setPosition(menu->play_b, pos);
	sfSprite_setPosition(menu->play_h, pos);
	pos.y = pos.y + 165;
	sfSprite_setPosition(menu->custom_b, pos);
	sfSprite_setPosition(menu->custom_h, pos);
	pos.y = pos.y + 165;
	sfSprite_setPosition(menu->option_b, pos);
	sfSprite_setPosition(menu->option_h, pos);
	pos.y = pos.y + 165;
	sfSprite_setPosition(menu->leave_b, pos);
	sfSprite_setPosition(menu->leave_h, pos);
	pos.x = 1000;
	pos.y = 600;
	sfSprite_setPosition(menu->philip, pos);

}

void	set_game_menu(t_game_menu *menu)
{
	menu->back = create_sprite("assets/main_title.png");
	menu->click = 0;
	set_sprite_button_game_menu(menu);
	set_pos_button_game_menu(menu);
}

void	sprite_set_hamburger(t_sprite *sprite)
{
	sprite->expect = rand_burger();
	sprite->cook = malloc(sizeof(char) * 8);
	my_strcpy(sprite->cook, "xxxxxxxx");
	set_rect_hamburger_game(sprite);
	set_sprite_hamburger_ing(sprite);
	set_sprite_hamburger_r(sprite);
	set_rect_sprite_hamburger_r(sprite, sprite->rect_no);
}