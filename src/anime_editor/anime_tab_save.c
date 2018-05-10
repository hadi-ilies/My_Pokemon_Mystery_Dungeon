/*
** EPITECH PROJECT, 2018
** save
** File description:
** save
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "macro.h"
#include "prototype.h"
#include "anime_tab.h"
#include "anime_name.h"

static void save_anime_part1(anime_tab_t *anime_tab, int fd)
{
	if (fd == -1) {
		anime_tab->error = ERR_OPEN;
		return;
	}
	if (write(fd, &anime_tab->nb_texname, SIZE_T) != SIZE_T) {
		anime_tab->error = ERR_WRITE;
		return;
	}
}

static void save_anime_part2(anime_tab_t *anime_tab, int fd)
{
	for (size_t i = 0; i < anime_tab->nb_texname; i++) {
		size_t len = 0;

		for (; anime_tab->texname[i].file_name[len] != '\0'; len++);
		if (write(fd, &len, SIZE_T) != SIZE_T) {
			anime_tab->error = ERR_WRITE;
			return;
		} if (write(fd, anime_tab->texname[i].file_name,
		sizeof(char) * len) != (ssize_t)(sizeof(char) * len)) {
			anime_tab->error = ERR_WRITE;
			return;
		}
	}
}

static void save_anime_part3(anime_tab_t *anime_tab, int fd, size_t i)
{
	if (write(fd, &anime_tab->anime[i].nb_rectex, SIZE_T) != SIZE_T) {
		anime_tab->error = ERR_WRITE;
		return;
	} for (size_t j = 0; j < anime_tab->anime[i].nb_rectex; j++)
		if (write(fd, &anime_tab->anime[i].rectex[j],
			RECTEX_T) != RECTEX_T) {
			anime_tab->error = ERR_WRITE;
			return;
		}
	if (write(fd, &anime_tab->anime[i].time, SIZE_T) != SIZE_T) {
		anime_tab->error = ERR_WRITE;
		return;
	}
}

void anime_tab_save(anime_tab_t *anime_tab, char *file_name)
{
	int fd = CREAT(file_name, S_IRUSR | S_IWUSR | S_IRGRP);

	save_anime_part1(anime_tab, fd);
	save_anime_part2(anime_tab, fd);
	if (write(fd, &anime_tab->nb_anime, SIZE_T) != SIZE_T) {
		anime_tab->error = ERR_WRITE;
		return;
	} for (size_t i = 0; i < anime_tab->nb_anime; i++)
		save_anime_part3(anime_tab, fd, i);
	close(fd);
}
