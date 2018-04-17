/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
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

void display_text_editor(sfRenderWindow *window, menu_t *menu)
{
	 int pos_y = 50;

	sfText_setString(menu->text[0], "LAUNCH EDITOR");
	sfText_setString(menu->text[1], "NEW MAP");
	sfText_setString(menu->text[2], "LOAD MAP");
	sfText_setString(menu->text[3], "OPTIONS");
	sfText_setString(menu->text[4], "EXIT");
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

size_t move_curseur_editor(menu_t *menu, sfEvent *event)
{
	static size_t y = 0;

	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp) && y > 0) {
			y -= 1;
		} if (sfKeyboard_isKeyPressed(sfKeyDown) && y <  NB_BUTTON_EDITOR - 1) {
			y += 1;
		}
	}
	sfRectangleShape_setPosition(menu->rect[1], (sfVector2f) {10, y * 100 + 45});
	return (y);
}

void trans_cursor_editor(menu_t *menu, int *tmp1, int *tmp2)
{
	sfRectangleShape_setFillColor(menu->rect[1], (sfColor){255, 255, 255, *tmp1});
	if (*tmp1 <= 10 || *tmp1 >= 255)
		*tmp2 = -(*tmp2);
	(*tmp1) += *tmp2;
}

bool enter_editor(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
	if (menu->button == 0 && event->key.code == sfKeyReturn) {
		printf("save\n");
	} if (menu->button == 1 && event->key.code == sfKeyReturn) {
		map_editor_menu(window);
	} if (menu->button == 2 && event->key.code == sfKeyReturn) {
		printf("load\n");
	} if (menu->button == 3 && event->key.code == sfKeyReturn) {
		printf("options\n");
	} if (menu->button == 4 && event->key.code == sfKeyReturn) {
		return (false);
	}
	return (true);
}

void menu_map_editor_menu(sfRenderWindow *window)
{
	sfEvent event;
	loading_t back = back_editor_create(window);
	menu_t menu = menu_editor_create();
	int tmp1 = 250;
	int tmp2 = 5;

	for (int i = 0; i < NB_BUTTON_EDITOR; i++)
		sfText_setFont(menu.text[i], menu.font);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			menu.button = move_curseur_editor(&menu, &event);
			if (enter_editor(window, &menu, &event) == false)
				return;
		}
		trans_cursor_editor(&menu, &tmp1, &tmp2);
		sfRenderWindow_clear(window, sfBlack);
		display_menu_editor(window, &menu, &back);
		sfRenderWindow_display(window);
	}
}
