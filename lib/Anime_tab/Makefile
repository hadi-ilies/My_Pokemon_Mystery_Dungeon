##
## EPITECH PROJECT, 2017
## for_norme
## File description:
## Makefile
##

NAME	=	../libAnime_tab.a

SRC	=	anime_tab_create.c \
		anime_tab_create_from_fd.c \
		anime_tab_create_from_file.c \
		anime_tab_copy.c \
		anime_tab_destroy.c \
		anime_tab_aff.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ../../include
		-W -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@ar rc $(NAME) $(OBJ)

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@rm -f $(NAME)

re	:	fclean all
