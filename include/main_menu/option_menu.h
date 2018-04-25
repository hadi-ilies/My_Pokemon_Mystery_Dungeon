/*
** EPITECH PROJECT, 2018
** option
** File description:
** option
*/

#pragma once

#include <SFML/Graphics.h>
#include <prototype.h>
#include <my.h>

typedef struct {
	sfText *choice[3];
	size_t choice_curs;
	sfText *window_size[3];
	sfFont *font;
	sfSprite *screen;
	sfRectangleShape *back;
	size_t nb_tile;
	size_t size_x;
	size_t size_y;
} option_t;
