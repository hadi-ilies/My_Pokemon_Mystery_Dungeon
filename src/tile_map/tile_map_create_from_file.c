/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_create_from_file.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tile_map.h"

bool tile_map_create_from_file_test(tile_map_t *tile_map)
{
	if (tile_map->image == NULL)
		return (true);
	for (size_t i = 0; i < tile_map->nb_type; i++) {
		if (tile_map->image[i] == NULL)
			return (true);
		for (size_t j = 0; j < tile_map->nb_var; j++)
			if (tile_map->image[i][j] == NULL)
				return (true);
	}
	return (false);
}

tile_map_t tile_map_create_from_file(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	tile_map_t tile_map;
	size_t nb_type = 0;
	size_t nb_var = 0;
	size_t nb_alt = 0;

	read(fd, &nb_type, sizeof(size_t));
	read(fd, &nb_var, sizeof(size_t));
	read(fd, &nb_alt, sizeof(size_t));
	tile_map = tile_map_create(nb_type, nb_var, nb_alt);
	if (tile_map_create_from_file_test(&tile_map))
		return (tile_map);
	for (size_t i = 0; i < tile_map.nb_type; i++)
		for (size_t j = 0; j < tile_map.nb_var; j++)
			for (size_t k = 0; k < tile_map.nb_alt; k++) {
				size_t str_len = 0;
				char *str;
				sfIntRect rect = {0, 0, 0, 0};

				read(fd, &str_len, sizeof(size_t));
				str = malloc(sizeof(char) * (str_len + 1));
				if (str == NULL)
					return (tile_map);
				read(fd, str, str_len);
				str[str_len] = '\0';
				tile_map.image[i][j][k] = image_create(str);
				read(fd, &rect, sizeof(sfIntRect));
				sfSprite_setTextureRect(tile_map.image[i][j][k].sprite, rect);
				free(str);
			}
	return (tile_map);
}
