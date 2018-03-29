/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** hit_functions.c
*/


#include <stdbool.h>
#include "prototype.h"

bool hit_point_rect(sfVector2i *point, sfFloatRect *rect)
{
	int nb = 0;

	point->x >= rect->left - rect->width / 2 ? nb++ : 0;
	point->y >= rect->top - rect->height / 2 ? nb++ : 0;
	point->x < rect->left + rect->width / 2 ? nb++ : 0;
	point->y < rect->top + rect->height / 2 ? nb++ : 0;
	return (nb == 4 ? true : false);
}

bool hit_point_sprite(sfVector2i *point, sfSprite *sprite)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

	return (hit_point_rect(point, &rect));
}
