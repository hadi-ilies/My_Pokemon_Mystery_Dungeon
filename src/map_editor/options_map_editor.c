/*
** EPITECH PROJECT, 2018
** map_options
** File description:
** map_optios
*/

#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include "prototype.h"
#include "my.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"

sfRectangleShape *create_back_param(sfRenderWindow *window)
{
	sfRectangleShape *back;

	back = sfRectangleShape_create();
	sfRectangleShape_setSize(back, (sfVector2f) {600, 600});
	sfRectangleShape_setOrigin(back, (sfVector2f) {300, 300});
	sfRectangleShape_setPosition(back, (sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2});
	sfRectangleShape_setFillColor(back, (sfColor) {30, 30, 30, 120});
	sfRectangleShape_setOutlineThickness(back, 10);
	sfRectangleShape_setOutlineColor(back, sfCyan);
	return (back);
}

void display_options_editor(sfSprite *screen, sfRectangleShape *back,
			sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, screen, NULL);
	sfRenderWindow_drawRectangleShape(window, back, NULL);
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

size_t change_tile_map(menu_t *menu, sfRenderWindow *window,
		sfText *text[count_tilemap()], sfEvent *event)
{
	size_t nb_filename =  count_tilemap();
	char **filename = take_filename();
	static size_t nb_tile = 0;

	for (size_t i = 0; i < nb_filename; i++)
		sfText_setString(text[i], filename[i]);
	if (nb_tile < nb_filename - 1 && event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyRight)
		nb_tile++;
	if (nb_tile > 0 && event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyLeft)
		nb_tile--;
	sfText_setPosition(text[nb_tile], (sfVector2f) {WINDOW_SIZE.x / 2 - 280,
				WINDOW_SIZE.y / 2 - 300});//tmp
	return (nb_tile);
}

void create_choose_tilemap(sfFont *font, sfText *text[count_tilemap()])
{
	font = sfFont_createFromFile(FONT);
	for (size_t i = 0; i < count_tilemap(); i++) {
		text[i] = sfText_create();
		sfText_setFont(text[i], font);
	}
}

void param_map(menu_t *menu, map_t *map, sfRenderWindow *window)
{
	sfText *text[count_tilemap()];
	sfFont *font;
	sfSprite *screen = create_screen_param(window);
	sfRectangleShape *back = create_back_param(window);
	sfEvent event;
	size_t nb_tile = 0;

	create_choose_tilemap(font, text);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
			nb_tile = change_tile_map(menu, window, text, &event);
		}
		sfRenderWindow_clear(window, sfBlack);
		display_options_editor(screen, back, window);
		sfRenderWindow_drawText(window, text[nb_tile], NULL);
		sfRenderWindow_display(window);
	}
}
