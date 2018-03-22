##
## EPITECH PROJECT, 2017
## my_rpg_2017
## File description:
## Makefile
##

NAME	=	my_rpg

SRCDIR	=	src/
LIBDIR	=	lib/
MAPDIR	=	$(SRCDIR)map/
ENTDIR	=	$(SRCDIR)entity/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)menu.c \
		$(SRCDIR)game_loop.c \
		$(SRCDIR)editor_loop.c \
		$(SRCDIR)evt_close.c \
		$(MAPDIR)map_create.c \
		$(MAPDIR)map_destroy.c \
		$(MAPDIR)map_aff.c \
		$(ENTDIR)entity_create.c \
		$(ENTDIR)entity_destroy.c \
		$(ENTDIR)entity_set_pos.c \
		$(ENTDIR)entity_move.c \
		$(ENTDIR)entity_aff.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra

LDFLAGS	+=	-l c_graph_prog
LDFLAGS	+=	-L $(LIBDIR) -l tile_map

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
