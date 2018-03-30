/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_move.c
*/

#include <stdbool.h>
#include "entity.h"

static bool ee(float n1, int n2)
{
	float n3 = (float)n2 - n1;

	n3 < 0 ? n3 = -n3 : 0;
	if (n3 < 0.001)
		return (true);
	return (false);
}

void entity_move(entity_t *entity)
{
	const float move_speed = 0.1;
	sfVector2i dir = {entity->new_pos.x - entity->pos.x, entity->new_pos.y - entity->pos.y};

	if (dir.x || dir.y) {
		entity->move_pos.x += move_speed * dir.x;
		entity->move_pos.y += move_speed * dir.y;
	}
	if (ee(entity->move_pos.x, entity->new_pos.x) && ee(entity->move_pos.y, entity->new_pos.y)) {
		entity->pos.x = entity->new_pos.x;
		entity->pos.y = entity->new_pos.y;
		entity->move_pos.x = entity->new_pos.x;
		entity->move_pos.y = entity->new_pos.y;
		entity->dir.x = 0;
		entity->dir.y = 0;
	}
}

/*void entity_move(entity_t *entity)
{
	const float move_speed = 0.1;
	sfVector2i dir;

	dir.x = entity->new_pos.x - entity->pos.x;
	dir.y = entity->new_pos.y - entity->pos.y;
	if (dir.x || dir.y) {
		entity->move_pos.x += move_speed * dir.x;
		entity->move_pos.y += move_speed * dir.y;
	}
	if (ee(entity->move_pos.x, entity->new_pos.x) && ee(entity->move_pos.y, entity->new_pos.y)) {
		entity->pos.x = entity->new_pos.x;
		entity->pos.y = entity->new_pos.y;
		entity->move_pos.x = entity->new_pos.x;
		entity->move_pos.y = entity->new_pos.y;
	}
	}*/
