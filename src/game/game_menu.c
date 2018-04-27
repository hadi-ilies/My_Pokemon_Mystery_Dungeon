/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game_menu.c
*/

#include <stdlib.h> //tmp
#include "prototype.h"
#include "type.h"
#include "capacity_tab.h"

int game_menu(sfRenderWindow *window)
{
	garou_t garou = garou_create();
	tile_map_t tile_map;

	garou.map = map_load("map_test"); //
	//garou.map = map_create(rand() % 50 + 50, rand() % 50 + 50);
	if (garou.map.error != MAP_OK)
		return (84);
	//map_random(&garou.map);
	garou.map.size.x = 200;
	garou.map.size.y = garou.map.size.x;
	garou.nb_entity = 2;
	garou.entity = malloc(sizeof(entity_t) * garou.nb_entity);
	for (size_t i = 0; i < garou.nb_entity; i++) {
		sfVector2i pos = {garou.map.nb_case_x / 2 + rand() % 5 - 2, garou.map.nb_case_y / 2 + rand() % 5 - 2};

		if (i == 0)
			pos = (sfVector2i){garou.map.nb_case_x / 2, garou.map.nb_case_y / 2};
		garou.entity[i] = entity_create();
		garou.entity[i].level = 10;
		garou.entity[i].type = i == 0 ? TYPE_NORMAL : TYPE_WATER;
		garou.entity[i].type2 = TYPE_NULL;
		garou.entity[i].capacity[0] = &capacity_tab[1];
		garou.entity[i].capacity[1] = &capacity_tab[2];
		garou.entity[i].capacity[2] = &capacity_tab[3];
		garou.entity[i].capacity[3] = &capacity_tab[4];
		for (size_t j = 0; j < 4; j++)
			garou.entity[i].pp[j] = garou.entity[i].capacity[j]->pp;
		garou.entity[i].ability = 0; // !!!
		garou.entity[i].nature = 0; // !!!
		if (i == 0)
			garou.entity[i].base_stat = (stats_t){310, 145, 145, 135, 135, 95};
		else
		garou.entity[i].base_stat = (stats_t){210, 145, 105, 105, 105, 85};
		garou.entity[i].iv = (stats_t){rand() % 32, rand() % 32, rand() % 32, rand() % 32, rand() % 32, rand() % 32};
		garou.entity[i].item = 0; // !!!
		if (i == 0)
			garou.entity[i].ia = 0; // !!!
		else
			garou.entity[i].ia = 1; // !!!
		garou.entity[i].life = STAT(garou.entity[i], life);
		if (i == 0)
			garou.entity[i].anime_tab = anime_tab_create_from_file("resources/texture/anime_tab/insolourdo_config");
		else
			garou.entity[i].anime_tab = anime_tab_create_from_file("resources/texture/anime_tab/gobou_config");
		if (garou.entity[i].anime_tab.error != ANIME_TAB_OK)
			return (84);
		garou.entity[i].anime_tab.num = rand() % 8;
		garou.entity[i].pos = pos;
	}
	game_loop(window, &garou);
	garou_destroy(&garou);
	tile_map_destroy(&tile_map);
	return (0);
}
