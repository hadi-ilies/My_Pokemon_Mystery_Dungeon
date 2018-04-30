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

void tile_map_stock(option_editor_t *option, map_t *map)
{
	char **filename = take_filename("resources/tile_map");
	size_t nb_file = count_file("resources/tile_map");

	for (size_t i = 0; i < nb_file; i++) {
		char *str = concat("resources/tile_map/", filename[i]);

		if (my_strcmp(str, map->tile_map_file_name) == 0) {
			option->nb_tile = i;
			free(str);
			break;
		}
		free(str);
	} for (size_t i = 0; i < nb_file; i++)
		free(filename[i]);
	free(filename);
}

void stock_map(option_editor_t *option, map_t *map)
{
	if (map == NULL) {
		sfText_setString(option->size_map_x, "50");
		sfText_setString(option->size_map_y, "50");
		option->nb_tile = 0;
		option->size_x = 50;
		option->size_y = 50;
		option->choice_curs = 0;
	} else {
		sfText_setString(option->size_map_x, inttostr(map->nb_case_x));
		sfText_setString(option->size_map_y, inttostr(map->nb_case_y));
		sfText_setString(option->text[0], map->tile_map_file_name);
		option->size_x = map->nb_case_x;
		option->size_y = map->nb_case_y;
		option->choice_curs = 0;
		tile_map_stock(option, map);
	}
}

option_editor_t option_editor_create(sfRenderWindow *window, map_t *map)
{
	option_editor_t option;

	option.text = malloc(sizeof(sfText *) * count_file("resources/tile_map"));
	if (option.text == NULL)
		return (option);
	create_choose_tilemap(&option);
	create_and_setchoice_curs(&option);
	option.screen = create_screen_param(window);
	option.back = create_back_param(window);
	option.size_map_x = sfText_create();
	option.size_map_y = sfText_create();
	sfText_setFont(option.size_map_y, option.font);
	sfText_setFont(option.size_map_x, option.font);
	stock_map(&option, map);
	return (option);
}
