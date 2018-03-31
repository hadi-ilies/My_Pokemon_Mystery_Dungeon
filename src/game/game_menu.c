/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game_menu.c
*/

#include <stdlib.h> //tmp
#include "prototype.h"

int game_menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;
	garou_t garou = garou_create();
	tile_map_t tile_map;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	garou.map = map_load("map_test");
	tile_map = tile_map_create_from_file("resources/texture/tile_map/grassy_config");
	garou.map.tile_map = &tile_map;
	if (garou.map.tile_map->error != TILE_MAP_OK)
		return (84);
	garou.map.size.x = 200;
	garou.map.size.y = garou.map.size.x;
	garou.nb_entity = 2;
	garou.entity = malloc(sizeof(entity_t) * garou.nb_entity);
	for (size_t i = 0; i < garou.nb_entity; i++) {
		sfVector2i pos = {garou.map.nb_case_x / 2, garou.map.nb_case_y / 2};

		garou.entity[i] = entity_create("resources/texture/anime_tab/gobou_config");
		if (garou.entity[i].anime_tab.error != ANIME_TAB_OK)
			return (84);
		entity_set_pos(&garou.entity[i], pos);
	}
	game_loop(window, &garou);
	garou_destroy(&garou);
	tile_map_destroy(&tile_map);
	sfRenderWindow_destroy(window);
	return (0);
}
