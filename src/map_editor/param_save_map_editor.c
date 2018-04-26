/*
** EPITECH PROJECT, 2018
** save
** File description:
** save
*/

#include <string.h>///tmp
#include <stdbool.h>
#include <stdio.h>
#include "my.h"
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_save.h"

void take_keyboard(save_editor_t *save, sfEvent *event, sfRenderWindow *window)
{
	if (save->choice_curs == 0) {
		write_name(event, save);
	}
	sfText_setString(save->text[3], save->name_file);
	sfText_setPosition(save->text[3],
			(sfVector2f) {WINDOW_SIZE.x / 2 - 150, WINDOW_SIZE.y / 2 - 300});
}

void ok_map(save_editor_t *save, sfEvent *event, map_t *map)
{
	char *str;

	if (save->choice_curs == 1 && event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyReturn) {
		str = concat("resources/maps/", save->name_file);
		map_save(map, str);
	}
}
