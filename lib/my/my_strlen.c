/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** my_strlen.c
*/

#include "my.h"

size_t my_strlen(const char *str)
{
	size_t size;

	if (str == NULL)
		return (0);
	for (size = 0; str[size] != '\0'; size++);
	return (size);
}
