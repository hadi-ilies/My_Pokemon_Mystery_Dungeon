/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** anime_tab_create_config_fd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "anime_tab.h"

anime_tab_t anime_tab_create_from_fd(int fd)
{
	anime_tab_t anime_tab = anime_tab_create();

	if (anime_tab.error != ANIME_TAB_OK)
		return (anime_tab);
	if (read(fd, &anime_tab.nb_texname, sizeof(size_t)) != sizeof(size_t)) {
		anime_tab.error = ANIME_TAB_READ;
		return (anime_tab);
	}
	if (anime_tab.nb_texname <= 0) {
		anime_tab.error = ANIME_TAB_INVALID_NUMBER;
		return (anime_tab);
	}
	anime_tab.texname = malloc(sizeof(texname_t) * anime_tab.nb_texname);
	if (anime_tab.texname == NULL) {
		anime_tab.error = ANIME_TAB_MALLOC;
		return (anime_tab);
	}
	for (size_t i = 0; i < anime_tab.nb_texname; i++) {
		size_t len = 0;

		if (read(fd, &len, sizeof(size_t)) != sizeof(size_t)) {
			anime_tab.error = ANIME_TAB_READ;
			return (anime_tab);
		}
		if (len <= 0) {
			anime_tab.error = ANIME_TAB_INVALID_NUMBER;
			return (anime_tab);
		}
		anime_tab.texname[i].file_name = malloc(sizeof(char) * (len + 1));
		if (anime_tab.texname[i].file_name == NULL) {
			anime_tab.error = ANIME_TAB_MALLOC;
			return (anime_tab);
		}
		if (read(fd, anime_tab.texname[i].file_name, sizeof(char) * len) != (int)(sizeof(char) * len)) {
			anime_tab.error = ANIME_TAB_READ;
			return (anime_tab);
		}
		anime_tab.texname[i].file_name[len] = '\0';
		anime_tab.texname[i].texture = sfTexture_createFromFile(anime_tab.texname[i].file_name, NULL);
		if (anime_tab.texname[i].texture == NULL) {
			anime_tab.error = ANIME_TAB_TEXTURE_CREATE;
			return (anime_tab);
		}
	}
	if (read(fd, &anime_tab.nb_anime, sizeof(size_t)) != sizeof(size_t)) {
		anime_tab.error = ANIME_TAB_READ;
		return (anime_tab);
	}
	if (anime_tab.nb_anime <= 0) {
		anime_tab.error = ANIME_TAB_INVALID_NUMBER;
		return (anime_tab);
	}
	anime_tab.anime = malloc(sizeof(anime_t) * anime_tab.nb_anime);
	if (anime_tab.anime == NULL) {
		anime_tab.error = ANIME_TAB_MALLOC;
		return (anime_tab);
	}
	for (size_t i = 0; i < anime_tab.nb_anime; i++) {
		if (read(fd, &anime_tab.anime[i].nb_rectex, sizeof(size_t)) != sizeof(size_t)) {
			anime_tab.error = ANIME_TAB_READ;
			return (anime_tab);
		}
		anime_tab.anime[i].rectex = malloc(sizeof(anime_t) * anime_tab.anime[i].nb_rectex);
		if (anime_tab.anime[i].rectex == NULL) {
			anime_tab.error = ANIME_TAB_MALLOC;
			return (anime_tab);
		}
		for (size_t j = 0; j < anime_tab.anime[i].nb_rectex; j++) {
			if (read(fd, &anime_tab.anime[i].rectex[j], sizeof(rectex_t)) != sizeof(rectex_t)) {
				anime_tab.error = ANIME_TAB_READ;
				return (anime_tab);
			}
			if (anime_tab.anime[i].rectex[j].texture_num >= anime_tab.nb_texname) {
				anime_tab.error = ANIME_TAB_INVALID_NUMBER;
				return (anime_tab);
			}
		}
		if (read(fd, &anime_tab.anime[i].time, sizeof(size_t)) != sizeof(size_t)) {
			anime_tab.error = ANIME_TAB_READ;
			return (anime_tab);
		}
		if (anime_tab.anime[i].time <= 0) {
			anime_tab.error = ANIME_TAB_INVALID_NUMBER;
			return (anime_tab);
		}
		anime_tab.anime[i].num = 0;
	}
	return (anime_tab);
}
