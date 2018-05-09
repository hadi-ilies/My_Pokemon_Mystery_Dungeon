/*
** EPITECH PROJECT, 2018
** menu_editor
** File description:
** menu_editor
*/


#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"

void pages_editor(menu_t *menu)
{
	sfTexture *texture;

	menu->rect[0] = sfRectangleShape_create();
	sfRectangleShape_setFillColor(menu->rect[0],
				(sfColor) {0, 0, 0, 150});
	sfRectangleShape_setOutlineThickness(menu->rect[0], 10);
	sfRectangleShape_setOutlineColor(menu->rect[0], sfRed);
	sfRectangleShape_setSize(menu->rect[0], V2F(400, 620));
	sfRectangleShape_setPosition(menu->rect[0], V2F(10, 10));
	menu->rect[1] = sfRectangleShape_create();
	texture = sfTexture_createFromFile(CURSOR_EDITOR, NULL);
	sfRectangleShape_setSize(menu->rect[1], V2F(44, 34));
	sfRectangleShape_setTexture(menu->rect[1], texture, sfTrue);
}

void text_editor(menu_t *menu)
{
	menu->font = sfFont_createFromFile(FONT);
	for (int i = 0; i < NB_BUTTON_EDITOR; i++)
		menu->text[i] = sfText_create();
}

size_t count_file(char *path)
{
	size_t nb_file = 0;
	DIR *dir = NULL;
	struct dirent *d;

	dir = opendir(path);
	if (dir == NULL)
		return (0);
	while ((d = readdir(dir)) != NULL)
		if (d->d_name[0] != '.')
			nb_file++;
	closedir(dir);
	return (nb_file);
}

menu_t menu_editor_create(sfMusic **sound_effect)
{
	menu_t menu;

	pages_editor(&menu);
	text_editor(&menu);
	menu.button = 0;
	menu.tile_map = malloc(sizeof(tile_map_t) *
			(count_file(TILE_MAP) + 1));
	menu.sound.sound_effect = sound_effect;
	return (menu);
}

loading_t back_editor_create(sfRenderWindow *window)
{
	loading_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(BACK_MENU_EDITOR, NULL);
	if (optional.texture == NULL)
		return (optional);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	sfFloatRect size = sfSprite_getLocalBounds(optional.sprite);

	sfSprite_setScale(optional.sprite,
	V2F(WINDOW_SIZE.x / size.width, WINDOW_SIZE.y / size.height));
	return (optional);
}
