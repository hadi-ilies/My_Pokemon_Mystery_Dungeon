/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include "prototype.h"

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

static bool entity_play(entity_t *entity, garou_t *garou,
		sfEvent *event)
{
	entity_t *GET_INFO(garou->dungeon.map);
	size_t input = 0;

	info_update(garou, info);
	if (entity->ia == 0)
		input = player(entity, garou, event);
	else
		input = ia(entity, &garou->dungeon.map, info);
	return (manage_input(entity, &garou->dungeon.map, info, input));
}

static void pick_up_item(garou_t *garou)
{
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
		if (garou->inventory[i] == NONE) {
			map_t map = garou->dungeon.map;
			entity_t entity = garou->dungeon.entity[0];

			garou->inventory[i] = ITEM(map, entity);
			ITEM(map, entity) = NONE;
			break;
		}
}

static bool manage_item(garou_t *garou)
{
	if (CLOCK(garou->dungeon.entity[0]) >= TIME_MOVE) {
		map_t map = garou->dungeon.map;
		entity_t entity = garou->dungeon.entity[0];

		if (ITEM(map, entity) == STAIRCASE)
			return (true);
		else if (ITEM(map, entity) != NONE)
			pick_up_item(garou);
	}
	return (false);
}

int game_loop(sfRenderWindow *window, garou_t *garou)
{
	size_t turn = 0;

	for (sfEvent event; sfRenderWindow_isOpen(window) && GENT(0).life;) {
		bool next = GENT(turn).life ? false : true;

		while (sfRenderWindow_pollEvent(window, &event)) {
			if (evt_close(&event, window))
				return (0);
			if (!next && !garou->dungeon.entity[turn].ia
			&& entity_play(&GENT(turn), garou, &event))
					next = true;
		}
		!next && entity_play(&GENT(turn), garou, NULL) ? next = 1 : 0;
		if (next == false)
			game_aff(window, garou);
		else ++turn >= garou->dungeon.nb_entity ? turn = 0 : 0;
		if (manage_item(garou))
			return (1);
	}
	return (0);
}
