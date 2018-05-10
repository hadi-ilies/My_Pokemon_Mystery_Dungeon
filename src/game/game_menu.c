/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game_menu.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "type.h"
#include "tile_name.h"
#include "item.h"
#include "macro.h"

sfVector2i rand_pos_ground(map_t *map)
{
	sfVector2i pos;

	do {
		pos.x = rand() % map->nb_case_x;
		pos.y = rand() % map->nb_case_y;
	}
	while (map->tab[pos.x][pos.y].type != GROUND);
	return (pos);
}

entity_t *generate_entitys(size_t nb_entity)
{
	entity_t *entity = malloc(sizeof(entity_t) * nb_entity);

	if (entity == NULL)
		return (NULL);
	for (size_t i = 1; i < nb_entity; i++) {
		entity[i] = entity_create_from_file("resources/entity/nomy");
		if (entity[i].error != ERR_OK)
			return (NULL);
	}
	return (entity);
}

dungeon_t generate_dungeon(size_t nb_stage, char *file_name)
{
	dungeon_t dungeon = dungeon_create();

	dungeon.nb_stage = nb_stage;
	dungeon.nb_entity = 20;
	dungeon.map = generate_map(50, file_name);
	dungeon.entity = generate_entitys(dungeon.nb_entity);
	return (dungeon);
}

int game_menu(sfRenderWindow *window)
{
	garou_t garou = garou_create(CONFIG);
	int result;

	garou.player = entity_create_from_file("resources/entity/my");
	garou.player.ia = 0;
	if (garou.player.error != ERR_OK)
		return (84);
	garou.dungeon = generate_dungeon(9, "resources/tile_map/Forest config");
	if (garou.dungeon.map.error != ERR_OK || garou.dungeon.entity == NULL)
		return (84);
	garou.dungeon.entity[0] = garou.player;
	sfMusic_play(garou.music);
	result = run_dungeon(window, &garou, -3);
	sfMusic_stop(garou.music);
	if (result == 84)
		return (84);
	dungeon_destroy(&garou.dungeon);
	garou_destroy(&garou);
	return (result);
}
