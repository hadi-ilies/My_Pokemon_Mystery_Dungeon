/*
** EPITECH PROJECT, 2018
** take name
** File description:
** take na
*/

#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include "prototype.h"
#include "my.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"

char *name_conf(char *name)
{
	char *str = malloc(sizeof(char) * 100);
	int i = 0;

	for (i = 0; name[i] > ' '; i++)
		str[i] = name[i];
	str[i] = '\0';
	return (str);
}

char **take_filename(void)
{
	char **filename = NULL;
	DIR *dir = NULL;
	struct dirent *d;

	dir = opendir("resources/tile_map");
	if (dir == NULL)
		return (0);
	while ((d = readdir(dir))) {
		if (d->d_name[0] != '.') {
			char *str = name_conf(d->d_name);

			filename = add_line(filename, str);
		}
	}
	closedir(dir);
	return (filename);
}
