/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_aff.c
*/

#include "entity.h"

void entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f *pos)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f or = {map->size.x / 2, map->size.y / 2};
	sfVector2f posi2 = {win_size.x / 2, win_size.y / 2};

	posi2.x += (entity->move_pos.x - pos->x) * map->size.x;
	posi2.y += (entity->move_pos.y - pos->y) * map->size.y;
	sfRectangleShape_setSize(rect, map->size);
	sfRectangleShape_setOrigin(rect, or);
	sfRectangleShape_setPosition(rect, posi2);
	sfRectangleShape_setFillColor(rect, sfWhite);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}
