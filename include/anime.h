/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** anime.h
*/

#ifndef ANIME_H_
#define ANIME_H_

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdbool.h>
#include "image.h"

typedef struct {
	size_t time;
	sfClock *clock;
	size_t nb_image;
	image_t *image;
	size_t num;
} anime_t;

anime_t anime_create(size_t nb_image);
anime_t anime_create_from_file(char *file_name);
anime_t anime_create_from_fd(int fd);
void anime_destroy(anime_t *anime);
void anime_aff(sfRenderWindow *window, anime_t *anime, sfFloatRect rect);
bool anime_error(anime_t *anime);

#endif
