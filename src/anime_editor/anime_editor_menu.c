/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** anime_editor_menu.c
*/

#include <stdlib.h> //tmp
#include "prototype.h"
#include "anime_tab.h"

int anime_editor_menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;
	//anime_tab_t anime_tab;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	//anime_editor_loop(window, &anime_tab);
	//anime_tab_destroy(&anime_tab);
	sfRenderWindow_destroy(window);
	return (0);
}
