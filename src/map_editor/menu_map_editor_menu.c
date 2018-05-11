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

bool second_enter_editor(sfRenderWindow *window, menu_t *menu, map_t *map)
{
	if (menu->button == 1 && map->error != 84)
		menu_save_map(map, window);
	if (menu->button == 2)
		new_map(map, window);
	if (menu->button == 3)
		load_editor_loop(map, window);
	if (menu->button == 4 && map->error != 84)
		param_map(map, window);
	if (menu->button == 5) {
		sfMusic_play(menu->sound.sound_effect[1]);
		return (false);
	}
	return (true);
}

bool enter_editor(sfRenderWindow *window, menu_t *menu,
		sfEvent *event,	map_t *map)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyReturn) {
		sfMusic_play(menu->sound.sound_effect[0]);
		if (menu->button == 0 && map->error == ERR_OK) {
			sfMusic_pause(menu->sound.sound_effect[6]);
			map_editor_loop(window, map);
			sfMusic_play(menu->sound.sound_effect[6]);
		}
		if (!second_enter_editor(window, menu, map))
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

void menu_map_editor_menu(sfRenderWindow *window, sfMusic **sound_effect)
{
	map_t map = {.error = 84};
	loading_t back = back_editor_create(window);
	menu_t menu = menu_editor_create(sound_effect);
	sfVector2i tmp = {250, 5};

	load_font_editor(&menu);
	while (sfRenderWindow_isOpen(window)) {
		sfEvent event;

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
