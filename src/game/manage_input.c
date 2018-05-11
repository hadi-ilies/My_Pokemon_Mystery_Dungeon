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

bool manage_input(entity_t *entity, map_t *map,
		entity_t *info[map->nb_case_x][map->nb_case_y],
		size_t input)
{
	if (sfClock_getElapsedTime(entity->clock).microseconds < TIME_MOVE)
		return (false);
	if (input & (LEFT | RIGHT | UP | DOWN)) {
		entity->dir = V2I(0, 0);
		input & LEFT ? entity->dir.x = -1 : 0;
		input & RIGHT ? entity->dir.x = 1 : 0;
		input & UP ? entity->dir.y = -1 : 0;
		input & DOWN ? entity->dir.y = 1 : 0;
	}
	if (input & MOVE && input & (LEFT | RIGHT | UP | DOWN))
		if (entity_move(entity, map, info))
			return (true);
	if (input & ATTACK) {
		if (input & (CAPACITY1 | CAPACITY2 | CAPACITY3 | CAPACITY4)) {
			bool tmp = false;

			if (input & CAPACITY1 && entity->pp[0]) {
				if ((size_t)rand() % 100 < CAPACITY(*entity, 0).accuracy)
					entity_attack(entity, &CAPACITY(*entity, 0), map, info);
				entity->pp[0]--;
				tmp = true;
			}
			if (input & CAPACITY2 && entity->pp[1]) {
				if ((size_t)rand() % 100 < CAPACITY(*entity, 1).accuracy)
					entity_attack(entity, &CAPACITY(*entity, 1), map, info);
				entity->pp[1]--;
				tmp = true;
			}
			if (input & CAPACITY3 && entity->pp[2]) {
				if ((size_t)rand() % 100 < CAPACITY(*entity, 2).accuracy)
					entity_attack(entity, &CAPACITY(*entity, 2), map, info);
				entity->pp[2]--;
				tmp = true;
			}
			if (input & CAPACITY4 && entity->pp[3]) {
				if ((size_t)rand() % 100 < CAPACITY(*entity, 3).accuracy)
					entity_attack(entity, &CAPACITY(*entity, 3), map, info);
				entity->pp[3]--;
				tmp = true;
			}
			return (tmp);
		}
		else {
			entity_attack(entity, &capacity_tab[0], map, info);
			return (true);
		}
	}
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
