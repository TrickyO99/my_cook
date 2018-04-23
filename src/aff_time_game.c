/*
** EPITECH PROJECT, 2018
** aff_time_game
** File description:
** aff_time_game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

char	*set_str_double_zero(char *str)
{
	if (str[0] == '0' && str[1] == '\0') {
		return ("00");
	} else if (my_strlen(str) == 1) {
		str[1] = str[0];
		str[0] = '0';
		str[2] = '\0';
		return (str);
	} else {
		return (str);
	}
}

char	*time_s_to_min(int time_s)
{
	char *str = malloc(sizeof(char) * 8);

	str[0] = '\0';
	str = my_strcat(str, int_to_string(time_s / 60));
	str = my_strcat(str, ":");
	str = my_strcat(str, set_str_double_zero(int_to_string(time_s % 60)));
	return (str);
}

void 	change_time_game(t_game_gui *gui)
{
	sfTime temp = sfClock_getElapsedTime(gui->times);
	float tempo = sfTime_asSeconds(temp);

	if (tempo > 1) {
		gui->time = gui->time - 1;
		sfClock_restart(gui->times);
	}
}

void	aff_time_game(t_game_gui *gui, sfRenderWindow *window)
{
	char *str = time_s_to_min(gui->time);

	sfText_setString(gui->t_time, str);
	sfRenderWindow_drawText(window, gui->t_time, NULL);
	if (gui->m_pause == 0 && gui->time > 0) {
		change_time_game(gui);
	}
}