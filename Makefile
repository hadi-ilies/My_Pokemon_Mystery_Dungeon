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
INCDIR		=	include/
MENUDIR		=	$(SRCDIR)main_menu/
GAMEDIR		=	$(SRCDIR)game/
MAPCDIR		=	$(SRCDIR)map_editor/
ANICDIR		=	$(SRCDIR)anime_editor/
MAPDIR		=	$(SRCDIR)map/
ENTDIR		=	$(SRCDIR)entity/
GAROUDIR	=	$(SRCDIR)game_resource/
INTRODIR	=	$(SRCDIR)intro/
STGSDIR		=	$(SRCDIR)settings/

SRC		=	$(SRCDIR)main.c \
			$(SRCDIR)create_window.c\
			$(SRCDIR)evt_close.c \
			$(MENUDIR)main_menu.c \
			$(MENUDIR)create_settings.c \
			$(MENUDIR)menu_create.c \
			$(MENUDIR)display_menu.c \
			$(MENUDIR)cursor_menu.c \
			$(MENUDIR)menu_destroy.c \
			$(MENUDIR)text_menu.c \
			$(MENUDIR)option.c \
			$(MENUDIR)option_cursor.c \
			$(MENUDIR)option_create.c \
			$(MENUDIR)resize_window.c \
			$(MENUDIR)sound_and_music_volume.c \
			$(MENUDIR)credit.c \
			$(INTRODIR)main_intro.c \
			$(INTRODIR)music_intro.c \
			$(INTRODIR)destroy_intro.c \
			$(INTRODIR)factories.c \
			$(GAMEDIR)game_menu.c \
			$(GAMEDIR)game_loop.c \
			$(MAPCDIR)load_map_editor.c \
			$(MAPCDIR)save_map_editor_create.c \
			$(MAPCDIR)factories_editor.c \
			$(MAPCDIR)manage_map_and_insert_into_map.c \
			$(MAPCDIR)graphic_write.c \
			$(MAPCDIR)options_map_editor.c \
			$(MAPCDIR)laod_editor_cursor.c \
			$(MAPCDIR)save_editor_cursor.c \
			$(MAPCDIR)param_save_map_editor.c \
			$(MAPCDIR)optional_create.c \
			$(MAPCDIR)display_tools.c \
			$(MAPCDIR)map_editor_loop.c \
			$(MAPCDIR)option_editor_create.c \
			$(MAPCDIR)create_back_and_screen.c \
			$(MAPCDIR)param_options_map_editor.c\
			$(MAPCDIR)menu_map_editor_menu.c \
			$(MAPCDIR)display_menu_editor.c \
			$(MAPCDIR)menu_editor_create.c \
			$(MAPCDIR)cursor_option_map_editor.c \
			$(MAPCDIR)load_editor_create.c \
			$(MAPCDIR)load_editor_display.c \
			$(MAPCDIR)cursor_editor.c \
			$(MAPCDIR)take_filename.c \
			$(MAPCDIR)all_move.c \
			$(MAPCDIR)hit_functions.c \
			$(MAPCDIR)new_map.c \
			$(MAPCDIR)map_editor_save.c \
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
			$(MAPDIR)map_tools.c \
			$(ENTDIR)entity_create.c \
			$(ENTDIR)entity_create_from_file.c \
			$(ENTDIR)entity_create_from_fd.c \
			$(ENTDIR)entity_destroy.c \
			$(ENTDIR)entity_move.c \
			$(ENTDIR)entity_get_move_pos.c \
			$(ENTDIR)entity_aff.c \
			$(ENTDIR)entity_gain_exp.c \
			$(GAROUDIR)garou_create.c \
			$(GAROUDIR)garou_destroy.c \
			$(GAROUDIR)capacity_aff.c \
			$(STGSDIR)settings_defaut.c \
			$(STGSDIR)settings_load.c \
			$(STGSDIR)settings_save.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I $(INCDIR)
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
			@make re -C $(LIBDIR)/Tile_map --no-print-directory
			@make re -C $(LIBDIR)/Anime_tab --no-print-directory
			@make re -C $(LIBDIR)/Video --no-print-directory
			@make re -C $(LIBDIR)/my --no-print-directory
			@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
			@make clean -C $(LIBDIR)/Tile_map --no-print-directory
			@make clean -C $(LIBDIR)/Anime_tab --no-print-directory
			@make clean -C $(LIBDIR)/Video --no-print-directory
			@make clean -C $(LIBDIR)/my --no-print-directory
			@rm -f $(OBJ)

fclean		:	clean
			@make fclean -C $(LIBDIR)/Tile_map --no-print-directory
			@make fclean -C $(LIBDIR)/Anime_tab --no-print-directory
			@make fclean -C $(LIBDIR)/Video --no-print-directory
			@make fclean -C $(LIBDIR)/my --no-print-directory
			@rm -f $(NAME)

re		:	fclean all
