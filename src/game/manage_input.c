/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** manage_input.c
*/

#include "game_resource.h"
#include "capacity_tab.h"
#include "anime_name.h"
#include "input.h"
#include "macro.h"

static void set_anime_idle(entity_t *entity)
{
	if (entity->dir.x == 0 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_IDLE_S;
	if (entity->dir.x == 0 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_IDLE_N;
	if (entity->dir.x == -1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_IDLE_W;
	if (entity->dir.x == 1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_IDLE_E;
	if (entity->dir.x == -1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_IDLE_SW;
	if (entity->dir.x == 1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_IDLE_SE;
	if (entity->dir.x == -1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_IDLE_NW;
	if (entity->dir.x == 1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_IDLE_NE;
}

static bool manage_capacity(entity_t *entity, map_t *map,
		entity_t *info[map->nb_case_x][map->nb_case_y],
		size_t input)
{
	size_t num;

	for (size_t i = 0; i < 4; i++)
		if (input & (CAPACITY1 << i))
			num = i;
	if (entity->pp[num]) {
		if ((size_t)rand() % 100 < CAPACITY(*entity, num).accuracy)
			entity_attack(entity, &CAPACITY(*entity, num), map, info);
		entity->pp[num]--;
		return (true);
	}
	return (false);
}

static bool manage_attack(entity_t *entity, map_t *map,
		entity_t *info[map->nb_case_x][map->nb_case_y],
		size_t input)
{
	if (input & (CAPACITY1 | CAPACITY2 | CAPACITY3 | CAPACITY4)) {
		if (manage_capacity(entity, map, info, input))
			return (true);
	}
	else {
		entity_attack(entity, &capacity_tab[0], map, info);
		return (true);
	}
	return (false);
}

static void set_dir(entity_t *entity, size_t input)
{
	entity->dir = V2I(0, 0);
	input & LEFT ? entity->dir.x = -1 : 0;
	input & RIGHT ? entity->dir.x = 1 : 0;
	input & UP ? entity->dir.y = -1 : 0;
	input & DOWN ? entity->dir.y = 1 : 0;
}

bool manage_input(entity_t *entity, map_t *map,
		entity_t *info[map->nb_case_x][map->nb_case_y],
		size_t input)
{
	if (CLOCK(*entity) < TIME_MOVE)
		return (false);
	if (input & (LEFT | RIGHT | UP | DOWN))
		set_dir(entity, input);
	if (input & MOVE && input & (LEFT | RIGHT | UP | DOWN))
		if (entity_move(entity, map, info))
			return (true);
	if (input & ATTACK)
		if (manage_attack(entity, map, info, input))
			return (true);
	if (input & WAIT) {
		entity->anime_tab.num = ANIME_SLEEP;
		if (entity->life < STAT(*entity, life))
			entity->life++;
		return (true);
	}
	if (input || entity->anime_tab.num != ANIME_SLEEP)
		set_anime_idle(entity);
	return (false);
}
