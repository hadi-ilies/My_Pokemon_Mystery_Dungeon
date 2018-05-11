/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** entity_life_aff.c
*/

#include "entity.h"
#include "macro.h"

void entity_life_aff(sfRenderWindow *window, entity_t *entity,
		sfFloatRect rect)
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
