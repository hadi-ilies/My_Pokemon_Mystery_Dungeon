/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** entity.h
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.h>
#include "map.h"
#include "anime_tab.h"

typedef struct {
	sfVector2i pos;
	sfVector2f move_pos;
	sfVector2i new_pos;
	anime_tab_t anime_tab;
} entity_t;

entity_t entity_create(char *anime_tab_config);
void entity_destroy(entity_t *entity);
void entity_set_pos(entity_t *entity, sfVector2i pos);
void entity_move(entity_t *entity);
void entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f pos);

#endif
