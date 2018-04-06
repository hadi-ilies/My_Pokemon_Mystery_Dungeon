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

bool entity_set_dir(entity_t *entity, map_t *map, entity_t *info[map->nb_case_x][map->nb_case_y])
{
	if (sfClock_getElapsedTime(entity->clock).microseconds > TIME_MOVE) {
		if (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyDown)) {
			entity->dir = (sfVector2i){0, 0};
			sfKeyboard_isKeyPressed(sfKeyLeft) ? entity->dir.x = -1 : 0;
			sfKeyboard_isKeyPressed(sfKeyRight) ? entity->dir.x = 1 : 0;
			sfKeyboard_isKeyPressed(sfKeyUp) ? entity->dir.y = -1 : 0;
			sfKeyboard_isKeyPressed(sfKeyDown)? entity->dir.y = 1 : 0;
			set_anime_num(entity);
			if (!sfKeyboard_isKeyPressed(sfKeyLShift) && !sfKeyboard_isKeyPressed(sfKeyRShift))
				if (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == GROUND || (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == WATER && (entity->type == TYPE_WATER || entity->type == TYPE_FLYING || entity->type2 == TYPE_WATER || entity->type2 == TYPE_FLYING))) {
					entity->pos.x += entity->dir.x;
					entity->pos.y += entity->dir.y;
					sfClock_restart(entity->clock);
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
					damage = (((level * 0.4 + 2) * atk * pui) / (def * 50) + 2) * 1;
					printf("life : %ld\n", info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life);
					printf("damage : %ld\n", damage);
					if ((ssize_t)info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life - (ssize_t)damage > 0)
						info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life -= damage;
					else
						info[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y]->life = 0;
					return (true);
				}
	}
	return (false);
}

bool entity_set_dir2(entity_t *entity, map_t *map, entity_t *info[map->nb_case_x][map->nb_case_y])
{
	if (sfClock_getElapsedTime(entity->clock).microseconds > TIME_MOVE) {
		entity->dir = (sfVector2i){0, 0};
		while (entity->dir.x == 0 && entity->dir.y == 0) {
			entity->dir.x = rand() % 3 - 1;
			entity->dir.y = rand() % 3 - 1;
		}
		set_anime_num(entity);
		if (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == GROUND || (map->tab[entity->pos.x + entity->dir.x][entity->pos.y + entity->dir.y].type == WATER && (entity->type == TYPE_WATER || entity->type == TYPE_FLYING || entity->type2 == TYPE_WATER || entity->type2 == TYPE_FLYING))) {
			entity->pos.x += entity->dir.x;
			entity->pos.y += entity->dir.y;
			sfClock_restart(entity->clock);
			return (true);
		}
	}
	return (false);
}

int game_loop(sfRenderWindow *window, garou_t *garou)
{
	sfEvent event;
	entity_t *info[garou->map.nb_case_x][garou->map.nb_case_y];

	while (sfRenderWindow_isOpen(window)) {
		for (size_t i = 0; i < garou->map.nb_case_x; i++)
			for (size_t j = 0; j < garou->map.nb_case_y; j++)
				info[i][j] = NULL;
		for (size_t i = 0; i < garou->nb_entity; i++)
			if (garou->entity[i].life > 0)
				info[garou->entity[i].pos.x][garou->entity[i].pos.y] = &garou->entity[i];
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		if (garou->entity[0].life > 0 && entity_set_dir(&garou->entity[0], &garou->map, info))
			for (size_t i = 1; i < garou->nb_entity; i++)
				if (garou->entity[i].life > 0)
					entity_set_dir2(&garou->entity[i], &garou->map, info);
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
