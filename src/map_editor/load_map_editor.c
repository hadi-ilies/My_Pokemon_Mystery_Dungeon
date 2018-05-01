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

void display_load_editor(load_editor_t *load, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, load->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, load->back, NULL);
	load_choice_cursor(load, window);
}

load_editor_t load_editor_create(sfRenderWindow *window)
{
	load_editor_t load;

	load.text = malloc(sizeof(sfText *) * count_file("resources/maps"));
	if (load.text == NULL)
		return (load);
	load.back = create_back_param(window);
	load.screen = create_screen_param(window);
	load.font = sfFont_createFromFile(FONT);
	for (size_t i = 0; i < 2; i++) {
		load.choice[i] = sfText_create();
		sfText_setFont(load.choice[i], load.font);
	}
	sfText_setString(load.choice[0], "MAPS");
	sfText_setString(load.choice[1], "OK");
	for (size_t i = 0; i < count_file("resources/maps"); i++) {
		load.text[i] = sfText_create();
		sfText_setFont(load.text[i], load.font);
	}
	load.choice_curs = 0;
	load.text_curs = 0;
	load.name_file = NULL;
	return (load);
}

void display_load_list(load_editor_t *load, sfRenderWindow *window,
		sfRectangleShape *back, sfSprite *screen)
{
	sfRectangleShape_setOutlineColor(back, sfGreen);
	sfRectangleShape_setPosition(back,
		(sfVector2f) {WINDOW_SIZE.x / 2 + 600, WINDOW_SIZE.y / 2});
	sfRenderWindow_drawSprite(window, screen, NULL);
	sfRenderWindow_drawRectangleShape(window, back, NULL);
	count_file("resources/maps") > 5  ?
		load_list_choice_cursor(load, window) :
		load_list_choice_min(load, window);
}

void insert_maps_text(load_editor_t *load)
{
	char **filename = take_filename("resources/maps");
	size_t nb_file = count_file("resources/maps");

	for (size_t i = 0; i < nb_file; i++)
		sfText_setString(load->text[i], filename[i]);
}

char *maps_list(map_t *map, sfRenderWindow *window, load_editor_t *load)
{
	sfEvent event;
	sfRectangleShape *back = create_back_param(window);
	sfSprite *screen = create_screen_param(window);

	insert_maps_text(load);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
				//destroy back and screnn
				return (NULL);
			} if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) {
				return ((char *)sfText_getString(load->text[load->text_curs]));
			}
			move_curseur_load_list(load, &event);
		}
		sfRenderWindow_clear(window, sfBlack);
		display_load_list(load, window, back, screen);
		sfRenderWindow_display(window);
	}
	return (NULL);
}

bool load_entry(map_t *map, sfRenderWindow *window, load_editor_t *load, sfEvent *event)
{
	if (event && event->type == sfEvtKeyPressed) {
		if (event->key.code == sfKeyReturn && load->choice_curs == 0)
			load->name_file = maps_list(map, window, load);
		if (event->key.code == sfKeyReturn && load->choice_curs == 1) {
			char *str = concat("resources/maps/", load->name_file);

			*map = map_load(str);
			free(str);
			return (map->error == MAP_OK ? true : false);
		}
	}
	return (false);
}

void load_editor_loop(menu_t *menu, map_t *map, sfRenderWindow *window)
{
	 sfEvent event;
	load_editor_t load = load_editor_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
				//destroy back and screnn
				return;
			}
			if (load_entry(map, window, &load, &event) == true)
				//destroy back and screnn
				return;
				move_curseur_load_editor(&load, &event);
		}
		sfRenderWindow_clear(window, sfBlack);
		display_load_editor(&load, window);
		sfRenderWindow_display(window);
	}
}
