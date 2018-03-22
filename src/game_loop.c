/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"

bool entity_dir(entity_t *entity)
{
	if (entity->new_pos.x == entity->pos.x && entity->new_pos.y == entity->pos.y) {
		sfVector2i dir = {0, 0};

		sfKeyboard_isKeyPressed(sfKeyLeft) ? dir.x = -1 : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? dir.x = 1 : 0;
		sfKeyboard_isKeyPressed(sfKeyUp) ? dir.y = -1 : 0;
		sfKeyboard_isKeyPressed(sfKeyDown)? dir.y = 1 : 0;
		entity->new_pos.x = entity->pos.x + dir.x;
		entity->new_pos.y = entity->pos.y + dir.y;
		entity->move_pos.x = entity->pos.x;
		entity->move_pos.y = entity->pos.y;
		if (dir.x || dir.y) {
			dir.x == 0 && dir.y == 1 ? entity->anime_tab.num = 0 : 0;
			dir.x == 0 && dir.y == -1 ? entity->anime_tab.num = 1 : 0;
			dir.x == -1 && dir.y == 0 ? entity->anime_tab.num = 2 : 0;
			dir.x == 1 && dir.y == 0 ? entity->anime_tab.num = 3 : 0;
			dir.x == -1 && dir.y == 1 ? entity->anime_tab.num = 4 : 0;
			dir.x == 1 && dir.y == 1 ? entity->anime_tab.num = 5 : 0;
			dir.x == -1 && dir.y == -1 ? entity->anime_tab.num = 6 : 0;
			dir.x == 1 && dir.y == -1 ? entity->anime_tab.num = 7 : 0;
			return (true);
		}
	}
	return (false);
}

bool entity_dir2(entity_t *entity)
{
	if (entity->new_pos.x == entity->pos.x && entity->new_pos.y == entity->pos.y) {
		sfVector2i dir = {0, 0};

		do {
			dir = (sfVector2i){0, 0}; // tmp
			if (rand() & 2)
				dir.x = rand() % 3 - 1;
			else
				dir.y = rand() % 3 - 1;
		} while (!dir.x && !dir.y);
		entity->new_pos.x = entity->pos.x + dir.x;
		entity->new_pos.y = entity->pos.y + dir.y;
		entity->move_pos.x = entity->pos.x;
		entity->move_pos.y = entity->pos.y;
		if (dir.x || dir.y) {
			dir.x == 0 && dir.y == 1 ? entity->anime_tab.num = 0 : 0;
			dir.x == 0 && dir.y == -1 ? entity->anime_tab.num = 1 : 0;
			dir.x == -1 && dir.y == 0 ? entity->anime_tab.num = 2 : 0;
			dir.x == 1 && dir.y == 0 ? entity->anime_tab.num = 3 : 0;
			dir.x == -1 && dir.y == 1 ? entity->anime_tab.num = 4 : 0;
			dir.x == 1 && dir.y == 1 ? entity->anime_tab.num = 5 : 0;
			dir.x == -1 && dir.y == -1 ? entity->anime_tab.num = 6 : 0;
			dir.x == 1 && dir.y == -1 ? entity->anime_tab.num = 7 : 0;
			return (true);
		}
	}
	return (false);
}

int game_loop(sfRenderWindow *window, game_t *game)
{
	sfEvent event;
	size_t nb_entity = 100;
	entity_t *entity = malloc(sizeof(entity_t) * nb_entity);

	for (size_t i = 0; i < nb_entity; i++) {
		sfVector2i pos = {50, 50};

		entity[i] = entity_create("resources/texture/anime_tab/gobou_config");
		entity_set_pos(&entity[i], pos);
	}
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		if (entity_dir(&entity[0]))
			for (size_t i = 1; i < nb_entity; i++)
				entity_dir2(&entity[i]);
		for (size_t i = 0; i < nb_entity; i++)
			entity_move(&entity[i]);
		sfRenderWindow_clear(window, sfBlack);
		map_aff(window, &game->map, &entity[0].move_pos);
		for (size_t i = 0; i < nb_entity; i++)
			entity_aff(window, &entity[i], &game->map, &entity[0].move_pos);
		sfRenderWindow_display(window);
	}
	for (size_t i = 0; i < nb_entity; i++)
		entity_destroy(&entity[i]);
	free(entity);
	return (0);
}
