/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_create.c
*/

#include <stdlib.h>
#include "tile_map.h"

tile_map_t tile_map_create(size_t nb_type, size_t nb_var, size_t nb_alt)
{
	tile_map_t tile_map;

	tile_map.nb_type = nb_type;
	tile_map.nb_var = nb_var;
	tile_map.nb_alt = nb_alt;
	tile_map.image = malloc(sizeof(image_t **) * nb_type);
	if (tile_map.image == NULL)
		return (tile_map);
	for (size_t i = 0; i < tile_map.nb_type; i++) {
		tile_map.image[i] = malloc(sizeof(image_t *) * nb_var);
		if (tile_map.image[i] == NULL)
			return (tile_map);
		for (size_t j = 0; j < tile_map.nb_var; j++)
			tile_map.image[i][j] = malloc(sizeof(image_t) * nb_alt);
	}
	return (tile_map);
}
