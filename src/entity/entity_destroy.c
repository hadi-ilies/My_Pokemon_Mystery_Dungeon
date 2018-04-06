/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_destroy.c
*/

#include "entity.h"

void entity_destroy(entity_t *entity)
{
	sfClock_destroy(entity->clock);
	anime_tab_destroy(&entity->anime_tab);
}
