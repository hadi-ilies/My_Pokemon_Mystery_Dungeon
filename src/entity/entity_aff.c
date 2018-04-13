/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_aff.c
*/

#include "entity.h"

void entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f pos)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfFloatRect rect = {map->size.x, map->size.y, map->size.x, map->size.y};

	rect.left *= entity_get_move_pos(entity).x - pos.x;
	rect.top *= entity_get_move_pos(entity).y - pos.y;
	rect.left += win_size.x / 2;
	rect.top += win_size.y / 2;
	anime_tab_aff(window, &entity->anime_tab, rect);
}
