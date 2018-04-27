/*
** EPITECH PROJECT, 2018
** load.h
** File description:
** load.h
*/

#include "prototype.h"
#pragma once

typedef struct {
	sfRectangleShape *back;
	sfText **text;
	sfFont *font;
	sfSprite *screen;
	int choice_curs;
	char *name_file;
}load_editor_t;
