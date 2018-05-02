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
	for (size_t i = 0; i < tile_map->nb_texture; i++)
		sfTexture_destroy(tile_map->texture[i]);
	free(tile_map->texture);
	for (size_t i = 0; i < tile_map->nb_type; i++) {
		for (size_t j = 0; j < tile_map->nb_var[i]; j++)
			free(tile_map->rectex[i][j]);
		free(tile_map->nb_alt[i]);
		free(tile_map->rectex[i]);
	}
	free(tile_map->nb_var);
	free(tile_map->nb_alt);
	free(tile_map->rectex);
	sfSprite_destroy(tile_map->sprite);
}
