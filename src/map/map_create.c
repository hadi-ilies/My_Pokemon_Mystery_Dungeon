/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_create.c
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"
#include "macro.h"

static void map_param_set_to_0(map_t *map)
{
	map->size = V2F(0, 0);
	map->pos = V2F(0, 0);
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++) {
			map->tab[i][j] = (tva_t){0, 0, 0};
			map->item[i][j] = NONE;
		}
}

static bool map_malloc(map_t *map)
{
	map->tab = malloc(sizeof(tva_t *) * map->nb_case_x);
	map->item = malloc(sizeof(enum item_e *) * map->nb_case_x);
	if (map->tab == NULL || map->item == NULL)
		return (map->error = ERR_MALLOC, true);
	for (size_t i = 0; i < map->nb_case_x; i++) {
		map->tab[i] = malloc(sizeof(tva_t) * map->nb_case_y);
		map->item[i] = malloc(sizeof(enum item_e) * map->nb_case_y);
		if (map->tab[i] == NULL || map->item[i] == NULL)
			return (map->error = ERR_MALLOC, true);
	}
	return (false);
}

map_t map_create(size_t nb_case_x, size_t nb_case_y, char *tile_map_file_name)
{
	map_t map = {.nb_case_x = nb_case_x, .nb_case_y = nb_case_y};

	map.error = ERR_OK;
	if (nb_case_x < 3 || nb_case_y < 3)
		return (map.error = ERR_INVALID_NUMBER, map);
	if (map_malloc(&map))
		return (map);
	map_param_set_to_0(&map);
	map.tile_map_file_name = my_strdup(tile_map_file_name);
	map.tile_map = tile_map_create_from_file(map.tile_map_file_name);
	if (map.tile_map.error != ERR_OK)
		return (map.error = map.tile_map.error, map);
	return (map);
}
