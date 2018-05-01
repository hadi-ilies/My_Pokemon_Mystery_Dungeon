/*
** EPITECH PROJECT, 2018
** new map
** File description:
** new map
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"

void destroy_option_editor(option_editor_t *option)
{
	sfText_destroy(option->size_map_x);
	sfText_destroy(option->size_map_y);
	sfRectangleShape_destroy(option->back);
	sfSprite_destroy(option->screen);
	sfFont_destroy(option->font);
	for (size_t i = 0; i < count_file(TILE_MAP); i++)
		free(option->text[i]);
	for (size_t i = 0; i < 3; i++)
		sfText_destroy(option->choice[i]);

}

void new_map(menu_t *menu, map_t *map, sfRenderWindow *window)
{
	 option_editor_t option = param_map(menu, NULL, window);
	 char *str = (char *) sfText_getString(option.text[option.nb_tile]);

	 *map = map_create(option.size_x, option.size_y,
			concat("resources/tile_map/", str));
	 destroy_option_editor(&option);
	 map_smooth_all(map);
}
