/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_create_from_fd.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "tile_map.h"
#include "my.h"

static bool error_map(tile_map_t *tile_map, int fd)
{
	if (tile_map->error != ERR_OK)
		return (false);
	if (read(fd, &tile_map->nb_texture, sizeof(size_t)) != sizeof(size_t)) {
		tile_map->error = ERR_READ;
		return (false);
	} if (tile_map->nb_texture <= 0) {
		tile_map->error = ERR_INVALID_NUMBER;
		return (false);
	}
	tile_map->texture = malloc(sizeof(sfTexture *) * tile_map->nb_texture);
	if (tile_map->texture == NULL) {
		tile_map->error = ERR_MALLOC;
		return (false);
	}
	return (true);
}

static bool error_map2(tile_map_t *tile_map, int fd)
{
	for (size_t i = 0; i < tile_map->nb_texture; i++) {
		size_t len = 0;
		char *file_nam;

		if (read(fd, &len, sizeof(size_t)) != sizeof(size_t))
			return (tile_map->error = ERR_READ, false);
		if (len <= 0)
			return (tile_map->error = ERR_INVALID_NUMBER, false);
		file_nam = malloc(sizeof(char) * (len + 1));
		if (file_nam == NULL)
			return (tile_map->error = ERR_MALLOC, false);
		if (READ(file_nam, (int)(sizeof(char) * len)))
			return (tile_map->error = ERR_READ, false);
		file_nam[len] = '\0';
		tile_map->texture[i] = sfTexture_createFromFile(file_nam, NULL);
		if (tile_map->texture[i] == NULL)
			return (tile_map->error = ERR_TEXTURE_CREATE, false);
		free(file_nam);
	}
	return (true);
}

static bool error_map3(tile_map_t *tile_map, int fd)
{
	if (read(fd, &tile_map->nb_type, sizeof(size_t)) != sizeof(size_t))
		return (tile_map->error = ERR_READ, false);
	if (tile_map->nb_type <= 0)
		return (tile_map->error = ERR_INVALID_NUMBER, false);
	tile_map->nb_var = malloc(sizeof(size_t) * tile_map->nb_type);
	tile_map->nb_alt = malloc(sizeof(size_t *) * tile_map->nb_type);
	tile_map->rectex = malloc(sizeof(rectex_t **) * tile_map->nb_type);
	if (tile_map->nb_var == NULL || tile_map->nb_alt == NULL
	|| tile_map->rectex == NULL)
		return (tile_map->error = ERR_MALLOC, false);
	return (true);
}

static bool error_map4(tile_map_t *tile_map, int fd, size_t i)
{
	if (read(fd, &tile_map->nb_var[i], sizeof(size_t)) != sizeof(size_t))
		return (tile_map->error = ERR_READ, false);
	if (tile_map->nb_var[i] <= 0)
		return (tile_map->error = ERR_INVALID_NUMBER, false);
	tile_map->nb_alt[i] = malloc(sizeof(size_t) * tile_map->nb_var[i]);
	tile_map->rectex[i] = malloc(sizeof(rectex_t *) * tile_map->nb_var[i]);
	if (tile_map->nb_alt[i] == NULL || tile_map->rectex[i] == NULL)
		return (tile_map->error = ERR_MALLOC, false);
	return (true);
}

tile_map_t tile_map_create_from_fd(int fd)
{
	tile_map_t tile_map = tile_map_create();

	if (!error_map(&tile_map, fd) || !error_map2(&tile_map, fd)
	|| !error_map3(&tile_map, fd))
		return (tile_map);
	for (size_t i = 0; i < tile_map.nb_type; i++) {
		if (!error_map4(&tile_map, fd, i)
		|| !error_map5(&tile_map, fd, i))
			return (tile_map);
	}
	return (tile_map);
}
