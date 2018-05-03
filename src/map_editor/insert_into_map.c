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
