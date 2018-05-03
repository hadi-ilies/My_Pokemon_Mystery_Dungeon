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
#include "item.h"

sfVector2i rand_pos_ground(map_t *map)
{
	sfVector2i pos;

	do {
		pos.x = rand() % map->nb_case_x;
		pos.y = rand() % map->nb_case_y;
	}
	while (map->tab[pos.x][pos.y].type != GROUND);
	return (pos);
}

void put_item(map_t *map)
{
	sfVector2i pos = rand_pos_ground(map);

	map->item[pos.x][pos.y] = STAIRCASE;
}

int game_menu(sfRenderWindow *window)
{
	garou_t garou = garou_create("resources/config");
	size_t size = 60;

	garou.map = map_create(size, size, my_strdup("resources/tile_map/Forest config"));
	if (garou.map.error != ERR_OK)
		return (84);
	map_random(&garou.map);
	put_item(&garou.map);
	garou.map.size = (sfVector2f) {GAME_ZOOM};
	garou.nb_entity = size / 3;
	garou.entity = malloc(sizeof(entity_t) * garou.nb_entity);
	if (garou.entity == NULL)
		return (84);
	for (size_t i = 0; i < garou.nb_entity; i++) {
		garou.entity[i] = entity_create_from_file(i ? "nomy" : "my");
		if (garou.entity[i].error != ERR_OK)
			return (84);
		garou.entity[i].ia = i ? 1 : 0;
		garou.entity[i].dir = (sfVector2i){0, 0};
		garou.entity[i].pos = rand_pos_ground(&garou.map);
	}
	game_loop(window, &garou);
	//entity_save(&garou.entity[0], "my");
	//entity_save(&garou.entity[1], "nomy");
	garou_destroy(&garou);
	return (0);
}
