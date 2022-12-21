##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_makefile
##

SRC	=	$(shell find src/ -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

LIB	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

INC	=	-I./include/

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) $(INC) -g3

clean:
	rm -f	$(OBJ)

fclean:	clean
	rm -f $(NAME)
	find . -name '*~' -delete
	rm -rf .vscode .dist

re:	fclean all
