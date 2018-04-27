/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_create.c
*/

#include <stdlib.h>
#include "map.h"

static void map_param_set_to_0(map_t *map)
{
	map->size = (sfVector2f){0, 0};
	map->pos = (sfVector2f){0, 0};
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			map->tab[i][j] = (tva_t){0, 0, 0};
}

map_t map_create(size_t nb_case_x, size_t nb_case_y, char *tile_map_file_name)
{
	map_t map = {.nb_case_x = nb_case_x, .nb_case_y = nb_case_y};

	map.error = MAP_OK;
	if (nb_case_x < 3 || nb_case_y < 3) {
		map.error = MAP_INVALID_NUMBER;
		return (map);
	}
	map.tab = malloc(sizeof(tva_t *) * map.nb_case_x);
	if (map.tab == NULL) {
		map.error = MAP_MALLOC;
		return (map);
	}
	for (size_t i = 0; i < map.nb_case_x; i++) {
		map.tab[i] = malloc(sizeof(tva_t) * map.nb_case_y);
		if (map.tab[i] == NULL) {
			map.error = MAP_MALLOC;
			return (map);
		}
	}
	map_param_set_to_0(&map);
	map.tile_map = tile_map_create_from_file(tile_map_file_name);
	if (map.tile_map.error != TILE_MAP_OK) {
		map.error = MAP_TILE_MAP;
		return (map);
	}
	return (map);
}
