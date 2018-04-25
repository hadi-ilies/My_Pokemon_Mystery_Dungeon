/*
** EPITECH PROJECT, 2018
** my
** File description:
** my_atoi
*/

#include "my.h"

bool my_atoi(int *nb, char *str)
{
	size_t i = 0;

	if (nb == NULL || str == NULL)
		return (false);
	for (; str[i] != '\0'; i++) {
		bool tmp = false;

		str[i] >= '0' && str[i] <= '9' ? tmp = true : 0;
		!i && (str[i] == '+' || str[i] == '-') ? tmp = true : 0;
		if (tmp == false)
			return (false);
	}
	*nb = 0;
	i = (*str == '-' || *str == '+' ? 1 : 0);
	for (; str[i] != '\0'; i++)
		*nb = *nb * 10 + str[i] - '0';
	*nb = (*str == '-' ? -*nb : *nb);
	return (true);
}
