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
