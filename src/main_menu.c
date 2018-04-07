/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu.c
*/

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

menu_t menu_create(sfRenderWindow *window)
{
	menu_t menu;

	menu.rect[0] = sfRectangleShape_create();
	menu.rect[1] = sfRectangleShape_create();
	menu.rect[2] = sfRectangleShape_create();
	menu.texture = sfTexture_createFromFile(TEXTURE_RECT, NULL);
	sfRectangleShape_setSize(menu.rect[0], (sfVector2f) {400, 800});
	sfRectangleShape_setPosition(menu.rect[0], (sfVector2f) {0, 0});
	sfRectangleShape_setTexture(menu.rect[0], menu.texture, sfTrue);
	sfRectangleShape_setFillColor(menu.rect[0], (sfColor) {255, 255, 255, 150});
	sfRectangleShape_setSize(menu.rect[1], (sfVector2f) {400, 400});
	sfRectangleShape_setPosition(menu.rect[1], (sfVector2f) {1920 - 400, 0});/*must use winsize*/
	sfRectangleShape_setTexture(menu.rect[1], menu.texture, sfTrue);
	sfRectangleShape_setFillColor(menu.rect[1], (sfColor) {255, 255, 255, 150});
	sfRectangleShape_setSize(menu.rect[2], (sfVector2f) {1100, 300});
	sfRectangleShape_setPosition(menu.rect[2], (sfVector2f) {400, 850});
	sfRectangleShape_setTexture(menu.rect[2], menu.texture, sfTrue);
	sfRectangleShape_setFillColor(menu.rect[2], (sfColor) {255, 255, 255, 150});
	return (menu);
}

void display_menu(sfRenderWindow *window, menu_t *menu)
{
	sfRenderWindow_drawRectangleShape(window, menu->rect[0], NULL);
	sfRenderWindow_drawRectangleShape(window, menu->rect[1], NULL);
	sfRenderWindow_drawRectangleShape(window, menu->rect[2], NULL);
}

int main_menu(void)
{
	sfRenderWindow *window = window_create();
	loading_t back = back_create(window);
	menu_t menu = menu_create(window);
	sfEvent event;

	sfRenderWindow_display(window);
	main_intro(window, &event);
	//exit(0);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, back.sprite, NULL);
		display_menu(window, &menu);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return (0);
}
