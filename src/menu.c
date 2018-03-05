/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** menu.c
*/

#include "prototype.h"

int menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, 30);
	game(window);
	sfRenderWindow_destroy(window);
	return (0);
}
