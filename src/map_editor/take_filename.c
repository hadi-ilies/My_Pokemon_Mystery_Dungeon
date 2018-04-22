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

char **malloc_filename(char *path)
{
	char **filename = malloc(sizeof(char *) * count_file(path));
	DIR *dir = NULL;
	int i = 0;
	struct dirent *d;

	if (filename == NULL)
		return (NULL);
	dir = opendir(path);
	if (dir == NULL)
		return (0);
	while ((d = readdir(dir))) {
		if (d->d_name[0] != '.') {
			filename[i] = malloc(sizeof(char) *
					(my_strlen(d->d_name) + 1));
			i++;
		}
	}
	closedir(dir);
	return (filename);
}

char **take_filename(char *path)
{
	char **filename = malloc_filename(path);
	DIR *dir = NULL;
	struct dirent *d;
	size_t j = 0;
	size_t i = 0;

	dir = opendir(path);
	if (dir == NULL)
		return (0);
	while ((d = readdir(dir))) {
		if (d->d_name[0] != '.') {
			for (j = 0; d->d_name[j] != '\0'; j++)
				filename[i][j] = d->d_name[j];
			filename[i][j] = '\0';
			i++;
		}
	}
	closedir(dir);
	return (filename);
}
