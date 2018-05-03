/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** anime_editor_menu.c
*/

#include <stdlib.h> //tmp
#include <unistd.h> //tmp
#include <fcntl.h> //tmp
#include "prototype.h"
#include "anime_tab.h"
#include "anime_name.h"

void save_anime_part1(anime_tab_t *anime_tab, char *file_name, int fd)
{
	if (fd == -1) {
		anime_tab->error = ERR_OPEN;
		return;
	}
	if (write(fd, &anime_tab->nb_texname, sizeof(size_t)) != sizeof(size_t)) {
		anime_tab->error = ERR_WRITE;
		return;
	}
}

void save_anime_part2(anime_tab_t *anime_tab, char *file_name, int fd)
{
	for (size_t i = 0; i < anime_tab->nb_texname; i++) {
		size_t len = 0;

		for (; anime_tab->texname[i].file_name[len] != '\0'; len++);
		if (write(fd, &len, sizeof(size_t)) != sizeof(size_t)) {
			anime_tab->error = ERR_WRITE;
			return;
		} if (write(fd, anime_tab->texname[i].file_name,
		sizeof(char) * len) != (ssize_t)(sizeof(char) * len)) {
			anime_tab->error = ERR_WRITE;
			return;
		}
	}
}

void save(anime_tab_t *anime_tab, char *file_name)
{
	int fd = CREAT(file_name, S_IRUSR | S_IWUSR | S_IRGRP);

	save_anime(anime_tab, file_name, fd);

	save_anime_part2(anime_tab, file_name, fd);
	if (write(fd, &anime_tab->nb_anime, sizeof(size_t)) != sizeof(size_t)) {
		anime_tab->error = ERR_WRITE;
		return;
	}
	for (size_t i = 0; i < anime_tab->nb_anime; i++) {
		if (write(fd, &anime_tab->anime[i].nb_rectex, sizeof(size_t)) != sizeof(size_t)) {
			anime_tab->error = ERR_WRITE;
			return;
		}
		for (size_t j = 0; j < anime_tab->anime[i].nb_rectex; j++)
			if (write(fd, &anime_tab->anime[i].rectex[j], sizeof(rectex_t)) != sizeof(rectex_t)) {
				anime_tab->error = ERR_WRITE;
				return;
			}
		if (write(fd, &anime_tab->anime[i].time, sizeof(size_t)) != sizeof(size_t)) {
			anime_tab->error = ERR_WRITE;
			return;
		}
	}
	close(fd);
}

void anime_tab_add_texture(anime_tab_t *anime_tab, char *file_name)
{
	texname_t *texname = malloc(sizeof(texname_t) * (anime_tab->nb_texname + 1));

	if (texname == NULL) {
		anime_tab->error = ERR_MALLOC;
		return;
	}
	for (size_t i = 0; i < anime_tab->nb_texname; i++)
		texname[i] = anime_tab->texname[i];
	texname[anime_tab->nb_texname].file_name = my_strdup(file_name);
	texname[anime_tab->nb_texname].texture = sfTexture_createFromFile(file_name, NULL);
	if (texname[anime_tab->nb_texname].texture == NULL) {
		anime_tab->error = ERR_TEXTURE_CREATE;
		return;
	}
	free(anime_tab->texname);
	anime_tab->texname = texname;
	anime_tab->nb_texname++;
}

int anime_editor_menu(sfRenderWindow *window)
{
	anime_tab_t anime_tab;

	/*anime_tab = anime_tab_create();
	if (anime_tab.error != ANIME_TAB_OK)
		return (84);
	anime_tab_add_texture(&anime_tab, "resources/texture/anime_tab/Insolourdo.png");
	anime_tab.nb_anime = ANIME_NB;
	anime_tab.anime = malloc(sizeof(anime_t) * anime_tab.nb_anime);
	if (anime_tab.anime == NULL)
		anime_tab.error = ANIME_TAB_MALLOC;
	for (size_t i = 0; i < anime_tab.nb_anime; i++) {
		anime_tab.anime[i].nb_rectex = 1;
		anime_tab.anime[i].rectex = malloc(sizeof(anime_t) * anime_tab.anime[i].nb_rectex);
		for (size_t j = 0; j < anime_tab.anime[i].nb_rectex; j++)
			anime_tab.anime[i].rectex[j] = (rectex_t){0, {0, 0, 0, 0}};
		anime_tab.anime[i].time = 500000;
		anime_tab.anime[i].num = 0;
		}*/
	anime_tab = anime_tab_create_from_file("resources/texture/anime_tab/gobou_config");
	if (anime_tab.error != ERR_OK)
		return (84);
	anime_editor_loop(window, &anime_tab);
	save(&anime_tab, "resources/texture/anime_tab/gobou_config");
	anime_tab_destroy(&anime_tab);
	return (0);
}
