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
#include "item.h"
#include "macro.h"

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
		printf("%s : %ld - %ld = ", capacity->name, INFO(*entity)->life, damage);
		if (INFO(*entity)->life > damage)
			INFO(*entity)->life -= damage;
		else {
			INFO(*entity)->life = 0;
			entity_gain_exp(entity, INFO(*entity)->level + rand() % INFO(*entity)->level);
		}
		printf("%ld\n", INFO(*entity)->life);
		set_anime_hurt(INFO(*entity));
		//INFO(*entity)->dir.x = 0;
		//INFO(*entity)->dir.y = 0;
		//sfClock_restart(INFO(*entity)->clock);
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
	set_anime_idle(entity);
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
		if (entity->life < STAT(*entity, life))
			entity->life++;
		return (true);
	}
	return (false);
}

entity_t *get_cible(entity_t *entity, map_t *map,
		    entity_t *info[map->nb_case_x][map->nb_case_y])
{
	size_t dist = 5;
	size_t i_min = (entity->pos.x - (ssize_t)dist >= 0 ? entity->pos.x - dist : 0);
	size_t j_min = (entity->pos.y - (ssize_t)dist >= 0 ? entity->pos.y - dist : 0);
	size_t i_max = (entity->pos.x + dist <= map->nb_case_x - 1 ? entity->pos.x + dist : map->nb_case_x - 1);
	size_t j_max = (entity->pos.y + dist <= map->nb_case_y - 1 ? entity->pos.y + dist : map->nb_case_y - 1);

	for (size_t i = i_min; i < i_max; i++)
		for (size_t j = j_min; j < j_max; j++)
			if (info[i][j] && info[i][j]->ia == 0)
			return (info[i][j]);

	return (NULL);
}

void ia2(map_t *map, size_t tab[map->nb_case_x][map->nb_case_y], size_t x, size_t y)
{
	for (char i = -1; i <= 1; i++)
		for (char j = -1; j <= 1; j++)
			if (map->tab[x + i][y + j].type == GROUND && tab[x + i][y + j] == 0) //
				tab[x + i][y + j] = tab[x][y] + 1;
}

sfVector2i new_pos(entity_t *entity, size_t input)
{
	sfVector2i pos = entity->pos;

	input & LEFT ? pos.x += -1 : 0;
	input & RIGHT ? pos.x += 1 : 0;
	input & UP ? pos.y += -1 : 0;
	input & DOWN ? pos.y += 1 : 0;
	return (pos);
}

size_t ia(entity_t *entity, map_t *map,
	  entity_t *info[map->nb_case_x][map->nb_case_y])
{
	size_t input = 0;
	entity_t *cible = get_cible(entity, map, info);

	if (cible) {
		size_t tab[map->nb_case_x][map->nb_case_y];

		for (size_t i = 0; i < map->nb_case_x; i++)
			for (size_t j = 0; j < map->nb_case_y; j++)
				tab[i][j] = 0;
		tab[cible->pos.x][cible->pos.y] = 1;
		for (size_t n = 1; n <= 20; n++)
			for (size_t i = 1; i < map->nb_case_x - 1; i++)
				for (size_t j = 1; j < map->nb_case_y - 1; j++)
					if (tab[i][j] == n)
						ia2(map, tab, i, j);
		if (tab[entity->pos.x][entity->pos.y] == 0)
			input = (rand() % 0b1111 + 1) | MOVE | WAIT;
		else
			for (char i = -1; i <= 1; i++)
				for (char j = -1; j <= 1; j++)
					if (tab[entity->pos.x + i][entity->pos.y + j] < tab[entity->pos.x][entity->pos.y] && tab[entity->pos.x + i][entity->pos.y + j] != 0) {
						i == -1 ? input |= LEFT : 0;
						i == 1 ? input |= RIGHT : 0;
						j == -1 ? input |= UP : 0;
						j == 1 ? input |= DOWN : 0;
						if (info[entity->pos.x + i][entity->pos.y + j] && info[entity->pos.x + i][entity->pos.y + j]->ia == 0)
							input |= ATTACK;
						else
							input |= MOVE;
						input |= WAIT;
					}
	}
	else {
		/*map->tab[entity->pos.x - entity->dir.x][entity->pos.y - entity->dir.y].type = WATER;
		while (1) {
			sfVector2i pos;
		*/
			input = (0b001 << (rand() % 4));
			/*	pos = new_pos(entity, input);
			if (map->tab[pos.x][pos.y].type == GROUND)
				break;
		}
		map->tab[entity->pos.x - entity->dir.x][entity->pos.y - entity->dir.y].type = GROUND;*/
		input |= MOVE | WAIT;
	}
	return (input);
}

