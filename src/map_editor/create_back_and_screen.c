/*
** EPITECH PROJECT, 2018
** create_back and screnn
** File description:
** create_back and screnn
*/

#include "prototype.h"
#include "my.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"
#include "option_map_editor.h"

void screen_and_back_destroy(sfRectangleShape *back, sfSprite *screen)
{
	sfRectangleShape_destroy(back);
	sfSprite_destroy(screen);
}

sfSprite *create_screen_param(sfRenderWindow *window)
{
	sfSprite *sprite;
	sfImage *screen = sfRenderWindow_capture(window);
	sfTexture *texture;

	sprite = sfSprite_create();
	texture = sfTexture_createFromImage(screen, NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setColor(sprite, (sfColor) {100, 100, 100, 255});
	return (sprite);
}

sfRectangleShape *create_back_param(sfRenderWindow *window)
{
	sfRectangleShape *back;

	back = sfRectangleShape_create();
	sfRectangleShape_setSize(back, (sfVector2f) {600, 600});
	sfRectangleShape_setOrigin(back, (sfVector2f) {300, 300});
	sfRectangleShape_setPosition(back,
		(sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2});
	sfRectangleShape_setFillColor(back, (sfColor) {30, 30, 30, 120});
	sfRectangleShape_setOutlineThickness(back, 10);
	sfRectangleShape_setOutlineColor(back, sfCyan);
	return (back);
}
