/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_move.c
*/

#include "entity.h"
#include "tile_name.h"
#include "anime_name.h"
#include "type.h"

static void set_anime_move(entity_t *entity)
{
	if (entity->dir.x == 0 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_MOVE_S;
	if (entity->dir.x == 0 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_MOVE_N;
	if (entity->dir.x == -1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_MOVE_W;
	if (entity->dir.x == 1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_MOVE_E;
	if (entity->dir.x == -1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_MOVE_SW;
	if (entity->dir.x == 1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_MOVE_SE;
	if (entity->dir.x == -1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_MOVE_NW;
	if (entity->dir.x == 1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_MOVE_NE;
}

bool entity_move(entity_t *entity, map_t *map,
		 entity_t *info[map->nb_case_x][map->nb_case_y])
{
	if (CAN_MOVE(*entity)) {
		entity->pos.x += entity->dir.x;
		entity->pos.y += entity->dir.y;
		sfClock_restart(entity->clock);
		set_anime_move(entity);
		return (true);
	}
	return (false);
}
