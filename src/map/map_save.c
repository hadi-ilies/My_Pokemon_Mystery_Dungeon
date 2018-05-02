/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_save.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "map.h"
#include "my.h"

void map_save(map_t *map, char *file_name)
{
	int fd = CREAT(file_name, S_IRUSR | S_IWUSR | S_IRGRP);
	size_t len = my_strlen(map->tile_map_file_name);

	if (fd == -1) {
		map->error = ERR_OPEN;
		return;
	} if (write(fd, &map->nb_case_x, sizeof(size_t)) != sizeof(size_t)) {
		map->error = ERR_WRITE;
		return;
	} if (write(fd, &map->nb_case_y, sizeof(size_t)) != sizeof(size_t)) {
		map->error = ERR_WRITE;
		return;
	} if (write(fd, &len, sizeof(size_t)) != sizeof(size_t)) {
		map->error = ERR_WRITE;
		return;
	} if (write(fd, map->tile_map_file_name, len) != (int)len) {
		map->error = ERR_WRITE;
		return;
	} for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			if (write(fd, &map->tab[i][j], sizeof(tva_t)) != sizeof(tva_t)) {
				map->error = ERR_WRITE;
				return;
			}
	close(fd);
}
