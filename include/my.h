/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** prototypes
*/

#include "struct.h"
#include <stdarg.h>

#ifndef MY_H
#define MY_H

sfSprite	*hoover2sprite(sfSprite *sp1, sfSprite *sp2, t_window *window);
sfText		*create_texte(char *text, char *path_font, int size,
	sfColor color);
sfVector2f	convert_sfvector2i_to_sfvector2f(sfVector2i vec2i);
sfVector2i	get_mouse_pos(sfRenderWindow *window);
sfVector2i	get_sprite_pos(sfSprite *sprite);
sfSprite	*create_sprite(char *str);
void	my_put_uint_base(unsigned int nb, char *base);
void	list_functions(void(*pntrfunc[])(va_list));
void	pntrfunc(va_list ap, char *letter, int n);
void	set_start_menu(t_start_menu *start_menu);
void	display_and_cursor(t_window *window);
void	my_put_nbr_base(int nb, char *base);
void	set_game_menu(t_game_menu *menu);
void	my_put_spe_str(char const *str);
void	input_event(t_window window);
void	window_set(t_window *window);
void	sprite_set(t_sprite *sprite);
void	start_menu(t_window *window);
void	my_printf(char *format, ...);
void	my_put_pointer(int pointer);
void	game_menu(t_window *window);
void	flag_pourcent(va_list ap);
void	my_putchar_error(char c);
void	rb_print_err(char *c);
void	my_putstr(char *str);
void	flag_d_i(va_list ap);
void	flag_gx(va_list ap);
void	flag_gs(va_list ap);
void	flag_o(va_list ap);
void	flag_x(va_list ap);
void	flag_b(va_list ap);
void	flag_u(va_list ap);
void	flag_p(va_list ap);
void	flag_s(va_list ap);
void	flag_c(va_list ap);
void	flag_m(va_list ap);
void	my_putchar(char c);
void	start_game(void);
int	my_strlen(char const *str);
int	my_getnbr(char const *str);
int	main(int ac, char **av);
int	error_msg(char **av);
void	aff_burger(t_sprite *sprite, char *c_burger, int size,
	sfVector2f pos, sfRenderWindow *window);
char	*rand_burger(void);
char	*copy_str_f(char *dest, char *src);
char	find_ing_to_add_burger(sfRenderWindow *window, t_sprite *sprite);
void	list_sprite_r_hamburger(void(*pntrfunc[]), t_sprite *sprite);
void	aff_burger_r_ing(t_sprite *sprite, sfRenderWindow *window);
char	*perso_burger(char *str, char c);
int	mouse_on_the_sprite(sfSprite *sprite, sfRenderWindow *window);
void	destroy_game_menu(t_game_menu *menu);
void	set_pos_sprite(sfSprite *sprite, float x, float y);
void	aff_good_rect(sfSprite *sp, sfIntRect rb, sfIntRect rh,
	sfRenderWindow *window, int b);
void	set_game_gui(t_game_gui *gui);
void	play_game(t_window *window);
void	set_size_sprite(sfSprite *sprite, int size);
void	aff_sprite_game(t_game_gui *gui, t_sprite *sprite,
	t_window *window);
char	*my_strcpy(char *dest, char const *src);
void	aff_sprite_game(t_game_gui *gui, t_sprite *sprite,
	t_window *window);
void	click_game_burger(t_sprite *sprite, t_window *window);
char	*my_revstr(char *str);
char	*int_to_string(int nb);
char	*my_strcat(char *dest, char *str);
void	aff_time_game(t_game_gui *gui, sfRenderWindow *window);
int	compare_str(char *zip, char *src);
void	aff_serve_burger_game(t_game_gui *gui, t_sprite *sprite,
	t_window *window);
void	action_game(t_game_gui *gui, t_sprite *sprite);
void	set_rect_sprite_hamburger_r(t_sprite *sprite, sfIntRect rect);
void	set_pos_game_gui(t_game_gui *gui);
char	*float_to_str(float nb);
void	close_game(t_window *window);
void	destroy_sprite_and_game(t_game_gui *gui, t_sprite *sprite);
void	sprite_set_hamburger(t_sprite *sprite);
void	set_sprite_hamburger_r(t_sprite *sprite);
void	set_sprite_hamburger_r_2(t_sprite *sprite, sfVector2f pos);
void	sprite_set_hamburger(t_sprite *sprite);
void	set_sprite_hamburger_ing(t_sprite *sprite);
void	set_rect_hamburger_game(t_sprite *sprite);
void	settings(t_window *window);
void	input_event_start_menu(t_window *window);
void	how_to_play(t_window *window);

#endif  /* MY_H */
