/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dungeon_destroy.c
*/

#include <stdlib.h>
#include "dungeon.h"

// do not free entity[0] because it is the player
void dungeon_destroy(dungeon_t *dungeon)
{
	map_destroy(&dungeon->map);
	for (size_t i = 1; i < dungeon->nb_entity; i++)
		entity_destroy(&dungeon->entity[i]);
	free(dungeon->entity);

}
