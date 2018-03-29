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
	sfVector2f pos;
	tile_map_t *tile_map;
	size_t error;
} map_t;

map_t map_create(size_t nb_case_x, size_t nb_case_y);
void map_resize(map_t *map, size_t new_nb_case_x, size_t new_nb_case_y);
void map_destroy(map_t *map);
void map_aff(sfRenderWindow *window, map_t *map);
void map_save(map_t *map, char *file_name);
map_t map_load(char *file_name);

#endif
