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
#include "item.h"
#include "macro.h"

static sfVector2i rand_pos_ground(map_t *map)
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
	sfVector2i pos;
	size_t size = map->nb_case_x * map->nb_case_y;
	size_t nb_item = rand() % (size / 500) + 1;

	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			map->item[i][j] = NONE;
	for (size_t i = 0; i < nb_item; i++) {
		pos = rand_pos_ground(map);
		map->item[pos.x][pos.y] = rand() % (NB_ITEM - 1) + 1;
	}
	pos = rand_pos_ground(map);
	map->item[pos.x][pos.y] = STAIRCASE;
}

map_t generate_map(size_t size, char *tile_map_file_name)
{
	map_t map = map_create(size, size, my_strdup(tile_map_file_name));

	if (map.error != ERR_OK)
		return (map);
	map.size = V2F(GAME_ZOOM, GAME_ZOOM);
	return (map);
}

entity_t *generate_entitys(size_t nb_entity)
{
	entity_t *entity = malloc(sizeof(entity_t) * nb_entity);

	if (entity == NULL)
		return (NULL);
	for (size_t i = 1; i < nb_entity; i++) {
		entity[i] = entity_create_from_file("resources/entity/nomy");
		if (entity[i].error != ERR_OK)
			return (NULL);
	}
	return (entity);
}

int run_dungeon(sfRenderWindow *window, garou_t *garou, size_t level)
{
	for (; garou->dungeon.stage_num < garou->dungeon.nb_stage; garou->dungeon.stage_num++) {
		map_random(&garou->dungeon.map);
		put_item(&garou->dungeon.map);
		for (size_t i = 1; i < garou->dungeon.nb_entity; i++) {
			garou->dungeon.entity[i].level = level;
			garou->dungeon.entity[i].life = STAT(garou->dungeon.entity[i], life);
			garou->dungeon.entity[i].ia = 1;
			garou->dungeon.entity[i].dir = V2I(0, 0);
			garou->dungeon.entity[i].pos = rand_pos_ground(&garou->dungeon.map);
		}
		// -------------player--------------------------------
		garou->dungeon.entity[0].dir = V2I(0, 0);
		garou->dungeon.entity[0].pos = rand_pos_ground(&garou->dungeon.map);
		// ---------------------------------------------------
		if (game_loop(window, garou) == 0)
			return (0);
	}
	return (1);
}

dungeon_t generate_dungeon(size_t nb_stage, char *file_name)
{
	dungeon_t dungeon = dungeon_create();

	dungeon.nb_stage = nb_stage;
	dungeon.nb_entity = 20;
	dungeon.map = generate_map(50, file_name);
	dungeon.entity = generate_entitys(dungeon.nb_entity);
	return (dungeon);
	resources/anime_tab/insolourdo_config
}

int game_menu(sfRenderWindow *window)
{
	garou_t garou = garou_create("resources/config");

	garou.player = entity_create_from_file("resources/entity/my");
	garou.player.ia = 0;
	if (garou.player.error != ERR_OK)
		return (84);



	garou.dungeon = generate_dungeon(3, "resources/tile_map/Forest config");
	if (garou.dungeon.map.error != ERR_OK || garou.dungeon.entity == NULL)
		return (84);
	garou.dungeon.entity[0] = garou.player;
	if (run_dungeon(window, &garou, 8) == 84)
		return (84);



	garou_destroy(&garou);
	return (0);
}
