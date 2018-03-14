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
		if (dir.x || dir.y)
			return (true);
	}
	return (false);
}

bool entity_dir2(entity_t *entity)
{
	if (entity->new_pos.x == entity->pos.x && entity->new_pos.y == entity->pos.y) {
		sfVector2i dir = {0, 0};

		do {
			dir.x = rand() % 3 - 1;
			dir.y = rand() % 3 - 1;
		} while (!dir.x && !dir.y);
		entity->new_pos.x = entity->pos.x + dir.x;
		entity->new_pos.y = entity->pos.y + dir.y;
		entity->move_pos.x = entity->pos.x;
		entity->move_pos.y = entity->pos.y;
		if (dir.x || dir.y)
			return (true);
	}
	return (false);
}

void for_fun(entity_t *entity, size_t nb_entity)
{
	#include <stdio.h>
	#include <unistd.h>
	static int s = -1;
	int x = entity[0].pos.x;
	int y = entity[0].pos.y;
	static int prev_x = -1;
	static int prev_y = -1;

	for (size_t i = 1; i < nb_entity; i++)
		if (entity[i].pos.x == x && entity[i].pos.y == y) {
			printf("Score : %d\n", s);
			usleep(1000000 / 4);
			exit(0);
		}
	if (x != prev_x || y != prev_y) {
		s++;
		prev_x = x;
		prev_y = y;
	}
}

int game_loop(sfRenderWindow *window, game_t *game)
{
	sfEvent event;
	size_t nb_entity = 500;
	entity_t *entity = malloc(sizeof(entity_t) * nb_entity);

	for (size_t i = 0; i < nb_entity; i++) {
		entity[i] = entity_create();
		entity[i].pos.x = rand() % game->map.nb_case_x;
		entity[i].pos.y = rand() % game->map.nb_case_y;
		entity[i].move_pos.x = entity[i].pos.x;
		entity[i].move_pos.y = entity[i].pos.y;
		entity[i].new_pos.x = entity[i].pos.x;
		entity[i].new_pos.y = entity[i].pos.y;
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
		for_fun(entity, nb_entity);
	}
	free(entity);
	return (0);
}
