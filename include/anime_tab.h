/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** anime_tab.h
*/

#ifndef ANIME_TAB_H_
#define ANIME_TAB_H_

#include <SFML/Graphics.h>
#include <stddef.h>
#include "rectex.h"

enum anime_tab_error {
	ANIME_TAB_OK,
	ANIME_TAB_CLOCK_CREATE,
	ANIME_TAB_TEXTURE_CREATE,
	ANIME_TAB_SPRITE_CREATE,
	ANIME_TAB_OPEN,
	ANIME_TAB_READ,
	ANIME_TAB_MALLOC,
	ANIME_TAB_INVALID_NUMBER
};

typedef struct {
	size_t nb_rectex;
	rectex_t *rectex;
	size_t time;
	size_t num;
} anime_t;

typedef struct {
	size_t nb_texture;
	sfTexture **texture;
	size_t nb_anime;
	anime_t *anime;
	sfClock *clock;
	sfSprite *sprite;
	size_t num;
	size_t error;
} anime_tab_t;

anime_tab_t anime_tab_create(void);
anime_tab_t anime_tab_create_from_fd(int fd);
anime_tab_t anime_tab_create_from_file(char *file_name);
void anime_tab_destroy(anime_tab_t *anime_tab);
void anime_tab_aff(sfRenderWindow *window, anime_tab_t *anime_tab,
		   sfFloatRect rect);

#endif
