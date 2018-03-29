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

void pick_tile(sfRenderWindow *window, map_t *map, sfFloatRect rect, int sprite_size, int i)
{
	sfVector2i coord_mouse = sfMouse_getPositionRenderWindow(window);
	sfFloatRect rec = (sfFloatRect) {coord_mouse.x, coord_mouse.y, sprite_size, sprite_size};
	static int sprite = 3; //tmp

	if (hit_point_rect(&coord_mouse, &rect) == true) //tmp
		sprite = i;//tmp
	tile_map_aff(window, map->tile_map, TVA(sprite, 0, 0), rec); //tmp
}

void display_tools(sfRenderWindow *window, map_t *map)
{
	const size_t sprite_size = 100;
	const size_t sprite_dist = 200;

	sfVector2f origin = {WINDOW_WIDTH / 2 - map->tile_map->nb_type / 2 * sprite_dist,
			WINDOW_HEIGHT - sprite_size / 2};
	for (size_t i = 0; i < map->tile_map->nb_type; i++) {
		sfFloatRect rect = {origin.x + i * sprite_dist, origin.y, sprite_size, sprite_size};

		tile_map_aff(window, map->tile_map, TVA(i, 0, 0), rect);
		pick_tile(window, map, rect, sprite_size, i);
	}
}
int map_editor_loop(sfRenderWindow *window, map_t *map)
{
	sfVector2f pos = {10, 10};
	sfEvent event;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			zoom_map(&event, map);
		}
		sfRenderWindow_clear(window, sfBlack);
		map_aff(window, map, pos);
		display_tools(window, map);
		move_map(&pos);
		sfRenderWindow_display(window);
	}
	return (0);
}
