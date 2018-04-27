/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_aff.c
*/

#include "map.h"

void map_aff(sfRenderWindow *window, map_t *map)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f center = {win_size.x / 2, win_size.y / 2};
	tile_map_t *tile_map = &map->tile_map;
	size_t i_min = X_MIN;
	size_t i_max = X_MAX;
	size_t j_min = Y_MIN;
	size_t j_max = Y_MAX;

	for (size_t i = i_min; i < i_max; i++)
		for (size_t j = j_min; j < j_max; j++) {
			sfFloatRect rect;

			rect.left = map->size.x * (i - map->pos.x) + center.x;
			rect.top = map->size.y * (j - map->pos.y) + center.y;
			rect.width = map->size.x;
			rect.height = map->size.y;
			rect.left = (int)rect.left;
			rect.top = (int)rect.top;
			tile_map_aff(window, tile_map, map->tab[i][j], rect);
		}
}
