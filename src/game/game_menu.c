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

int run_stage(sfRenderWindow *window, entity_t *player,
	      size_t level, char *tile_map_file_name)
{
	garou_t garou = garou_create("resources/config");
	const size_t size = 60;
	int result;

	garou.map = map_create(size, size, my_strdup(tile_map_file_name));
	if (garou.map.error != ERR_OK)
		return (84);
	map_random(&garou.map);
	put_item(&garou.map);
	garou.map.size = (sfVector2f) {GAME_ZOOM};
	garou.nb_entity = size / 3;
	garou.entity = malloc(sizeof(entity_t) * garou.nb_entity);
	if (garou.entity == NULL)
		return (84);
	for (size_t i = 1; i < garou.nb_entity; i++) {
		garou.entity[i] = entity_create_from_file("nomy");
		if (garou.entity[i].error != ERR_OK)
			return (84);
		garou.entity[i].level = level;
		garou.entity[i].life = STAT(garou.entity[i], life);
		garou.entity[i].ia = 1;
		garou.entity[i].dir = (sfVector2i){0, 0};
		garou.entity[i].pos = rand_pos_ground(&garou.map);
	}
	// -------------player--------------------------------
	player->ia = 0;
	player->dir = (sfVector2i){0, 0};
	player->pos = rand_pos_ground(&garou.map);
	garou.entity[0] = *player;
	// ---------------------------------------------------
	result = game_loop(window, &garou);
	if (result == 1)
		*player = garou.entity[0];
	garou_destroy(&garou);
	return (result);
}

int game_menu(sfRenderWindow *window)
{
	int result = 1;
	entity_t player = entity_create_from_file("my");

	if (player.error != ERR_OK)
		return (84);
	printf("level : %ld\n", player.level);
	while (result) {
		result = run_stage(window, &player, player.level - 1, "resources/tile_map/Forest config");
		if (result == 84)
			return (84);
	}
	entity_destroy(&player);
	return (0);
}
