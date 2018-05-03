/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_copy.c
*/

#include <stdlib.h>
#include "map.h"

map_t map_copy(map_t *map)
{
	char *tmfn = map->tile_map_file_name;
	map_t map_cpy = map_create(map->nb_case_x, map->nb_case_y, tmfn);

	if (map_cpy.error != ERR_OK)
		return (map_cpy);
	for (size_t i = 0; i < map_cpy.nb_case_x; i++)
		for (size_t j = 0; j < map_cpy.nb_case_y; j++) {
			map_cpy.tab[i][j] = map->tab[i][j];
			map_cpy.item[i][j] = map->item[i][j];
		}
	return (map_cpy);
}
