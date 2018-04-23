/*
** EPITECH PROJECT, 2017
** set.c
** File description:
** 
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

void	set_sprite_hamburger_ing(t_sprite *sprite)
{
	sprite->lower_bun = create_sprite(
	"assets/hamburger/lower_bun.png");
	sprite->upper_bun = create_sprite(
	"assets/hamburger/upper_bun.png");
	sprite->bacon = create_sprite("assets/hamburger/bacon.png");
	sprite->cheese = create_sprite(
	"assets/hamburger/cheese.png");
	sprite->onion = create_sprite("assets/hamburger/onion.png");
	sprite->salad = create_sprite("assets/hamburger/salad.png");
	sprite->steak = create_sprite("assets/hamburger/beef.png");
	sprite->tomato = create_sprite(
	"assets/hamburger/tomato.png");
	sprite->plate = create_sprite("assets/hamburger/plate.png");
}

void	set_sprite_hamburger_r(t_sprite *sprite)
{
	sfVector2f pos;

	pos.x = 180;
	pos.y = 550;
	sprite->r_upper_bun = create_sprite("assets/ring/upper_bun.png");
	sfSprite_setPosition(sprite->r_upper_bun, pos);
	pos.y = pos.y + 100;
	sprite->r_cheese = create_sprite("assets/ring/cheese.png");
	sfSprite_setPosition(sprite->r_cheese, pos);
	pos.y = pos.y + 100;
	sprite->r_salad = create_sprite("assets/ring/salad.png");
	sfSprite_setPosition(sprite->r_salad, pos);
	pos.y = pos.y + 100;
	sprite->r_steak = create_sprite("assets/ring/steak.png");
	sfSprite_setPosition(sprite->r_steak, pos);
	set_sprite_hamburger_r_2(sprite, pos);
}

void	set_sprite_hamburger_r_2(t_sprite *sprite, sfVector2f pos)
{
	pos.y = pos.y - 300;
	pos.x = pos.x + 150;
	sprite->r_lower_bun = create_sprite("assets/ring/lower_bun.png");
	sfSprite_setPosition(sprite->r_lower_bun, pos);
	pos.y = pos.y + 100;
	sprite->r_tomato = create_sprite("assets/ring/tomato.png");
	sfSprite_setPosition(sprite->r_tomato, pos);
	pos.y = pos.y + 100;
	sprite->r_bacon = create_sprite("assets/ring/bacon.png");
	sfSprite_setPosition(sprite->r_bacon, pos);
	pos.y = pos.y + 100;
	sprite->r_onion = create_sprite("assets/ring/onion.png");
	sfSprite_setPosition(sprite->r_onion, pos);
}

void	set_rect_sprite_hamburger_r(t_sprite *sprite, sfIntRect rect)
{
	sfSprite_setTextureRect(sprite->r_bacon, rect);
	sfSprite_setTextureRect(sprite->r_cheese, rect);
	sfSprite_setTextureRect(sprite->r_salad, rect);
	sfSprite_setTextureRect(sprite->r_steak, rect);
	sfSprite_setTextureRect(sprite->r_tomato, rect);
	sfSprite_setTextureRect(sprite->r_upper_bun, rect);
	sfSprite_setTextureRect(sprite->r_onion, rect);
	sfSprite_setTextureRect(sprite->r_lower_bun, rect);
}

void	set_rect_hamburger_game(t_sprite *sprite)
{
	sprite->rect_no.top = 0;
	sprite->rect_no.left = 0;
	sprite->rect_no.height = 74;
	sprite->rect_no.width = 74;
	sprite->rect_on.top = 0;
	sprite->rect_on.left = 75;
	sprite->rect_on.height = 75;
	sprite->rect_on.width = 75;
}