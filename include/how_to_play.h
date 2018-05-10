/*
** EPITECH PROJECT, 2018
** how to play
** File description:
** how to play
*/

#pragma once

#include "my.h"
#include "prototype.h"

#define NB_PAGE 4
#define TUTO1 "resources/tuto/tuto1.png"
#define TUTO2 "resources/tuto/tuto2.png"
#define TUTO3 "resources/tuto/tuto3.png"
#define TUTO4 "resources/tuto/tuto4.png"

typedef struct {
	size_t page;
	bool tex;
	sfSprite *img;
	sfTexture *textu[NB_PAGE];
} how_to_play_t;

how_to_play_t create_tuto(sfRenderWindow *window);
