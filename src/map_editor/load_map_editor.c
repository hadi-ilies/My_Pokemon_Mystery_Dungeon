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
	for (size_t i = 0; i < count_file("resources/maps"); i++) {
		load.text[i] = sfText_create();
		sfText_setFont(load.text[i], load.font);
	}
	load.choice_curs = 0;
	load.name_file = NULL;
	return (load);
}

void load_editor_loop(menu_t *menu, map_t *map, sfRenderWindow *window)
{
	 sfEvent event;
	load_editor_t load = load_editor_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
		} if (sfKeyboard_isKeyPressed(sfKeyEscape))
			  break;
		sfRenderWindow_clear(window, sfBlack);
		display_load_editor(&load, window);
		sfRenderWindow_display(window);
	}
}
