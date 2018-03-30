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

void map_save(map_t *map, char *file_name)
{
	int fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU, S_IRWXU | S_IRWXG);

	if (fd == -1) {
		map->error = MAP_OPEN;
		return;
	}
	if (write(fd, &map->nb_case_x, sizeof(size_t)) != sizeof(size_t)) {
		map->error = MAP_WRITE;
		return;
	}
	if (write(fd, &map->nb_case_y, sizeof(size_t)) != sizeof(size_t)) {
		map->error = MAP_WRITE;
		return;
	}
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			if (write(fd, &map->tab[i][j], sizeof(tva_t)) != sizeof(tva_t)) {
				map->error = MAP_WRITE;
				return;
			}
	close(fd);
}
