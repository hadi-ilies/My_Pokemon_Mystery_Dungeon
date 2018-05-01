/*
** EPITECH PROJECT, 2018
** strtofloat
** File description:
** strtofloat
*/

#include <stdlib.h>

float get_float(char *str)
{
	float nb = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		else if (str[i] == '.')
			break;
		else
			return (0);
	return (nb);
}
