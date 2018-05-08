/*
** EPITECH PROJECT, 2017
** test
** File description:
** my_atoi.c
*/

#include <stdlib.h>
#include <unistd.h>

int my_atoi(char *str)
{
	int nb = 0;

	if (str == NULL)
		return (-1);
	for (size_t i = 0; str[i] >= '0' && str[i] <= '9'; i++)
		nb = nb * 10 + str[i] - '0';
	return (nb);
}
