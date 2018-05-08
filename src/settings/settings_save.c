/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** settings_save.c
*/

#include <fcntl.h>
#include "settings.h"
#include "my.h"

static void insert_in_file(settings_t *settings, int fd)
{
	my_fprintf(fd, "%s %d %d\n", "WindowSize:", settings->window_size.x,
		settings->window_size.y);
	my_fprintf(fd, "%s %f\n", "MusicVolume:", settings->music_volume);
	my_fprintf(fd, "%s %f\n", "SoundVolume:", settings->sound_volume);
	my_fprintf(fd, "%s %d\n", "KeyUp:", settings->key[KEY_UP]);
	my_fprintf(fd, "%s %d\n", "KeyLeft:", settings->key[KEY_LEFT]);
	my_fprintf(fd, "%s %d\n", "KeyRight:", settings->key[KEY_RIGHT]);
	my_fprintf(fd, "%s %d\n", "KeyDown:", settings->key[KEY_DOWN]);
	my_fprintf(fd, "%s %d\n", "KeyEnter:", settings->key[KEY_ENTER]);
	my_fprintf(fd, "%s %d\n", "KeyEchap:", settings->key[KEY_ECHAP]);
	my_fprintf(fd, "%s %d\n", "KeyWait:", settings->key[KEY_WAIT]);
	my_fprintf(fd, "%s %d\n", "KeyMove:", settings->key[KEY_MOVE]);
	my_fprintf(fd, "%s %d\n", "KeyAttack:", settings->key[KEY_ATTACK]);
	my_fprintf(fd, "%s %d\n", "KeyInventory:",
		settings->key[KEY_INVENTORY]);
}

void settings_save(settings_t *settings, char *file_name)
{
	int fd = CREAT(file_name, S_IRUSR | S_IWUSR | S_IRGRP);

	if (fd == -1)
		return;
	if (settings == NULL)
		*settings = settings_defaut();
	insert_in_file(settings, fd);
	close(fd);
}
