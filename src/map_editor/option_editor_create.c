/*
** EPITECH PROJECT, 2018
** option_create
** File description:
** option_create
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
#include "option_map_editor.h"

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
	sfRectangleShape_setPosition(back, (sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2});
	sfRectangleShape_setFillColor(back, (sfColor) {30, 30, 30, 120});
	sfRectangleShape_setOutlineThickness(back, 10);
	sfRectangleShape_setOutlineColor(back, sfCyan);
	return (back);
}

void create_and_setchoice_curs(option_editor_t *option)
{
	for (size_t i = 0; i < 3; i++) {
		option->choice[i] = sfText_create();
		sfText_setFont(option->choice[i], option->font);
	}
}

void create_choose_tilemap(option_editor_t *option)
{
	option->font = sfFont_createFromFile(FONT);
	for (size_t i = 0; i < count_file("resources/tile_map"); i++) {
		option->text[i] = sfText_create();
		sfText_setFont(option->text[i], option->font);
	}
}

option_editor_t option_editor_create(sfRenderWindow *window)
{
	option_editor_t option;

	option.text = malloc(sizeof(sfText *) * count_file("resources/tile_map"));
	if (option.text == NULL)
		return (option);
	create_choose_tilemap(&option);
	create_and_setchoice_curs(&option);
	option.screen = create_screen_param(window);
	option.back =  create_back_param(window);
	option.size_map_x = sfText_create();
	option.size_map_y = sfText_create();
	sfText_setFont(option.size_map_y, option.font);
	sfText_setFont(option.size_map_x, option.font);
	sfText_setString(option.size_map_x, "50");
	sfText_setString(option.size_map_y, "50");
	option.nb_tile = 0;
	option.size_x = 50;
	option.size_y = 50;
	option.choice_curs = 0;
	return (option);
}
