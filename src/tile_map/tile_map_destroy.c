/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_destroy.c
*/

#include <stdlib.h>
#include "tile_map.h"

void tile_map_destroy(tile_map_t *tile_map)
{
	for (size_t i = 0; i < tile_map->nb_type; i++) {
		for (size_t j = 0; j < tile_map->nb_var; j++) {
			for (size_t k = 0; k < tile_map->nb_alt; k++)
				image_destroy(&tile_map->image[i][j][k]);
			free(tile_map->image[i][j]);
		}
		free(tile_map->image[i]);
	}
	free(tile_map->image);
}
