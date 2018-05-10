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

void entity_attack(entity_t *entity, const capacity_t *capacity, map_t *map,
		   entity_t *info[map->nb_case_x][map->nb_case_y])
{
	set_anime_atk(entity);
	if (INFO(*entity)) {
		size_t attack = STATATK(*entity, *capacity);
		size_t power = capacity->power;
		size_t defense = STATDEF(*INFO(*entity), *capacity);
		size_t damage = (entity->level * 0.4 + 2) * attack * power;

		damage /= defense * 50 + 2;
		damage *= (rand() % (100 - 85 + 1) + 85) / 100.0;
		if (INFO(*entity)->life > damage)
			INFO(*entity)->life -= damage;
		else {
			size_t exp = rand() % INFO(*entity)->level;

			INFO(*entity)->life = 0;
			entity_gain_exp(entity, INFO(*entity)->level * exp);
		}
		set_anime_hurt(INFO(*entity));
	}
}

bool manage_input(entity_t *entity, map_t *map,
		  entity_t *info[map->nb_case_x][map->nb_case_y],
		  size_t input)
{
	if (sfClock_getElapsedTime(entity->clock).microseconds < TIME_MOVE)
		return (false);
	if (input & (LEFT | RIGHT | UP | DOWN)) {
		entity->dir = V2I(0, 0);
		input & LEFT ? entity->dir.x = -1 : 0;
		input & RIGHT ? entity->dir.x = 1 : 0;
		input & UP ? entity->dir.y = -1 : 0;
		input & DOWN ? entity->dir.y = 1 : 0;
	}
	if (input & MOVE && input & (LEFT | RIGHT | UP | DOWN))
		if (entity_move(entity, map, info))
			return (true);
	if (input & ATTACK) {
		if (input & (CAPACITY1 | CAPACITY2 | CAPACITY3 | CAPACITY4)) {
			bool tmp = false;

			if (input & CAPACITY1 && entity->pp[0]) {
				if ((size_t)rand() % 100 < CAPACITY(*entity, 0).accuracy)
					entity_attack(entity, &CAPACITY(*entity, 0), map, info);
				entity->pp[0]--;
				tmp = true;
			}
			if (input & CAPACITY2 && entity->pp[1]) {
				if ((size_t)rand() % 100 < CAPACITY(*entity, 1).accuracy)
					entity_attack(entity, &CAPACITY(*entity, 1), map, info);
				entity->pp[1]--;
				tmp = true;
			}
			if (input & CAPACITY3 && entity->pp[2]) {
				if ((size_t)rand() % 100 < CAPACITY(*entity, 2).accuracy)
					entity_attack(entity, &CAPACITY(*entity, 2), map, info);
				entity->pp[2]--;
				tmp = true;
			}
			if (input & CAPACITY4 && entity->pp[3]) {
				if ((size_t)rand() % 100 < CAPACITY(*entity, 3).accuracy)
					entity_attack(entity, &CAPACITY(*entity, 3), map, info);
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
	if (input & WAIT) {
		entity->anime_tab.num = ANIME_SLEEP;
		if (entity->life < STAT(*entity, life))
			entity->life++;
		return (true);
	}
	if (entity->anime_tab.num != ANIME_SLEEP)
		set_anime_idle(entity);
	return (false);
}

bool entity_set_dir(entity_t *entity, garou_t *garou,
		    entity_t *GET_INFO(garou->dungeon.map),
		    sfEvent *event)
{
	size_t input = 0;

	if (entity->ia == 0) {
		if (!sfKeyboard_isKeyPressed(garou->settings.key[KEY_MOVE]))
			input |= MOVE;
		if (sfKeyboard_isKeyPressed(garou->settings.key[KEY_ATTACK])) {
			if (event && event->type == sfEvtKeyPressed) {
				if (event->key.code == garou->settings.key[KEY_UP])
					input |= ATTACK | CAPACITY1;
				if (event->key.code == garou->settings.key[KEY_LEFT])
					input |= ATTACK | CAPACITY2;
				if (event->key.code == garou->settings.key[KEY_RIGHT])
					input |= ATTACK | CAPACITY3;
				if (event->key.code == garou->settings.key[KEY_DOWN])
					input |= ATTACK | CAPACITY4;
			}
		}
		else {
			sfKeyboard_isKeyPressed(garou->settings.key[KEY_LEFT]) ? input |= LEFT : 0;
			sfKeyboard_isKeyPressed(garou->settings.key[KEY_RIGHT]) ? input |= RIGHT : 0;
			sfKeyboard_isKeyPressed(garou->settings.key[KEY_UP]) ? input |= UP : 0;
			sfKeyboard_isKeyPressed(garou->settings.key[KEY_DOWN])? input |= DOWN : 0;
		}
		if (event && event->type == sfEvtKeyPressed && event->key.code == garou->settings.key[KEY_WAIT])
			input |= WAIT;
		if (event && event->type == sfEvtKeyPressed && event->key.code == sfKeyM && garou->inventory[0] != NONE) {
			if (garou->inventory[0] == ORAN_BERRY) {
				entity->life += 20;
				if (entity->life > STAT(*entity, life))
					entity->life = STAT(*entity, life);
			}
			if (garou->inventory[0] == MAX_ELIXIR) {
				size_t max = 0;

				for (size_t i = 1; i < 4; i++)
					if (CAPACITY(*entity, i).pp - entity->pp[i] > CAPACITY(*entity, max).pp - entity->pp[max])
						max = i;
				entity->pp[max] += 10;
				if (entity->pp[max] > CAPACITY(*entity, max).pp)
					entity->pp[max] = CAPACITY(*entity, max).pp;
			}
			garou->inventory[0] = NONE;
			input = WAIT;
		}
	}
	else
		input = ia(entity, &garou->dungeon.map, info);
	return (manage_input(entity, &garou->dungeon.map, info, input));
}

void info_update(garou_t *garou,
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

/*---life_aff---------
  rect.left -> pos.x
  rect.top -> pos.y
  rect.width -> size.x of 1 HP and height of white rods
  rect.height -> size.y
  -----------------*/
void entity_life_aff(sfRenderWindow *window, entity_t *entity,
		     sfFloatRect rect)
{
	sfRectangleShape *rectangle = sfRectangleShape_create();
	size_t life_max = STAT(*entity, life);
	sfVector2f pos = {rect.left, rect.top};
	sfVector2f size = {rect.width * life_max, rect.height};

	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setFillColor(rectangle, COL(250, 250, 250, 250));
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	pos.y += rect.width;
	size.y -= rect.width * 2;
	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setFillColor(rectangle, COL(0, 0, 0, 250));
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	size.x = rect.width * entity->life;
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setFillColor(rectangle, COL(0, 220, 0, 250));
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	sfRectangleShape_destroy(rectangle);
}

void game_aff(sfRenderWindow *window, garou_t *garou)
{
	sfVector2f pos = entity_get_move_pos(&garou->dungeon.entity[0]);
	bool tmp = true;

	sfRenderWindow_clear(window, sfBlack);
	garou->dungeon.map.pos = pos;
	map_aff(window, &garou->dungeon.map);
	for (size_t i = 0; i < garou->dungeon.nb_entity; i++)
		if (garou->dungeon.entity[i].life > 0) {
			entity_aff(window, &garou->dungeon.entity[i], &garou->dungeon.map, pos);
			if (sfClock_getElapsedTime(garou->dungeon.entity[i].clock).microseconds < TIME_MOVE)
				tmp = false;
		}
	entity_life_aff(window, &garou->dungeon.entity[0], (sfFloatRect){LIFE_RECT});
	if (sfKeyboard_isKeyPressed(garou->settings.key[KEY_INVENTORY]))
		inventory_aff(window, garou);
	else if (sfKeyboard_isKeyPressed(garou->settings.key[KEY_ATTACK]) && tmp)
		capacity_aff(window, garou);
	sfRenderWindow_display(window);
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
				if (entity_set_dir(&garou->dungeon.entity[entity_turn], garou, info, &event))
					next = true;
			}
		}
		if (!next) {
			info_update(garou, info);
			if (entity_set_dir(&garou->dungeon.entity[entity_turn], garou, info, NULL))
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
