/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "my.h"

static char *my_strdup_main(const char *str)
{
	size_t len = my_strlen(str) + 1;
	char *cpy = malloc(sizeof(char) * len);

	if (cpy == NULL)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		cpy[i] = str[i];
	return (cpy);
}

char *my_strdup(const char *str)
{
	if (str == NULL)
		return (NULL);
	return (my_strdup_main(str));
}
