/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** entity.h
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"
#include "anime_tab.h"
#include "capacity.h"

// game_macros
#define TIME_MOVE 300000

// code_macros
#define NEW_X entity->pos.x + entity->dir.x
#define NEW_Y entity->pos.y + entity->dir.y
#define INFO info[NEW_X][NEW_Y]
#define STAT(entity, stat) ((entity).base_stat.stat			\
			    + (entity).ev.stat + (entity).iv.stat)	\
	* ((entity).level / 100.0) * (entity).boost.stat
#define STATATK(entity, capacity) (capacity).category == PHYSICAL ?	\
		STAT(entity, atk) : STAT(entity, spa)
#define STATDEF(entity, capacity) (capacity).category == PHYSICAL ?	\
		STAT(entity, def) : STAT(entity, spd)

typedef struct {
	ssize_t life;
	ssize_t atk;
	ssize_t def;
	ssize_t spa;
	ssize_t spd;
	ssize_t speed;
} stats_t;

typedef struct {
	size_t level;
	size_t life;
	size_t type;
	size_t type2;
	capacity_t *capacity[4];
	size_t pp[4];
	size_t ability;
	size_t nature;
	stats_t base_stat;
	stats_t ev;
	stats_t iv;
	stats_t boost;
	size_t item;

	size_t ia;

	sfVector2i dir;
	sfVector2i pos;
	sfClock *clock;
	anime_tab_t anime_tab;
} entity_t;

entity_t entity_create(void);
void entity_destroy(entity_t *entity);
bool entity_move(entity_t *entity, map_t *map,
		 entity_t *info[map->nb_case_x][map->nb_case_y]);
sfVector2f entity_get_move_pos(entity_t *entity);
void entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f pos);

#endif
