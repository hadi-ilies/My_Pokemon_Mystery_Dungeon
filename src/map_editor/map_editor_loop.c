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
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f origin;
	sfRectangleShape *reck = sfRectangleShape_create();

	origin.x = win_size.x / 2 - map->tile_map->nb_type / 2 * TOOL_DIST;
	origin.y = win_size.y - TOOL_SIZE / 2;
	sfRectangleShape_setSize(reck, (sfVector2f){TOOL_SIZE + 20, TOOL_SIZE + 20});
	sfRectangleShape_setFillColor(reck, (sfColor) {150, 150, 150, 100});
	for (size_t i = 0; i < map->tile_map->nb_type; i++) {
		sfFloatRect rect = {.width = TOOL_SIZE, .height = TOOL_SIZE};
		tva_t tva = {i, V111_1X1_111, 0};

		rect.left = origin.x + i * TOOL_DIST;
		rect.top = origin.y;
		sfRectangleShape_setPosition(reck, (sfVector2f){PIX, PIY});
		sfRenderWindow_drawRectangleShape(window, reck, NULL);
		tile_map_aff(window, map->tile_map, tva, rect);
		pick_tile(window, rect, tva, mouse_tva);
	}
	sfRectangleShape_destroy(reck);
}

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
	if (sfMouse_isButtonPressed(sfMouseLeft) == true) {
		insert_to_map(map->tile_map, &map->tab[x][y], *mouse_tva);
		map_smooth(map, x, y);
	}
}

void refresh_map(sfEvent *event, map_t *map)
{
	if (event->type == sfEvtKeyPressed)
		if (sfKeyboard_isKeyPressed(sfKeyF5))
			map_smooth_all(map);
}

back_and_music_t optional_create(void)
{
	back_and_music_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(BACK_MAP, NULL);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	optional.music = sfMusic_createFromFile(MUSIC_EDITOR);
	sfMusic_play(optional.music);
	sfMusic_setLoop(optional.music, true);
	return (optional);
}

int map_editor_loop(sfRenderWindow *window, map_t *map)
{
	tva_t mouse_tva = {map->tile_map->nb_type, V111_1X1_111, 0};
	sfEvent event;
	back_and_music_t optional = optional_create();

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
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
