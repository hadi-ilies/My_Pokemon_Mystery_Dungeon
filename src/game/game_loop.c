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

static void set_anime_num(entity_t *entity)
{
	entity->dir.x == 0 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_MOVE_S : 0;
	entity->dir.x == 0 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_MOVE_N : 0;
	entity->dir.x == -1 && entity->dir.y == 0 ? entity->anime_tab.num = ANIME_MOVE_W : 0;
	entity->dir.x == 1 && entity->dir.y == 0 ? entity->anime_tab.num = ANIME_MOVE_E : 0;
	entity->dir.x == -1 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_MOVE_SW : 0;
	entity->dir.x == 1 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_MOVE_SE : 0;
	entity->dir.x == -1 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_MOVE_NW : 0;
	entity->dir.x == 1 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_MOVE_NE : 0;
}

bool entity_set_dir(entity_t *entity, map_t *map)
{
	if (entity->new_pos.x == entity->pos.x && entity->new_pos.y == entity->pos.y) {
		entity->dir = (sfVector2i){0, 0};
		sfKeyboard_isKeyPressed(sfKeyLeft) ? entity->dir.x = -1 : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? entity->dir.x = 1 : 0;
		sfKeyboard_isKeyPressed(sfKeyUp) ? entity->dir.y = -1 : 0;
		sfKeyboard_isKeyPressed(sfKeyDown)? entity->dir.y = 1 : 0;
		set_anime_num(entity);
		if (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type != GROUND)
			return (false);
		entity->new_pos.x = entity->pos.x + entity->dir.x;
		entity->new_pos.y = entity->pos.y + entity->dir.y;
		entity->move_pos.x = entity->pos.x;
		entity->move_pos.y = entity->pos.y;
		if (entity->dir.x || entity->dir.y)
			return (true);
	}
	return (false);
}

bool entity_set_dir2(entity_t *entity, map_t *map)
{
	if (entity->new_pos.x == entity->pos.x && entity->new_pos.y == entity->pos.y) {
		entity->dir = (sfVector2i){0, 0};
		do {
			entity->dir.x = rand() % 3 - 1;
			entity->dir.y = rand() % 3 - 1;
		} while (!entity->dir.x && !entity->dir.y);
		set_anime_num(entity);
		if (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type != GROUND)
			return (false);
		entity->new_pos.x = entity->pos.x + entity->dir.x;
		entity->new_pos.y = entity->pos.y + entity->dir.y;
		entity->move_pos.x = entity->pos.x;
		entity->move_pos.y = entity->pos.y;
		if (entity->dir.x || entity->dir.y)
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
		if (entity_set_dir(&garou->entity[0], &garou->map))
			for (size_t i = 1; i < garou->nb_entity; i++)
				entity_set_dir2(&garou->entity[i], &garou->map);
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
