/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_create_random.c
*/

#include <stdlib.h>
#include "map.h"
#include "tile_name.h"

map_t map_create_random(unsigned int seed)
{
	map_t map = map_create(rand() % 50 + 50, rand() % 50 + 50);

	srand(seed);
	for (size_t i = 0; i < map.nb_case_x; i++)
		for (size_t j = 0; j < map.nb_case_y; j++)
			map.tab[i][j] = (tva_t){0, 0, 0};
	for (size_t i = 0; i < 50 * 50; i++)
		map.tab[rand() % map.nb_case_x][rand() % map.nb_case_y].type = GROUND;
	map_smooth_all(&map);
	return (map);
}
