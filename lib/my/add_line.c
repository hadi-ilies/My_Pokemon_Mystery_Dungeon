/*
** EPITECH PROJECT, 2018
** add_line
** File description:
** add_line
*/

#include <stdlib.h>
#include "my.h"

char **add_line(char **map, char *line)
{
	size_t i = 0;
	char **new_map;

	if (line == NULL)
		return (map);
	for (; map && map[i] != NULL; i++);
	if ((new_map = malloc(sizeof(char *) * (i + 2))) == NULL)
		return (NULL);
	for (i = 0; map && map[i] != NULL; i++)
		new_map[i] = map[i];
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}
