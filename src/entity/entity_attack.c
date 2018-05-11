/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_attack.c
*/

#include "entity.h"
#include "anime_name.h"

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
