/*
** EPITECH PROJECT, 2018
** option
** File description:
** option
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"

void option_menu(sfRenderWindow *window, sfEvent *event)
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
