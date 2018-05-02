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
	printf("1\n");
	map_destroy(&garou->map);
	printf("2\n");
	for (size_t i = 0; i < garou->nb_entity; i++)
		entity_destroy(&garou->entity[i]);
	printf("3\n");
	free(garou->entity);
	printf("4\n");
}
