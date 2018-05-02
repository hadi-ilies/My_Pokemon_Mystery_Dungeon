/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_create_from_file.c
*/

#include <unistd.h>
#include <fcntl.h>
#include "tile_map.h"

tile_map_t tile_map_create_from_file(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	tile_map_t tile_map;

	if (fd == -1) {
		tile_map = tile_map_create();
		tile_map.error = ERR_OPEN;
		return (tile_map);
	}
	tile_map = tile_map_create_from_fd(fd);
	close(fd);
	return (tile_map);
}
