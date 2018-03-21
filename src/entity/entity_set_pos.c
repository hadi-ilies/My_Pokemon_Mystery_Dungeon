/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_set_pos.c
*/

#include "entity.h"

void entity_set_pos(entity_t *entity, sfVector2i pos)
{
	sfVector2f posf = {pos.x, pos.y};

	entity->pos = pos;
	entity->move_pos = posf;
	entity->new_pos = pos;
}
