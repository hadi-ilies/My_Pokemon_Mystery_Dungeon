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

#define TILEFILE concat("resources/tile_map/", \
			(char *) sfText_getString(option.text[option.nb_tile]))

typedef struct {
	sfText *choice[3];
	size_t choice_curs;
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

void move_curseur_option_editor(option_editor_t *option, sfEvent *event);
option_editor_t option_editor_create(sfRenderWindow *window, map_t *map);
void size_tile_map_x(sfEvent *event,
		sfRenderWindow *window, option_editor_t *option);
void size_tile_map_y(sfEvent *event,
		sfRenderWindow *window, option_editor_t *option);
void change_tile_map(sfRenderWindow *window,
		option_editor_t *option, sfEvent *event);
