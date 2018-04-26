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

void new_map(menu_t *menu, map_t *map)
{
	if (load_the_map(map, &menu->tile_map[0]) == 84)
		return;
	else
		menu->button = 4;
}
