/*
** EPITECH PROJECT, 2018
** cursor_editor
** File description:
** cursor_editor
*/


#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "map_editor_function.h"
#include "main_menu/menu.h"

size_t move_curseur_editor(menu_t *menu, sfEvent *event)
{
	static size_t y = 0;

	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp) && y > 0)
			y--;
		if (sfKeyboard_isKeyPressed(sfKeyDown)
		&& y <  NB_BUTTON_EDITOR - 1)
			y++;
	}
	sfRectangleShape_setPosition(menu->rect[1],
				(sfVector2f) {10, y * 100 + 45});
	return (y);
}

void trans_cursor_editor(menu_t *menu, int *tmp1, int *tmp2)
{
	sfRectangleShape_setFillColor(menu->rect[1],
				(sfColor) {255, 255, 255, *tmp1});
	if (*tmp1 <= 10 || *tmp1 >= 255)
		*tmp2 = -(*tmp2);
	(*tmp1) += *tmp2;
}
