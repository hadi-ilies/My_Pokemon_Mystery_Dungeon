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
MAPEDIR		=	$(SRCDIR)map_editor/
ANIEDIR		=	$(SRCDIR)anime_editor/
MAPDIR		=	$(SRCDIR)map/
ENTDIR		=	$(SRCDIR)entity/
GAROUDIR	=	$(SRCDIR)game_resource/
DUNGEONDIR	=	$(SRCDIR)dungeon/
INTRODIR	=	$(SRCDIR)intro/
STGSDIR		=	$(SRCDIR)settings/
AD_DIR		=	$(SRCDIR)adventure_intro/

SRC		=	$(SRCDIR)main.c \
			$(SRCDIR)create_window.c\
			$(SRCDIR)evt_close.c \
			$(MENUDIR)main_menu.c \
			$(MENUDIR)tuto_create.c \
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
			$(MAPEDIR)load_map_editor.c \
			$(MAPEDIR)save_map_editor_create.c \
			$(MAPEDIR)factories_editor.c \
			$(MAPEDIR)manage_map.c \
			$(MAPEDIR)insert_into_map.c \
			$(MAPEDIR)graphic_write.c \
			$(MAPEDIR)options_map_editor.c \
			$(MAPEDIR)laod_editor_cursor.c \
			$(MAPEDIR)save_editor_cursor.c \
			$(MAPEDIR)param_save_map_editor.c \
			$(MAPEDIR)optional_create.c \
			$(MAPEDIR)play_your_map.c \
			$(MAPEDIR)display_tools.c \
			$(MAPEDIR)map_editor_loop.c \
			$(MAPEDIR)option_editor_create.c \
			$(MAPEDIR)create_back_and_screen.c \
			$(MAPEDIR)param_options_map_editor.c \
			$(MAPEDIR)menu_map_editor_menu.c \
			$(MAPEDIR)display_menu_editor.c \
			$(MAPEDIR)menu_editor_create.c \
			$(MAPEDIR)cursor_option_map_editor.c \
			$(MAPEDIR)load_editor_create.c \
			$(MAPEDIR)load_editor_display.c \
			$(MAPEDIR)cursor_editor.c \
			$(MAPEDIR)take_filename.c \
			$(MAPEDIR)all_move.c \
			$(MAPEDIR)hit_functions.c \
			$(MAPEDIR)new_map.c \
			$(MAPEDIR)map_editor_save.c \
			$(ANIEDIR)anime_editor_menu.c \
			$(ANIEDIR)anime_editor_loop.c \
			$(ANIEDIR)save_anime.c \
			$(ANIEDIR)set_rectex_pos.c \
			$(ANIEDIR)get_sprite_rect.c \
			$(ANIEDIR)manage_keys.c \
			$(ANIEDIR)add_rectex.c \
			$(MAPDIR)map_create.c \
			$(MAPDIR)map_copy.c \
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
			$(ENTDIR)entity_save.c \
			$(ENTDIR)entity_move.c \
			$(ENTDIR)entity_get_move_pos.c \
			$(ENTDIR)entity_aff.c \
			$(ENTDIR)entity_gain_exp.c \
			$(GAROUDIR)garou_create.c \
			$(GAROUDIR)garou_destroy.c \
			$(GAROUDIR)capacity_aff.c \
			$(DUNGEONDIR)dungeon_create.c \
			$(DUNGEONDIR)dungeon_destroy.c \
			$(STGSDIR)settings_defaut.c \
			$(STGSDIR)settings_load.c \
			$(STGSDIR)settings_save.c \
			$(AD_DIR)adventure_intro.c\
			$(AD_DIR)adventure_intro_create.c\
			$(AD_DIR)naration.c\
			$(AD_DIR)illustration.c\
			$(AD_DIR)adventure_end.c\

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
