/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** map_game_loop.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"

int map_editor_loop(sfRenderWindow *window, map_t *map)
{
	sfVector2f pos = {50, 50};
	sfEvent event;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		sfRenderWindow_clear(window, sfBlack);
		map_aff(window, map, &pos);
		sfRenderWindow_display(window);
	}
	return (0);
}
