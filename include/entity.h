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
#include "error.h"
#include "map.h"
#include "anime_tab.h"
#include "capacity.h"

// game_macros
#define TIME_MOVE 300000
#define LIFE_RECT 10, 10, 10, 50

// code_macros
#define EXP_MAX(entity) (entity).level * ((entity).level + 10)
#define NEW_X(entity) (entity).pos.x + (entity).dir.x
#define NEW_Y(entity) (entity).pos.y + (entity).dir.y
#define INFO(entity) info[NEW_X(entity)][NEW_Y(entity)]
#define STAT(entity, stat) (size_t)(((entity).base_stat.stat		\
				+ (entity).ev.stat + (entity).iv.stat) \
				* ((entity).level / 100.0) *	\
				((entity).boost.stat * 0.5 + 1.0))
#define STATATK(entity, capacity) (capacity).category == PHYSICAL ?	\
		STAT(entity, atk) : STAT(entity, spa)
#define STATDEF(entity, capacity) (capacity).category == PHYSICAL ?	\
		STAT(entity, def) : STAT(entity, spd)
#define CAPACITY(entity, num) capacity_tab[(entity).capacity_num[num]]
#define CAN_MOVE(entity) !INFO(entity)					\
	&& (map->tab[NEW_X(entity)][NEW_Y(entity)].type == GROUND	\
	|| (map->tab[NEW_X(entity)][NEW_Y(entity)].type == WATER	\
		&& ((entity).type == TYPE_WATER				\
		|| (entity).type == TYPE_FLYING			\
		|| (entity).type2 == TYPE_WATER			\
		|| (entity).type2 == TYPE_FLYING)))

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
	size_t exp;
	size_t life;
	size_t type;
	size_t type2;
	size_t capacity_num[4];
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
	char *anime_tab_file_name;
	anime_tab_t anime_tab;
	enum error_e error;
} entity_t;

entity_t entity_create(void);
entity_t entity_create_from_file(char *file_name);
entity_t entity_create_from_fd(int fd);
void entity_destroy(entity_t *entity);
void entity_save(entity_t *entity, char *file_name);
bool entity_move(entity_t *entity, map_t *map,
		 entity_t *info[map->nb_case_x][map->nb_case_y]);
sfVector2f entity_get_move_pos(entity_t *entity);
void entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f pos);
size_t entity_gain_exp(entity_t *entity, size_t exp);

#endif
