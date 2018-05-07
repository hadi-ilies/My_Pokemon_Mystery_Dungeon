/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rand_min_max.c
*/

#include <stdlib.h>
#include "my.h"

int rand_min_max(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}
