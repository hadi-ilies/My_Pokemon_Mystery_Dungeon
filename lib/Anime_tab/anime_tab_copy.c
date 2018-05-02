/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** anime_tab_copy.c
*/

#include <stdlib.h>
#include "anime_tab.h"

char *my_strcpy(char *str)
{
	char *new_str;
	size_t i = 0;

	for (; str[i] != '\0'; i++);
	new_str = malloc(sizeof(char) * (i + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[i] = '\0';
	for (i = 0; str[i] != '\0'; i++)
		new_str[i] = str[i];
	return (new_str);
}

anime_tab_t anime_tab_copy(anime_tab_t *anime_tab)
{
	anime_tab_t anime_tab_cpy;

	anime_tab_cpy.nb_texname = anime_tab->nb_texname;
	anime_tab_cpy.texname = malloc(sizeof(texname_t) * anime_tab_cpy.nb_texname);
	if (anime_tab_cpy.texname == NULL) {
		anime_tab_cpy.error = ANIME_TAB_MALLOC;
		return (anime_tab_cpy);
	}
	for (size_t i = 0; i < anime_tab_cpy.nb_texname; i++) {
		anime_tab_cpy.texname[i].file_name = my_strcpy(anime_tab->texname[i].file_name);
		anime_tab_cpy.texname[i].texture = sfTexture_copy(anime_tab->texname[i].texture);
	}
	anime_tab_cpy.nb_anime = anime_tab->nb_anime;
	anime_tab_cpy.anime = malloc(sizeof(anime_t) * anime_tab_cpy.nb_anime);
	if (anime_tab_cpy.anime == NULL) {
		anime_tab_cpy.error = ANIME_TAB_MALLOC;
		return (anime_tab_cpy);
	}
	for (size_t i = 0; i < anime_tab_cpy.nb_anime; i++) {
		anime_tab_cpy.anime[i].nb_rectex = anime_tab->anime[i].nb_rectex;
		anime_tab_cpy.anime[i].rectex = malloc(sizeof(rectex_t) * anime_tab_cpy.anime[i].nb_rectex);
		if (anime_tab_cpy.anime[i].rectex == NULL) {
			anime_tab_cpy.error = ANIME_TAB_MALLOC;
			return (anime_tab_cpy);
		}
		for (size_t j = 0; j < anime_tab_cpy.anime[i].nb_rectex; j++)
			anime_tab_cpy.anime[i].rectex[j] = anime_tab->anime[i].rectex[j];
		anime_tab_cpy.anime[i].time = anime_tab->anime[i].time;
		anime_tab_cpy.anime[i].num = anime_tab->anime[i].num;
	}
	anime_tab_cpy.clock = sfClock_copy(anime_tab->clock);
	anime_tab_cpy.sprite = sfSprite_copy(anime_tab->sprite);
	anime_tab_cpy.num = anime_tab->num;
	anime_tab_cpy.error = anime_tab->error;
	return (anime_tab_cpy);
}
