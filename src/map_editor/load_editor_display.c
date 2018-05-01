/*
** EPITECH PROJECT, 2018
** display load editor
** File description:
** and list
*/

#include "my.h"
#include "macro.h"
#include "map_editor_function.h"
#include "option_map_editor.h"
#include "load_maps_editor.h"

void display_load_editor(load_editor_t *load, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, load->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, load->back, NULL);
	load_choice_cursor(load, window);
}

void display_load_list(load_editor_t *load, sfRenderWindow *window,
		sfRectangleShape *back, sfSprite *screen)
{
	sfRectangleShape_setOutlineColor(back, sfGreen);
	sfRectangleShape_setPosition(back,
		(sfVector2f) {WINDOW_SIZE.x / 2 + 600, WINDOW_SIZE.y / 2});
	sfRenderWindow_drawSprite(window, screen, NULL);
	sfRenderWindow_drawRectangleShape(window, back, NULL);
	count_file(MAPS) > 5  ?
		load_list_choice_cursor(load, window) :
		load_list_choice_min(load, window);
}
