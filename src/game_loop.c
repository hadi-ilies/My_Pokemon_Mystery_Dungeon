/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include <stdlib.h>
#include "prototype.h"

char entity_move(entity_t *entity)
{
	static sfVector2i dir;
	static size_t tmp = 0;
	float speed = 0.1;

	if (!tmp) {
		sfKeyboard_isKeyPressed(sfKeyUp) ? dir.x = -1 : 0;
		sfKeyboard_isKeyPressed(sfKeyDown)? dir.x = 1 : 0;
		sfKeyboard_isKeyPressed(sfKeyLeft) ? dir.y = -1 : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? dir.y = 1 : 0;
		dir.x || dir.y ? tmp = 1 / speed : 0;
	}
	if (tmp) {
		entity->pos.y += speed * dir.x;
		entity->pos.x += speed * dir.y;
		tmp--;
	}
	if (!tmp && (dir.x || dir.y)) {
		dir.x = 0;
		dir.y = 0;
		entity->pos.x = (int)(entity->pos.x + 0.5);
		entity->pos.y = (int)(entity->pos.y + 0.5);
		return (2);
	}
	return (tmp ? 1 : 0);
}

char entity_move2(entity_t *entity)
{
	static sfVector2i dir;
	static size_t tmp = 0;
	float speed = 0.1;

	if (!tmp) {
		dir.x = rand() % 3 - 1;
		dir.y = rand() % 3 - 1;
		dir.x || dir.y ? tmp = 1 / speed : 0;
	}
	if (tmp) {
		entity->pos.y += speed * dir.x;
		entity->pos.x += speed * dir.y;
		tmp--;
	}
	if (!tmp && (dir.x || dir.y)) {
		dir.x = 0;
		dir.y = 0;
		entity->pos.x = (int)(entity->pos.x + 0.5);
		entity->pos.y = (int)(entity->pos.y + 0.5);
		return (2);
	}
	return (tmp ? 1 : 0);
}

int game_loop(sfRenderWindow *window, game_t *game)
{
	sfEvent event;
	entity_t entity;
	size_t nb_entity2 = 1;
	entity_t *entity2 = malloc(sizeof(entity_t) * nb_entity2);
	int tmp = 0;

	entity.pos.x = 25;
	entity.pos.y = 25;
	for (size_t i = 0; i < nb_entity2; i++) {
		entity2[i].pos.x = 23 + rand() % 5;
		entity2[i].pos.y = 23 + rand() % 5;
	}
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		if (tmp == 0 && entity_move(&entity))
			tmp = 1;
		if (tmp == 1)
			for (size_t i = 0; i < nb_entity2; i++)
				if (entity_move2(&entity2[i]))
					tmp = 0;
		sfRenderWindow_clear(window, sfBlack);
		map_aff(window, &game->map, &entity.pos);
		entity_aff(window, &entity, &game->map, &entity.pos);
		for (size_t i = 0; i < nb_entity2; i++)
			entity_aff(window, &entity2[i], &game->map, &entity.pos);
		sfRenderWindow_display(window);
	}
	free(entity2);
	return (0);
}
