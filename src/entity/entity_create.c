/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_create.c
*/

#include "entity.h"
#include "type.h"
#include "macro.h"

static void set_null(entity_t *entity)
{
	entity->level = 0;
	entity->exp = 0;
	entity->life = 0;
	entity->type = TYPE_NULL;
	entity->type2 = TYPE_NULL;
	entity->ability = 0; // !!!
	entity->nature = 0; // !!!
	entity->base_stat = (stats_t){0, 0, 0, 0, 0, 0};
	entity->ev = (stats_t){0, 0, 0, 0, 0, 0};
	entity->iv = (stats_t){0, 0, 0, 0, 0, 0};
	entity->boost = (stats_t){0, 0, 0, 0, 0, 0};
	entity->item = 0; // !!!
	entity->ia = 0; // !!!
	entity->dir = V2I(0, 0);
	entity->pos = V2I(0, 0);
}

entity_t entity_create(void)
{
	entity_t entity;

	set_null(&entity);
	entity.clock = sfClock_create();
	if (entity.clock == NULL)
		entity.error = ERR_CLOCK_CREATE;
	else
		entity.error = ERR_OK;
	entity.anime_tab_file_name = NULL;
	return (entity);
}
