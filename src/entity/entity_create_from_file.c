/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_create_from_file.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "entity.h"

entity_t entity_create_from_file(char *file_name)
{
	entity_t entity = entity_create();
	int fd = open(file_name, O_RDONLY);
	size_t len;

	if (entity.error != ERR_OK)
		return (entity);
	if (fd == -1)
		return (entity.error = ERR_OPEN, entity);
	if (read(fd, &entity.level, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.exp, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.life, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.type, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.type2, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	// capacity
	for (size_t i = 0; i < 4; i++)
		if (read(fd, &entity.pp[i], sizeof(size_t)) != sizeof(size_t))
			return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.ability, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.nature, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.ev, sizeof(stats_t)) != sizeof(stats_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.iv, sizeof(stats_t)) != sizeof(stats_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.boost, sizeof(stats_t)) != sizeof(stats_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.item, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.ia, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.dir, sizeof(sfVector2i)) != sizeof(sfVector2i))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.pos, sizeof(sfVector2i)) != sizeof(sfVector2i))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &len, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	entity.anime_tab_file_map = malloc(sizeof(char) * (len + 1));
	if (entity.anime_tab_file_map == NULL)
		return (entity.error = ERR_MALLOC, entity);
	if (read(fd, &entity.anime_tab_file_map, len) != (int)len)
		return (entity.error = ERR_READ, entity);
	entity.anime_tab_file_map[len] = '\0';
	entity.anime_tab = anime_tab_create_from_file(entity.anime_tab_file_map);
	if (entity.anime_tab.error != ERR_OK)
		return (entity.error = entity.anime_tab.error, entity);
	close(fd);
	return (entity);
}
