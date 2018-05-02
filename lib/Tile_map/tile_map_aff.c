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
	sfSprite *sprite;
	rectex_t rectex;
	sfFloatRect bounds;
	sfVector2f origin;
	sfVector2f scale;

	if (window == NULL || tile_map == NULL)
		return;
	if (tva.type >= tile_map->nb_type)
		return;
	if (tva.var >= tile_map->nb_var[tva.type])
		return;
	if (tva.alt >= tile_map->nb_alt[tva.type][tva.var])
		return;
	sprite = tile_map->sprite;
	rectex = tile_map->rectex[tva.type][tva.var][tva.alt];
	sfSprite_setTexture(sprite, tile_map->texture[rectex.texture_num], 1);
	sfSprite_setTextureRect(sprite, rectex.rect);
	bounds = sfSprite_getLocalBounds(sprite);
	scale.x = rect.width / bounds.width;
	scale.y = rect.height / bounds.height;
	origin.x = bounds.width / 2;
	origin.y = bounds.height / 2;
	sfSprite_setScale(sprite, scale);
	sfSprite_setOrigin(sprite, origin);
	sfSprite_setPosition(sprite, (sfVector2f){rect.left, rect.top});
	sfRenderWindow_drawSprite(window, sprite, NULL);
}
