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

int anime_editor_menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;
	anime_tab_t anime_tab;

	window = sfRenderWindow_create(mode, "Anime editor", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	anime_tab = anime_tab_create_from_file("resources/texture/anime_tab/gobou_config");
	if (anime_tab.error != ANIME_TAB_OK)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	anime_editor_loop(window, &anime_tab);
	save(&anime_tab, "resources/texture/anime_tab/gobou_config");
	anime_tab_destroy(&anime_tab);
	sfRenderWindow_destroy(window);
	return (0);
}
