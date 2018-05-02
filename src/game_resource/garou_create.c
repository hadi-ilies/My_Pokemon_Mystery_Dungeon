/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** garou_create.c
*/

#include "game_resource.h"

garou_t garou_create(char *settings_file_name)
{
	garou_t garou;

	garou.nb_entity = 0;
	garou.entity = NULL;
	garou.settings = settings_load(settings_file_name);
	return (garou);
}
