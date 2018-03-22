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
#include <stdbool.h>
#include "anime.h"

typedef struct {
	size_t nb_anime;
	anime_t *anime;
	size_t num;
} anime_tab_t;

anime_tab_t anime_tab_create(size_t nb_anime);
anime_tab_t anime_tab_create_from_file(char *file_name);
void anime_tab_destroy(anime_tab_t *anime_tab);
void anime_tab_aff(sfRenderWindow *window, anime_tab_t *anime_tab,
		   sfFloatRect rect);
bool anime_tab_error(anime_tab_t *anime_tab);

#endif
