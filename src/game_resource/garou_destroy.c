/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** garou_destroy.c
*/

#include "game_resource.h"

void game_destroy(garou_t *garou)
{
	for (size_t i = 0; i < garou->nb_tile_map; i++)
		tile_map_destroy(&garou->tile_map[i]);
	for (size_t i = 0; i < garou->nb_anime_tab; i++)
		anime_tab_destroy(&garou->anime_tab[i]);
	map_destroy(&garou->map);
}
