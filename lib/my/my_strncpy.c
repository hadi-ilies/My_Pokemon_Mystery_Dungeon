/*
** EPITECH PROJECT, 2018
** strncpy
** File description:
** strcpy
*/

#include <my.h>

char *my_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];
	if (n < i)
		dest[i] = '\0';
	return (dest);
}
