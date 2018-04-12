/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu.c
*/
#include <stdbool.h>
#include "prototype.h"
#include "menu.h"

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

loading_t back_create(sfRenderWindow *window)
{
	loading_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(BACK, NULL);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	return (optional);
}

bool enter(sfRenderWindow *window, menu_t *menu)
{
	if (menu->button == 0 && sfKeyboard_isKeyPressed(sfKeyReturn)) {
		game_menu(window);
	} if (menu->button == 1 && sfKeyboard_isKeyPressed(sfKeyReturn)) {
		map_editor_menu(window);
	} if (menu->button == 2 && sfKeyboard_isKeyPressed(sfKeyReturn)) {
		anime_editor_menu(window);
	} if (menu->button == 3 && sfKeyboard_isKeyPressed(sfKeyReturn)) {
		printf("options\n");
	} if (menu->button == 4 && sfKeyboard_isKeyPressed(sfKeyReturn)) {
		printf("Credit\n");
	} if (menu->button == 5 && sfKeyboard_isKeyPressed(sfKeyReturn)) {
		return (false);
	}
	return (true);
}

int main_menu(void)
{
	sfRenderWindow *window = window_create();
	loading_t back = back_create(window);
	menu_t menu = menu_create(window);
	sfEvent event;

	//change nb text
	sfRenderWindow_display(window);
	main_intro(window, &event);
	for (int i = 0; i < NB_BUTTON; i++)
		sfText_setFont(menu.text[i], menu.font);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			menu.button = move_curseur(window, &menu, &event);
			if (enter(window, &menu) == false)
				sfRenderWindow_close(window);
		}
		move_curseur(window, &menu, NULL);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, back.sprite, NULL);
		display_menu(window, &menu);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return (0);
}
