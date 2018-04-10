/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** map_editor_menu.c
*/

#include <stdlib.h> //tmp
#include "prototype.h"

int map_editor_menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;
	map_t map;
	tile_map_t tile_map;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	map = map_load("map_test");
	if (map.error != MAP_OK)
	  return (84);
	tile_map = tile_map_create_from_file("resources/texture/tile_map/grassy_config");
	map.tile_map = &tile_map;

	map.size.x = 100;
	map.size.y = map.size.x;
	map.pos.x = map.nb_case_x / 2;
	map.pos.y = map.nb_case_y / 2;
	map_editor_loop(window, &map);
	map_save(&map, "map_test");
	map_destroy(&map);
	tile_map_destroy(&tile_map);
	sfRenderWindow_destroy(window);
	return (0);
}
