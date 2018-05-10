/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
*/

#include "prototype.h"
#include "main_menu/menu.h"
#include "macro.h"

void display_text(sfRenderWindow *window, menu_t *menu)
{
	int pos_y = 50;

	sfText_setString(menu->text[0], "ADVENTURE");
	sfText_setString(menu->text[1], "MAP EDITOR");
	sfText_setString(menu->text[2], "ANIMATION EDITOR");
	sfText_setString(menu->text[3], "OPTIONS");
	sfText_setString(menu->text[4], "HOW TO PLAY");
	sfText_setString(menu->text[5], "EXIT");
	for (size_t i = 0; i < NB_BUTTON; i++) {
		sfText_setPosition(menu->text[i], V2F(60, pos_y));
		sfText_setColor(menu->text[i],
		COL(250, 250, 0, menu->button == i ? 255 : 180));
		sfRenderWindow_drawText(window, menu->text[i], NULL);
		pos_y += 100;
	}
}

void display_menu(sfRenderWindow *window, menu_t *menu, loading_t *back)
{
	sfRenderWindow_drawSprite(window, back->sprite, NULL);
	sfRenderWindow_drawRectangleShape(window, back->icon_back, NULL);
	sfRenderWindow_drawRectangleShape(window, menu->rect[0], NULL);
	sfRenderWindow_drawRectangleShape(window, menu->rect[1], NULL);
	sfRenderWindow_drawRectangleShape(window, menu->rect[2], NULL);
	sfRenderWindow_drawRectangleShape(window, menu->rect[3], NULL);
	display_texte_button(window, menu);
	display_text(window, menu);
}
