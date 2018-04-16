/*
** EPITECH PROJECT, 2018
** facto
** File description:
** facto
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "prototype.h"
#include "tile_name.h"
#include "macro.h"
#include "map_editor_function.h"

void refresh_map(sfEvent *event, map_t *map)
{
	if (event->type == sfEvtKeyPressed)
		if (sfKeyboard_isKeyPressed(sfKeyF5))
			map_smooth_all(map);
}

bool dont_touch_borders(map_t *map, size_t x, size_t y)
{
	if (x <= 1 || y <= 1)
		return (false);
	if (x >= map->nb_case_x - 2 || y >= map->nb_case_y - 2)
		return (false);
	return (true);
}
