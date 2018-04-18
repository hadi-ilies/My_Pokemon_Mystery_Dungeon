##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	$(SRC_DIR)main.c

SRC_DIR	=	src/

INC_DIR	=	include/

LIB_DIR	=	lib/

OBJ=            $(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I $(INC_DIR) -g -fdiagnostics-color

LDFLAGS	=	-L $(LIB_DIR) -lmy -lc_graph_prog

NAME=		particules

all:            $(NAME)

$(NAME):        $(OBJ)
		@make -C $(LIB_DIR) --no-print-directory
		@gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		@make clean -C $(LIB_DIR) --no-print-directory
		@rm -f $(OBJ)

fclean:		clean
		@make fclean -C $(LIB_DIR) --no-print-directory
		@rm -f $(NAME)

re:		fclean all
