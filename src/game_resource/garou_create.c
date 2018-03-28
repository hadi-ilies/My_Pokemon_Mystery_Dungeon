/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** garou_create.c
*/

#include "game_resource.h"

garou_t game_create(void)
{
	garou_t garou;

	garou.nb_tile_map = 0;
	garou.tile_map = NULL;
	garou.nb_anime_tab = 0;
	garou.anime_tab = NULL;
	return (garou);
}
