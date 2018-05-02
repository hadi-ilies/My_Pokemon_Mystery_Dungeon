##
## EPITECH PROJECT, 2017
## for_norme
## File description:
## Makefile
##

NAME	=	../libTile_map.a

SRC	=	tile_map_create.c \
		tile_map_create_from_file.c \
		tile_map_create_from_fd.c \
		tile_map_destroy.c \
		tile_map_aff.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I../../include
CFLAGS	+=	-W -Wall -Wextra

LDFLAGS	+=	-l c_graph_prog

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@ar rc $(NAME) $(OBJ)

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@rm -f $(NAME)

re	:	fclean all
