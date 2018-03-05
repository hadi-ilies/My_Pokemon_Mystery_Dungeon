/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include "prototype.h"

int game(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		sfRenderWindow_clear(window, sfBlack);
		// aff
		sfRenderWindow_display(window);
	}
	return (0);
}