bool entity_set_dir(entity_t *entity, garou_t *garou,
		    entity_t *info[garou->dungeon.map.nb_case_x][garou->dungeon.map.nb_case_y],
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
	}
	else
		input = ia(entity, &garou->dungeon.map, info);
	return (manage_input(entity, &garou->dungeon.map, info, input));
}

void info_update(garou_t *garou,
		 entity_t *info[garou->dungeon.map.nb_case_x][garou->dungeon.map.nb_case_y])
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
void entity_life_aff(sfRenderWindow *window, entity_t *entity, sfFloatRect rect)
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

void inventory_aff(sfRenderWindow *window, garou_t *garou)
{
	sfRectangleShape *rectangle = sfRectangleShape_create();
	sfRectangleShape *rectangle_ombre = sfRectangleShape_create();
	sfTexture *texture = sfTexture_createFromFile(STAT_RECT, NULL);
	sfTexture *texture_ombre = sfTexture_createFromFile(STAT_SHADOW, NULL);
	sfFont *font = sfFont_createFromFile(GAME_FONT);
	sfText *text = sfText_create();
	char *str = malloc(sizeof(char) * 20);
	sfVector2f size = {600, 600};

	sfRectangleShape_setPosition(rectangle, V2F(250, 250));
	sfRectangleShape_setPosition(rectangle_ombre, V2F(250 + size.x / 20, 250 + size.y / (6 * 2) - (30 * 2.666) / 2));
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setSize(rectangle_ombre, V2F(500, 30 * 2.666));
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	sfRectangleShape_setTexture(rectangle_ombre, texture_ombre, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);

	sfText_setPosition(text, V2F(250 + size.x / 5, 250 + size.y / (6 * 2) - 30 / 2));
	sfText_setFont(text, font);
	sprintf(str, "HP : %ld/%ld\n", garou->dungeon.entity[0].life, STAT(garou->dungeon.entity[0], life));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "atk : %ld\n", STAT(garou->dungeon.entity[0], atk));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "def : %ld\n", STAT(garou->dungeon.entity[0], def));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "spa : %ld\n", STAT(garou->dungeon.entity[0], spa));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "spd : %ld\n", STAT(garou->dungeon.entity[0], spd));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "speed : %ld\n", STAT(garou->dungeon.entity[0], speed));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	free(str);
	sfFont_destroy(font);
	sfText_destroy(text);
	sfTexture_destroy(texture);
	sfTexture_destroy(texture_ombre);
	sfRectangleShape_destroy(rectangle);
	sfRectangleShape_destroy(rectangle_ombre);
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
	entity_t *info[garou->dungeon.map.nb_case_x][garou->dungeon.map.nb_case_y];
	size_t entity_turn = 0;

	while (sfRenderWindow_isOpen(window)) {
		bool next = garou->dungeon.entity[entity_turn].life ? false : true;

		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
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
		if (garou->dungeon.map.item[garou->dungeon.entity[0].pos.x][garou->dungeon.entity[0].pos.y] == STAIRCASE && sfClock_getElapsedTime(garou->dungeon.entity[0].clock).microseconds >= TIME_MOVE)
			return (1);
	}
	return (0);
}
