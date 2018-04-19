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

void launch_map(map_t *map, sfRenderWindow *window)
{
	//map_random(map);
	map_editor_loop(window, map);
	map_save(map, "map_test");
}

bool enter_editor(sfRenderWindow *window, menu_t *menu, sfEvent *event,	map_t *map)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyReturn) {
		if (menu->button == 0) {
			launch_map(map, window);
		} if (menu->button == 1) {
			//fonction pour cree file "maptest"
			map_save(map, "map_test");
			printf("save\n");
		} if (menu->button == 2) {
			printf("load\n");
		} if (menu->button == 3) {
			param_map(menu, map, window);
			printf("options\n");
		} if (menu->button == 4) {
			return (false);
		}
	}
	return (true);
}

void load_font_editor(menu_t *menu)
{
	for (int i = 0; i < NB_BUTTON_EDITOR; i++)
		sfText_setFont(menu->text[i], menu->font);
}

int load_the_map(map_t *map, tile_map_t *tile_map)
{
	*map = map_load("map_test");
	if (map->error != MAP_OK)
		return (84);
	*tile_map = tile_map_create_from_file("resources/tile_map/Deep_cavern config");
	map->tile_map = tile_map;
	map->size.x = 100;
	map->size.y = map->size.x;
	map->pos.x = map->nb_case_x / 2;
	map->pos.y = map->nb_case_y / 2;
	return (0);
}

void menu_map_editor_menu(sfRenderWindow *window)
{
	map_t map;
	sfEvent event;
	loading_t back = back_editor_create(window);
	menu_t menu = menu_editor_create();
	int tmp1 = 250;
	int tmp2 = 5;

	load_font_editor(&menu);
	if (load_the_map(&map, &menu.tile_map[0]) == 84)//
		return;//tmp
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			menu.button = move_curseur_editor(&menu, &event);
			if (enter_editor(window, &menu, &event, &map) == false)
				return;
		}
		trans_cursor_editor(&menu, &tmp1, &tmp2);
		sfRenderWindow_clear(window, sfBlack);
		display_menu_editor(window, &menu, &back);
		sfRenderWindow_display(window);
	}
	map_destroy(&map);
	//tile_map_destroy(&menutile_map);
}
