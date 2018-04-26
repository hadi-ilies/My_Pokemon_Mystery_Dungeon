/*
** EPITECH PROJECT, 2018
** create settings
** File description:
** create setings
*/

#include <unistd.h>
#include <stdlib.h>
#include "settings.h"

settings_t create_setting(void)
{
	settings_t settings;

	settings.window_size = (sfVector2u) {1920, 1080};
	settings.sound_volume = 100;
	settings.music_volume = 100;
	return (settings);
}
