/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** add_rectex.c
*/

#include "prototype.h"

void add_rectex(anime_t *anime)
{
	rectex_t *rectex = malloc(sizeof(rectex_t) * (anime->nb_rectex + 1));

	if (!rectex)
		return;
	for (size_t i = 0; i < anime->nb_rectex; i++)
		rectex[i] = anime->rectex[i];
	rectex[anime->nb_rectex] = (rectex_t){0, {0, 0, 0, 0}};
	free(anime->rectex);
	anime->rectex = rectex;
	anime->nb_rectex++;
}
