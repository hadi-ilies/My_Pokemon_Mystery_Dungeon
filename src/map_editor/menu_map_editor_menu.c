/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"

bool enter_editor(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
	if (menu->button == 0 && event->key.code == sfKeyReturn) {
		printf("save\n");
	} if (menu->button == 1 && event->key.code == sfKeyReturn) {
		map_editor_menu(window);
	} if (menu->button == 2 && event->key.code == sfKeyReturn) {
		printf("load\n");
	} if (menu->button == 3 && event->key.code == sfKeyReturn) {
		printf("options\n");
	} if (menu->button == 4 && event->key.code == sfKeyReturn) {
		return (false);
	}
	return (true);
}

void menu_map_editor_menu(sfRenderWindow *window)
{
	sfEvent event;
	loading_t back = back_editor_create(window);
	menu_t menu = menu_editor_create();
	int tmp1 = 250;
	int tmp2 = 5;

	for (int i = 0; i < NB_BUTTON_EDITOR; i++)
		sfText_setFont(menu.text[i], menu.font);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			menu.button = move_curseur_editor(&menu, &event);
			if (enter_editor(window, &menu, &event) == false)
				return;
		}
		trans_cursor_editor(&menu, &tmp1, &tmp2);
		sfRenderWindow_clear(window, sfBlack);
		display_menu_editor(window, &menu, &back);
		sfRenderWindow_display(window);
	}
}
