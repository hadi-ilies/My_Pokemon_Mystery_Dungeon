/*
** EPITECH PROJECT, 2018
** load_map
** File description:
** load_map
*/

#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include "prototype.h"
#include "my.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"
#include "option_map_editor.h"
#include "load_maps_editor.h"

void insert_maps_text(load_editor_t *load)
{
	char **filename = take_filename(MAPS);
	size_t nb_file = count_file(MAPS);

	for (size_t i = 0; i < nb_file; i++)
		sfText_setString(load->text[i], filename[i]);
}

char *maps_list(sfRenderWindow *window, load_editor_t *load)
{
	sfRectangleShape *back = create_back_param(window);
	sfSprite *screen = create_screen_param(window);

	insert_maps_text(load);
	while (sfRenderWindow_isOpen(window)) {
		sfEvent event;

		while (sfRenderWindow_pollEvent(window, &event)) {
			if (EXIT)
				return (screen_and_back_destroy(back, screen),
				NULL);
			if (ENTER_COND)
				return ((char *) GET_STRING);
			move_curseur_load_list(load, &event);
		}
		sfRenderWindow_clear(window, sfBlack);
		display_load_list(load, window, back, screen);
		sfRenderWindow_display(window);
	}
	return (NULL);
}

bool load_entry(map_t *map, sfRenderWindow *window,
		load_editor_t *load, sfEvent *event)
{
	if (event && event->type == sfEvtKeyPressed) {
		if (event->key.code == sfKeyReturn && load->choice_curs == 0)
			load->name_file = maps_list(window, load);
		if (event->key.code == sfKeyReturn && load->choice_curs == 1) {
			char *str = concat("resources/maps/", load->name_file);

			*map = map_load(str);
			free(str);
			return (map->error == ERR_OK ? true : false);
		}
	}
	return (false);
}

static bool loop_editor_loop(map_t *map, sfRenderWindow *window,
		sfEvent *event, load_editor_t *load)
{
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtKeyPressed && event->key.code ==
		sfKeyEscape || load_entry(map, window, load, event) == true) {
			load_editor_destroy(load);
			return (false);
		}
		move_curseur_load_editor(load, event);
	}
	return (true);
}

void load_editor_loop(map_t *map, sfRenderWindow *window)
{
	sfEvent event;
	load_editor_t load = load_editor_create(window);

	while (sfRenderWindow_isOpen(window)) {
		if (!loop_editor_loop(map, window, &event, &load))
			return;
		sfRenderWindow_clear(window, sfBlack);
		display_load_editor(&load, window);
		sfRenderWindow_display(window);
	}
}
