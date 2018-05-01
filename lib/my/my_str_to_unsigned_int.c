/*
** EPITECH PROJECT, 2018
** strtouint
** File description:
** sttouint
*/

#include <stdlib.h>

size_t get_uint(char *str)
{
	unsigned int nb = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		else
			return (0);
	return (nb);
}
