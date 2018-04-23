/*
** EPITECH PROJECT, 2018
** fonc_game3
** File description:
** fon_game3.
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

void	set_size_sprite(sfSprite *sprite, int size)
{
	sfVector2f scale;

	scale.x = (float) size / 100;
	scale.y = (float) size / 100;
	sfSprite_setScale(sprite, scale);
}

char	*int_to_string(int nb)
{
	char *str = malloc(sizeof(char) * 11);
	int i = 0;

	if (nb == 0) {
		return ("0");
	}
	while (nb > 0) {
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i = i + 1;
	}
	str[i] = '\0';
	my_revstr(str);
	return (str);
}

int	compare_str(char *zip, char *src)
{
	int i = 0;

	while (zip[i] != '\0' || src[i] != '\0') {
		if (zip[i] != src[i]) {
			return (0);
		}
		i = i + 1;
	}
	return (1);
}

char	*float_to_str(float nb)
{
	int x = nb * 100;
	char *str = malloc(sizeof(char) * 10);

	my_strcpy(str, int_to_string(x / 100));
	str = my_strcat(str, ",");
	str = my_strcat(str, int_to_string(x % 100));
	return (str);
}