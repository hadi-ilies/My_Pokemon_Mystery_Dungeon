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

void credit_menu(sfRenderWindow *window, sfEvent *event)
{
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_display(window);
	}
}
