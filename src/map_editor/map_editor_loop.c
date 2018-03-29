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

	rect.left -= rect.width / 2;
	rect.top -= rect.height / 2;
	if (sfMouse_isButtonPressed(sfMouseLeft) == true
	&& hit_point_rect(&coord_mouse, &rect) == true)
		*mouse_tva = tva;
}

void display_tools(sfRenderWindow *window, map_t *map, tva_t *mouse_tva)
{
	const size_t sprite_size = 100;
	const size_t sprite_dist = 200;

	sfVector2f origin = {WINDOW_WIDTH / 2 - map->tile_map->nb_type / 2 *
			     sprite_dist, WINDOW_HEIGHT - sprite_size / 2};

	for (size_t i = 0; i < map->tile_map->nb_type; i++) {
		sfFloatRect rect = {origin.x + i * sprite_dist, origin.y,
				sprite_size, sprite_size};
		tva_t tva = {i, V111_1X1_111, 0};

		tile_map_aff(window, map->tile_map, tva, rect);
		pick_tile(window, rect, tva, mouse_tva);
	}
}

void insert_to_map2(tva_t mouse_tva, tva_t *tva, tile_map_t *tile_map)
{
	if (mouse_tva.alt == 0) {
		bool tmp = false;
		size_t type = tva->type;
		size_t var = tva->var;

		tva->type = mouse_tva.type;
		tva->var = mouse_tva.var;
		tva->alt >= tile_map->nb_alt[type][var] ? tmp = true : 0;
		tmp ? tva->alt = 0 : 0;
	}
	else
		tva->alt = mouse_tva.alt;

}

void insert_to_map(tva_t mouse_tva, map_t *map, sfRenderWindow *window, sfVector2f pos)
{
	sfVector2i coord_mouse = sfMouse_getPositionRenderWindow(window);
	int x2 = map->size.x * (-pos.x) + WINDOW_WIDTH / 2 - map->size.y / 2;
	int y2 = map->size.y * (-pos.y) + WINDOW_HEIGHT / 2 - map->size.y / 2;

		coord_mouse.x -= x2;
		coord_mouse.y -= y2;

	if (coord_mouse.x < 0 || coord_mouse.y < 0)
		return;
	if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
		size_t x = coord_mouse.x / map->size.x;
		size_t y = coord_mouse.y / map->size.y;

		if (x < map->nb_case_x && y < map->nb_case_y)
			insert_to_map2(mouse_tva, &map->tab[x][y], map->tile_map);
	}
}

int map_editor_loop(sfRenderWindow *window, map_t *map)
{
	tva_t mouse_tva = {map->tile_map->nb_type, 0, 0};
	sfVector2f pos = {10, 10};
	sfEvent event;

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			zoom_map(&event, map);
		}
		sfRenderWindow_clear(window, sfBlack);
		map_aff(window, map, pos);
		display_tools(window, map, &mouse_tva);
		insert_to_map(mouse_tva, map, window, pos);
		tile_map_aff(window, map->tile_map, mouse_tva, RECT_MOUSE);
		move_map(&pos);
		sfRenderWindow_display(window);
	}
	return (0);
}
