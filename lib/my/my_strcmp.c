/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(const char *a, const char *b)
{
	return (*a != *b || *a == '\0' ? *a - *b : my_strcmp(a + 1, b + 1));
}
