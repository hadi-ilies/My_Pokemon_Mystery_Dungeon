/*
** EPITECH PROJECT, 2018
** illutr
** File description:
** illustration
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "adventure_intro.h"

void illustration(sfRenderWindow *window, size_t button,
		intro_adventure_t *ad_intro)
{
	static size_t i = 0;

	if (i < 255)
		sfRectangleShape_setFillColor(ad_intro->rect,
				(sfColor) {255, 255, 255, i++});
	if (button == 0)
		sfRenderWindow_drawRectangleShape(window, ad_intro->rect, NULL);
	//if (button == 1)
}
