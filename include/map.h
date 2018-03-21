/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** map.h
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>
#include <stddef.h>
#include "tile_map.h"

typedef struct {
	size_t nb_case_x;
	size_t nb_case_y;
	tva_t **tab;
	sfVector2f size;
	tile_map_t tile_map;
} map_t;

map_t map_create(int nb_case_x, int nb_case_y);
void map_destroy(map_t *map);
void map_aff(sfRenderWindow *window, map_t *map, sfVector2f *pos);

#endif
