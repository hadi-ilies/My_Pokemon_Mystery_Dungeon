/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** settings.h
*/

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <SFML/Graphics.h>

enum key {
	KEY_UP,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_DOWN,
	KEY_ENTER,
	KEY_ECHAP,
	KEY_WAIT,
	KEY_MOVE,
	KEY_ATTACK,
	KEY_INVENTORY,
	NB_KEY
};

typedef struct {
	sfVector2u window_size;
	float music_volume;
	float sound_volume;
	sfKeyCode key[NB_KEY];
} settings_t;

settings_t settings_defaut(void);
settings_t settings_load(char *file_name);
void settings_save(settings_t *settings, char *file_name);

#endif
