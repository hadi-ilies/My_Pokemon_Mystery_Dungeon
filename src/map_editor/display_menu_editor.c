/*
** EPITECH PROJECT, 2018
** displau
** File description:
** display
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"

void display_text_editor(sfRenderWindow *window, menu_t *menu)
{
	 int pos_y = 50;

	sfText_setString(menu->text[0], "LAUNCH EDITOR");
	sfText_setString(menu->text[1], "SAVE MAP");
	sfText_setString(menu->text[2], "NEW MAP");
	sfText_setString(menu->text[3], "LOAD MAP");
	sfText_setString(menu->text[4], "OPTIONS");
	sfText_setString(menu->text[5], "BACK");
	for (size_t i = 0; i < NB_BUTTON_EDITOR; i++) {
		sfText_setPosition(menu->text[i], (sfVector2f) {60, pos_y});
		sfText_setColor(menu->text[i], (sfColor){250, 250, 0,
					menu->button == i ? 255 : 180});
		sfRenderWindow_drawText(window, menu->text[i], NULL);
		pos_y += 100;
	}
}

void display_menu_editor(sfRenderWindow *window, menu_t *menu, loading_t *back)
{
	sfRenderWindow_drawSprite(window, back->sprite, NULL);
	sfRenderWindow_drawRectangleShape(window, menu->rect[0], NULL);
	display_text_editor(window, menu);
	sfRenderWindow_drawRectangleShape(window, menu->rect[1], NULL);
}
