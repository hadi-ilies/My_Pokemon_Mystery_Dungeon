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
#include "map.h"
#include "anime_tab.h"

#define TIME_MOVE (1000000 / 3)

enum type {
	TYPE_NULL,
	TYPE_BUG,
	TYPE_DARK,
	TYPE_DRAGON,
	TYPE_ELECTRIC,
	TYPE_DAIRY,
	TYPE_FIGHTING,
	TYPE_FIRE,
	TYPE_FLYING,
	TYPE_GHOST,
	TYPE_GRASS,
	TYPE_GROUND,
	TYPE_ICE,
	TYPE_NORMAL,
	TYPE_POISON,
	TYPE_PSYCHIC,
	TYPE_ROCK,
	TYPE_STEEL,
	TYPE_WATER,
};

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
	size_t ability;
	size_t nature;
	stats_t base_stat;
	stats_t ev;
	stats_t iv;
	stats_t boost;
	size_t item;

	sfVector2i dir;
	sfVector2i pos;
	sfClock *clock;
	anime_tab_t anime_tab;
} entity_t;

entity_t entity_create(void);
void entity_destroy(entity_t *entity);
void entity_move(entity_t *entity);
sfVector2f entity_get_move_pos(entity_t *entity);
void entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f pos);

#endif
