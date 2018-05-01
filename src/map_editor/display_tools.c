/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "prototype.h"
#include "tile_name.h"
#include "macro.h"
#include "map_editor_function.h"

void swap_alt(tile_map_t *tile_map, tva_t *tva)
{
	size_t type = tva->type;
	size_t var = tva->var;

	if (tva->alt != 0 || tile_map->nb_alt[type][var] == 1)
		return;
	for (size_t i = 1; i < tile_map->nb_alt[type][var]; i++)
		if (rand() % 3) {
			tva->alt = i;
			return;
		}
}

void pick_tile(sfRenderWindow *window, sfFloatRect rect,
	tva_t tva, tva_t *mouse_tva)
{
	sfVector2i coord_mouse = sfMouse_getPositionRenderWindow(window);
	bool tmp = sfMouse_isButtonPressed(sfMouseLeft);

	if (tmp && hit_point_rect(&coord_mouse, &rect))
		*mouse_tva = tva;
}

void display_tools(sfRenderWindow *window, map_t *map, tva_t *mouse_tva)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f origin;
	sfRectangleShape *reck = sfRectangleShape_create();

	origin.x = win_size.x / 2 - map->tile_map.nb_type / 2 * TOOL_DIST;
	origin.y = win_size.y - TOOL_SIZE / 2;
	sfRectangleShape_setSize(reck, POS_SIZE_SHAPE);
	sfRectangleShape_setFillColor(reck, (sfColor) {150, 150, 150, 100});
	for (size_t i = 0; i < map->tile_map.nb_type; i++) {
		sfFloatRect rect = {.width = TOOL_SIZE, .height = TOOL_SIZE};
		tva_t tva = {i, 4, 0};

		rect.left = origin.x + i * TOOL_DIST;
		rect.top = origin.y;
		sfRectangleShape_setPosition(reck, (sfVector2f){PIX, PIY});
		sfRenderWindow_drawRectangleShape(window, reck, NULL);
		tile_map_aff(window, &map->tile_map, tva, rect);
		pick_tile(window, rect, tva, mouse_tva);
	}
	sfRectangleShape_destroy(reck);
}
