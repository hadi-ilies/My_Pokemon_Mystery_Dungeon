/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** dungeon.h
*/

#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <stddef.h>
#include "map.h"
#include "entity.h"

typedef struct {
	size_t stage_num;
	size_t nb_stage;
	map_t map;
	size_t nb_entity;
	entity_t *entity;
} dungeon_t;

//dungeon_t dungeon_create(void);
//void dungeon_destroy(dungeon_t *dungeon);

#endif
