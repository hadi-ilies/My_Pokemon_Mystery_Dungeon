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

static void ee(entity_t *entity, sfVector2i dir)
{
	dir.x == 0 && dir.y == 1 ? entity->anime_tab.num = 0 : 0;
	dir.x == 0 && dir.y == -1 ? entity->anime_tab.num = 1 : 0;
	dir.x == -1 && dir.y == 0 ? entity->anime_tab.num = 2 : 0;
	dir.x == 1 && dir.y == 0 ? entity->anime_tab.num = 3 : 0;
	dir.x == -1 && dir.y == 1 ? entity->anime_tab.num = 4 : 0;
	dir.x == 1 && dir.y == 1 ? entity->anime_tab.num = 5 : 0;
	dir.x == -1 && dir.y == -1 ? entity->anime_tab.num = 6 : 0;
	dir.x == 1 && dir.y == -1 ? entity->anime_tab.num = 7 : 0;
}

bool entity_dir(entity_t *entity, map_t *map)
{
	if (entity->new_pos.x == entity->pos.x && entity->new_pos.y == entity->pos.y) {
		sfVector2i dir = {0, 0};

		sfKeyboard_isKeyPressed(sfKeyLeft) ? dir.x = -1 : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? dir.x = 1 : 0;
		sfKeyboard_isKeyPressed(sfKeyUp) ? dir.y = -1 : 0;
		sfKeyboard_isKeyPressed(sfKeyDown)? dir.y = 1 : 0;
		ee(entity, dir);
		if (map->tab[entity->pos.x + dir.x][entity->pos.y + dir.y].type != GROUND)
			return (false);
		entity->new_pos.x = entity->pos.x + dir.x;
		entity->new_pos.y = entity->pos.y + dir.y;
		entity->move_pos.x = entity->pos.x;
		entity->move_pos.y = entity->pos.y;
		if ((dir.x || dir.y))
			return (true);
	}
	return (false);
}

bool entity_dir2(entity_t *entity, map_t *map)
{
	if (entity->new_pos.x == entity->pos.x && entity->new_pos.y == entity->pos.y) {
		sfVector2i dir = {0, 0};

		do {
			dir.x = rand() % 3 - 1;
			dir.y = rand() % 3 - 1;
		} while (!dir.x && !dir.y);
		ee(entity, dir);
		if (map->tab[entity->pos.x + dir.x][entity->pos.y + dir.y].type != GROUND)
			return (false);
		entity->new_pos.x = entity->pos.x + dir.x;
		entity->new_pos.y = entity->pos.y + dir.y;
		entity->move_pos.x = entity->pos.x;
		entity->move_pos.y = entity->pos.y;
		if ((dir.x || dir.y))
			return (true);
	}
	return (false);
}

int game_loop(sfRenderWindow *window, garou_t *garou)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		if (entity_dir(&garou->entity[0], &garou->map))
			for (size_t i = 1; i < garou->nb_entity; i++)
				entity_dir2(&garou->entity[i], &garou->map);
		for (size_t i = 0; i < garou->nb_entity; i++)
			entity_move(&garou->entity[i]);
		sfRenderWindow_clear(window, sfBlack);
		garou->map.pos = garou->entity[0].move_pos;
		map_aff(window, &garou->map);
		for (size_t i = 0; i < garou->nb_entity; i++)
			entity_aff(window, &garou->entity[i], &garou->map, garou->entity[0].move_pos);
		sfRenderWindow_display(window);
	}
	return (0);
}
