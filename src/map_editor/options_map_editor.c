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
#include "option_map_editor.h"

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

void display_options_editor(option_editor_t *option, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, option->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, option->back, NULL);
	sfRenderWindow_drawText(window, option->text[option->nb_tile], NULL);
	sfRenderWindow_drawText(window, option->size_map_x, NULL);
	sfRenderWindow_drawText(window, option->size_map_y, NULL);
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

void change_tile_map(menu_t *menu, sfRenderWindow *window,
		option_editor_t *option, sfEvent *event)
{
	size_t nb_filename =  count_tilemap();
	char **filename = take_filename();

	for (size_t i = 0; i < nb_filename; i++)
		sfText_setString(option->text[i], filename[i]);
	if (option->nb_tile < nb_filename - 1 && event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyRight)
		option->nb_tile++;
	if (option->nb_tile > 0 && event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyLeft)
		option->nb_tile--;
	sfText_setPosition(option->text[option->nb_tile],
	(sfVector2f) {WINDOW_SIZE.x / 2 - 280, WINDOW_SIZE.y / 2 - 300});//tmp
}

void create_choose_tilemap(option_editor_t *option)
{
	option->font = sfFont_createFromFile(FONT);
	for (size_t i = 0; i < count_tilemap(); i++) {
		option->text[i] = sfText_create();
		sfText_setFont(option->text[i], option->font);
	}
}

void size_tile_map_x(map_t *map, sfEvent *event,
		   sfRenderWindow *window, option_editor_t *option)
{
	char *str;

	if (option->size_x < 999 && event->type == sfEvtKeyPressed
	    && event->key.code == sfKeyRight) {
		option->size_x++;
	} if (option->size_x > 30 && event->type == sfEvtKeyPressed
	      && event->key.code == sfKeyLeft) {
		option->size_x--;
	}
	str = inttostr(option->size_x);
	//map->nb_case_x = option->size_x;
	sfText_setString(option->size_map_x, str);
	sfText_setPosition(option->size_map_x, (sfVector2f) {WINDOW_SIZE.x / 2 - 280,
				WINDOW_SIZE.y / 2 });
}

void size_tile_map_y(map_t *map, sfEvent *event,
		   sfRenderWindow *window, option_editor_t *option)
{
	char *str;

	if (option->size_y < 999 && event->type == sfEvtKeyPressed
	    && event->key.code == sfKeyRight) {
		option->size_y++;
	} if (option->size_y > 30 && event->type == sfEvtKeyPressed
	      && event->key.code == sfKeyLeft) {
		option->size_y--;
	}
	str = inttostr(option->size_y);
	//map->nb_case_y = option->size_y;
	sfText_setString(option->size_map_y, str);
	sfText_setPosition(option->size_map_y, (sfVector2f) {WINDOW_SIZE.x / 2 - 280,
				WINDOW_SIZE.y / 2 - 30 });
}

option_editor_t option_editor_create(sfRenderWindow *window)
{
	option_editor_t option;

	option.text = malloc(sizeof(sfText *) * count_tilemap());
	create_choose_tilemap(&option);
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
	return (option);
}

void param_map(menu_t *menu, map_t *map, sfRenderWindow *window)
{
	sfEvent event;
	option_editor_t option = option_editor_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
			size_tile_map_x(map, &event, window, &option);
			size_tile_map_y(map, &event, window, &option);
			map_resize(map, option.size_x, option.size_y);
			change_tile_map(menu, window, &option, &event);//tmp
			menu->tile_map[0] = tile_map_create_from_file(concat("resources/tile_map/",
			sfText_getString(option.text[option.nb_tile])));
			map->tile_map = &menu->tile_map[0];//tmp
		}
		sfRenderWindow_clear(window, sfBlack);
		display_options_editor(&option, window);
		sfRenderWindow_display(window);
	}
}
