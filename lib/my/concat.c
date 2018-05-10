/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <stdlib.h>
#include "my.h"

char *inttostr(int nb)
{
	char *str = malloc(sizeof(char) * 20);
	int size = 1;

	if (nb == 0)
		return ("0");
	for (int nb2 = nb; nb2 >= 10; nb2 /= 10)
		size++;
	for (int i = 0; i <= size; i++)
		str[i] = '\0';
	for (int j = 1; nb > 0 ; j++) {
		str[size - j] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

char *concat(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	int c = 0;
	char *str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));

	if (str == NULL)
		return (NULL);
	for (int i = 0; s1[i] != '\0'; i++) {
		str[c] = s1[i];
		c++;
	}
	for (int j = 0; s2[j] != '\0'; j++) {
		str[c] = s2[j];
		c++;
	}
	str[c] = '\0';
	return (str);
}
