/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game_menu.c
*/

#include <stdlib.h> //tmp
#include "prototype.h"

int game_menu(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;
	game_t game;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (!window)
		return (84);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	game.map = map_create(100, 100, "resources/texture/grassy_config");
	for (size_t i = 0; i < game.map.nb_case_x; i++)
		for (size_t j = 0; j < game.map.nb_case_y; j++) {
			game.map.tab[i][j].type = 1;
			game.map.tab[i][j].var = 4;
			game.map.tab[i][j].alt = (rand() % 10 ? 0 : (rand() % 3 ? 1 : 2));
		}
	game.map.size.x = 200;
	game.map.size.y = game.map.size.x;
	game_loop(window, &game);
	map_destroy(&game.map);
	sfRenderWindow_destroy(window);
	return (0);
}
