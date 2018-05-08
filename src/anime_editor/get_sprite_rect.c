/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** get_sprite_rect.c
*/

#include "prototype.h"

sfFloatRect get_sprite_rect(sfSprite *sprite)
{
	sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);
	sfFloatRect rect_div = sfSprite_getLocalBounds(sprite);

	sprite_rect.width /= rect_div.width;
	sprite_rect.height /= rect_div.height;
	return (sprite_rect);
}
