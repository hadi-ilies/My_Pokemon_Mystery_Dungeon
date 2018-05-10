/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** input_move_short.c
*/

#include "game_resource.h"
#include "tile_name.h"
#include "input.h"

size_t input_move_short(entity_t *entity, map_t *map,
			size_t tab[map->nb_case_x][map->nb_case_y],
			entity_t *info[map->nb_case_x][map->nb_case_y])
{
	size_t input = WAIT;

	for (char i = -1; i <= 1; i++)
		for (char j = -1; j <= 1; j++)
			if (tab[entity->pos.x + i][entity->pos.y + j] < tab[entity->pos.x][entity->pos.y] && tab[entity->pos.x + i][entity->pos.y + j] && !info[entity->pos.x + i][entity->pos.y + j]) {
				i == -1 ? input |= LEFT : 0;
				i == 1 ? input |= RIGHT : 0;
				j == -1 ? input |= UP : 0;
				j == 1 ? input |= DOWN : 0;
				return (input |= MOVE);
			}
	return (WAIT);
}
