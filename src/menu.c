/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** menu.c
*/

#include "prototype.h"

int menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;
	game_t game;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	game.map = map_create(50, 50);
	sfRenderWindow_setFramerateLimit(window, 30);
	for (size_t i = 0; i < game.map.nb_case_x; i++)
		for (size_t j = 0; j < game.map.nb_case_y; j++)
			game.map.tab[i][j].type = 0;
	game.map.size.x = 200;
	game.map.size.y = game.map.size.x;
	game_loop(window, &game);
	map_destroy(&game.map);
	sfRenderWindow_destroy(window);
	return (0);
}
