##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for myls
##

SRC	=	./src/background.c	\
		./src/bird.c	\
		./src/menu.c	\
		./src/clock.c	\
		./src/gun.c	\
		./src/crosshair.c	\
		./src/change_text.c	\
		./src/get_sprite.c	\
		./src/manage_click.c	\
		./src/menu_display.c	\
		./src/my_stock_nbr.c	\
		./src/windows.c	\
		./src/file_systemes6.c	\
		./src/my_strlen.c	\
		./src/my_strcat.c	\
		./src/save_score.c	\
		./src/my_strcmp.c	\
		./src/my_putstr.c	\
		./src/destroy.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

# CFLAGS	=	-Werror -Wall -Wextra

TEST_FILES	=	tests/test_my_function.c

CSFML_LIB = csfml-system -l csfml-window -l csfml-graphics -l csfml-audio

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) ./src/main.c $(SRC) -l $(CSFML_LIB) -Werror -Wall -Wextra

debug:	$(OBJ)
	gcc -o $(NAME) $(SRC) ./src/main.c -L. -g -l $(CSFML_LIB)

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.a
	rm -f ./src/$(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f unit_function

re: fclean $(NAME)

unit_function: fclean
	make -C ./lib/
	gcc -o unit_function $(TEST_FILES) $(SRC) --coverage -lcriterion -L. -lpr
	./unit_function
