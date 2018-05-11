/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"
#include "tile_name.h"
#include "anime_name.h"
#include "capacity_tab.h"
#include "macro.h"
#include "input.h"

static bool entity_play(entity_t *entity, garou_t *garou,
		entity_t *GET_INFO(garou->dungeon.map),
		sfEvent *event)
{
	size_t input = 0;

	if (entity->ia == 0)
		input = player(entity, garou, event);
	else
		input = ia(entity, &garou->dungeon.map, info);
	return (manage_input(entity, &garou->dungeon.map, info, input));
}

static void info_update(garou_t *garou,
		 entity_t *GET_INFO(garou->dungeon.map))
{
	for (size_t i = 0; i < garou->dungeon.map.nb_case_x; i++)
		for (size_t j = 0; j < garou->dungeon.map.nb_case_y; j++)
			info[i][j] = NULL;
	for (size_t i = 0; i < garou->dungeon.nb_entity; i++)
		if (garou->dungeon.entity[i].life > 0) {
			size_t x = garou->dungeon.entity[i].pos.x;
			size_t y = garou->dungeon.entity[i].pos.y;

			info[x][y] = &garou->dungeon.entity[i];
		}
}

int game_loop(sfRenderWindow *window, garou_t *garou)
{
	sfEvent event;
	entity_t *GET_INFO(garou->dungeon.map);
	size_t entity_turn = 0;

	while (sfRenderWindow_isOpen(window)) {
		bool next = garou->dungeon.entity[entity_turn].life ? false : true;

		while (sfRenderWindow_pollEvent(window, &event)) {
			if (evt_close(&event, window))
				return (0);
			if (!next && !garou->dungeon.entity[entity_turn].ia) {
				info_update(garou, info);
				if (entity_play(&garou->dungeon.entity[entity_turn], garou, info, &event))
					next = true;
			}
		}
		if (!next) {
			info_update(garou, info);
			if (entity_play(&garou->dungeon.entity[entity_turn], garou, info, NULL))
				next = true;
		}
		if (next == false)
			game_aff(window, garou);
		else if (++entity_turn >= garou->dungeon.nb_entity)
			entity_turn = 0;
		if (sfClock_getElapsedTime(garou->dungeon.entity[0].clock).microseconds >= TIME_MOVE) {
			if (ITEM(garou->dungeon.map, garou->dungeon.entity[0]) == STAIRCASE)
				return (1);
			else if (ITEM(garou->dungeon.map, garou->dungeon.entity[0]) != NONE)
				for (size_t i = 0; i < INVENTORY_SIZE; i++)
					if (garou->inventory[i] == NONE) {
						garou->inventory[i] = ITEM(garou->dungeon.map, garou->dungeon.entity[0]);
						ITEM(garou->dungeon.map, garou->dungeon.entity[0]) = NONE;
						break;
					}
		}
		if (garou->dungeon.entity[0].life == 0)
			return (0);
	}
	return (0);
}
