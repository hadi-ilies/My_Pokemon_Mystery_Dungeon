/*
** EPITECH PROJECT, 2018
** how to play
** File description:
** how to play
*/

#pragma once

#include "my.h"
#include "prototype.h"

#define NB_PAGE 3

typedef struct {
	size_t page;
	bool tex;
	sfSprite *img;
	sfTexture *textu[NB_PAGE];
} how_to_play_t;

how_to_play_t create_tuto(sfRenderWindow *window);
