##
## EPITECH PROJECT, 2017
## my_rpg_2017
## File description:
## Makefile
##

NAME	=	my_rpg

SRCDIR	=	src/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)menu.c \
		$(SRCDIR)game.c \
		$(SRCDIR)evt_close.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-l c_graph_prog

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
