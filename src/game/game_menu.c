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
	garou_t garou;
	tile_map_t tile_map;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	garou.map = map_create(100, 100);
	tile_map = tile_map_create_from_file("resources/texture/tile_map/grassy_config");
	garou.map.tile_map = &tile_map;
	for (size_t i = 0; i < garou.map.nb_case_x; i++)
		for (size_t j = 0; j < garou.map.nb_case_y; j++) {
			garou.map.tab[i][j].type = 0;
			garou.map.tab[i][j].var = 4;
			garou.map.tab[i][j].alt = (rand() % 10 ? 0 : (rand() % 3 ? 1 : 2));
		}
	for (size_t i = 30; i < garou.map.nb_case_x - 20; i++)
		for (size_t j = 23; j < garou.map.nb_case_y - 34; j++)
			garou.map.tab[i][j].type = 1;
	for (size_t i = 30; i < garou.map.nb_case_x - 20; i++) {
		garou.map.tab[i][22].var = 7;
		if (garou.map.tab[i][22].alt > 1)
			garou.map.tab[i][22].alt = 0;
		garou.map.tab[i][23].var = 1;
		garou.map.tab[i][23].alt = 0;
		garou.map.tab[i][garou.map.nb_case_y - 34].var = 1;
		garou.map.tab[i][garou.map.nb_case_y - 34].alt = 0;
		garou.map.tab[i][garou.map.nb_case_y - 35].var = 7;
		garou.map.tab[i][garou.map.nb_case_y - 35].alt = 0;
	}
	for (size_t j = 23; j < garou.map.nb_case_y - 34; j++) {
		garou.map.tab[29][j].var = 5;
		garou.map.tab[29][j].alt = 0;
		garou.map.tab[30][j].var = 3;
		garou.map.tab[30][j].alt = 0;
		garou.map.tab[garou.map.nb_case_x - 20][j].var = 3;
		garou.map.tab[garou.map.nb_case_x - 20][j].alt = 0;
		garou.map.tab[garou.map.nb_case_x - 21][j].var = 5;
		garou.map.tab[garou.map.nb_case_x - 21][j].alt = 0;
	}
	garou.map.tab[29][22].var = 29;
	garou.map.tab[29][22].alt = 0;
	garou.map.tab[30][23].var = 0;
	garou.map.tab[30][23].alt = 0;
	garou.map.tab[garou.map.nb_case_x - 20][22].var = 30;
	garou.map.tab[garou.map.nb_case_x - 20][22].alt = 0;
	garou.map.tab[garou.map.nb_case_x - 21][23].var = 2;
	garou.map.tab[garou.map.nb_case_x - 21][23].alt = 0;
	garou.map.tab[29][garou.map.nb_case_y - 34].var = 31;
	garou.map.tab[29][garou.map.nb_case_y - 34].alt = 0;
	garou.map.tab[30][garou.map.nb_case_y - 35].var = 6;
	garou.map.tab[30][garou.map.nb_case_y - 35].alt = 0;
	garou.map.tab[garou.map.nb_case_x - 20][garou.map.nb_case_y - 34].var = 32;
	garou.map.tab[garou.map.nb_case_x - 20][garou.map.nb_case_y - 34].alt = 0;
	garou.map.tab[garou.map.nb_case_x - 21][garou.map.nb_case_y - 35].var = 8;
	garou.map.tab[garou.map.nb_case_x - 21][garou.map.nb_case_y - 35].alt = 0;
	garou.map.size.x = 200;
	garou.map.size.y = garou.map.size.x;
	garou.nb_entity = 200;
	garou.entity = malloc(sizeof(entity_t) * garou.nb_entity);
	for (size_t i = 0; i < garou.nb_entity; i++) {
		sfVector2i pos = {garou.map.nb_case_x / 2, garou.map.nb_case_y / 2};

		garou.entity[i] = entity_create("resources/texture/anime_tab/gobou_config");
		entity_set_pos(&garou.entity[i], pos);
	}
	game_loop(window, &garou);
	map_destroy(&garou.map);
	tile_map_destroy(&tile_map);
	sfRenderWindow_destroy(window);
	return (0);
}
