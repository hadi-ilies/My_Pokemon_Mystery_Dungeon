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
	int fd = open(file_name, O_WRONLY | O_CREAT);

	if (fd == -1)
		return;
	if (write(fd, &map->nb_case_x, sizeof(size_t)) != sizeof(size_t))
		return;
	if (write(fd, &map->nb_case_y, sizeof(size_t)) != sizeof(size_t))
		return;
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++) {
			write(fd, &map->tab[i][j], sizeof(tva_t));
		}
	close(fd);
}
