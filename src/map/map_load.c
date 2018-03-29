/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_load.c
*/

#include <unistd.h>
#include <fcntl.h>
#include "map.h"

map_t map_load(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	map_t map;
	size_t nb_case_x;
	size_t nb_case_y;

	if (fd == -1) {
		map.error = 1;
		return (map);
	}
	if (read(fd, &nb_case_x, sizeof(size_t)) != sizeof(size_t)) {
		map.error = 1;
		return (map);
	}
	if (read(fd, &nb_case_y, sizeof(size_t)) != sizeof(size_t)) {
		map.error = 1;
		return (map);
	}
	map = map_create(nb_case_x, nb_case_y);
	if (map.error != 0)
		return (map);
	for (size_t i = 0; i < map.nb_case_x; i++)
		for (size_t j = 0; j < map.nb_case_y; j++) {
			if (read(fd, &map.tab[i][j], sizeof(tva_t)) != sizeof(tva_t)) {
				map.error = 1;
				return (map);
			}
		}
	return (map);
}
