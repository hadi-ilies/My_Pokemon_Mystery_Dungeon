/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** settings_save.c
*/

#include <fcntl.h>
#include "settings.h"
#include "my.h"

void settings_save(settings_t *settings, char *file_name)
{
	int fd = CREAT(file_name, S_IRUSR | S_IWUSR | S_IRGRP);

	if (fd == -1)
		return;
	if (settings == NULL)
		*settings = settings_defaut();
	//
	close(fd);
}
