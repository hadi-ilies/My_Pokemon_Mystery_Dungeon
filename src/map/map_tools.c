/*
** EPITECH PROJECT, 2018
** map_tools
** File description:
** map_tools
*/

#include <stdbool.h>
#include <stdlib.h>
#include "map.h"
#include "prototype.h"
#include "macro.h"
#include "tile_name.h"

sfVector2i path_map(map_t *map, sfVector2i *cor, ssize_t nx, ssize_t ny)
{
	bool tmp = false;
	ssize_t size_x = 0;
	ssize_t size_y = 0;

	for (; (size_t) cor->x + size_x > 0
	&& (size_t) cor->x + size_x < map->nb_case_x; size_x += nx) {
		for (; cor->y+ size_y > 0 && cor->y+ size_y < map->nb_case_y;
		size_y += ny) {
			if (PATH_MAP_COND == WALL && tmp == false)
				tmp = true;
			if (PATH_MAP_COND == GROUND && tmp == true)
				return (V2I(0, 0));
			if (PATH_MAP_COND == WATER && tmp == true)
				return (V2I(size_x, size_y));
			if (ny == 0)
				break;
		} if (nx == 0)
			break;
	}
	return (V2I(0, 0));
}

void set_origin(map_t *map)
{
	size_t origin_x = 0;
	size_t origin_y = 0;

	while (map->tab[origin_x][origin_y].type != GROUND) {
		origin_x = rand() % map->nb_case_x;
		origin_y = rand() % map->nb_case_y;
	}
	map->tab[origin_x][origin_y].type = WATER;
}

void dig_path(map_t *map, sfVector2i size, size_t x, size_t y)
{
	size.x < 0 ? x += size.x : 0;
	size.x < 0 ? size.x = -size.x : 0;
	size.y < 0 ? y += size.y : 0;
	size.y < 0 ? size.y = -size.y : 0;
	for (size_t i = x; i <= x + size.x; i++)
		for (size_t j = y; j <= y + size.y; j++)
			map->tab[i][j].type = GROUND;
}

void linking_rooms(map_t *map)
{
	set_origin(map);
	for (size_t n = 0; n < 100000 && insert_water_loop(map) == false; n++) {
		size_t x = 0;
		size_t y = 0;
		sfVector2i size;

		while (map->tab[x][y].type != GROUND) {
			x = rand() % map->nb_case_x;
			y = rand() % map->nb_case_y;
		} if (rand() % 2)
			size = path_map(map, &V2I(x, y), rand() % 2 ? 1 : -1, 0);
		else
			size = path_map(map, &V2I(x, y), 0, rand() % 2 ? 1 : -1);
		size.x || size.y ? dig_path(map, size, x, y) : n++;
	} for (size_t i = 0; i < map->nb_case_x; i++)
		  for (size_t j = 0; j < map->nb_case_y; j++) {
			map->tab[i][j].type == WATER
				? map->tab[i][j].type = GROUND : 0;
			map_smooth(map, i, j);
		  }
}
