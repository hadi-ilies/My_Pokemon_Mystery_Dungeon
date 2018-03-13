/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_move.c
*/

#include "entity.h"

bool ee(float n1, int n2)
{
	float n3 = (float)n2 - n1;

	n3 < 0 ? n3 = -n3 : 0;
	if (n3 < 0.1)
		return (true);
	return (false);
}

void entity_move(entity_t *entity)
{
	const float move_speed = 0.1;

	if (entity->new_pos.x != entity->pos.x || entity->new_pos.y != entity->pos.y) {
		entity->move_pos.x += move_speed * (entity->new_pos.x - entity->pos.x);
		entity->move_pos.y += move_speed * (entity->new_pos.y - entity->pos.y);
	}
	if (ee(entity->move_pos.x, entity->new_pos.x) && ee(entity->move_pos.y, entity->new_pos.y)) {
		entity->pos.x = entity->new_pos.x;
		entity->pos.y = entity->new_pos.y;
		entity->move_pos.x = entity->new_pos.x;
		entity->move_pos.y = entity->new_pos.y;
	}
}
