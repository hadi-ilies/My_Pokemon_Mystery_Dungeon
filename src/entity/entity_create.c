/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_create.c
*/

#include "entity.h"

entity_t entity_create(void)
{
	entity_t entity;
	sfVector2i i0 = {0, 0};
	sfVector2f f0 = {0, 0};

	entity.pos = i0;
	entity.move_pos = f0;
	entity.new_pos = i0;
	return (entity);
}
