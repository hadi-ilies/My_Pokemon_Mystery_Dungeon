/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu.c
*/

#include <prototype.h>

sfRenderWindow *window_create(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (window == NULL)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	return (window);
}

int main_menu(void)
{
	sfRenderWindow *window = window_create();
	sfEvent event;

	sfRenderWindow_display(window);
	main_intro(window, &event);
	exit(0);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		sfRenderWindow_clear(window, sfBlack);
		//
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return (0);
}
