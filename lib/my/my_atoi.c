/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdlib.h>
#include <unistd.h>

int my_atoi(char *str)
{
	int nb = 0;

	if (str == NULL)
		return (-1);
	for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (-2);
	} for (; *str >= '0' && *str <= '9'; (str)++)
		nb = nb * 10 + (*str - '0');
	if (str[0] == '-')
		return (-nb);
	return (nb);
}
