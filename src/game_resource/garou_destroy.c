/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** garou_destroy.c
*/

#include <stdlib.h>
#include "game_resource.h"

void garou_destroy(garou_t *garou)
{
	map_destroy(&garou->map);
	for (size_t i = 0; i < garou->nb_entity; i++)
		entity_destroy(&garou->entity[i]);
	free(garou->entity);
}
