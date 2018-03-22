/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_create.c
*/

#include "entity.h"

entity_t entity_create(char *anime_tab_config)
{
	entity_t entity;
	sfVector2i v2i0 = {0, 0};
	sfVector2f v2f0 = {0, 0};

	entity.pos = v2i0;
	entity.move_pos = v2f0;
	entity.new_pos = v2i0;
	entity.anime_tab = anime_tab_create_from_file(anime_tab_config);
	return (entity);
}
