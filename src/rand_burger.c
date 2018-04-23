/*
** EPITECH PROJECT, 2018
** rand burger
** File description:
** rand_burger
*/

#include <time.h>
#include <stdlib.h>
#include "../include/my.h"

char	*copy_str_f(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

char	find_ing_burger(char *ing)
{
	int i = rand() % my_strlen(ing);

	return (ing[i]);
}

char	*sup_ing_burger(char *ing, char c)
{
	int i = 0;

	while (ing[i] != c) {
		i = i + 1;
	}
	while (ing[i] != '\0') {
		ing[i] = ing[i + 1];
		i = i + 1;
	}
	ing[i] = '\0';
	return (ing);
}

char	*rand_burger(void)
{
	char *str = malloc(sizeof(char) * 8);
	char *ing = malloc(sizeof(char) * 6);
	int nb_ing = (rand() % 6) + 1;
	int i = 1;

	copy_str_f(ing, "cdefgh");
	copy_str_f(str, "axxxxxxx");
	while (nb_ing > 0) {
		str[i] = find_ing_burger(ing);
		ing = sup_ing_burger(ing, str[i]);
		i = i + 1;
		nb_ing = nb_ing - 1;
	}
	str[i] = 'b';
	free(ing);
	return (str);
}