/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map_editor_function.h
*/

#ifndef MAP_EDITOR_FUNCTION_H_
#define MAP_EDITOR_FUNCTION_H_

#include "prototype.h"

typedef struct {
	sfSprite *sprite;
	sfTexture *texture;
	sfMusic *music;
} back_and_music_t;

void move_map(sfVector2f *pos);
void zoom_map(sfEvent *event, map_t *map);
bool hit_point_rect(sfVector2i *point, sfFloatRect *rect);
back_and_music_t optional_create(void);
#endif
