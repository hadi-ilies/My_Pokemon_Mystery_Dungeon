##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=
HEAD	=	my.h

CFLAGS	=	-W -Wall -Wextra -I ./

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
