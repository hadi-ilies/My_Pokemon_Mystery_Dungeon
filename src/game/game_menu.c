/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game_menu.c
*/

#include <stdlib.h> //tmp
#include "prototype.h"
#include "type.h"
#include "tile_name.h"
#include "capacity_tab.h"

int game_menu(sfRenderWindow *window)
{
	garou_t garou = garou_create("resources/config");

	garou.map = map_create(50, 50, my_strdup("resources/tile_map/Forest config"));
	if (garou.map.error != ERR_OK)
		return (84);
	map_random(&garou.map);
	garou.map.size.x = 200;
	garou.map.size.y = garou.map.size.x;
	garou.nb_entity = 20;
	garou.entity = malloc(sizeof(entity_t) * garou.nb_entity);
	if (garou.entity == NULL)
		return (84);
	for (size_t i = 0; i < garou.nb_entity; i++) {
		sfVector2i pos;

		garou.entity[i] = entity_create_from_file(i ? "nomy" : "my");
		if (garou.entity[i].error != ERR_OK)
			return (84);
		do {
			pos.x = rand() % garou.map.nb_case_x;
			pos.y = rand() % garou.map.nb_case_y;
		}
		while (garou.map.tab[pos.x][pos.y].type != GROUND);
		garou.entity[i].dir = (sfVector2i){0, 0};
		garou.entity[i].pos = pos;
	}
	game_loop(window, &garou);
	garou.entity[0].life = STAT(garou.entity[0], life);
	for (size_t i = 0; i < 4; i++)
		garou.entity[0].pp[i] = CAPACITY(garou.entity[0], i).pp;
	entity_save(&garou.entity[0], "my");
	garou.entity[1].life = STAT(garou.entity[1], life);
	entity_save(&garou.entity[1], "nomy");
	garou_destroy(&garou);
	return (0);
}
