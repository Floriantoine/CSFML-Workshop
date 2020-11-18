##
## EPITECH PROJECT, 2018
## delivery
## File description:
## Makefile
##

resources	= example.c \

OBJ     =   $(resources:.c=.o)

NAME    =   runMe
all:$(NAME)

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean	all

.PHONY:	all	clean fclean	re
