/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** ia1.c
*/

#include "game_resource.h"
#include "tile_name.h"
#include "input.h"

entity_t *get_cible(entity_t *entity, map_t *map,
		    entity_t *info[map->nb_case_x][map->nb_case_y])
{
	const size_t dist = 5;
	size_t i_min = (entity->pos.x - (ssize_t)dist >= 0 ? entity->pos.x - dist : 0);
	size_t j_min = (entity->pos.y - (ssize_t)dist >= 0 ? entity->pos.y - dist : 0);
	size_t i_max = (entity->pos.x + dist <= map->nb_case_x - 1 ? entity->pos.x + dist : map->nb_case_x - 1);
	size_t j_max = (entity->pos.y + dist <= map->nb_case_y - 1 ? entity->pos.y + dist : map->nb_case_y - 1);

	for (size_t i = i_min; i < i_max; i++)
		for (size_t j = j_min; j < j_max; j++)
			if (info[i][j] && info[i][j]->ia == 0)
			return (info[i][j]);

	return (NULL);
}

void ia2(map_t *map, size_t tab[map->nb_case_x][map->nb_case_y], size_t x, size_t y)
{
	for (char i = -1; i <= 1; i++)
		for (char j = -1; j <= 1; j++)
			if (map->tab[x + i][y + j].type == GROUND && tab[x + i][y + j] == 0) //
				tab[x + i][y + j] = tab[x][y] + 1;
}

size_t ia(entity_t *entity, map_t *map,
	  entity_t *info[map->nb_case_x][map->nb_case_y])
{
	size_t input = WAIT;
	entity_t *cible = get_cible(entity, map, info);
	size_t tab[map->nb_case_x][map->nb_case_y];

	if (!cible)
		return ((0b001 << (rand() % 4)) | MOVE | WAIT);
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			tab[i][j] = 0;
	tab[cible->pos.x][cible->pos.y] = 1;
	for (size_t n = 1; n <= 20; n++)
		for (size_t i = 1; i < map->nb_case_x - 1; i++)
			for (size_t j = 1; j < map->nb_case_y - 1; j++)
				if (tab[i][j] == n)
					ia2(map, tab, i, j);
	if (tab[entity->pos.x][entity->pos.y] == 0)
		return ((rand() % 0b1111 + 1) | MOVE);
	for (char i = -1; i <= 1; i++)
		for (char j = -1; j <= 1; j++)
			if (tab[entity->pos.x + i][entity->pos.y + j] < tab[entity->pos.x][entity->pos.y] && tab[entity->pos.x + i][entity->pos.y + j] != 0) {
				i == -1 ? input |= LEFT : 0;
				i == 1 ? input |= RIGHT : 0;
				j == -1 ? input |= UP : 0;
				j == 1 ? input |= DOWN : 0;
				if (info[entity->pos.x + i][entity->pos.y + j] && info[entity->pos.x + i][entity->pos.y + j]->ia == 0)
					return (input |= ATTACK);
				return (input |= MOVE);
			}
	return (WAIT);
}
