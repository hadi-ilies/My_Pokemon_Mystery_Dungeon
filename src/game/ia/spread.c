/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** spread.c
*/

#include "game_resource.h"
#include "tile_name.h"

static void one_spread(map_t *map, size_t tab[map->nb_case_x][map->nb_case_y],
		       size_t x, size_t y)
{
	for (char i = -1; i <= 1; i++)
		for (char j = -1; j <= 1; j++) {
			bool c1 = map->tab[x + i][y + j].type == GROUND;
			bool c2 = !tab[x + i][y + j];

			c1 && c2 ? tab[x + i][y + j] = tab[x][y] + 1 : 0;
		}
}

static void spread_cycle(map_t *map, size_t tab[map->nb_case_x][map->nb_case_y],
			 size_t n)
{
	for (size_t i = 1; i < map->nb_case_x - 1; i++)
		for (size_t j = 1; j < map->nb_case_y - 1; j++)
			tab[i][j] == n ? one_spread(map, tab, i, j) : 0;
}

void spread(map_t *map, size_t tab[map->nb_case_x][map->nb_case_y],
	    entity_t *cible)
{
	const size_t spread_dist = 20;

	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			tab[i][j] = 0;
	tab[cible->pos.x][cible->pos.y] = 1;
	for (size_t n = 1; n <= spread_dist; n++)
		spread_cycle(map, tab, n);
}
