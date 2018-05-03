/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_destroy.c
*/

#include <stdlib.h>
#include "map.h"

void map_destroy(map_t *map)
{
	for (size_t i = 0; i < map->nb_case_x; i++) {
		free(map->tab[i]);
		free(map->item[i]);
	}
	free(map->tab);
	free(map->item);
	free(map->tile_map_file_name);
	tile_map_destroy(&map->tile_map);
}
