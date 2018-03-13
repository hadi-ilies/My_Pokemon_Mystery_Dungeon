/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include <stdlib.h>
#include "prototype.h"

bool ee(float n1, int n2)
{
	float n3 = (float)n2 - n1;

	n3 < 0 ? n3 = -n3 : 0;
	if (n3 < 0.1)
		return (true);
	return (false);
}

char entity_move(entity_t *entity)
{
	float move_speed = 0.1;

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
	}
	if (entity->new_pos.x != entity->pos.x || entity->new_pos.y != entity->pos.y) {
		entity->move_pos.x += move_speed * (entity->new_pos.x - entity->pos.x);
		entity->move_pos.y += move_speed * (entity->new_pos.y - entity->pos.y);
	}
	if (ee(entity->move_pos.x, entity->new_pos.x) && ee(entity->move_pos.y, entity->new_pos.y)) {
		entity->pos.x = entity->new_pos.x;
		entity->pos.y = entity->new_pos.y;
		entity->move_pos.x = entity->new_pos.x;
		entity->move_pos.y = entity->new_pos.y;
		return (2);
	}
	return (entity->new_pos.x != entity->pos.x || entity->new_pos.y != entity->pos.y ? 1 : 0);
}

char entity_move2(entity_t *entity)
{
	float move_speed = 0.1;

	if (entity->new_pos.x == entity->pos.x && entity->new_pos.y == entity->pos.y) {
		sfVector2i dir = {0, 0};

		dir.x = rand() % 3 - 1;
		dir.y = rand() % 3 - 1;
		entity->new_pos.x = entity->pos.x + dir.x;
		entity->new_pos.y = entity->pos.y + dir.y;
		entity->move_pos.x = entity->pos.x;
		entity->move_pos.y = entity->pos.y;
	}
	if (entity->new_pos.x != entity->pos.x || entity->new_pos.y != entity->pos.y) {
		entity->move_pos.x += move_speed * (entity->new_pos.x - entity->pos.x);
		entity->move_pos.y += move_speed * (entity->new_pos.y - entity->pos.y);
	}
	if (ee(entity->move_pos.x, entity->new_pos.x) && ee(entity->move_pos.y, entity->new_pos.y)) {
		entity->pos.x = entity->new_pos.x;
		entity->pos.y = entity->new_pos.y;
		entity->move_pos.x = entity->new_pos.x;
		entity->move_pos.y = entity->new_pos.y;
		return (2);
	}
	return (entity->new_pos.x != entity->pos.x || entity->new_pos.y != entity->pos.y ? 1 : 0);
}

int game_loop(sfRenderWindow *window, game_t *game)
{
	sfEvent event;
	entity_t entity;
	size_t nb_entity2 = 100;
	entity_t *entity2 = malloc(sizeof(entity_t) * nb_entity2);
	int tmp = 0;

	entity.pos.x = 25;
	entity.pos.y = 25;
	entity.move_pos.x = entity.pos.x;
	entity.move_pos.y = entity.pos.y;
	entity.new_pos.x = entity.pos.x;
	entity.new_pos.y = entity.pos.y;
	for (size_t i = 0; i < nb_entity2; i++) {
		entity2[i].pos.x = 23 + rand() % 5;
		entity2[i].pos.y = 23 + rand() % 5;
		entity2[i].move_pos.x = entity2[i].pos.x;
		entity2[i].move_pos.y = entity2[i].pos.y;
		entity2[i].new_pos.x = entity2[i].pos.x;
		entity2[i].new_pos.y = entity2[i].pos.y;
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
		map_aff(window, &game->map, &entity.move_pos);
		entity_aff(window, &entity, &game->map, &entity.move_pos);
		for (size_t i = 0; i < nb_entity2; i++)
			entity_aff(window, &entity2[i], &game->map, &entity.move_pos);
		sfRenderWindow_display(window);
	}
	free(entity2);
	return (0);
}
