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

void play_your_map(sfRenderWindow *window, garou_t *garou, map_t *map)
{
	garou->map.size = (sfVector2f){GAME_ZOOM};
	garou->nb_entity = (map->nb_case_x * map->nb_case_y) / 100;
	garou->entity = malloc(sizeof(entity_t) * garou->nb_entity);
	if (garou->entity == NULL)
		return;
	for (size_t i = 0; i < garou->nb_entity; i++) {
		sfVector2i pos = {rand() % garou->map.nb_case_x,
				  rand() % garou->map.nb_case_y};

		garou->entity[i] = entity_create_from_file(i == 0 ?
							   "my" : "nomy");
		while (garou->map.tab[pos.x][pos.y].type != GROUND)
			pos = (sfVector2i){rand() % garou->map.nb_case_x,
					   rand() % garou->map.nb_case_y};
		garou->entity[i].dir = (sfVector2i){0, 1};
		garou->entity[i].pos = pos;
	}
	game_loop(window, garou);
	//garou_destroy(&garou);
}
