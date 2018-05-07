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
	size_t nb_item = rand() % (size / 100) + 1;

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
	map_random(&map);
	put_item(&map);
	map.size = (sfVector2f) {GAME_ZOOM};
	return (map);
}

entity_t *generate_entitys(size_t nb_entity, size_t level, map_t *map)
{
	entity_t *entity = malloc(sizeof(entity_t) * nb_entity);

	if (entity == NULL)
		return (NULL);
	for (size_t i = 1; i < nb_entity; i++) {
		entity[i] = entity_create_from_file("nomy");
		if (entity[i].error != ERR_OK)
			return (NULL);
		entity[i].level = level;
		entity[i].life = STAT(entity[i], life);
		entity[i].ia = 1;
		entity[i].dir = (sfVector2i){0, 0};
		entity[i].pos = rand_pos_ground(map);
	}
	return (entity);
}

int run_stage(sfRenderWindow *window, entity_t *player,
	      size_t level, char *tile_map_file_name)
{
	garou_t garou = garou_create("resources/config");
	const size_t size = 60;
	int result;

	garou.nb_entity = size / 3;
	garou.map = generate_map(size, tile_map_file_name);
	garou.entity = generate_entitys(garou.nb_entity, level, &garou.map);
	if (garou.map.error != ERR_OK || garou.entity == NULL)
		return (84);
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
	while (result) {
		result = run_stage(window, &player, player.level - 1, "resources/tile_map/Forest config");
		if (result == 84)
			return (84);
	}
	entity_destroy(&player);
	return (0);
}
