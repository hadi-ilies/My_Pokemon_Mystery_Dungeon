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
	int fd = open(file_name, O_RDONLY);
	entity_t entity;

	if (fd == -1)
		return (entity.error = ERR_OPEN, entity);
	entity = entity_create_from_fd(fd);
	close(fd);
	return (entity);
}
