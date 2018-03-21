/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map.h
*/

#ifndef TILE_MAP_H_
#define TILE_MAP_H_

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdbool.h>
#include "image.h"

#define TVA(type, var, alt) (tva_t) {type, var, alt}

typedef struct {
	size_t type;
	size_t var;
	size_t alt;
} tva_t;

typedef struct {
	size_t nb_type;
	size_t nb_var;
	size_t nb_alt;
	image_t ***image;
} tile_map_t;

tile_map_t tile_map_create(size_t nb_type, size_t nb_var, size_t nb_alt);
tile_map_t tile_map_create_from_file(char *file_name);
void tile_map_destroy(tile_map_t *tile_map);
void tile_map_aff(sfRenderWindow *window, tile_map_t *tile_map,
		  tva_t tva, sfFloatRect rect);
bool tile_map_error(tile_map_t *tile_map);

#endif
