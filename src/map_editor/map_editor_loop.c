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
#include "tile_name.h"
#include "macro.h"
#include "map_editor_function.h"

bool isit_on_inventory(map_t *map, sfRenderWindow *window)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2i coord_mouse = sfMouse_getPositionRenderWindow(window);
	sfVector2f origin;

	origin.x = win_size.x / 2 - map->tile_map.nb_type / 2 * TOOL_DIST;
	origin.y = win_size.y - TOOL_SIZE / 2;
	for (size_t i = 0; i < map->tile_map.nb_type; i++) {
		sfFloatRect rect = {.width = TOOL_SIZE, .height = TOOL_SIZE};

		rect.left = origin.x + i * TOOL_DIST;
		rect.top = origin.y;
		if (hit_point_rect(&coord_mouse, &rect))
			return (true);
	}
	return (false);
}

void clean_map(map_t *map)
{
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			map->tab[i][j] = TVA(0, 0, 0);
	map_smooth_all(map);
}

void window_open_func(sfRenderWindow *window, map_t *map,
		tva_t *mouse_tva, back_and_music_t *optional)
{
	move_map(&map->pos);
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, optional->sprite, NULL);
	map_aff(window, map);
	display_tools(window, map, mouse_tva);
	tile_map_aff(window, &map->tile_map, *mouse_tva, RECT_MOUSE);
	sfRenderWindow_display(window);
}

void key_command_editor(sfRenderWindow *window, map_t *map, sfEvent *event)
{
	LINK_ROOMS_WITH_P;
	CLEAN_MAP_WITH_C;
	//PLAY_YOUR_MAP_WITH_G;
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyG) {
		garou_t garou;

		game_loop(window, &garou);
	}
}

int map_editor_loop(sfRenderWindow *window, map_t *map)
{
	tva_t mouse_tva = {map->tile_map.nb_type, 4, 0};
	sfEvent event;
	back_and_music_t optional = optional_create();

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
				sfMusic_destroy(optional.music);
				return (0);
			}
			key_command_editor(window, map, &event);
			zoom_map(&event, map);
			refresh_map(&event, map);
			manage_map(&event, window, map, &mouse_tva);
		}
		window_open_func(window, map, &mouse_tva, &optional);
	}
	return (0);
}
