/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_create_from_fd.c
*/

#include <unistd.h>
#include "entity.h"
#include "capacity_tab.h"

entity_t entity_create_from_fd(int fd)
{
	entity_t entity = entity_create();
	size_t len;

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
	for (size_t i = 0; i < 4; i++)
		if (read(fd, &entity.capacity_num[i], sizeof(size_t)) != sizeof(size_t))
			return (entity.error = ERR_READ, entity);
	for (size_t i = 0; i < 4; i++)
		if (read(fd, &entity.pp[i], sizeof(size_t)) != sizeof(size_t))
			return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.ability, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.nature, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	if (read(fd, &entity.base_stat, sizeof(stats_t)) != sizeof(stats_t))
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
	if (read(fd, &len, sizeof(size_t)) != sizeof(size_t))
		return (entity.error = ERR_READ, entity);
	entity.anime_tab_file_name = malloc(sizeof(char) * (len + 1));
	if (entity.anime_tab_file_name == NULL)
		return (entity.error = ERR_MALLOC, entity);
	if (read(fd, entity.anime_tab_file_name, len) != (int)len)
		return (entity.error = ERR_READ, entity);
	entity.anime_tab_file_name[len] = '\0';
	entity.anime_tab = anime_tab_create_from_file(entity.anime_tab_file_name);
	if (entity.anime_tab.error != ERR_OK)
		return (entity.error = entity.anime_tab.error, entity);
	return (entity);
}
