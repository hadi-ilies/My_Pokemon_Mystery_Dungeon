/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_create.c
*/

#include "tile_map.h"

tile_map_t tile_map_create(void)
{
	tile_map_t tile_map;

	tile_map.nb_type = 0;
	tile_map.nb_var = NULL;
	tile_map.nb_alt = NULL;
	tile_map.rectex = NULL;
	tile_map.nb_texture = 0;
	tile_map.texture = NULL;
	tile_map.sprite = sfSprite_create();
	if (tile_map.sprite == NULL)
		tile_map.error = TILE_MAP_SPRITE_CREATE;
	else
		tile_map.error = TILE_MAP_OK;
	return (tile_map);
}
