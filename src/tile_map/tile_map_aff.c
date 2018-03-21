/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** tile_map_aff.c
*/

#include "tile_map.h"

void tile_map_aff(sfRenderWindow *window, tile_map_t *tile_map,
		  tva_t tva, sfFloatRect rect)
{
	sfSprite *sprite = tile_map->image[tva.type][tva.var][tva.alt].sprite;
	sfFloatRect bounds = sfSprite_getLocalBounds(sprite);
	sfVector2f pos = {rect.left, rect.top};
	sfVector2f scale;

	scale.x = rect.width / bounds.width;
	scale.y = rect.height / bounds.height;
	sfSprite_setPosition(sprite, pos);
	sfSprite_setScale(sprite, scale);
	sfRenderWindow_drawSprite(window, sprite, NULL);
}
