/*
** EPITECH PROJECT, 2018
** donjon
** File description:
** dungeon
*/

#include <stdlib.h>
#include "prototype.h"
#include "type.h"
#include "tile_name.h"
#include "item.h"
#include "macro.h"

void put_item(map_t *map)
{
	sfVector2i pos;
	size_t size = map->nb_case_x * map->nb_case_y;
	size_t nb_item = rand() % (size / 500) + 1;

	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			map->item[i][j] = NONE;
	for (size_t i = 0; i < nb_item; i++) {
		pos = rand_pos_ground(map);
		map->item[pos.x][pos.y] = rand() % (NB_ITEM - 1) + 1;
	}
	pos = rand_pos_ground(map);
	map->item[pos.x][pos.y] = STAIRCASE;
}

map_t generate_map(size_t size, char *tile_map_file_name)
{
	map_t map = map_create(size, size, my_strdup(tile_map_file_name));

	if (map.error != ERR_OK)
		return (map);
	map.size = V2F(GAME_ZOOM, GAME_ZOOM);
	return (map);
}

int run_dungeon(sfRenderWindow *window, garou_t *garou, ssize_t level_diff)
{
	for (; STEPS; garou->dungeon.stage_num++) {
		map_random(&garou->dungeon.map);
		put_item(&garou->dungeon.map);
		for (size_t i = 1; i < garou->dungeon.nb_entity; i++) {
			garou->dungeon.entity[i].level = LEVEL;
			garou->dungeon.entity[i].life = LIFE;
			garou->dungeon.entity[i].ia = 1;
			garou->dungeon.entity[i].dir = V2I(0, 0);
			garou->dungeon.entity[i].pos = POSITION;
		}
		garou->dungeon.entity[0].dir = V2I(0, 0);
		garou->dungeon.entity[0].pos = POSITION;
		if (game_loop(window, garou) == 0)
			return (0);
	}
	return (1);
}
