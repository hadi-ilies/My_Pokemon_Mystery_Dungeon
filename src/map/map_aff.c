/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** map_aff.c
*/

#include "map.h"
#include "item_tab.h"

void item_aff(sfRenderWindow *window, enum item_e item, sfFloatRect rect)
{
	sfRectangleShape *rectangle;
	sfTexture *texture;
	sfVector2f pos = {rect.left, rect.top};
	sfVector2f size = {rect.width, rect.height};

	if (item <= NONE || item >= NB_ITEM)
		return;
	pos.x -= rect.width / 2;
	pos.y -= rect.height / 2;
	rectangle = sfRectangleShape_create();
	texture = sfTexture_createFromFile(item_file_name[item], NULL);
	if (texture == NULL)
		return;
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	sfTexture_destroy(texture);
	sfRectangleShape_destroy(rectangle);
}

void map_aff(sfRenderWindow *window, map_t *map)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f center = {win_size.x / 2, win_size.y / 2};
	tile_map_t *tile_map = &map->tile_map;

	for (size_t i = X_MIN; i < X_MAX; i++)
		for (size_t j = Y_MIN; j < Y_MAX; j++) {
			sfFloatRect rect;

			rect.left = map->size.x * (i - map->pos.x) + center.x;
			rect.top = map->size.y * (j - map->pos.y) + center.y;
			rect.width = map->size.x;
			rect.height = map->size.y;
			rect.left = (int)rect.left;
			rect.top = (int)rect.top;
			tile_map_aff(window, tile_map, map->tab[i][j], rect);
			item_aff(window, map->item[i][j], rect);
		}
}
