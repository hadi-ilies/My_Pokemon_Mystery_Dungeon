/*
** EPITECH PROJECT, 2018
** adventure_intro
** File description:
** adventure_intro
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "adventure_intro.h"

bool event_intro(sfEvent *event, size_t *button,
		menu_t *menu, intro_adventure_t *ad_intro)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) || *button > 5) {
		ad_intro_destroy(ad_intro);
		sfMusic_pause(menu->sound.music[1]);
		return (true);
	} if (event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyReturn)
		(*button)++;
	return (false);
}

void adventure_intro(sfRenderWindow *window, menu_t *menu)
{
	intro_adventure_t ad_intro = ad_intro_create();
	size_t button = 0;
	bool set_one = true;

	sfMusic_pause(menu->sound.sound_effect[6]);
	sfMusic_play(menu->sound.music[1]);
	while (sfRenderWindow_isOpen(window)) {
		sfEvent event;

		while (sfRenderWindow_pollEvent(window, &event)) {
			if (evt_close(&event, window) ||
			event_intro(&event, &button, menu, &ad_intro))
				return;
		}
		sfRenderWindow_clear(window, sfBlack);
		illustration(window, button, &ad_intro, &set_one);
		display_history(window, &ad_intro, button, menu);
		sfRenderWindow_display(window);
	}
}
