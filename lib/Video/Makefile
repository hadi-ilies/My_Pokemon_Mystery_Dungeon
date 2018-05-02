##
## EPITECH PROJECT, 2017
## for_norme
## File description:
## Makefile
##

NAME	=	../libVideo.a


SRC	=	video_create.c \
		video_create_from_fd.c \
		video_create_from_file.c \
		video_aff.c \
		video_destroy.c \

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
