/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** game_resource.h
*/

#ifndef GAME_RESOURCE_H_
#define GAME_RESOURCE_H_

#include <SFML/Graphics.h>
#include "settings.h"
#include "dungeon.h"
#include "map.h"
#include "entity.h"
#include "item.h"

// game_macros
#define INVENTORY_SIZE 1

// file_macros
#define GAME_FONT "resources/font/Minecraftia.ttf"
#define CAPACITY_UP "resources/texture/Bup.png"
#define CAPACITY_LEFT "resources/texture/Bleft.png"
#define CAPACITY_RIGHT "resources/texture/Bright.png"
#define CAPACITY_DOWN "resources/texture/Bdown.png"
#define STAT_RECT "resources/texture/n1.png"
#define STAT_SHADOW "resources/texture/n5.png"

// code_macros
#define GET_INFO(map) info[(map).nb_case_x][(map).nb_case_y]
#define ITEM(map, entity) (map).item[(entity).pos.x][(entity).pos.y]

typedef struct {
	entity_t player;
	dungeon_t dungeon;
	enum item_e inventory[INVENTORY_SIZE];
	settings_t settings;
} garou_t;

garou_t garou_create(char *settings_file_name);
void garou_destroy(garou_t *garou);
void capacity_aff(sfRenderWindow *window, garou_t *garou);
size_t ia(entity_t *entity, map_t *map,
	  entity_t *info[map->nb_case_x][map->nb_case_y]);

#endif
