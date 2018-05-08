/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** settings_defaut.c
*/

#include "settings.h"
#include "macro.h"

settings_t settings_defaut(void)
{
	settings_t settings;

	settings.window_size = V2U(1920, 1080);
	settings.music_volume = 100.0;
	settings.sound_volume = 100.0;
	settings.key[KEY_UP] = sfKeyUp;
	settings.key[KEY_LEFT] = sfKeyLeft;
	settings.key[KEY_RIGHT] = sfKeyRight;
	settings.key[KEY_DOWN] = sfKeyDown;
	settings.key[KEY_ENTER] = sfKeyReturn;
	settings.key[KEY_ECHAP] = sfKeyEscape;
	settings.key[KEY_WAIT] = sfKeyW;
	settings.key[KEY_MOVE] = sfKeyLShift;
	settings.key[KEY_ATTACK] = sfKeySpace;
	settings.key[KEY_INVENTORY] = sfKeyI;
	return (settings);
}
