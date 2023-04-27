##
## EPITECH PROJECT, 2022
## B-MUL-100-LYN-1-1-myhunter-nathan.baudelin
## File description:
## Makefile
##

SRC		=	src/event.c	\
			src/main.c	\
			src/animation.c	\
			src/my_clock.c	\
			src/sprite.c	\
			src/sprite_2.c	\
			src/mouse_events.c	\
			src/final_screen.c	\
			src/menu.c	\

NAME	=	my_hunter

CREATE_LIB_PRINTF = cd lib/printf && make && cd ../../.

CLEAN_LIB_PRINTF = cd lib/printf && make fclean && cd ../../.

all	:	$(NAME)

$(NAME):
	$(CREATE_LIB_PRINTF)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system -Llib/printf -lprintf
	$(CLEAN_LIB_PRINTF)

clean	:
	rm -f $(NAME)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean	all

.PHONY: clean, all, re, fclean
