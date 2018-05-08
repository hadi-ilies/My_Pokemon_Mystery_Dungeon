/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_get_move_pos.c
*/

#include "entity.h"
#include "macro.h"

sfVector2f entity_get_move_pos(entity_t *entity)
{
	sfVector2f move_pos;
	sfInt64 time = sfClock_getElapsedTime(entity->clock).microseconds;

	move_pos.x = entity->pos.x - entity->dir.x;
	move_pos.y = entity->pos.y - entity->dir.y;
	if (time < TIME_MOVE) {
		move_pos.x += (float)entity->dir.x * time / TIME_MOVE;
		move_pos.y += (float)entity->dir.y * time / TIME_MOVE;
		return (move_pos);
	}
	return (V2F(entity->pos.x, entity->pos.y));
}
