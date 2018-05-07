/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** anime_tab_create_config_fd.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "anime_tab.h"
#include "my.h"

static bool anime_tab1(anime_tab_t *anime_tab, int fd)
{
	if (anime_tab->error != ERR_OK)
		return (false);
	if (read(fd, &anime_tab->nb_texname, sizeof(size_t)) != sizeof(size_t))
		return (anime_tab->error = ERR_READ, false);
	if (anime_tab->nb_texname <= 0)
		return (anime_tab->error = ERR_INVALID_NUMBER, false);
	anime_tab->texname = malloc(sizeof(texname_t) * anime_tab->nb_texname);
	if (anime_tab->texname == NULL)
		return (anime_tab->error = ERR_MALLOC, false);
	return (true);
}

static bool anime_tab2(anime_tab_t *anime_tab, int fd)
{
	for (size_t i = 0; i < anime_tab->nb_texname; i++) {
		size_t len = 0;

		if (read(fd, &len, sizeof(size_t)) != sizeof(size_t))
			return (anime_tab->error = ERR_READ, false);
		if (len <= 0)
			return (anime_tab->error = ERR_INVALID_NUMBER, false);
		anime_tab->texname[i].file_name = MALLOC_NAME;
		if (anime_tab->texname[i].file_name == NULL)
			return (anime_tab->error = ERR_MALLOC, false);
		if (READ(anime_tab->texname[i].file_name, (int) (sizeof(char)
								* len)))
			return (anime_tab->error = ERR_READ, false);
		anime_tab->texname[i].file_name[len] = '\0';
		anime_tab->texname[i].texture =
		sfTexture_createFromFile(anime_tab->texname[i].file_name, NULL);
		if (anime_tab->texname[i].texture == NULL)
			return (anime_tab->error = ERR_TEXTURE_CREATE, false);
	}
	return (true);
}

static bool anime_tab3(anime_tab_t *anime_tab, int fd, size_t i)
{
	if (READ(&anime_tab->anime[i].nb_rectex, sizeof(size_t)))
		return (anime_tab->error = ERR_READ, false);
	anime_tab->anime[i].rectex =
		malloc(sizeof(anime_t) * anime_tab->anime[i].nb_rectex);
	if (anime_tab->anime[i].rectex == NULL)
		return (anime_tab->error = ERR_MALLOC, false);
	for (size_t j = 0; j < anime_tab->anime[i].nb_rectex; j++) {
		if (READ(&anime_tab->anime[i].rectex[j], sizeof(rectex_t)))
			return (anime_tab->error = ERR_READ, false);
		if (anime_tab->anime[i].rectex[j].texture_num >=
		anime_tab->nb_texname)
			return (anime_tab->error = ERR_INVALID_NUMBER, false);
	} if (READ(&anime_tab->anime[i].time, sizeof(size_t)))
		return (anime_tab->error = ERR_READ, false);
	if (anime_tab->anime[i].time <= 0)
		return (anime_tab->error = ERR_INVALID_NUMBER, false);
	anime_tab->anime[i].num = 0;
	return (true);
}

anime_tab_t anime_tab_create_from_fd(int fd)
{
	anime_tab_t anime_tab = anime_tab_create();

	if (!anime_tab1(&anime_tab, fd) || !anime_tab2(&anime_tab, fd))
		return (anime_tab);
	if (read(fd, &anime_tab.nb_anime, sizeof(size_t)) != sizeof(size_t))
		return (anime_tab.error = ERR_READ, anime_tab);
	if (anime_tab.nb_anime <= 0)
		return (anime_tab.error = ERR_INVALID_NUMBER, anime_tab);
	anime_tab.anime = malloc(sizeof(anime_t) * anime_tab.nb_anime);
	if (anime_tab.anime == NULL)
		return (anime_tab.error = ERR_MALLOC, anime_tab);
	for (size_t i = 0; i < anime_tab.nb_anime; i++) {
		if (!anime_tab3(&anime_tab, fd, i))
			return (anime_tab);
	}
	return (anime_tab);
}
