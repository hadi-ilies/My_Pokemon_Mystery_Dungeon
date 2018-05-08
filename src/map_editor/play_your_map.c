/*
** EPITECH PROJECT, 2018
** play_your_map
** File description:
** play_your_map
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "prototype.h"
#include "tile_name.h"
#include "macro.h"
#include "map_editor_function.h"

void play_your_map(sfRenderWindow *window, map_t *map)
{
	(void)window;
	(void)map;
	/*garou_t garou = garou_create(CONFIG);

	garou.dungeon.map = map_copy(map);
	if (garou.dungeon.map.error != ERR_OK)
		return;
	garou.dungeon.map.size = V2F(GAME_ZOOM, GAME_ZOOM);
	garou.dungeon.nb_entity = 20;
	garou.entity = malloc(sizeof(entity_t) * garou->nb_entity);
	if (garou.dungeon.entity == NULL)
		return;
	for (size_t i = 0; i < garou->nb_entity; i++) {
		sfVector2i pos;

		garou->entity[i] = entity_create_from_file(i ? "nomy" : "my");
		do {
			pos.x = rand() % garou->map.nb_case_x;
			pos.y = rand() % garou->map.nb_case_y;
		}
		while (garou->map.tab[pos.x][pos.y].type != GROUND);
		garou->entity[i].dir = V2I(0, 0);
		garou->entity[i].pos = pos;
	}
	game_loop(window, garou);
	garou_destroy(&garou);*/
}
