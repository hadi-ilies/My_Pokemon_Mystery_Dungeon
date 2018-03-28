/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** map_game_loop.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "prototype.h"

void move_map(sfVector2f *pos)
{
	sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue ? pos->x++ : 0;
	sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue ? pos->x-- : 0;
	sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue ? pos->y-- : 0;
	sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue ? pos->y++ : 0;
}
void zoom_map(sfEvent *event, map_t *map)
{
	if (event->type == sfEvtMouseWheelScrolled)
		map->size.x += event->mouseWheelScroll.delta * 2;
	if (map->size.x > 200)
		map->size.x = 200;
	if (map->size.x < 20)
		map->size.x = 20;
	map->size.y = map->size.x;
}

int map_editor_loop(sfRenderWindow *window, map_t *map)
{
	sfVector2f pos = {10, 10};
	sfEvent event;
	sfFloatRect rect = {100, 100, 100, 100};

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			zoom_map(&event, map);
		}
		sfRenderWindow_clear(window, sfBlack);
		map_aff(window, map, pos);
		tile_map_aff(window, map->tile_map, TVA(1, 4, 1), rect);
		move_map(&pos);
		sfRenderWindow_display(window);
	}
	return (0);
}
