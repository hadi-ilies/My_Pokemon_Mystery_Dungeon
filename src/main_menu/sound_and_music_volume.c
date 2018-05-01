/*
** EPITECH PROJECT, 2018
** sound and music
** File description:
** sound and music
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "option_map_editor.h"
#include "main_menu/option_menu.h"

void music_volume(sfEvent *event,
		  sfRenderWindow *window, option_t *option, menu_t *menu)
{
	char *str;

	if (option->choice_curs == 1) {
		if (menu->settings.music_volume < 100
		&& event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight)
			menu->settings.music_volume++;
		if (menu->settings.music_volume > 0
		&& event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft)
			menu->settings.music_volume--;
	}
	str = inttostr((int)menu->settings.music_volume);
	sfText_setString(option->sound_value[0], str);
	sfText_setPosition(option->sound_value[0],
		(sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2 - 200});
	free(str);
}

void sound_volume(sfEvent *event,
		  sfRenderWindow *window, option_t *option, menu_t *menu)
{
	char *str;

	if (option->choice_curs == 2) {
		if (menu->settings.sound_volume < 100
		&& event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight)
			menu->settings.sound_volume++;
		if (menu->settings.sound_volume > 0
		&& event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft)
			menu->settings.sound_volume--;
	}
	str = inttostr((int)menu->settings.sound_volume);
	sfText_setString(option->sound_value[1], str);
	sfText_setPosition(option->sound_value[1],
		(sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2 - 100});
	free(str);
}
