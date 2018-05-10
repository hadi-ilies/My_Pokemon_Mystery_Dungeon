/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** input_attack.c
*/

#include "game_resource.h"
#include "tile_name.h"
#include "input.h"

size_t input_attack(entity_t *entity, map_t *map,
		    size_t tab[map->nb_case_x][map->nb_case_y],
		    entity_t *info[map->nb_case_x][map->nb_case_y])
{
	size_t input = WAIT;

	for (char i = -1; i <= 1; i++)
		for (char j = -1; j <= 1; j++)
			if (tab[entity->pos.x + i][entity->pos.y + j] != WALL && info[entity->pos.x + i][entity->pos.y + j] && info[entity->pos.x + i][entity->pos.y + j]->ia == 0) {
				i == -1 ? input |= LEFT : 0;
				i == 1 ? input |= RIGHT : 0;
				j == -1 ? input |= UP : 0;
				j == 1 ? input |= DOWN : 0;
				return (input |= ATTACK);
			}
	return (WAIT);
}
