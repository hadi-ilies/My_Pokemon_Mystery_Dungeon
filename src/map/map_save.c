/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_save.c
*/

#include <fcntl.h>
#include "map.h"
#include "my.h"

static void tab_save2(map_t *map, size_t x, size_t y, int fd)
{
	if (write(fd, &map->tab[x][y], sizeof(tva_t)) != sizeof(tva_t))
		map->error = ERR_WRITE;
}

static void tab_save(map_t *map, int fd)
{
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			tab_save2(map, i, j, fd);
}

void map_save(map_t *map, char *file_name)
{
	int fd = CREAT(file_name, S_IRUSR | S_IWUSR | S_IRGRP);
	size_t len = my_strlen(map->tile_map_file_name);

	if (fd == -1) {
		map->error = ERR_OPEN;
		return;
	}
	if (write(fd, &map->nb_case_x, sizeof(size_t)) != sizeof(size_t))
		map->error = ERR_WRITE;
	if (write(fd, &map->nb_case_y, sizeof(size_t)) != sizeof(size_t))
		map->error = ERR_WRITE;
	if (write(fd, &len, sizeof(size_t)) != sizeof(size_t))
		map->error = ERR_WRITE;
	if (write(fd, map->tile_map_file_name, len) != (int)len)
		map->error = ERR_WRITE;
	tab_save(map, fd);
	close(fd);
}
