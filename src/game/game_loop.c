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

static void set_anime_idle(entity_t *entity)
{
	entity->dir.x == 0 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_IDLE_S : 0;
	entity->dir.x == 0 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_IDLE_N : 0;
	entity->dir.x == -1 && entity->dir.y == 0 ? entity->anime_tab.num = ANIME_IDLE_W : 0;
	entity->dir.x == 1 && entity->dir.y == 0 ? entity->anime_tab.num = ANIME_IDLE_E : 0;
	entity->dir.x == -1 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_IDLE_SW : 0;
	entity->dir.x == 1 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_IDLE_SE : 0;
	entity->dir.x == -1 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_IDLE_NW : 0;
	entity->dir.x == 1 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_IDLE_NE : 0;
}

static void set_anime_move(entity_t *entity)
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

static void set_anime_atk(entity_t *entity)
{
	entity->dir.x == 0 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_ATK_S : 0;
	entity->dir.x == 0 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_ATK_N : 0;
	entity->dir.x == -1 && entity->dir.y == 0 ? entity->anime_tab.num = ANIME_ATK_W : 0;
	entity->dir.x == 1 && entity->dir.y == 0 ? entity->anime_tab.num = ANIME_ATK_E : 0;
	entity->dir.x == -1 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_ATK_SW : 0;
	entity->dir.x == 1 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_ATK_SE : 0;
	entity->dir.x == -1 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_ATK_NW : 0;
	entity->dir.x == 1 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_ATK_NE : 0;
}

static void set_anime_hurt(entity_t *entity)
{
	entity->dir.x == 0 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_HURT_S : 0;
	entity->dir.x == 0 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_HURT_N : 0;
	entity->dir.x == -1 && entity->dir.y == 0 ? entity->anime_tab.num = ANIME_HURT_W : 0;
	entity->dir.x == 1 && entity->dir.y == 0 ? entity->anime_tab.num = ANIME_HURT_E : 0;
	entity->dir.x == -1 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_HURT_SW : 0;
	entity->dir.x == 1 && entity->dir.y == 1 ? entity->anime_tab.num = ANIME_HURT_SE : 0;
	entity->dir.x == -1 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_HURT_NW : 0;
	entity->dir.x == 1 && entity->dir.y == -1 ? entity->anime_tab.num = ANIME_HURT_NE : 0;
}

bool entity_set_dir(entity_t *entity, map_t *map, entity_t *info[map->nb_case_x][map->nb_case_y])
{
	if (sfClock_getElapsedTime(entity->clock).microseconds > TIME_MOVE) {
		set_anime_idle(entity);
		if (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyDown)) {
			entity->dir = (sfVector2i){0, 0};
			sfKeyboard_isKeyPressed(sfKeyLeft) ? entity->dir.x = -1 : 0;
			sfKeyboard_isKeyPressed(sfKeyRight) ? entity->dir.x = 1 : 0;
			sfKeyboard_isKeyPressed(sfKeyUp) ? entity->dir.y = -1 : 0;
			sfKeyboard_isKeyPressed(sfKeyDown)? entity->dir.y = 1 : 0;
			if (!sfKeyboard_isKeyPressed(sfKeyLShift) && !sfKeyboard_isKeyPressed(sfKeyRShift))
				if (!info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y] && (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == GROUND || (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == WATER && (entity->type == TYPE_WATER || entity->type == TYPE_FLYING || entity->type2 == TYPE_WATER || entity->type2 == TYPE_FLYING)))) {
					entity->pos.x += entity->dir.x;
					entity->pos.y += entity->dir.y;
					sfClock_restart(entity->clock);
					set_anime_move(entity);
					return (true);
				}
		}
		if (sfKeyboard_isKeyPressed(sfKeySpace))
			if (info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y])
				if (info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life > 0) {
					size_t level = info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->level;
					stats_t stat = info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->base_stat;
					stats_t ev = info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->ev;
					stats_t iv = info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->iv;
					stats_t boost = info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->boost;
					size_t atk = entity->base_stat.atk + entity->ev.atk + entity->iv.atk;
					size_t pui = 40;
					size_t def = stat.def + ev.def + iv.def;
					size_t damage;

					atk *= (float)level / 100.0;
					def *= (float)level / 100.0;
					atk += atk * entity->boost.atk;
					def += def * boost.def;
					damage = (((level * 0.4 + 2) * atk * pui) / (def * 50) + 2) * (rand() % (100 - 85 + 1) + 85) / 100.0;
					printf("life : %ld\n", info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life);
					printf("damage : %ld\n", damage);
					if ((ssize_t)info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life - (ssize_t)damage > 0)
						info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life -= damage;
					else
						info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life = 0;
					set_anime_atk(entity);
					set_anime_hurt(info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]);
					return (true);
				}
	}
	return (false);
}

bool entity_set_dir2(entity_t *entity, map_t *map, entity_t *info[map->nb_case_x][map->nb_case_y])
{
	if (sfClock_getElapsedTime(entity->clock).microseconds > TIME_MOVE) {
		set_anime_idle(entity);
		entity->dir = (sfVector2i){0, 0};
		for (size_t i = 0; i < 100 && (entity->dir.x == 0 && entity->dir.y == 0 || map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == WALL || info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]); i++) {
			entity->dir.x = rand() % 3 - 1;
			entity->dir.y = rand() % 3 - 1;
		}
		if (!info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y] && (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == GROUND || (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == WATER && (entity->type == TYPE_WATER || entity->type == TYPE_FLYING || entity->type2 == TYPE_WATER || entity->type2 == TYPE_FLYING)))) {
			entity->pos.x += entity->dir.x;
			entity->pos.y += entity->dir.y;
			sfClock_restart(entity->clock);
			set_anime_move(entity);
			return (true);
		}
	}
	return (false);
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
			for (size_t i = 0; i < garou->map.nb_case_x; i++)
				for (size_t j = 0; j < garou->map.nb_case_y; j++)
					info[i][j] = NULL;
			for (size_t i = 0; i < garou->nb_entity; i++)
				if (garou->entity[i].life > 0)
					info[garou->entity[i].pos.x][garou->entity[i].pos.y] = &garou->entity[i];
			if (entity_num == 0)
				entity_set_dir(&garou->entity[entity_num], &garou->map, info) ? entity_num++ : 0;
			else
				entity_set_dir2(&garou->entity[entity_num], &garou->map, info) ? entity_num++ : 0;
		}
		else
			entity_num++;
		if (entity_num >= garou->nb_entity)
			entity_num = 0;
		sfRenderWindow_clear(window, sfBlack);
		garou->map.pos = entity_get_move_pos(&garou->entity[0]);
		map_aff(window, &garou->map);
		for (size_t i = 0; i < garou->nb_entity; i++)
			if (garou->entity[i].life > 0)
				entity_aff(window, &garou->entity[i], &garou->map, entity_get_move_pos(&garou->entity[0]));
		sfRenderWindow_display(window);
	}
	return (0);
}
