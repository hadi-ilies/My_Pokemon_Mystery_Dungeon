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

// file_macros
#define GAME_FONT "resources/font/Minecraftia.ttf"
#define CAPACITY_UP "Bup.png"
#define CAPACITY_LEFT "Bleft.png"
#define CAPACITY_RIGHT "Bright.png"
#define CAPACITY_DOWN "Bdown.png"

typedef struct {
	size_t nb_tile_map;
	tile_map_t *tile_map;
	size_t nb_anime_tab;
	anime_tab_t *anime_tab;
	map_t map;
	size_t nb_entity;
	entity_t *entity;
} garou_t;

garou_t garou_create(void);
void garou_destroy(garou_t *garou);
void capacity_aff(sfRenderWindow *window, garou_t *garou);

#endif
