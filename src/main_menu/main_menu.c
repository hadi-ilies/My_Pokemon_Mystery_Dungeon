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

sfRenderWindow *window_create(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (window == NULL)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	return (window);
}

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
	if (menu->button == 0 && event->key.code == sfKeyReturn) {
		game_menu(window);
	} if (menu->button == 1 && event->key.code == sfKeyReturn) {
		menu_map_editor_menu(window);
	} if (menu->button == 2 && event->key.code == sfKeyReturn) {
		anime_editor_menu(window);
	} if (menu->button == 3 && event->key.code == sfKeyReturn) {
		option_menu(window, event);
	} if (menu->button == 4 && event->key.code == sfKeyReturn) {
		credit_menu(window, event);
	} if (menu->button == 5 && event->key.code == sfKeyReturn) {
		return (false);
	}
	return (true);
}

int main_menu(void)
{
	sfRenderWindow *window = window_create();
	loading_t back = back_create();
	menu_t menu = menu_create();
	sfEvent event;

	set_icon(window, "icon.png");
	sfRenderWindow_display(window);
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
		move_curseur(&menu, NULL);
		sfRenderWindow_clear(window, sfBlack);
		display_menu(window, &menu, &back);
		sfRenderWindow_display(window);
	}
	destroy_all(&back, window, &menu);
	return (0);
}
