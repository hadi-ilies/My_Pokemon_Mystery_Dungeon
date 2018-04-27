/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_load.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "map.h"

map_t map_load(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	map_t map;
	size_t nb_case_x;
	size_t nb_case_y;
	size_t len;
	char *tile_map_file_name;

	if (fd == -1) {
		map.error = MAP_OPEN;
		return (map);
	}
	if (read(fd, &nb_case_x, sizeof(size_t)) != sizeof(size_t)) {
		map.error = MAP_READ;
		return (map);
	}
	if (read(fd, &nb_case_y, sizeof(size_t)) != sizeof(size_t)) {
		map.error = MAP_READ;
		return (map);
	}
	if (read(fd, &len, sizeof(size_t)) != sizeof(size_t)) {
		map.error = MAP_READ;
		return (map);
	}
	tile_map_file_name = malloc(sizeof(char) * (len + 1));
	if (tile_map_file_name == NULL) {
		map.error = MAP_MALLOC;
		return (map);
	}
	if (read(fd, &tile_map_file_name, len) != (int)len) {
		map.error = MAP_READ;
		return (map);
	}
	tile_map_file_name[len] = '\0';
	map.tile_map = tile_map_create_from_file(tile_map_file_name);
	free(tile_map_file_name);
	if (map.tile_map.error != TILE_MAP_OK) {
		map.error = MAP_TILE_MAP;
		return (map);
	}
	map = map_create(nb_case_x, nb_case_y, tile_map_file_name);
	if (map.error != MAP_OK)
		return (map);
	for (size_t i = 0; i < map.nb_case_x; i++)
		for (size_t j = 0; j < map.nb_case_y; j++) {
			if (read(fd, &map.tab[i][j], sizeof(tva_t)) != sizeof(tva_t)) {
				map.error = MAP_READ;
				return (map);
			}
		}

	return (map);
}
