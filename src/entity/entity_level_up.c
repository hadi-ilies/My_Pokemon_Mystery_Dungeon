/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_level_up.c
*/

#include "entity.h"

void entity_level_up(entity_t *entity)
{
	while (entity->level < 100 && entity->exp >= EXP_MAX(*entity)) {
		entity->exp -= EXP_MAX(*entity);
		entity->level++;
	}
}
