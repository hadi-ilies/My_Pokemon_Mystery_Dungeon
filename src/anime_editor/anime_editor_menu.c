/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** anime_editor_menu.c
*/

#include <stdlib.h> //tmp
#include <unistd.h> //tmp
#include <string.h> //tmp
#include <fcntl.h> //tmp
#include "prototype.h"
#include "anime_tab.h"
#include "anime_name.h"

void save(anime_tab_t *anime_tab, char *file_name)
{
	int fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU, S_IRWXU | S_IRWXG);

	if (fd == -1) {
		//map->error = MAP_OPEN;
		return;
	}
	if (write(fd, &anime_tab->nb_texture, sizeof(size_t)) != sizeof(size_t)) {
		//map->error = MAP_WRITE;
		return;
	}
	for (size_t i = 0; i < anime_tab->nb_texture; i++) {
		size_t len = 0;

		for (; anime_tab->texname[i].file_name[len] != '\0'; len++);
		if (write(fd, &len, sizeof(size_t)) != sizeof(size_t)) {
			//map->error = MAP_WRITE;
			return;
		}
		if (write(fd, anime_tab->texname[i].file_name, sizeof(char) * len) != (ssize_t)(sizeof(char) * len)) {
			//map->error = MAP_WRITE;
			return;
		}
	}
	if (write(fd, &anime_tab->nb_anime, sizeof(size_t)) != sizeof(size_t)) {
		//map->error = MAP_WRITE;
		return;
	}
	for (size_t i = 0; i < anime_tab->nb_anime; i++) {
		if (write(fd, &anime_tab->anime[i].nb_rectex, sizeof(size_t)) != sizeof(size_t)) {
			//map->error = MAP_WRITE;
			return;
		}
		for (size_t j = 0; j < anime_tab->anime[i].nb_rectex; j++)
			if (write(fd, &anime_tab->anime[i].rectex[j], sizeof(rectex_t)) != sizeof(rectex_t)) {
				//map->error = MAP_WRITE;
				return;
			}
		if (write(fd, &anime_tab->anime[i].time, sizeof(size_t)) != sizeof(size_t)) {
			//map->error = MAP_WRITE;
			return;
		}
	}
	close(fd);
}

void anime_tab_add_texture(anime_tab_t *anime_tab, char *file_name)
{
	texname_t *texname = malloc(sizeof(texname_t) * (anime_tab->nb_texture + 1));

	if (texname == NULL) {
		anime_tab->error = ANIME_TAB_MALLOC;
		return;
	}
	for (size_t i = 0; i < anime_tab->nb_texture; i++)
		texname[i] = anime_tab->texname[i];
	texname[anime_tab->nb_texture].file_name = strdup(file_name);
	texname[anime_tab->nb_texture].texture = sfTexture_createFromFile(file_name, NULL);
	if (texname[anime_tab->nb_texture].texture == NULL) {
		anime_tab->error = ANIME_TAB_TEXTURE_CREATE;
		return;
	}
	free(anime_tab->texname);
	anime_tab->texname = texname;
	anime_tab->nb_texture++;
}

int anime_editor_menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;
	anime_tab_t anime_tab;

	window = sfRenderWindow_create(mode, "Anime editor", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
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
	anime_tab = anime_tab_create_from_file("resources/texture/anime_tab/insolourdo_config");
	if (anime_tab.error != ANIME_TAB_OK)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	anime_editor_loop(window, &anime_tab);
	save(&anime_tab, "resources/texture/anime_tab/insolourdo_config");
	anime_tab_destroy(&anime_tab);
	sfRenderWindow_destroy(window);
	return (0);
}
