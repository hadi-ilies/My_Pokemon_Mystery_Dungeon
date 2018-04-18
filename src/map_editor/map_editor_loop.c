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

	origin.x = win_size.x / 2 - map->tile_map->nb_type / 2 * TOOL_DIST;
	origin.y = win_size.y - TOOL_SIZE / 2;
	for (size_t i = 0; i < map->tile_map->nb_type; i++) {
		sfFloatRect rect = {.width = TOOL_SIZE, .height = TOOL_SIZE};

		rect.left = origin.x + i * TOOL_DIST;
		rect.top = origin.y;
		if (hit_point_rect(&coord_mouse, &rect))
			return (true);
	}
	return (false);
}

void insert_to_map(tile_map_t *tile_map, tva_t *tva, tva_t mouse_tva)
{
	if (mouse_tva.alt == 0) {
		size_t type = mouse_tva.type;
		size_t var = mouse_tva.var;

		tva->type = mouse_tva.type;
		tva->var = mouse_tva.var;
		if (tva->alt >= tile_map->nb_alt[type][var])
			tva->alt = 0;
	}
	else
		*tva = mouse_tva;
}

void manage_map(sfEvent *event, sfRenderWindow *window, map_t *map, tva_t *mouse_tva)
{
	size_t x = GET_MAP_X;
	size_t y = GET_MAP_Y;
	bool cond = event->type == sfEvtMouseButtonPressed;

	if (x >= map->nb_case_x || y >= map->nb_case_y)
		return;
	if (cond && sfMouse_isButtonPressed(sfMouseMiddle) == true)
		mouse_tva->type = map->tab[x][y].type;
	if (sfMouse_isButtonPressed(sfMouseRight) == true)
		swap_alt(map->tile_map, &map->tab[x][y]);
	if (mouse_tva->type >= map->tile_map->nb_type)
		return;
	if (sfMouse_isButtonPressed(sfMouseLeft) == true
	&& isit_on_inventory(map, window) != true
	&& dont_touch_borders(map, x, y)) {
		insert_to_map(map->tile_map, &map->tab[x][y], *mouse_tva);
		map_smooth(map, x, y);
	}
}

int map_editor_loop(sfRenderWindow *window, map_t *map)
{
	tva_t mouse_tva = {map->tile_map->nb_type, V111_1X1_111, 0};
	sfEvent event;
	back_and_music_t optional = optional_create();

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return (0);
			zoom_map(&event, map);
			refresh_map(&event, map);
			manage_map(&event, window, map, &mouse_tva);
		}
		move_map(&map->pos);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, optional.sprite, NULL);
		map_aff(window, map);
		display_tools(window, map, &mouse_tva);
		tile_map_aff(window, map->tile_map, mouse_tva, RECT_MOUSE);
		sfRenderWindow_display(window);
	}
	return (0);
}
