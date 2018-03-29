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
	for (size_t i = 0; i < garou->nb_tile_map; i++)
		tile_map_destroy(&garou->tile_map[i]);
	free(garou->tile_map);
	for (size_t i = 0; i < garou->nb_anime_tab; i++)
		anime_tab_destroy(&garou->anime_tab[i]);
	free(garou->anime_tab);
	map_destroy(&garou->map);
	for (size_t i = 0; i < garou->nb_entity; i++)
		entity_destroy(&garou->entity[i]);
	free(garou->entity);
}
