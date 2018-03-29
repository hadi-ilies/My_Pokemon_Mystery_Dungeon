/*
** EPITECH PROJECT, 2018
** move
** File description:
** move
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "prototype.h"

void move_map(sfVector2f *pos)
{
	sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue ? pos->x++ : 0;
	sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue ? pos->x-- : 0;
	sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue ? pos->y-- : 0;
	sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue ? pos->y++ : 0;
}

void zoom_map(sfEvent *event, map_t *map)
{
	if (event->type == sfEvtMouseWheelScrolled)
		map->size.x += event->mouseWheelScroll.delta * 2;
	if (map->size.x > 200)
		map->size.x = 200;
	if (map->size.x < 20)
		map->size.x = 20;
	map->size.y = map->size.x;
}
