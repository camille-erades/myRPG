##
## EPITECH PROJECT, 2023
## B-MUL-200-LYN-2-1-myrpg-camille.erades
## File description:
## Makefile
##

SRC			= 	$(addprefix $(DIRECTORY), $(SRC_FILE))

DIRECTORY 		= 	src/

SRC_FILE =		actualise_mob.c \
		animation.c \
		anitype_atk.c \
		anitype_atk_m.c \
		anitype_atk_r.c \
		anitype_dash.c \
		anitype_idle.c \
		anitype_idle_m.c \
		anitype_idle_r.c \
		anitype_run.c \
		anitype_run_m.c \
		anitype_run_r.c \
		attack.c \
		create_melee.c \
		create_mob.c \
		create_range.c \
		destroy_all.c \
		destroy_tab.c \
		display_game.c \
		draw_level.c \
		enemy_move.c \
		event.c \
		game_worker.c \
		hitbox.c \
		init_map_hitbox.c \
		levels.c \
		main.c \
		movement.c \
		my_getnbr.c \
		my_str_to_word_array.c \
		pnj.c \
		prepare_all.c \
		put_badguys.c \
		put_pnj.c \
		screen.c \
		shield.c \
		manage_button.c \
		init_menu.c \
		button_function.c \
		destroy_mob.c \
		prepare_pnj.c \
		boss1.c \
		player_atk.c

OBJ	=	$(SRC:.c=.o)

FLAG = -Iinclude -lcsfml-graphics -lcsfml-audio -lcsfml-system \
	-lcsfml-window -lm

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
		@gcc -o $(NAME) $(OBJ) $(FLAG)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all

.PHONY : all clean fclean re
