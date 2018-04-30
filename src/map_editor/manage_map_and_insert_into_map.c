/*
** EPITECH PROJECT, 2018
** in loop map_editor_loop
** File description:
** in loop map_editor_loop
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "prototype.h"
#include "tile_name.h"
#include "macro.h"
#include "map_editor_function.h"

void insert_to_map(tile_map_t *tile_map, tva_t *tva, tva_t mouse_tva)
{
	if (mouse_tva.alt == 0) {
		size_t type = mouse_tva.type;
		size_t var = mouse_tva.var;

		tva->type = mouse_tva.type;
		tva->var = mouse_tva.var;
		if (tva->alt >= tile_map->nb_alt[type][var])
			tva->alt = 0;
	}
	else
		*tva = mouse_tva;
}

void manage_map(sfEvent *event, sfRenderWindow *window,
		map_t *map, tva_t *mouse_tva)
{
	size_t x = GET_MAP_X;
	size_t y = GET_MAP_Y;
	bool cond = event->type == sfEvtMouseButtonPressed;

	if (x >= map->nb_case_x || y >= map->nb_case_y)
		return;
	if (cond && sfMouse_isButtonPressed(sfMouseMiddle) == true)
		mouse_tva->type = map->tab[x][y].type;
	if (sfMouse_isButtonPressed(sfMouseRight) == true)
		swap_alt(&map->tile_map, &map->tab[x][y]);
	if (mouse_tva->type >= map->tile_map.nb_type)
		return;
	if (sfMouse_isButtonPressed(sfMouseLeft) == true
	&& isit_on_inventory(map, window) != true
	&& dont_touch_borders(map, x, y)) {
		insert_to_map(&map->tile_map, &map->tab[x][y], *mouse_tva);
		map_smooth(map, x, y);
	}
}
