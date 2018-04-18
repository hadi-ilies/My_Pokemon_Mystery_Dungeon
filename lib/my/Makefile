##
## EPITECH PROJECT, 2017
## tetrus
## File description:
## Makefile
##

NAME	=	../libmy.a

SRC	=	my_fprintf.c \
		my_getline.c \
		my_strcmp.c \
		my_strdup.c \
		my_strlen.c \
		my_strncat.c \
		my_str_to_tab.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I../../include
CFLAGS	+=	-W -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@ar rc $(NAME) $(OBJ)

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@rm -f $(NAME)

re	:	fclean all
