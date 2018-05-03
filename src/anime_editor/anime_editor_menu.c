/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** anime_editor_menu.c
*/

#include <stdlib.h> //tmp
#include <unistd.h> //tmp
#include <fcntl.h> //tmp
#include "macro.h"
#include "prototype.h"
#include "anime_tab.h"
#include "anime_name.h"

void anime_tab_add_texture(anime_tab_t *anime_tab, char *file_name)
{
	texname_t *texname = malloc(sizeof(texname_t) *
				(anime_tab->nb_texname + 1));

	if (texname == NULL) {
		anime_tab->error = ERR_MALLOC;
		return;
	}
	for (size_t i = 0; i < anime_tab->nb_texname; i++)
		texname[i] = anime_tab->texname[i];
	texname[anime_tab->nb_texname].file_name = my_strdup(file_name);
	texname[anime_tab->nb_texname].texture =
		sfTexture_createFromFile(file_name, NULL);
	if (texname[anime_tab->nb_texname].texture == NULL) {
		anime_tab->error = ERR_TEXTURE_CREATE;
		return;
	}
	free(anime_tab->texname);
	anime_tab->texname = texname;
	anime_tab->nb_texname++;
}

int anime_editor_menu(sfRenderWindow *window)
{
	anime_tab_t anime_tab;
	char *conf = "resources/texture/anime_tab/gobou_config";

	anime_tab = anime_tab_create_from_file(conf);
	if (anime_tab.error != ERR_OK)
		return (84);
	anime_editor_loop(window, &anime_tab);
	save(&anime_tab, conf);
	anime_tab_destroy(&anime_tab);
	return (0);
}
