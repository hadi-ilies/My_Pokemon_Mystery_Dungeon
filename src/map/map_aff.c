/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_aff.c
*/

#include "map.h"

void map_aff(sfRenderWindow *window, map_t *map, sfVector2f *pos)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f or = {map->size.x / 2, map->size.y / 2};
	sfVector2f posi2 = {win_size.x / 2, win_size.y / 2};

	sfRectangleShape_setSize(rect, map->size);
	sfRectangleShape_setOrigin(rect, or);
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++) {
			sfColor color = {255, 255, 255, 20};
			sfVector2f posi = {map->size.x * (i - pos->x) + posi2.x, map->size.y * (j - pos->y) + posi2.y};

			sfRectangleShape_setPosition(rect, posi);
			map->tab[i][j].type ? color.a += 100 : 0;
			(i + j) % 2 ? color.a += 20 : 0;
			sfRectangleShape_setFillColor(rect, color);
			sfRenderWindow_drawRectangleShape(window, rect, NULL);
		}
	sfRectangleShape_destroy(rect);
}
