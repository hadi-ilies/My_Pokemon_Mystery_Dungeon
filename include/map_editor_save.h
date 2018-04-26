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

void write_name(sfEvent *event, save_editor_t *save);
save_editor_t save_editor_create(sfRenderWindow *window);
void choice_cursor_save(save_editor_t *save, sfRenderWindow *window);
void move_curseur_save_editor(save_editor_t *save, sfEvent *event);
void take_keyboard(save_editor_t *save, sfEvent *event,
		sfRenderWindow *window);
void ok_map(save_editor_t *save, sfEvent *event, map_t *map);
