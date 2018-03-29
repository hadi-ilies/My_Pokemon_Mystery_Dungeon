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
	//map = map_load("map_test");
	map = map_create(5, 5);
	for (size_t i = 0; i < map.nb_case_x; i++)
		for (size_t j = 0; j < map.nb_case_y; j++) {
			map.tab[i][j].type = 0;
			map.tab[i][j].var = 4;
			map.tab[i][j].alt = 0;
		}//*/
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
