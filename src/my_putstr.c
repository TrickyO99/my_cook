/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** displays string of caracters
*/

#include "../include/my.h"
#include <unistd.h>

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
