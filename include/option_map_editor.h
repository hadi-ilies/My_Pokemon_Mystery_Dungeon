/*
** EPITECH PROJECT, 2018
** option
** File description:
** option
*/

#pragma once

#include "SFML/Graphics.h"

typedef struct {
	sfText **text;
	sfFont *font;
	sfText *size_map_x;
	sfText *size_map_y;
	sfSprite *screen;
	sfRectangleShape *back;
	size_t nb_tile;
	size_t size_x;
	size_t size_y;
} option_editor_t;
