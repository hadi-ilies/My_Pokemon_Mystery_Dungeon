/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu.c
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "settings.h"

void back_create_icon(loading_t *optional)
{
	optional->icon_back = sfRectangleShape_create();
	optional->texture_icon =  sfTexture_createFromFile(ITEM, NULL);
	sfRectangleShape_setSize(optional->icon_back,
				(sfVector2f) {800, 358});
	sfRectangleShape_setOrigin(optional->icon_back,
				(sfVector2f) {400, 358 / 2});
	sfRectangleShape_setPosition(optional->icon_back,
				(sfVector2f) {1920 / 2, 1080 / 2 - 358 / 2});
	sfRectangleShape_setFillColor(optional->icon_back,
				(sfColor) {255, 255, 255, 120});
}

loading_t back_create(void)
{
	loading_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(BACK, NULL);
	back_create_icon(&optional);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	sfRectangleShape_setTexture(optional.icon_back, optional.texture_icon,
				sfTrue);
	return (optional);
}

bool enter(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyReturn) {
		if (menu->button == 0)
			game_menu(window);
		if (menu->button == 1)
			menu_map_editor_menu(window);
		if (menu->button == 2)
			anime_editor_menu(window);
		if (menu->button == 3)
			option_menu(window, event, menu);
		if (menu->button == 4)
			credit_menu(window, event);
		if (menu->button == 5)
			return (false);
	}
	return (true);
}

void open_window_menu(sfRenderWindow *window, menu_t *menu, loading_t *back)
{
	move_curseur(menu, NULL);
	sfRenderWindow_clear(window, sfBlack);
	display_menu(window, menu, back);
	sfRenderWindow_display(window);
}

int main_menu(sfRenderWindow *window)
{
	loading_t back = back_create();
	menu_t menu = menu_create();
	sfEvent event = {.type = sfEvtJoystickButtonPressed};

	main_intro(window, &event);
	for (int i = 0; i < NB_BUTTON; i++)
		sfText_setFont(menu.text[i], menu.font);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			menu.button = move_curseur(&menu, &event);
			if (enter(window, &menu, &event) == false)
				sfRenderWindow_close(window);
		}
		open_window_menu(window, &menu, &back);
	}
	destroy_all(&back, window, &menu);
	return (0);
}
