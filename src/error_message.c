/*
** EPITECH PROJECT, 2018
** eeror message
** File description:
** error_message
*/

#include "../include/my.h"

int	error_msg(char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		my_putstr("\nCooking game made with CSFML\n\nUSAGE\n");
		my_putstr("\t./my_cook\n\n\nOPTIONS\n\t-h\t\t\tprints the");
		my_putstr("game man\n\n\nUSER INTERACTIONS\n\tMOUSE\t\t\t");
		my_putstr("The whole game get played with only your mouse.\n");
		return (0);
	} else {
		my_putstr("Usage : ./my_cook (-h)\n");
		return (84);
	}
}