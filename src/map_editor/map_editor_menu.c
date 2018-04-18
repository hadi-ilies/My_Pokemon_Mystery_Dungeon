/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** map_editor_menu.c
*/

#include <stdlib.h> //tmp
#include "prototype.h"

int map_editor_menu(sfRenderWindow *window)
{
	map_t map;
	tile_map_t tile_map;

	map = map_load("map_test");
	if (map.error != MAP_OK)
	  return (84);
	tile_map = tile_map_create_from_file("resources/texture/tile_map/grassy_config");
	map.tile_map = &tile_map;
	map.size.x = 100;
	map.size.y = map.size.x;
	map.pos.x = map.nb_case_x / 2;
	map.pos.y = map.nb_case_y / 2;
	map_generator(&map);//tmp
	map_editor_loop(window, &map);
	map_save(&map, "map_test");
	map_destroy(&map);
	tile_map_destroy(&tile_map);
	return (0);
}
