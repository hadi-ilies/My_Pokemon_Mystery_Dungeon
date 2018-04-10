/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_smooth.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "map.h"
#include "tile_name.h"

void map_smooth4(map_t *map, size_t x, size_t y)
{
	size_t type = map->tab[x][y].type;
	size_t var = map->tab[x][y].var;

	if (map->tab[x][y].alt != 0 || map->tile_map == NULL || map->tile_map->nb_alt[type][var] == 1)
		return;
	for (size_t i = 1; i < map->tile_map->nb_alt[type][var]; i++)
		if (rand() % 3) {
			map->tab[x][y].alt = i;
			return;
		}
}

void map_smooth3(map_t *map, size_t x, size_t y)
{
	size_t type = map->tab[x][y].type;
	size_t var = map->tab[x][y].var;

	if (map->tile_map == NULL || map->tab[x][y].alt >= map->tile_map->nb_alt[type][var])
		map->tab[x][y].alt = 0;
}

void map_smooth2(map_t *map, size_t x, size_t y)
{
	bool tmp[3][3] = {false};

	if (map->tab[x - 1][y - 1].type == map->tab[x][y].type)
		tmp[0][0] = true;
	if (map->tab[x][y - 1].type == map->tab[x][y].type)
		tmp[1][0] = true;
	if (map->tab[x + 1][y - 1].type == map->tab[x][y].type)
		tmp[2][0] = true;
	if (map->tab[x - 1][y].type == map->tab[x][y].type)
		tmp[0][1] = true;
	if (map->tab[x + 1][y].type == map->tab[x][y].type)
		tmp[2][1] = true;
	if (map->tab[x - 1][y + 1].type == map->tab[x][y].type)
		tmp[0][2] = true;
	if (map->tab[x][y + 1].type == map->tab[x][y].type)
		tmp[1][2] = true;
	if (map->tab[x + 1][y + 1].type == map->tab[x][y].type)
		tmp[2][2] = true;

	if (!tmp[1][0] && !tmp[0][1] && tmp[2][1] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V000_0X1_011;
	if (!tmp[1][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V000_1X1_111;
	if (!tmp[1][0] && tmp[0][1] && !tmp[2][1] && tmp[0][2] && tmp[1][2])
		map->tab[x][y].var = V000_1X0_110;
	if (tmp[1][0] && tmp[2][0] && !tmp[0][1] && tmp[2][1] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V011_0X1_011;
	if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V111_1X1_111;
	if (tmp[0][0] && tmp[1][0] && tmp[0][1] && !tmp[2][1] && tmp[0][2] && tmp[1][2])
		map->tab[x][y].var = V110_1X0_110;
	if (tmp[1][0] && tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V011_0X1_000;
	if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V111_1X1_000;
	if (tmp[0][0] && tmp[1][0] && tmp[0][1] && !tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V110_1X0_000;

	if (!tmp[1][0] && !tmp[0][1] && tmp[2][1] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V000_0X1_010;
	if (!tmp[1][0] && tmp[0][1] && tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V000_1X1_000;
	if (!tmp[1][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && tmp[1][2])
		map->tab[x][y].var = V000_1X0_010;
	if (tmp[1][0] && !tmp[0][1] && !tmp[2][1] && tmp[1][2])
		map->tab[x][y].var = V010_0X0_010;
	if (!tmp[1][0] && !tmp[0][1] && !tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V000_0X0_000;
	if (tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V010_0X1_000;
	if (!tmp[0][0] && tmp[1][0] && tmp[0][1] && !tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V010_1X0_000;

	if (!tmp[1][0] && !tmp[0][1] && !tmp[2][1] && tmp[1][2])
		map->tab[x][y].var = V000_0X0_010;
	if (!tmp[1][0] && !tmp[0][1] && tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V000_0X1_000;
	if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V010_1X1_010;
	if (!tmp[1][0] && tmp[0][1] && !tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V000_1X0_000;
	if (tmp[1][0] && !tmp[0][1] && !tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V010_0X0_000;

	if (!tmp[1][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V000_1X1_010;
	if (tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V010_0X1_010;
	if (!tmp[0][0] && tmp[1][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && tmp[1][2])
		map->tab[x][y].var = V010_1X0_010;
	if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V010_1X1_000;

	if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V111_1X1_010;
	if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V110_1X1_110;
	if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V011_1X1_011;
	if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V010_1X1_111;

	if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V111_1X1_110;
	if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V111_1X1_011;
	if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V110_1X1_111;
	if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V011_1X1_111;

	if (tmp[1][0] && tmp[2][0] && !tmp[0][1] && tmp[2][1] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V011_0X1_010;
	if (tmp[0][0] && tmp[1][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && tmp[1][2])
		map->tab[x][y].var = V110_1X0_010;
	if (tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V010_0X1_011;
	if (!tmp[0][0] && tmp[1][0] && tmp[0][1] && !tmp[2][1] && tmp[0][2] && tmp[1][2])
		map->tab[x][y].var = V010_1X0_110;

	if (!tmp[1][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V000_1X1_110;
	if (!tmp[1][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V000_1X1_011;
	if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V110_1X1_000;
	if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[1][2])
		map->tab[x][y].var = V011_1X1_000;

	if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V010_1X1_011;
	if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V010_1X1_110;
	if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V011_1X1_010;
	if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V110_1X1_010;

	if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
		map->tab[x][y].var = V011_1X1_110;
	if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
		map->tab[x][y].var = V110_1X1_011;
	map_smooth3(map, x, y);
}

void map_smooth(map_t *map, size_t x, size_t y)
{
	size_t i_min = x - 1;
	size_t i_max = x + 1;
	size_t j_min = y - 1;
	size_t j_max = y + 1;

	i_min <= 0 ? i_min = 1 : 0;
	i_max >= map->nb_case_x - 1 ? i_max = map->nb_case_x - 2 : 0;
	j_min <= 0 ? j_min = 1 : 0;
	j_max >= map->nb_case_y - 1 ? j_max = map->nb_case_y - 2 : 0;
	for (size_t i = i_min; i <= i_max; i++)
		for (size_t j = j_min; j <= j_max; j++)
			map_smooth2(map, i, j);
}

void map_smooth_all(map_t *map)
{
	for (size_t i = 0; i < map->nb_case_x; i++) {
		map->tab[i][0] = TVA(WALL, V111_1X1_111, 0);
		map->tab[i][map->nb_case_y - 1] = TVA(WALL, V111_1X1_111, 0);
		map->tab[i][1].type = WALL;
		map->tab[i][map->nb_case_y - 2].type = WALL;
	}
	for (size_t i = 0; i < map->nb_case_y; i++) {
		map->tab[0][i] = TVA(WALL, V111_1X1_111, 0);
		map->tab[map->nb_case_x - 1][i] = TVA(WALL, V111_1X1_111, 0);
		map->tab[1][i].type = WALL;
		map->tab[map->nb_case_x - 2][i].type = WALL;
	}
	for (size_t i = 1; i < map->nb_case_x - 1; i++)
		for (size_t j = 1; j < map->nb_case_y - 1; j++) {
			map_smooth2(map, i, j);
			map->tab[i][j].alt = 0;
			rand() % 10 == 0 ? map_smooth4(map, i, j) : 0;
		}
}
