/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** anime_tab_create_config_file.c
*/

#include <unistd.h>
#include <fcntl.h>
#include "anime_tab.h"

anime_tab_t anime_tab_create_from_file(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	anime_tab_t anime_tab;

	if (fd == -1) {
		anime_tab = anime_tab_create();
		anime_tab.error = ERR_OPEN;
		return (anime_tab);
	}
	anime_tab = anime_tab_create_from_fd(fd);
	close(fd);
	return (anime_tab);
}
