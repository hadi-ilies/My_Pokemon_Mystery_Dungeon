/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include <stdio.h> //tmp
#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"
#include "tile_name.h"
#include "anime_name.h"
#include "capacity_tab.h"

enum input {
	     DOWN = 0b00000000001,
	       UP = 0b00000000010,
	    RIGHT = 0b00000000100,
	     LEFT = 0b00000001000,
	     MOVE = 0b00000010000,
	CAPACITY1 = 0b00000100000,
	CAPACITY2 = 0b00001000000,
	CAPACITY3 = 0b00010000000,
	CAPACITY4 = 0b00100000000,
	   ATTACK = 0b01000000000,
	     WAIT = 0b10000000000,
};

static void set_anime_idle(entity_t *entity)
{
	if (entity->dir.x == 0 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_IDLE_S;
	if (entity->dir.x == 0 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_IDLE_N;
	if (entity->dir.x == -1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_IDLE_W;
	if (entity->dir.x == 1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_IDLE_E;
	if (entity->dir.x == -1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_IDLE_SW;
	if (entity->dir.x == 1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_IDLE_SE;
	if (entity->dir.x == -1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_IDLE_NW;
	if (entity->dir.x == 1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_IDLE_NE;
}

static void set_anime_atk(entity_t *entity)
{
	if (entity->dir.x == 0 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_ATK_S;
	if (entity->dir.x == 0 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_ATK_N;
	if (entity->dir.x == -1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_ATK_W;
	if (entity->dir.x == 1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_ATK_E;
	if (entity->dir.x == -1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_ATK_SW;
	if (entity->dir.x == 1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_ATK_SE;
	if (entity->dir.x == -1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_ATK_NW;
	if (entity->dir.x == 1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_ATK_NE;
}

static void set_anime_hurt(entity_t *entity)
{
	if (entity->dir.x == 0 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_HURT_S;
	if (entity->dir.x == 0 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_HURT_N;
	if (entity->dir.x == -1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_HURT_W;
	if (entity->dir.x == 1 && entity->dir.y == 0)
		entity->anime_tab.num = ANIME_HURT_E;
	if (entity->dir.x == -1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_HURT_SW;
	if (entity->dir.x == 1 && entity->dir.y == 1)
		entity->anime_tab.num = ANIME_HURT_SE;
	if (entity->dir.x == -1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_HURT_NW;
	if (entity->dir.x == 1 && entity->dir.y == -1)
		entity->anime_tab.num = ANIME_HURT_NE;
}

void entity_attack(entity_t *entity, capacity_t *capacity, map_t *map,
		   entity_t *info[map->nb_case_x][map->nb_case_y])
{
	set_anime_atk(entity);
	if (INFO) {
		size_t attack = STATATK(*entity, *capacity);
		size_t power = capacity->power;
		size_t defense = STATDEF(*INFO, *capacity);
		size_t damage = (entity->level * 0.4 + 2) * attack * power;

		damage /= defense * 50 + 2;
		damage *= (rand() % (100 - 85 + 1) + 85) / 100.0;
		printf("%s : %ld - %ld = ", capacity->name, INFO->life, damage);
		if (INFO->life > damage)
			INFO->life -= damage;
		else
			INFO->life = 0;
		printf("%ld\n", INFO->life);
		set_anime_hurt(INFO);
	}
}

bool manage_input(entity_t *entity, map_t *map,
		  entity_t *info[map->nb_case_x][map->nb_case_y],
		  size_t input)
{
	if (sfClock_getElapsedTime(entity->clock).microseconds <= TIME_MOVE)
		return (false);
	if (input & (LEFT | RIGHT | UP | DOWN)) {
		entity->dir = (sfVector2i){0, 0};
		input & LEFT ? entity->dir.x = -1 : 0;
		input & RIGHT ? entity->dir.x = 1 : 0;
		input & UP ? entity->dir.y = -1 : 0;
		input & DOWN ? entity->dir.y = 1 : 0;
	}
	set_anime_idle(entity);
	if (input & MOVE && input & (LEFT | RIGHT | UP | DOWN))
		if (entity_move(entity, map, info))
			return (true);
	if (input & ATTACK) {
		if (input & (CAPACITY1 | CAPACITY2 | CAPACITY3 | CAPACITY4)) {
			bool tmp = false;

			if (input & CAPACITY1 && entity->pp[0]) {
				if ((size_t)rand() % 100 < entity->capacity[0]->accuracy)
					entity_attack(entity, entity->capacity[0], map, info);
				entity->pp[0]--;
				tmp = true;
			}
			if (input & CAPACITY2 && entity->pp[1]) {
				if ((size_t)rand() % 100 < entity->capacity[1]->accuracy)
					entity_attack(entity, entity->capacity[1], map, info);
				entity->pp[1]--;
				tmp = true;
			}
			if (input & CAPACITY3 && entity->pp[2]) {
				if ((size_t)rand() % 100 < entity->capacity[2]->accuracy)
					entity_attack(entity, entity->capacity[2], map, info);
				entity->pp[2]--;
				tmp = true;
			}
			if (input & CAPACITY4 && entity->pp[3]) {
				if ((size_t)rand() % 100 < entity->capacity[3]->accuracy)
					entity_attack(entity, entity->capacity[3], map, info);
				entity->pp[3]--;
				tmp = true;
			}
			return (tmp);
		}
		else {
			entity_attack(entity, &capacity_tab[0], map, info);
			return (true);
		}
	}
	if (input & WAIT)
		return (true);
	return (false);
}

bool entity_set_dir(entity_t *entity, map_t *map,
		    entity_t *info[map->nb_case_x][map->nb_case_y],
		    sfEvent *event)
{
	size_t input = 0;

	if (entity->ia == 0) {
		if (!sfKeyboard_isKeyPressed(sfKeyLShift))
			input |= MOVE;
		if (sfKeyboard_isKeyPressed(sfKeySpace)) {
			if (event && event->type == sfEvtKeyPressed) {
				if (event->key.code == sfKeyUp)
					input |= ATTACK | CAPACITY1;
				if (event->key.code == sfKeyLeft)
					input |= ATTACK | CAPACITY2;
				if (event->key.code == sfKeyRight)
					input |= ATTACK | CAPACITY3;
				if (event->key.code == sfKeyDown)
					input |= ATTACK | CAPACITY4;
			}
		}
		else {
			sfKeyboard_isKeyPressed(sfKeyLeft) ? input |= LEFT : 0;
			sfKeyboard_isKeyPressed(sfKeyRight) ? input |= RIGHT : 0;
			sfKeyboard_isKeyPressed(sfKeyUp) ? input |= UP : 0;
			sfKeyboard_isKeyPressed(sfKeyDown)? input |= DOWN : 0;
		}
		if (event && event->type == sfEvtKeyPressed && event->key.code == sfKeyW)
			input |= WAIT;
	}
	else
		input = (rand() % 0b1111 + 1) | MOVE | WAIT;
	return (manage_input(entity, map, info, input));
}

void info_update(garou_t *garou,
		 entity_t *info[garou->map.nb_case_x][garou->map.nb_case_y])
{
	for (size_t i = 0; i < garou->map.nb_case_x; i++)
		for (size_t j = 0; j < garou->map.nb_case_y; j++)
			info[i][j] = NULL;
	for (size_t i = 0; i < garou->nb_entity; i++)
		if (garou->entity[i].life > 0) {
			size_t x = garou->entity[i].pos.x;
			size_t y = garou->entity[i].pos.y;

			info[x][y] = &garou->entity[i];
		}
}

/*---life_aff---------
  rect.left -> pos.x
  rect.top -> pos.y
  rect.width -> size.x of 1 HP and height of white rods
  rect.height -> size.y
  -----------------*/
void entity_life_aff(sfRenderWindow *window, entity_t *entity, sfFloatRect rect)
{
	sfRectangleShape *rectangle = sfRectangleShape_create();
	size_t life_max = STAT(*entity, life);
	sfVector2f pos = {rect.left, rect.top};
	sfVector2f size = {rect.width * life_max, rect.height};

	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setFillColor(rectangle, (sfColor){250, 250, 250, 250});
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	pos.y += rect.width;
	size.y -= rect.width * 2;
	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setFillColor(rectangle, (sfColor){0, 0, 0, 250});
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	size.x = rect.width * entity->life;
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setFillColor(rectangle, (sfColor){0, 220, 0, 250});
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	sfRectangleShape_destroy(rectangle);
}

void game_aff(sfRenderWindow *window, garou_t *garou)
{
	sfVector2f pos = entity_get_move_pos(&garou->entity[0]);

	sfRenderWindow_clear(window, sfBlack);
	garou->map.pos = pos;
	map_aff(window, &garou->map);
	for (size_t i = 0; i < garou->nb_entity; i++)
		if (garou->entity[i].life > 0)
			entity_aff(window, &garou->entity[i], &garou->map, pos);
	entity_life_aff(window, &garou->entity[0], (sfFloatRect){LIFE_RECT});
	sfRenderWindow_display(window);
}

int game_loop(sfRenderWindow *window, garou_t *garou)
{
	sfEvent event;
	entity_t *info[garou->map.nb_case_x][garou->map.nb_case_y];
	size_t entity_num = 0;

	while (sfRenderWindow_isOpen(window)) {
		bool next = garou->entity[entity_num].life ? false : true;

		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			if (!next && !garou->entity[entity_num].ia) {
				info_update(garou, info);
				if (entity_set_dir(&garou->entity[entity_num], &garou->map, info, &event))
					next = true;
			}
		}
		if (!next) {
			info_update(garou, info);
			if (entity_set_dir(&garou->entity[entity_num], &garou->map, info, NULL))
				next = true;
		}
		if (next == false)
			game_aff(window, garou);
		else if (++entity_num >= garou->nb_entity)
			entity_num = 0;
	}
	return (0);
}
