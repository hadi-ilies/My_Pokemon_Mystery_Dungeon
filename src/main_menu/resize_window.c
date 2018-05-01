/*
** EPITECH PROJECT, 2018
** resize_win
** File description:
** resize_win
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "option_map_editor.h"
#include "main_menu/option_menu.h"

void insert_win_size(sfText *win_size[3])
{
	sfText_setString(win_size[0], "800 X 600");
	sfText_setString(win_size[1], "1600 X 1200");
	sfText_setString(win_size[2], "1920 X 1080");
}

void change_win_size(option_t *option, sfEvent *event, sfRenderWindow *window)
{
	if (option->choice_curs == 0) {
		if (option->nb_tile < 2 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight)
			option->nb_tile++;
		if (option->nb_tile > 0 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft)
			option->nb_tile--;
	}
	sfText_setPosition(option->window_size[option->nb_tile],
		(sfVector2f) {WINDOW_SIZE.x / 2 + 50, WINDOW_SIZE.y / 2 - 300});
}

void resize_win(sfRenderWindow *window, option_t *option)
{
	if (option->choice_curs == 0) {
		char *str = (char *) GET_STRING_SIZE;
		char **size = my_str_to_tab(str, "X");
		sfRenderWindow_setSize(window,
		(sfVector2u) {atoi(size[0]), atoi(size[1])});
	}
}
