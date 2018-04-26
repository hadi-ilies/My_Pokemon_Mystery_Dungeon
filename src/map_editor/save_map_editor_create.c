/*
** EPITECH PROJECT, 2018
** save_map_editor
** File description:
** save_map_editor
*/

#include <stdbool.h>
#include <stdio.h>
#include "my.h"
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_save.h"

void create_save_text(save_editor_t *save)
{
	save->font = sfFont_createFromFile(FONT);
	for (size_t i = 0; i < 4; i++) {
		save->text[i] = sfText_create();
		sfText_setFont(save->text[i], save->font);
	}
}

save_editor_t save_editor_create(sfRenderWindow *window)
{
	save_editor_t save;

	save.back = create_back_param(window);
	save.screen = create_screen_param(window);
	create_save_text(&save);
	save.choice_curs = 0;
	save.name_file = NULL;
	return (save);
}
