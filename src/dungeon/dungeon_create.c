/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** dungeon_create.c
*/

#include "dungeon.h"

dungeon_t dungeon_create(void)
{
	dungeon_t dungeon;

	dungeon.stage_num = 0;
	dungeon.nb_stage = 0;
	dungeon.nb_entity = 0;
	dungeon.entity = NULL;
	return (dungeon);
}
