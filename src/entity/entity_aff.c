/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_aff.c
*/

#include "entity.h"

void entity_aff2(sfRenderWindow *window, entity_t *entity,
		 map_t *map, sfVector2f pos)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f or = {map->size.x / 2, map->size.y / 2};
	sfVector2f posi2 = {win_size.x / 2, win_size.y / 2};

	posi2.x += (entity->pos.x - pos.x) * map->size.x;
	posi2.y += (entity->pos.y - pos.y) * map->size.y;
	sfRectangleShape_setSize(rect, map->size);
	sfRectangleShape_setOrigin(rect, or);
	sfRectangleShape_setPosition(rect, posi2);
	sfRectangleShape_setFillColor(rect, (sfColor){255, 255, 255, 100});
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
}

void entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f pos)
{
	entity_aff2(window, entity, map, pos);
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfFloatRect rect = {map->size.x, map->size.y, map->size.x, map->size.y};

	rect.left *= entity_get_move_pos(entity).x - pos.x;
	rect.top *= entity_get_move_pos(entity).y - pos.y;
	rect.left += win_size.x / 2;
	rect.top += win_size.y / 2;
	anime_tab_aff(window, &entity->anime_tab, rect);
}
