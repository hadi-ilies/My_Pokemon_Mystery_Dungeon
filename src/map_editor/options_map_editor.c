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

void choice_cursor(option_editor_t *option, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;

	sfText_setString(option->choice[0], "MAP TYPE");
	sfText_setString(option->choice[1], "MAP HEIGHT");
	sfText_setString(option->choice[2], "MAP WIDTH");
	for (size_t i = 0; i < 3; i++) {
		sfText_setPosition(option->choice[i], (sfVector2f) {WINDOW_SIZE.x / 2 - 300, pos_y});
		sfText_setColor(option->choice[i], (sfColor){250, 250, 0,
					option->choice_curs == i ? 255 : 180});
		sfRenderWindow_drawText(window, option->choice[i], NULL);
		pos_y += 100;
	}
}

void display_options_editor(option_editor_t *option, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, option->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, option->back, NULL);
	choice_cursor(option, window);
	option->choice_curs == 0 ? sfRenderWindow_drawText(window,
							  option->text[option->nb_tile], NULL) : 0;
	option->choice_curs == 2 ? sfRenderWindow_drawText(window, option->size_map_x, NULL) : 0;
	option->choice_curs == 1 ? sfRenderWindow_drawText(window, option->size_map_y, NULL) : 0;
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
	(sfVector2f) {WINDOW_SIZE.x / 2 - 150, WINDOW_SIZE.y / 2 - 300});//tmp
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
	sfText_setString(option->size_map_x, str);
	sfText_setPosition(option->size_map_x, (sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2 - 100});
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
	sfText_setString(option->size_map_y, str);
	sfText_setPosition(option->size_map_y, (sfVector2f) {WINDOW_SIZE.x / 2,
				WINDOW_SIZE.y / 2 - 200});
}

void create_and_setchoice_curs(option_editor_t *option)
{
	for (size_t i = 0; i < 3; i++) {
		option->choice[i] = sfText_create();
		sfText_setFont(option->choice[i], option->font);
	}
}

option_editor_t option_editor_create(sfRenderWindow *window)
{
	option_editor_t option;

	option.text = malloc(sizeof(sfText *) * count_tilemap());
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

void param_map(menu_t *menu, map_t *map, sfRenderWindow *window)
{
	sfEvent event;
	option_editor_t option = option_editor_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
			move_curseur_option_editor(&option, &event);
			option.choice_curs == 2 ? size_tile_map_x(map, &event, window, &option) : 0;
			option.choice_curs == 1 ? size_tile_map_y(map, &event, window, &option) : 0;
			map_resize(map, option.size_x, option.size_y);
			option.choice_curs == 0 ? change_tile_map(menu, window, &option, &event) : 0;
			menu->tile_map[0] = tile_map_create_from_file(concat("resources/tile_map/",
			sfText_getString(option.text[option.nb_tile])));
			map->tile_map = &menu->tile_map[0];//tmp
		}
		sfRenderWindow_clear(window, sfBlack);
		display_options_editor(&option, window);
		sfRenderWindow_display(window);
	}
}
