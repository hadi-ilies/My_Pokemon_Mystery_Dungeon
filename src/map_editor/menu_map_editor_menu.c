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

bool enter_editor(sfRenderWindow *window, menu_t *menu,
		sfEvent *event,	map_t *map)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyReturn) {
		if (menu->button == 0 && map->error == ERR_OK)
			map_editor_loop(window, map);
		if (menu->button == 1 && map->error != 84)
			menu_save_map(map, window);
		if (menu->button == 2)
			new_map(menu, map, window);
		if (menu->button == 3)
			load_editor_loop(menu, map, window);
		if (menu->button == 4 && map->error != 84)
			param_map(menu, map, window);
		if (menu->button == 5)
			return (false);
	}
	return (true);
}

void load_font_editor(menu_t *menu)
{
	for (int i = 0; i < NB_BUTTON_EDITOR; i++)
		sfText_setFont(menu->text[i], menu->font);
}

void window_open_menu_editor(sfVector2i *tmp, menu_t *menu,
			sfRenderWindow *window, loading_t *back)
{
	trans_cursor_editor(menu, &tmp->x, &tmp->y);
	sfRenderWindow_clear(window, sfBlack);
	display_menu_editor(window, menu, back);
	sfRenderWindow_display(window);
}

void menu_map_editor_menu(sfRenderWindow *window)
{
	map_t map = {.error = 84};
	sfEvent event;
	loading_t back = back_editor_create(window);
	menu_t menu = menu_editor_create();
	sfVector2i tmp = {250, 5};

	load_font_editor(&menu);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			menu.button = move_curseur_editor(&menu, &event);
			if (enter_editor(window, &menu, &event, &map) == false)
				return;
		}
		window_open_menu_editor(&tmp, &menu, window, &back);
	}
	map_destroy(&map);
}
