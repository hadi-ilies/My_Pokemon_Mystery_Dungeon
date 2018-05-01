/*
** EPITECH PROJECT, 2018
** load.h
** File description:
** load.h
*/

#include "prototype.h"
#pragma once

typedef struct {
	sfText *choice[2];
	sfRectangleShape *back;
	sfText **text;
	sfFont *font;
	sfSprite *screen;
	size_t choice_curs;
	size_t text_curs;
	char *name_file;
}load_editor_t;

void load_choice_cursor(load_editor_t *load, sfRenderWindow *window);
void move_curseur_load_editor(load_editor_t *load, sfEvent *event);
void load_list_choice_cursor(load_editor_t *load, sfRenderWindow *window);
void load_list_choice_min(load_editor_t *load, sfRenderWindow *window);
void move_curseur_load_list(load_editor_t *load, sfEvent *event);
