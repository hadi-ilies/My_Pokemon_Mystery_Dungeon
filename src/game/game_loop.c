/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include <stdio.h> // tmp
#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"
#include "tile_name.h"
#include "anime_name.h"

enum input {
	DOWN = 0b0000001,
	UP = 0b0000010,
	RIGHT = 0b0000100,
	LEFT = 0b0001000,
	MOVE = 0b0010000,
	ATTACK = 0b0100000,
	WAIT = 0b1000000,
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

bool attack(entity_t *entity, map_t *map,
		  entity_t *info[map->nb_case_x][map->nb_case_y])
{
	//
}

bool manage_input(entity_t *entity, map_t *map,
		  entity_t *info[map->nb_case_x][map->nb_case_y], size_t input)
{
	if (sfClock_getElapsedTime(entity->clock).microseconds <= TIME_MOVE)
		return (false);
	set_anime_idle(entity);
	if (input & (LEFT | RIGHT | UP | DOWN)) {
		entity->dir = (sfVector2i){0, 0};
		input & 0b1000 ? entity->dir.x = -1 : 0;
		input & 0b0100 ? entity->dir.x = 1 : 0;
		input & 0b0010 ? entity->dir.y = -1 : 0;
		input & 0b0001 ? entity->dir.y = 1 : 0;
	}
	if (input & MOVE && input & (LEFT | RIGHT | UP | DOWN))
		if (entity_move(entity, map, info))
			return (true);
	if (input & ATTACK) {
		if (INFO) {
			size_t level = INFO->level;
			stats_t stat = INFO->base_stat;
			stats_t ev = INFO->ev;
			stats_t iv = INFO->iv;
			stats_t boost = INFO->boost;
			size_t atk = entity->base_stat.atk + entity->ev.atk + entity->iv.atk;
			size_t pui = 40;
			size_t def = stat.def + ev.def + iv.def;
			size_t damage;

			atk *= (float)level / 100.0;
			def *= (float)level / 100.0;
			atk += atk * entity->boost.atk;
			def += def * boost.def;
			damage = (((level * 0.4 + 2) * atk * pui) / (def * 50) + 2) * (rand() % (100 - 85 + 1) + 85) / 100.0;
			printf("life : %ld\n", INFO->life);
			printf("damage : %ld\n", damage);
			if ((ssize_t)INFO->life - (ssize_t)damage > 0)
				INFO->life -= damage;
			else
				INFO->life = 0;
			set_anime_atk(entity);
			set_anime_hurt(INFO);
		}
		return (true);
	}
	if (input & WAIT)
		return (true);
	return (false);
}

bool entity_set_dir(entity_t *entity, map_t *map,
		    entity_t *info[map->nb_case_x][map->nb_case_y])
{
	size_t input = 0;

	if (entity->ia == 0) {
		sfKeyboard_isKeyPressed(sfKeyLeft) ? input |= LEFT : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? input |= RIGHT : 0;
		sfKeyboard_isKeyPressed(sfKeyUp) ? input |= UP : 0;
		sfKeyboard_isKeyPressed(sfKeyDown)? input |= DOWN : 0;
		if (!sfKeyboard_isKeyPressed(sfKeyLShift))
			input |= MOVE;
		if (sfKeyboard_isKeyPressed(sfKeySpace))
			input |= ATTACK;
		if (sfKeyboard_isKeyPressed(sfKeyW))
			input |= WAIT;
	}
	else {
		input |= 0b0001;
		input <<= rand() % 4;
		input |= MOVE | WAIT;
	}
	return (manage_input(entity, map, info, input));
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
	sfRenderWindow_display(window);
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

int game_loop(sfRenderWindow *window, garou_t *garou)
{
	sfEvent event;
	entity_t *info[garou->map.nb_case_x][garou->map.nb_case_y];
	size_t entity_num = 0;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		if (garou->entity[entity_num].life > 0) {
			info_update(garou, info);
			if (entity_set_dir(&garou->entity[entity_num], &garou->map, info))
				entity_num++;
		}
		else
			entity_num++;
		if (entity_num >= garou->nb_entity)
			entity_num = 0;
		game_aff(window, garou);
	}
	return (0);
}
