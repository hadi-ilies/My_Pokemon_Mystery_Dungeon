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
/*
void display_ad_intro(sfRenderWindow *window, intro_adventure_t *ad_intro)
{
	sfRenderWindow_drawRectangleShape(window, menu->rect[0], NULL);
	sfRenderWindow_drawText(window, ad_intro->text, NULL);
}
*/
bool event_intro(sfEvent *event, size_t *button, menu_t *menu)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) || *button > 5) {
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
	sfEvent event;
	size_t button = 0;

	sfMusic_pause(menu->sound.sound_effect[6]);
	sfMusic_play(menu->sound.music[1]);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event_intro(&event, &button, menu))
				return;
		}
		sfRenderWindow_clear(window, sfBlack);
		display_history(window, &ad_intro, button, menu);
		//display_ad_intro(window, &ad_intro);
		sfRenderWindow_display(window);
	}
}
