/*
** EPITECH PROJECT, 2018
** menu_editor
** File description:
** menu_editor
*/


#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"

void pages_editor(menu_t *menu)
{
	sfTexture *texture;

	menu->rect[0] = sfRectangleShape_create();
	sfRectangleShape_setFillColor(menu->rect[0], (sfColor) {0, 0, 0, 150});
	sfRectangleShape_setOutlineThickness(menu->rect[0], 10);
	sfRectangleShape_setOutlineColor(menu->rect[0], sfRed);
	sfRectangleShape_setSize(menu->rect[0], (sfVector2f) {400, 620});
	sfRectangleShape_setPosition(menu->rect[0], (sfVector2f) {10, 10});
	menu->rect[1] = sfRectangleShape_create();
	texture = sfTexture_createFromFile(CURSOR_EDITOR, NULL);
	sfRectangleShape_setSize(menu->rect[1], (sfVector2f) {44, 34});
	sfRectangleShape_setTexture(menu->rect[1], texture, sfTrue);
}

void text_editor(menu_t *menu)
{
	menu->font = sfFont_createFromFile(FONT);
	for (int i = 0; i < NB_BUTTON_EDITOR; i++)
		menu->text[i] = sfText_create();
}

menu_t menu_editor_create(void)
{
	menu_t menu;

	pages_editor(&menu);
	text_editor(&menu);
	menu.button = 0;
	return (menu);
}

loading_t back_editor_create(sfRenderWindow *window)
{
	loading_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(BACK_MENU_EDITOR, NULL);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	sfFloatRect size = sfSprite_getLocalBounds(optional.sprite);

	sfSprite_setScale(optional.sprite, (sfVector2f) {WINDOW_SIZE.x / size.width,
				WINDOW_SIZE.y / size.height});
	return (optional);
}
