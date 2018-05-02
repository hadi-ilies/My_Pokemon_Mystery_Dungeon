/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** anime_tab_destroy.c
*/

#include <stdlib.h>
#include "anime_tab.h"

void anime_tab_destroy(anime_tab_t *anime_tab)
{
	for (size_t i = 0; i < anime_tab->nb_texname; i++) {
		free(anime_tab->texname[i].file_name);
		sfTexture_destroy(anime_tab->texname[i].texture);
	}
	free(anime_tab->texname);
	for (size_t i = 0; i < anime_tab->nb_anime; i++)
		free(anime_tab->anime[i].rectex);
	free(anime_tab->anime);
	sfClock_destroy(anime_tab->clock);
	sfSprite_destroy(anime_tab->sprite);
}
