/*
** EPITECH PROJECT, 2018
** adventure end
** File description:
** adventure end
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "adventure_intro.h"

static bool event_end(sfEvent *event, size_t *button, menu_t *menu)
{
	if (*button > 1) {
		sfMusic_pause(menu->sound.music[1]);
		return (true);
	} if (event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyReturn)
		(*button)++;
	return (false);
}

static bool event_end_loop(sfRenderWindow *window, menu_t *menu,
		size_t *but, sfEvent *event)
{
	while (sfRenderWindow_pollEvent(window, event)) {
		if (event_end(event, but, menu)) {
			return (false);
		}
	}
	return (true);
}

void adventure_end(sfRenderWindow *window, menu_t *menu)
{
	sfEvent event;
	intro_adventure_t ad_intro = ad_end_create();
	size_t but = 0;

	sfMusic_play(menu->sound.music[1]);
	while (sfRenderWindow_isOpen(window)) {
		if (!event_end_loop(window, menu, &but, &event)) {
			ad_intro_destroy(&ad_intro);
			return;
		}
		sfRenderWindow_clear(window, sfBlack);
		illustration_end(but, &ad_intro);
		sfRenderWindow_drawRectangleShape(window, ad_intro.rect, NULL);
		but == 0 ? display_history(window, &ad_intro, but, menu) : 0;
		sfRenderWindow_display(window);
	}
}
