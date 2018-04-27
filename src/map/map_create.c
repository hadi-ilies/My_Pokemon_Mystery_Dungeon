/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_create.c
*/

#include <stdlib.h>
#include "map.h"

void map_param_set_to_0(map_t *map)
{
	map->size = (sfVector2f){0, 0};
	map->pos = (sfVector2f){0, 0};
}

map_t map_create(size_t nb_case_x, size_t nb_case_y)
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
	return (map);
}
