/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** ia.c
*/

#include "game_resource.h"
#include "tile_name.h"
#include "input.h"

static entity_t *get_cible(entity_t *entity, map_t *map,
			entity_t *info[map->nb_case_x][map->nb_case_y])
{
	const size_t dist = 5;
	size_t i_min;
	size_t j_min;
	size_t i_max = map->nb_case_x - 1;
	size_t j_max = map->nb_case_y - 1;
	entity_t *cible = NULL;

	i_min = (entity->pos.x - (ssize_t)dist >= 0 ? entity->pos.x - dist : 0);
	j_min = (entity->pos.y - (ssize_t)dist >= 0 ? entity->pos.y - dist : 0);
	if (entity->pos.x + dist <= map->nb_case_x - 1)
		i_max = entity->pos.x + dist;
	if (entity->pos.y + dist <= map->nb_case_y - 1)
		j_max = entity->pos.y + dist;
	for (size_t i = i_min; !cible && i < i_max; i++)
		for (size_t j = j_min; !cible && j < j_max; j++)
			info[i][j] && !info[i][j]->ia ? cible = info[i][j] : 0;
	return (cible);
}

size_t ia(entity_t *entity, map_t *map,
	entity_t *info[map->nb_case_x][map->nb_case_y])
{
	entity_t *cible = get_cible(entity, map, info);
	size_t tab[map->nb_case_x][map->nb_case_y];

	if (!cible)
		return ((0b001 << (rand() % 4)) | MOVE | WAIT);
	spread(map, tab, cible);
	if (tab[entity->pos.x][entity->pos.y] == 0)
		return ((0b001 << (rand() % 4)) | MOVE | WAIT);
	if (input_attack(entity, map, tab, info) & ATTACK)
		return (input_attack(entity, map, tab, info));
	if (input_move_short(entity, map, tab, info) & MOVE)
		return (input_move_short(entity, map, tab, info));
	if (input_move_long(entity, map, tab, info) & MOVE)
		return (input_move_long(entity, map, tab, info));
	return (WAIT);
}
