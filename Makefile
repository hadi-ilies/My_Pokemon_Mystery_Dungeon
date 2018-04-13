##
## EPITECH PROJECT, 2017
## my_rpg_2017
## File description:
## Makefile
##

NAME		=	my_rpg

CC		=	cc

SRCDIR		=	src/
LIBDIR		=	lib/
GAMEDIR		=	$(SRCDIR)game/
MAPCDIR		=	$(SRCDIR)map_editor/
ANICDIR		=	$(SRCDIR)anime_editor/
MAPDIR		=	$(SRCDIR)map/
ENTDIR		=	$(SRCDIR)entity/
GAROUDIR	=	$(SRCDIR)game_resource/
INTRODIR	=	$(SRCDIR)intro/

SRC		=	$(SRCDIR)main.c \
			$(SRCDIR)evt_close.c \
			$(SRCDIR)main_menu.c \
			$(SRCDIR)menu_create.c \
			$(SRCDIR)display_menu.c \
			$(SRCDIR)cursor_menu.c \
			$(SRCDIR)set_icon.c \
			$(SRCDIR)menu_destroy.c \
			$(SRCDIR)text_menu.c \
			$(INTRODIR)main_intro.c \
			$(INTRODIR)music_intro.c \
			$(INTRODIR)destroy_intro.c \
			$(INTRODIR)factories.c \
			$(GAMEDIR)game_menu.c \
			$(GAMEDIR)game_loop.c \
			$(MAPCDIR)map_editor_menu.c \
			$(MAPCDIR)map_editor_loop.c \
			$(MAPCDIR)all_move.c \
			$(MAPCDIR)hit_functions.c \
			$(ANICDIR)anime_editor_menu.c \
			$(ANICDIR)anime_editor_loop.c \
			$(MAPDIR)map_create.c \
			$(MAPDIR)map_resize.c \
			$(MAPDIR)map_destroy.c \
			$(MAPDIR)map_aff.c \
			$(MAPDIR)map_smooth.c \
			$(MAPDIR)map_save.c \
			$(MAPDIR)map_load.c \
			$(MAPDIR)map_random.c \
			$(ENTDIR)entity_create.c \
			$(ENTDIR)entity_destroy.c \
			$(ENTDIR)entity_move.c \
			$(ENTDIR)entity_get_move_pos.c \
			$(ENTDIR)entity_aff.c \
			$(GAROUDIR)garou_create.c \
			$(GAROUDIR)garou_destroy.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I./include
CFLAGS		+=	-W -Wall -Wextra
CFLAGS		+=	-fdiagnostics-color
CFLAGS		+=	-g #debug

LDFLAGS		+=	-l c_graph_prog
LDFLAGS		+=	-L $(LIBDIR) -l Tile_map
LDFLAGS		+=	-L $(LIBDIR) -l Anime_tab
LDFLAGS		+=	-L $(LIBDIR) -l Video
LDFLAGS		+=	-L $(LIBDIR) -l my

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			@make re -C $(LIBDIR)/my --no-print-directory
			@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
			@make clean -C $(LIBDIR)/my --no-print-directory
			@rm -f $(OBJ)

fclean		:	clean
			@make fclean -C $(LIBDIR)/my --no-print-directory
			@rm -f $(NAME)

re		:	fclean all
