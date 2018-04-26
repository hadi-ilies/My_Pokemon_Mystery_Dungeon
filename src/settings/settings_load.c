/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** settings_load.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include "settings.h"
#include "my.h"

static size_t get_uint(char *str)
{
	unsigned int nb = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		else
			return (0);
	return (nb);
}

static float get_float(char *str)
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

static sfKeyCode get_sfkeycode(char *str)
{
	sfKeyCode nb = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		else
			return (0);
	return (nb);
}

static void get_key(settings_t *settings, char **tab)
{
	if (my_strcmp(tab[0], "KeyUp:") == 0)
		settings->key[KEY_UP] = get_sfkeycode(tab[1]);
	if (my_strcmp(tab[0], "KeyLeft:") == 0)
		settings->key[KEY_LEFT] = get_sfkeycode(tab[1]);
	if (my_strcmp(tab[0], "KeyRight:") == 0)
		settings->key[KEY_RIGHT] = get_sfkeycode(tab[1]);
	if (my_strcmp(tab[0], "KeyDown:") == 0)
		settings->key[KEY_DOWN] = get_sfkeycode(tab[1]);
	if (my_strcmp(tab[0], "KeyEnter:") == 0)
		settings->key[KEY_ENTER] = get_sfkeycode(tab[1]);
	if (my_strcmp(tab[0], "KeyEchap:") == 0)
		settings->key[KEY_ECHAP] = get_sfkeycode(tab[1]);
	if (my_strcmp(tab[0], "KeyWait:") == 0)
		settings->key[KEY_WAIT] = get_sfkeycode(tab[1]);
	if (my_strcmp(tab[0], "KeyRotate:") == 0)
		settings->key[KEY_ROTATE] = get_sfkeycode(tab[1]);
	if (my_strcmp(tab[0], "KeyAttack:") == 0)
		settings->key[KEY_ATTACK] = get_sfkeycode(tab[1]);
}

static void get_settings(settings_t *settings, char *line)
{
	char **tab = my_str_to_tab(line, " ");

	if (tab == NULL || !tab[0] || !tab[1])
		return;
	if (my_strcmp(tab[0], "WindowSize:") == 0 && tab[2]) {
		settings->window_size.x = get_uint(tab[1]);
		settings->window_size.y = get_uint(tab[2]);
	}
	if (my_strcmp(tab[0], "MusicVolume:") == 0)
		settings->music_volume = get_float(tab[1]);
	if (my_strcmp(tab[0], "SoundVolume:") == 0)
		settings->music_volume = get_float(tab[1]);
	get_key(settings, tab);
	for (size_t i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
}

settings_t settings_load(char *file_name)
{
	settings_t settings = settings_defaut();
	int fd = open(file_name, O_RDONLY);
	char *line;

	if (fd == -1)
		return (settings);
	while (1) {
		line = my_getline(fd);
		if (line == NULL)
			break;
		for (size_t i = 0; line[i] != '\0'; i++)
			line[i] == '#' ? line[i] = '\0' : 0;
		if (line[0] != '\0')
			get_settings(&settings, line);
		free(line);
	}
	close(fd);
	return (settings);
}
