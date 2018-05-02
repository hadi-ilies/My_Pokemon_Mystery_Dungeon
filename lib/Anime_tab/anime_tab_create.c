/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** anime_tab_create.c
*/

#include "anime_tab.h"

anime_tab_t anime_tab_create(void)
{
	anime_tab_t anime_tab;

	anime_tab.nb_texname = 0;
	anime_tab.texname = NULL;
	anime_tab.nb_anime = 0;
	anime_tab.anime = NULL;
	anime_tab.clock = sfClock_create();
	anime_tab.sprite = sfSprite_create();
	anime_tab.num = 0;
	if (anime_tab.clock == NULL)
		anime_tab.error = ANIME_TAB_CLOCK_CREATE;
	else if (anime_tab.sprite == NULL)
		anime_tab.error = ANIME_TAB_SPRITE_CREATE;
	else
		anime_tab.error = ANIME_TAB_OK;
	return (anime_tab);
}
