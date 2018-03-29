/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_smooth.c
*/

#include <stdbool.h>
#include "map.h"
#include "tile_name.h"

void map_smooth(map_t *map)
{
	for (size_t i = 0; i < map->nb_case_x; i++) {
		map->tab[i][0] = TVA(WALL, V111_1X1_111, 0);
		map->tab[i][map->nb_case_x - 1] = TVA(WALL, V111_1X1_111, 0);
	}
	for (size_t i = 0; i < map->nb_case_y; i++) {
		map->tab[0][i] = TVA(WALL, V111_1X1_111, 0);
		map->tab[map->nb_case_y - 1][0] = TVA(WALL, V111_1X1_111, 0);
	}
	for (size_t i = 1; i < map->nb_case_x - 1; i++)
		for (size_t j = 1; j < map->nb_case_y - 1; j++) {
			bool tmp[3][3] = {false};

			if (map->tab[i - 1][j - 1].type == map->tab[i][j].type)
				tmp[0][0] = true;
			if (map->tab[i][j - 1].type == map->tab[i][j].type)
				tmp[1][0] = true;
			if (map->tab[i + 1][j - 1].type == map->tab[i][j].type)
				tmp[2][0] = true;
			if (map->tab[i - 1][j].type == map->tab[i][j].type)
				tmp[0][1] = true;
			if (map->tab[i + 1][j].type == map->tab[i][j].type)
				tmp[2][1] = true;
			if (map->tab[i - 1][j + 1].type == map->tab[i][j].type)
				tmp[0][2] = true;
			if (map->tab[i][j + 1].type == map->tab[i][j].type)
				tmp[0][2] = true;
			if (map->tab[i + 1][j + 1].type == map->tab[i][j].type)
				tmp[2][2] = true;

			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V000_0X1_011;
			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V000_1X1_111;
			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_1X0_110;
			if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && !tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V011_0X1_011;
			if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V111_1X1_111;
			if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V110_1X0_110;
			if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V011_0X1_000;
			if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V111_1X1_000;
			if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V110_1X0_000;

			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_0X1_010;
			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_1X1_000;
			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_1X0_010;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && !tmp[0][1] && !tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_0X0_010;
			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && !tmp[0][1] && !tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_0X0_000;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_0X1_000;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_1X0_000;

			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && !tmp[0][1] && !tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_0X0_010;
			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_0X1_000;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_1X1_010;
			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_1X0_000;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && !tmp[0][1] && !tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_0X0_000;

			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_1X1_010;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_0X1_010;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_1X0_010;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_1X1_000;

			if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V111_1X1_010;
			if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V110_1X1_110;
			if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V011_1X1_011;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V010_1X1_111;

			if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V111_1X1_110;
			if (tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V111_1X1_011;
			if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V110_1X1_111;
			if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V011_1X1_111;

			if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V011_0X1_010;
			if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V110_1X0_010;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && !tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V010_0X1_011;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && !tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_1X0_110;

			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V000_1X1_110;
			if (!tmp[0][0] && !tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V000_1X1_011;
			if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V110_1X1_000;
			if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && !tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V011_1X1_000;

			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V010_1X1_011;
			if (!tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V010_1X1_110;
			if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V011_1X1_010;
			if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V110_1X1_010;

			if (!tmp[0][0] && tmp[1][0] && tmp[2][0] && tmp[0][1] && tmp[2][1] && tmp[0][2] && tmp[1][2] && !tmp[2][2])
				map->tab[i][j].var = V011_1X1_110;
			if (tmp[0][0] && tmp[1][0] && !tmp[2][0] && tmp[0][1] && tmp[2][1] && !tmp[0][2] && tmp[1][2] && tmp[2][2])
				map->tab[i][j].var = V110_1X1_011;
		}
}
