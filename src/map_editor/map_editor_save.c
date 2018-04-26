/*
** EPITECH PROJECT, 2018
** map_editor_save
** File description:
** map_editor_save
*/

#include <stdbool.h>
#include <stdio.h>
#include "my.h"
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_save.h"

void display_save_editor(save_editor_t *save, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, save->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, save->back, NULL);
	choice_cursor_save(save, window);
	sfRenderWindow_drawText(window, save->text[3], NULL);
}

void menu_save_map(map_t *map, sfRenderWindow *window)
{
	sfEvent event;
	save_editor_t save = save_editor_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
			move_curseur_save_editor(&save, &event);
			take_keyboard(&save, &event, window);
			ok_map(&save, &event, map);
		}
		sfRenderWindow_clear(window, sfBlack);
		display_save_editor(&save, window);
		sfRenderWindow_display(window);
	}
}
