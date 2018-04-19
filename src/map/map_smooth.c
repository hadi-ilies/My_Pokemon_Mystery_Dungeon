/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_smooth.c
*/

#include <stdlib.h>
#include <limits.h>
#include "map.h"
#include "tile_name.h"

static char tile_var[] = {
	0b00001011,
	0b00011111,
	0b00010110,
	0b01101011,
	0b11111111,
	0b11010110,
	0b01101000,
	0b11111000,
	0b11010000,

	0b00001010,
	0b00011000,
	0b00010010,
	0b01000010,
	0b00000000,
	0b01001000,
	0b01010000,

	0b00000010,
	0b00001000,
	0b01011010,
	0b00010000,
	0b01000000,

	0b00011010,
	0b01001010,
	0b01010010,
	0b01011000,

	0b11111010,
	0b11011110,
	0b01111011,
	0b01011111,

	0b11111110,
	0b11111011,
	0b11011111,
	0b01111111,

	0b01101010,
	0b11010010,
	0b01001011,
	0b01010110,

	0b00011110,
	0b00011011,
	0b11011000,
	0b01111000,

	0b01011011,
	0b01011110,
	0b01111010,
	0b11011010,

	0b01111110,
	0b11011011,
	0b10100101
};

void map_smooth4(map_t *map, size_t x, size_t y)
{
	size_t type = map->tab[x][y].type;
	size_t var = map->tab[x][y].var;

	if (map->tab[x][y].alt != 0 || map->tile_map == NULL)
		return;
	if (map->tile_map->nb_alt[type][var] == 1)
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

	if (map->tile_map == NULL)
		map->tab[x][y].alt = 0;
	else if (map->tab[x][y].alt >= map->tile_map->nb_alt[type][var])
		map->tab[x][y].alt = 0;
}

void map_smooth2(map_t *map, size_t x, size_t y)
{
	char rd = 0;

	for (size_t i = 0; i < CHAR_BIT; i++) {
		size_t nx = x + (int)(i + (i >= 4 ? 1 : 0)) % 3 - 1;
		size_t ny = y + (int)(i + (i >= 4 ? 1 : 0)) / 3 - 1;

		if (map->tab[nx][ny].type == map->tab[x][y].type)
			rd |= (0b10000000 >> i);
	}
	(rd & (char)0b01010000) != (char)0b01010000 ? rd &= 0b01111111 : 0;
	(rd & (char)0b01001000) != (char)0b01001000 ? rd &= 0b11011111 : 0;
	(rd & (char)0b00010010) != (char)0b00010010 ? rd &= 0b11111011 : 0;
	(rd & (char)0b00001010) != (char)0b00001010 ? rd &= 0b11111110 : 0;
	for (size_t i = 0; tile_var[i] != (char)0b10100101; i++)
		if (tile_var[i] == rd) {
			map->tab[x][y].var = i;
			break;
		}
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
		for (size_t j = j_min; j <= j_max; j++) {
			map_smooth2(map, i, j);
			map_smooth3(map, i, j);
		}
}

void map_smooth_all(map_t *map)
{
	for (size_t i = 0; i < map->nb_case_x; i++) {
		map->tab[i][0] = TVA(WALL, 4, 0);
		map->tab[i][map->nb_case_y - 1] = TVA(WALL, 4, 0);
		map->tab[i][1].type = WALL;
		map->tab[i][map->nb_case_y - 2].type = WALL;
	}
	for (size_t i = 0; i < map->nb_case_y; i++) {
		map->tab[0][i] = TVA(WALL, 4, 0);
		map->tab[map->nb_case_x - 1][i] = TVA(WALL, 4, 0);
		map->tab[1][i].type = WALL;
		map->tab[map->nb_case_x - 2][i].type = WALL;
	}
	for (size_t i = 1; i < map->nb_case_x - 1; i++)
		for (size_t j = 1; j < map->nb_case_y - 1; j++) {
			map_smooth2(map, i, j);
			map_smooth3(map, i, j);
			map->tab[i][j].alt = 0;
			rand() % 10 == 0 ? map_smooth4(map, i, j) : 0;
		}
}
