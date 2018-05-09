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
#include "my.h"

static bool map_read(map_t *map, int fd, size_t *nb_case_x, size_t *nb_case_y)
{
	size_t len;
	char *tile_map_file_name;

	if (read(fd, nb_case_x, sizeof(size_t)) != sizeof(size_t))
		return (map->error = ERR_READ, true);
	if (read(fd, nb_case_y, sizeof(size_t)) != sizeof(size_t))
		return (map->error = ERR_READ, true);
	if (read(fd, &len, sizeof(size_t)) != sizeof(size_t))
		return (map->error = ERR_READ, true);
	tile_map_file_name = malloc(sizeof(char) * (len + 1));
	if (tile_map_file_name == NULL)
		return (map->error = ERR_MALLOC, true);
	if (read(fd, tile_map_file_name, len) != (int)len)
		return (map->error = ERR_READ, true);
	tile_map_file_name[len] = '\0';
	*map = map_create(*nb_case_x, *nb_case_y, tile_map_file_name);
	free(tile_map_file_name);
	return (false);
}

map_t map_load(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	map_t map;
	size_t nb_case_x;
	size_t nb_case_y;

	if (fd == -1)
		return (map.error = ERR_OPEN, map);
	if (map_read(&map, fd, &nb_case_x, &nb_case_y) || map.error != ERR_OK)
		return (map);
	for (size_t i = 0; i < map.nb_case_x; i++)
		for (size_t j = 0; j < map.nb_case_y; j++) {
			if (READ(&map.tab[i][j], sizeof(tva_t)))
				return (map.error = ERR_READ, map);
		}
	close(fd);
	return (map);
}
