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
	game.map = map_create(100, 100, "resources/texture/tile_map/grassy_config");
	for (size_t i = 0; i < game.map.nb_case_x; i++)
		for (size_t j = 0; j < game.map.nb_case_y; j++) {
			game.map.tab[i][j].type = 0;
			game.map.tab[i][j].var = 4;
			game.map.tab[i][j].alt = (rand() % 10 ? 0 : (rand() % 3 ? 1 : 2));
		}
	for (size_t i = 30; i < game.map.nb_case_x - 20; i++)
		for (size_t j = 23; j < game.map.nb_case_y - 34; j++)
			game.map.tab[i][j].type = 1;
	for (size_t i = 30; i < game.map.nb_case_x - 20; i++) {
		game.map.tab[i][22].var = 7;
		if (game.map.tab[i][22].alt > 1)
			game.map.tab[i][22].alt = 0;
		game.map.tab[i][23].var = 1;
		game.map.tab[i][23].alt = 0;
		game.map.tab[i][game.map.nb_case_y - 34].var = 1;
		game.map.tab[i][game.map.nb_case_y - 34].alt = 0;
		game.map.tab[i][game.map.nb_case_y - 35].var = 7;
		game.map.tab[i][game.map.nb_case_y - 35].alt = 0;
	}
	for (size_t j = 23; j < game.map.nb_case_y - 34; j++) {
		game.map.tab[29][j].var = 5;
		game.map.tab[29][j].alt = 0;
		game.map.tab[30][j].var = 3;
		game.map.tab[30][j].alt = 0;
		game.map.tab[game.map.nb_case_x - 20][j].var = 3;
		game.map.tab[game.map.nb_case_x - 20][j].alt = 0;
		game.map.tab[game.map.nb_case_x - 21][j].var = 5;
		game.map.tab[game.map.nb_case_x - 21][j].alt = 0;
	}
	game.map.tab[29][22].var = 29;
	game.map.tab[29][22].alt = 0;
	game.map.tab[30][23].var = 0;
	game.map.tab[30][23].alt = 0;
	game.map.tab[game.map.nb_case_x - 20][22].var = 30;
	game.map.tab[game.map.nb_case_x - 20][22].alt = 0;
	game.map.tab[game.map.nb_case_x - 21][23].var = 2;
	game.map.tab[game.map.nb_case_x - 21][23].alt = 0;
	game.map.tab[29][game.map.nb_case_y - 34].var = 31;
	game.map.tab[29][game.map.nb_case_y - 34].alt = 0;
	game.map.tab[30][game.map.nb_case_y - 35].var = 6;
	game.map.tab[30][game.map.nb_case_y - 35].alt = 0;
	game.map.tab[game.map.nb_case_x - 20][game.map.nb_case_y - 34].var = 32;
	game.map.tab[game.map.nb_case_x - 20][game.map.nb_case_y - 34].alt = 0;
	game.map.tab[game.map.nb_case_x - 21][game.map.nb_case_y - 35].var = 8;
	game.map.tab[game.map.nb_case_x - 21][game.map.nb_case_y - 35].alt = 0;
	game.map.size.x = 200;
	game.map.size.y = game.map.size.x;
	game_loop(window, &game);
	map_destroy(&game.map);
	sfRenderWindow_destroy(window);
	return (0);
}
