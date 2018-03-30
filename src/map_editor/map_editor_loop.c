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

void pick_tile(sfRenderWindow *window, sfFloatRect rect, tva_t tva, tva_t *mouse_tva)
{
	sfVector2i coord_mouse = sfMouse_getPositionRenderWindow(window);
	bool tmp = sfMouse_isButtonPressed(sfMouseLeft);

	if (tmp && hit_point_rect(&coord_mouse, &rect))
		*mouse_tva = tva;
}

void display_tools(sfRenderWindow *window, map_t *map, tva_t *mouse_tva)
{
	const size_t tool_size = 100;
	const size_t tool_dist = 200;
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f origin;
	sfRectangleShape *reck = sfRectangleShape_create();
	sfColor color = {150, 150, 150, 100};

	origin.x = win_size.x / 2 - map->tile_map->nb_type / 2 * tool_dist;
	origin.y = win_size.y - tool_size / 2;
	sfRectangleShape_setSize(reck, (sfVector2f){tool_size + 20, tool_size + 20});
	sfRectangleShape_setFillColor(reck, color);
	for (size_t i = 0; i < map->tile_map->nb_type; i++) {
		sfFloatRect rect = {.width = tool_size, .height = tool_size};
		tva_t tva = {i, V111_1X1_111, 0};

		rect.left = origin.x + i * tool_dist;
		rect.top = origin.y;
		sfRectangleShape_setPosition(reck, (sfVector2f){rect.left - rect.width / 2 - 10, rect.top - rect.height / 2 - 10});
		sfRenderWindow_drawRectangleShape(window, reck, NULL);
		tile_map_aff(window, map->tile_map, tva, rect);
		pick_tile(window, rect, tva, mouse_tva);
	}
	sfRectangleShape_destroy(reck);
}

void insert_to_map2(tva_t mouse_tva, tva_t *tva, tile_map_t *tile_map)
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

void insert_to_map(sfRenderWindow *window, map_t *map, tva_t mouse_tva)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2i coord_mouse = sfMouse_getPositionRenderWindow(window);
	int x2 = map->size.x * (-map->pos.x) + win_size.x / 2;
	int y2 = map->size.y * (-map->pos.y) + win_size.y / 2;

	coord_mouse.x -= x2 - map->size.y / 2;
	coord_mouse.y -= y2 - map->size.y / 2;
	if (mouse_tva.type >= map->tile_map->nb_type)
		return;
	if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
		size_t x = coord_mouse.x / map->size.x;
		size_t y = coord_mouse.y / map->size.y;

		if (x >= map->nb_case_x || y >= map->nb_case_y)
			return;
		insert_to_map2(mouse_tva, &map->tab[x][y], map->tile_map);
		map_smooth(map, x, y);
	}
}

void refresh_map(sfEvent *event, map_t *map)
{
	if (event->type == sfEvtKeyPressed)
		if (sfKeyboard_isKeyPressed(sfKeyF5))
			map_smooth_all(map);
}

int map_editor_loop(sfRenderWindow *window, map_t *map)
{
	tva_t mouse_tva = {map->tile_map->nb_type, 0, 0};
	sfEvent event;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			zoom_map(&event, map);
			refresh_map(&event, map);
		}
		move_map(&map->pos);
		insert_to_map(window, map, mouse_tva);
		sfRenderWindow_clear(window, sfBlack);
		map_aff(window, map);
		display_tools(window, map, &mouse_tva);
		tile_map_aff(window, map->tile_map, mouse_tva, RECT_MOUSE);
		sfRenderWindow_display(window);
	}
	return (0);
}
