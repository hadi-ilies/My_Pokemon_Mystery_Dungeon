/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_create_from_fd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "tile_map.h"

tile_map_t tile_map_create_from_fd(int fd)
{
	tile_map_t tile_map = tile_map_create();

	if (tile_map.error != TILE_MAP_OK)
		return (tile_map);
	if (read(fd, &tile_map.nb_texture, sizeof(size_t)) != sizeof(size_t)) {
		tile_map.error = TILE_MAP_READ;
		return (tile_map);
	}
	if (tile_map.nb_texture <= 0) {
		tile_map.error = TILE_MAP_INVALID_NUMBER;
		return (tile_map);
	}
	tile_map.texture = malloc(sizeof(sfTexture *) * tile_map.nb_texture);
	if (tile_map.texture == NULL) {
		tile_map.error = TILE_MAP_MALLOC;
		return (tile_map);
	}
	for (size_t i = 0; i < tile_map.nb_texture; i++) {
		size_t len = 0;
		char *file_name;

		if (read(fd, &len, sizeof(size_t)) != sizeof(size_t)) {
			tile_map.error = TILE_MAP_READ;
			return (tile_map);
		}
		if (len <= 0) {
			tile_map.error = TILE_MAP_INVALID_NUMBER;
			return (tile_map);
		}
		file_name = malloc(sizeof(char) * (len + 1));
		if (file_name == NULL) {
			tile_map.error = TILE_MAP_MALLOC;
			return (tile_map);
		}
		if (read(fd, file_name, sizeof(char) * len) != (int)(sizeof(char) * len)) {
			tile_map.error = TILE_MAP_READ;
			return (tile_map);
		}
		file_name[len] = '\0';
		tile_map.texture[i] = sfTexture_createFromFile(file_name, NULL);
		if (tile_map.texture[i] == NULL) {
			tile_map.error = TILE_MAP_TEXTURE_CREATE;
			return (tile_map);
		}
		free(file_name);
	}
	if (read(fd, &tile_map.nb_type, sizeof(size_t)) != sizeof(size_t)) {
		tile_map.error = TILE_MAP_READ;
		return (tile_map);
	}
	if (tile_map.nb_type <= 0) {
		tile_map.error = TILE_MAP_INVALID_NUMBER;
		return (tile_map);
	}
	tile_map.nb_var = malloc(sizeof(size_t) * tile_map.nb_type);
	tile_map.nb_alt = malloc(sizeof(size_t *) * tile_map.nb_type);
	tile_map.rectex = malloc(sizeof(rectex_t **) * tile_map.nb_type);
	if (tile_map.nb_var == NULL || tile_map.nb_alt == NULL || tile_map.rectex == NULL) {
		tile_map.error = TILE_MAP_MALLOC;
		return (tile_map);
	}
	for (size_t i = 0; i < tile_map.nb_type; i++) {
		if (read(fd, &tile_map.nb_var[i], sizeof(size_t)) != sizeof(size_t)) {
			tile_map.error = TILE_MAP_READ;
			return (tile_map);
		}
		if (tile_map.nb_var[i] <= 0) {
			tile_map.error = TILE_MAP_INVALID_NUMBER;
			return (tile_map);
		}
		tile_map.nb_alt[i] = malloc(sizeof(size_t) * tile_map.nb_var[i]);
		tile_map.rectex[i] = malloc(sizeof(rectex_t *) * tile_map.nb_var[i]);
		if (tile_map.nb_alt[i] == NULL || tile_map.rectex[i] == NULL) {
			tile_map.error = TILE_MAP_MALLOC;
			return (tile_map);
		}
		for (size_t j = 0; j < tile_map.nb_var[i]; j++) {
			if (read(fd, &tile_map.nb_alt[i][j], sizeof(size_t)) != sizeof(size_t)) {
				tile_map.error = TILE_MAP_READ;
				return (tile_map);
			}
			if (tile_map.nb_alt[i][j] <= 0) {
				tile_map.error = TILE_MAP_INVALID_NUMBER;
				return (tile_map);
			}
			tile_map.rectex[i][j] = malloc(sizeof(rectex_t) * tile_map.nb_alt[i][j]);
			if (tile_map.rectex[i][j] == NULL) {
				tile_map.error = TILE_MAP_MALLOC;
				return (tile_map);
			}
			for (size_t k = 0; k < tile_map.nb_alt[i][j]; k++) {
				if (read(fd, &tile_map.rectex[i][j][k], sizeof(rectex_t)) != sizeof(rectex_t)) {
					tile_map.error = TILE_MAP_READ;
					return (tile_map);
				}
				if (tile_map.rectex[i][j][k].texture_num >= tile_map.nb_texture) {
					tile_map.error = TILE_MAP_INVALID_NUMBER;
					return (tile_map);
				}
			}
		}
	}
	return (tile_map);
}
