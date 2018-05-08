/*
** EPITECH PROJECT, 2018
** param
** File description:
** param
*/

#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include "prototype.h"
#include "my.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"
#include "option_map_editor.h"

void change_tile_map(sfRenderWindow *window,
		option_editor_t *option, sfEvent *event)
{
	size_t nb_filename =  count_file(TILE_MAP);
	char **filename = take_filename(TILE_MAP);

	for (size_t i = 0; i < nb_filename; i++)
		sfText_setString(option->text[i], filename[i]);
	if (option->choice_curs == 0) {
		if (option->nb_tile < nb_filename - 1
		&& event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight)
			option->nb_tile++;
		if (option->nb_tile > 0 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft)
			option->nb_tile--;
	}
	sfText_setPosition(option->text[option->nb_tile],
	V2F(WINDOW_SIZE.x / 2 - 150, WINDOW_SIZE.y / 2 - 300));
}

void size_tile_map_y(sfEvent *event,
		sfRenderWindow *window, option_editor_t *option)
{
	char *str;

	if (option->choice_curs == 1) {
		if (option->size_y < 999 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight) {
			option->size_y++;
		} if (option->size_y > 30 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft) {
		option->size_y--;
		}
	}
	str = inttostr(option->size_y);
	sfText_setString(option->size_map_y, str);
	sfText_setPosition(option->size_map_y,
	V2F(WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2 - 200));
	free(str);
}

void size_tile_map_x(sfEvent *event,
		sfRenderWindow *window, option_editor_t *option)
{
	char *str;

	if (option->choice_curs == 2) {
		if (option->size_x < 999 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight) {
			option->size_x++;
		} if (option->size_x > 30 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft) {
			option->size_x--;
		}
	}
	str = inttostr(option->size_x);
	sfText_setString(option->size_map_x, str);
	sfText_setPosition(option->size_map_x,
	V2F(WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2 - 100));
	free(str);
}
