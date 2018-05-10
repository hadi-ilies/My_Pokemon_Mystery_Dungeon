/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_save.c
*/

#include <unistd.h>
#include <fcntl.h>
#include "entity.h"
#include "my.h"

static void write_entity(entity_t *entity, int fd)
{
	if (write(fd, &entity->level, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->exp, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->life, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->type, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->type2, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	for (size_t i = 0; i < 4; i++)
		if (write(fd, &entity->capacity_num[i], sizeof(size_t))
		!= sizeof(size_t))
			entity->error = ERR_WRITE;
	for (size_t i = 0; i < 4; i++)
		if (write(fd, &entity->pp[i], sizeof(size_t)) != sizeof(size_t))
			entity->error = ERR_WRITE;
}

static void write_entity_2(entity_t *entity, int fd, size_t len)
{
	if (write(fd, &entity->ability, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->nature, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->base_stat, sizeof(stats_t)) != sizeof(stats_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->ev, sizeof(stats_t)) != sizeof(stats_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->iv, sizeof(stats_t)) != sizeof(stats_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->boost, sizeof(stats_t)) != sizeof(stats_t))
		entity->error = ERR_WRITE;
	if (write(fd, &entity->item, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	if (write(fd, &len, sizeof(size_t)) != sizeof(size_t))
		entity->error = ERR_WRITE;
	if (write(fd, entity->anime_tab_file_name, len) != (int)len)
		entity->error = ERR_WRITE;
}

void entity_save(entity_t *entity, char *file_name)
{
	int fd = CREAT(file_name, S_IRUSR | S_IWUSR | S_IRGRP);
	size_t len = my_strlen(entity->anime_tab_file_name);

	if (fd == -1) {
		entity->error = ERR_OPEN;
		return;
	}
	write_entity(entity, fd);
	write_entity_2(entity, fd, len);
	close(fd);
}
