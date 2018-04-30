/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** entity_gain_exp.c
*/

#include "entity.h"

size_t entity_gain_exp(entity_t *entity, size_t exp)
{
	size_t nb_level_pass = 0;

	if (entity->level < 100)
		entity->exp += exp;
	while (entity->level < 100 && entity->exp >= EXP_MAX(*entity)) {
		entity->exp -= EXP_MAX(*entity);
		entity->level++;
		nb_level_pass++;
	}
	if (entity->level >= 100) {
		entity->level = 100;
		entity->exp = EXP_MAX(*entity);
	}
	return (nb_level_pass);
}
