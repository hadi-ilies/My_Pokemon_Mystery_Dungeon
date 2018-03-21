/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_error.c
*/

#include <unistd.h>
#include "tile_map.h"

static bool pme(char *msg_error)
{
	size_t size = 0;

	while (msg_error[size++] != '\0');
	write(STDERR_FILENO, msg_error, size - 1);
	return (true);
}

bool tile_map_error(tile_map_t *tile_map)
{
	if (tile_map == NULL)
		return (pme("tile_map does not exist.\n"));
	if (tile_map->nb_type == 0)
		return (pme("nb_type is 0.\n"));
	if (tile_map->nb_var == 0)
		return (pme("nb_var is 0.\n"));
	if (tile_map->nb_alt == 0)
		return (pme("nb_alt is 0.\n"));
	if (tile_map->image == NULL)
		return (pme("image tab tab tab is NULL.\n"));
	for (size_t i = 0; i < tile_map->nb_type; i++) {
		if (tile_map->image[i] == NULL)
			return (pme("image tab tab is NULL.\n"));
		for (size_t j = 0; j < tile_map->nb_var; j++) {
			if (tile_map->image[i][j] == NULL)
				return (pme("image tab is NULL.\n"));
			for (size_t k = 0; k < tile_map->nb_alt; k++)
				if (image_error(&tile_map->image[i][j][k]))
					return (true);
		}
	}
	return (false);
}
