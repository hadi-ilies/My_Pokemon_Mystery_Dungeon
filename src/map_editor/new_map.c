/*
** EPITECH PROJECT, 2018
** new map
** File description:
** new map
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "prototype.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"

void new_map(menu_t *menu, map_t *map, sfRenderWindow *window)
{
	 option_editor_t option = param_map(menu, NULL, window);
	 char *str = sfText_getString(option.text[option.nb_tile]);

	 *map = map_create(option.size_x, option.size_y,
			concat("resources/tile_map/", str));
	map_random(map);
}
