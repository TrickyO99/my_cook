##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## making files
##

CC		=	gcc

SRC		=	src/action_game.c				\
			src/main.c						\
			src/set.c						\
			src/set_sprite_hamburger.c		\
			src/my_getnbr.c					\
			src/my_putstr.c					\
			src/my_strlen.c					\
			src/error_message.c				\
			src/start_menu.c				\
			src/fonc_game.c					\
			src/game_menu.c					\
			src/set_game_menu.c				\
			src/aff_burger.c				\
			src/rand_burger.c				\
			src/aff_burger_r_ing.c			\
			src/find_ing_to_add_burger.c	\
			src/fonc_game2.c				\
			src/destroy.c					\
			src/game.c						\
			src/set_game.c					\
			src/fonc_game3.c				\
			src/my_strcpy.c					\
			src/game2.c						\
			src/my_revstr.c					\
			src/my_strcat.c					\
			src/aff_time_game.c				\
			src/aff_serve_burger.c			\
			src/settings.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_cook

FLAGS	=	-l c_graph_prog -Wall -Wextra -Werror


all:	$(NAME)

$(NAME):	 $(OBJ)
		$(CC) -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
