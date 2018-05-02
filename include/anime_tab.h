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
#include "error.h"

#ifndef RECTEX_T_
#define RECTEX_T_

typedef struct {
	size_t texture_num;
	sfIntRect rect;
} rectex_t;

#endif

typedef struct {
	char *file_name;
	sfTexture *texture;
} texname_t;

typedef struct {
	size_t nb_rectex;
	rectex_t *rectex;
	size_t time;
	size_t num;
} anime_t;

typedef struct {
	size_t nb_texname;
	texname_t *texname;
	size_t nb_anime;
	anime_t *anime;
	sfClock *clock;
	sfSprite *sprite;
	size_t num;
	enum error_e error;
} anime_tab_t;

anime_tab_t anime_tab_create(void);
anime_tab_t anime_tab_create_from_fd(int fd);
anime_tab_t anime_tab_create_from_file(char *file_name);
anime_tab_t anime_tab_copy(anime_tab_t *anime_tab);
void anime_tab_destroy(anime_tab_t *anime_tab);
void anime_tab_aff(sfRenderWindow *window, anime_tab_t *anime_tab,
		   sfFloatRect rect);

#endif
