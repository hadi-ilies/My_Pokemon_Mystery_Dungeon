/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "tile_map.h"
#include "my.h"

bool error_map5(tile_map_t *tile_map, int fd, size_t i)
{
	for (size_t j = 0; j < tile_map->nb_var[i]; j++) {
		if (READ(&tile_map->nb_alt[i][j], sizeof(size_t)))
			return (tile_map->error = ERR_READ, false);
		if (tile_map->nb_alt[i][j] <= 0)
			return (tile_map->error = ERR_INVALID_NUMBER, false);
		tile_map->rectex[i][j] = malloc(sizeof(rectex_t)
						* tile_map->nb_alt[i][j]);
		if (tile_map->rectex[i][j] == NULL)
			return (tile_map->error = ERR_MALLOC, false);
		for (size_t k = 0; k < tile_map->nb_alt[i][j]; k++) {
			if (read(fd, &tile_map->rectex[i][j][k],
				sizeof(rectex_t)) != sizeof(rectex_t))
				return (tile_map->error = ERR_READ, false);
			if (tile_map->rectex[i][j][k].texture_num >=
			tile_map->nb_texture)
				return (tile_map->error = ERR_INVALID_NUMBER,
					false);
		}
	}
	return (true);
}
