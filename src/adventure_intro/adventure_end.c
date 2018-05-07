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

bool event_end(sfEvent *event, size_t *button, menu_t *menu)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) || *button > 5) {
		sfMusic_pause(menu->sound.music[1]);
		return (true);
	} if (event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyReturn)
		(*button)++;
	return (false);
}

void adventure_end(sfRenderWindow *window, menu_t *menu)
{
	intro_adventure_t ad_intro = ad_intro_create();
	sfEvent event;
	size_t button = 0;

	sfMusic_play(menu->sound.music[1]);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (RETURN_TO_MENU_WITH_ENTER) {
				ad_intro_destroy(&ad_intro);
				return;
			} if (event_end(&event, &button, menu))
				END_PAGE;
		}
		sfRenderWindow_clear(window, sfBlack);
		illustration_end(button, &ad_intro);
		sfRenderWindow_drawRectangleShape(window, ad_intro.rect, NULL);
		button < 6 ? display_history(window, &ad_intro, button, menu):0;
		sfRenderWindow_display(window);
	}
}
