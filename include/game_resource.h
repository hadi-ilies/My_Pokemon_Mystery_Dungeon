/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** game_resource.h
*/

#ifndef GAME_RESOURCE_H_
#define GAME_RESOURCE_H_

#include <SFML/Graphics.h>
#include "map.h"
#include "entity.h"

typedef struct {
	size_t nb_tile_map;
	tile_map_t *tile_map;
	size_t nb_anime_tab;
	anime_tab_t *anime_tab;
	map_t map;
} garou_t;

garou_t game_create(void);
void game_destroy(garou_t *garou);

#endif
