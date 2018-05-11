/*
** EPITECH PROJECT, 2018
** credit
** File description:
** credit
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "how_to_play.h"

void display_page(how_to_play_t *tuto)
{
	static size_t but = 0;

	if (but != tuto->page) {
		but = tuto->page;
		tuto->tex = true;
	} if (tuto->tex)
		sfSprite_setTexture(tuto->img, tuto->textu[but], sfTrue);
	tuto->tex = false;
}

bool turn_page(size_t *page, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyReturn)
		return (false);
	if (*page < NB_PAGE - 1 && event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyRight)
		(*page)++;
	if (*page > 0 && event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyLeft)
		(*page)--;
	return (true);
}

void credit_menu(sfRenderWindow *window, sfEvent *event)
{
	how_to_play_t tuto = create_tuto(window);
	bool exit = false;

	while (sfRenderWindow_isOpen(window) && exit == false) {
		while (sfRenderWindow_pollEvent(window, event)) {
			evt_close(event, window);
			!turn_page(&tuto.page, event) ? exit = true : 0;
		}
		display_page(&tuto);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, tuto.img, NULL);
		sfRenderWindow_display(window);
	}
}
