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

//void display_ad_intro(sfRenderWindow *window, intro_adventure_t *ad_intro)
//{
	//sfRenderWindow_drawRectangleShape(window, menu->rect[0], NULL);
	//sfRenderWindow_drawText(window, ad_intro->text, NULL);
//}

void adventure_intro(sfRenderWindow *window, menu_t *menu)
{
	(void)menu;
	intro_adventure_t ad_intro = ad_intro_create();
	sfEvent event;
	size_t button = 0;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape) || button > 5)
				return;
			if (event.type == sfEvtKeyPressed
			&& event.key.code == sfKeyReturn)
				button++;
		}
		sfRenderWindow_clear(window, sfBlack);
		display_history(window, &ad_intro, button);
		//display_ad_intro(window, &ad_intro);
		sfRenderWindow_display(window);
	}
}
