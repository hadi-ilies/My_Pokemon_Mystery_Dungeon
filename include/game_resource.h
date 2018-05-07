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

// file_macros
#define GAME_FONT "resources/font/Minecraftia.ttf"
#define CAPACITY_UP "resources/texture/Bup.png"
#define CAPACITY_LEFT "resources/texture/Bleft.png"
#define CAPACITY_RIGHT "resources/texture/Bright.png"
#define CAPACITY_DOWN "resources/texture/Bdown.png"
#define STAT_RECT "resources/texture/n1.png"
#define STAT_SHADOW "resources/texture/n5.png"

typedef struct {
	entity_t player;
	dungeon_t dungeon;
	settings_t settings;
} garou_t;

garou_t garou_create(char *settings_file_name);
void garou_destroy(garou_t *garou);
void capacity_aff(sfRenderWindow *window, garou_t *garou);

#endif
