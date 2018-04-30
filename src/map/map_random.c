/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_random.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "map.h"
#include "prototype.h"
#include "tile_name.h"

int rand_min_max(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

sfVector2i take_origin(map_t *map, sfVector2i *size)
{
	sfVector2i origin;
	bool test = true;

	while (test) {
		test = false;
		origin.x = rand_min_max(5, map->nb_case_x - size->x - 5);
		origin.y = rand_min_max(3, map->nb_case_y - size->y - 3);
		for (int x = origin.x; x < origin.x + size->x; x++)
			for (int y = origin.y; y < origin.y + size->y; y++)
				if (map->tab[x][y].type != WALL)
					test = true;
	}
	return (origin);
}

bool insert_water(map_t *map, size_t x, size_t y)
{
	bool tmp = false;

	for (char i = -1; i <= 1; i++)
		for (char j = -1; j <= 1; j++)
			if (map->tab[x + i][y + j].type == GROUND) {
				map->tab[x + i][y + j].type = WATER;
				tmp = true;
			}
	return (tmp);
}

bool insert_water_loop(map_t *map)
{
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			if (map->tab[i][j].type == WATER)
				if (insert_water(map, i, j)) {
					i--;
					j--;
				}
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			if (map->tab[i][j].type == GROUND)
				return (false);
	return (true);
}

sfVector2i path_map(map_t *map, size_t x, size_t y, ssize_t nx, ssize_t ny)
{
	bool tmp = false;
	ssize_t size_x = 0;
	ssize_t size_y = 0;

	for (; x + size_x > 0 && x + size_x < map->nb_case_x; size_x += nx) {
		for (; x + size_y > 0 && x + size_y < map->nb_case_y; size_y += ny) {
			if (map->tab[x + size_x][y + size_y].type == WALL && tmp == false)
				tmp = true;
			if (map->tab[x + size_x][y + size_y].type == GROUND && tmp == true)
				return ((sfVector2i){0, 0});
			if (map->tab[x + size_x][y + size_y].type == WATER && tmp == true)
				return ((sfVector2i){size_x, size_y});
			if (ny == 0)
				break;
		}
		if (nx == 0)
			break;
	}
	return ((sfVector2i){0, 0});
}

void set_origin(map_t *map)
{
	size_t origin_x = 0;
	size_t origin_y = 0;

	while (map->tab[origin_x][origin_y].type == WALL) {
		origin_x = rand() % map->nb_case_x;
		origin_y = rand() % map->nb_case_y;
	}
	map->tab[origin_x][origin_y].type = WATER;
}

void dig_path(map_t *map, sfVector2i size, size_t x, size_t y)
{
	size.x < 0 ? x += size.x : 0;
	size.x < 0 ? size.x = -size.x : 0;
	size.y < 0 ? y += size.y : 0;
	size.y < 0 ? size.y = -size.y : 0;
	for (size_t i = x; i <= x + size.x; i++)
		for (size_t j = y; j <= y + size.y; j++)
			map->tab[i][j].type = GROUND;
}

void linking_rooms(map_t *map)
{
	set_origin(map);
	for (size_t n = 0; n < 100000 && insert_water_loop(map) == false;) {
		size_t x = 0;
		size_t y = 0;
		sfVector2i size;

		while (map->tab[x][y].type != GROUND) {
			x = rand() % map->nb_case_x;
			y = rand() % map->nb_case_y;
		} if (rand() % 2)
			size = path_map(map, x, y, rand() % 2 ? 1 : -1, 0);
		else
			size = path_map(map, x, y, 0, rand() % 2 ? 1 : -1);
		size.x || size.y ? dig_path(map, size, x, y) : n++;
	} for (size_t i = 0; i < map->nb_case_x; i++)
		  for (size_t j = 0; j < map->nb_case_y; j++) {
			map->tab[i][j].type == WATER
				? map->tab[i][j].type = GROUND : 0;
			map_smooth(map, i, j);
		  }
}

void map_random(map_t *map)
{
	size_t area = map->nb_case_x * map->nb_case_y;
	size_t min = (area / 49) * 0.2;
	size_t max = (area / 49) * 0.3;
	size_t nb_room = rand_min_max(min, max);

	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			map->tab[i][j] = TVA(0, 0, 0);
	for (size_t num_room = 0; num_room < nb_room; num_room++) {
		sfVector2i size = {rand() % 5 + 5, rand() % 5 + 5};
		sfVector2i origin = take_origin(map, &size);;

		for (int i = origin.x; i < origin.x + size.x; i++)
			for (int j = origin.y; j < origin.y + size.y; j++)
				map->tab[i][j].type = GROUND;
	}
	linking_rooms(map);
	map_smooth_all(map);
}
