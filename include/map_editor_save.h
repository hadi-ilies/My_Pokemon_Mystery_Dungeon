/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#pragma once

typedef struct {
	sfRectangleShape *back;
	sfText *text[4];
	sfFont *font;
	sfSprite *screen;
	int choice_curs;
	char *name_file;
} save_editor_t;
